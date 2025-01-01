#include<iostream>

using namespace std;

    int a[10] = {1,2,3,4,0, -1,2,3,4,-3};


int MaxLeftMid(int i, int j) {
    int maxLM = a[j]; // Bắt đầu từ vị trí j
    int s = 0;

    for(int k = j; k>=i; k--) { // Bắt đầu trỏ từ vị trí j và giảm dần đến vị trí i
        s += a[k]; //Tổng
        maxLM = max(maxLM, s); // Nếu maxLM mà nhỏ hơn tổng mới, thì cập nhật, nếu lớn hơn thì bỏ qua 
    }

    return maxLM; 
}

int MaxRightMid(int i, int j) {

    int maxRM = a[i];
    int s = 0;

    for (int k = i; k <=j; k++){
        s+= a[k];
        maxRM = (maxRM>=s)?maxRM:s;
    }
    return maxRM;

}


int SubSeqMax(int i, int j){
    
    if (i == j) return a[i];

// Chia để trị
    int mid = (i+j)/2;
    int wL = SubSeqMax(i, mid);
    int wR = SubSeqMax(mid+1, j);

// Tính toán tổng con mà chạy qua mid, ta chia thành 2 tổng bên trái và bên phải mid
    int maxLM = MaxLeftMid(i,mid);
    int maxRM = MaxRightMid(mid+1, j);

// Tổng hợp
    int wM = maxLM + maxRM;
    return max(max(wL, wR), wM);
}


int main() {


   int b =  SubSeqMax(1, 9);

    cout<<b; 

    return 0;
}