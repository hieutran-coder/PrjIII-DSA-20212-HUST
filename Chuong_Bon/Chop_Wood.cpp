#include<iostream>
#include<vector>
using namespace std;

int N,M,lo =0, hi = 0, mid;

int p(int height, int N, const vector<int> &a) {
    int sum = 0;

    for (int i = 0; i<N; i++){
        if (height < a[i]) sum += a[i] - height;
    }

    return sum >= M; 
   // return sum; 
}

int res;

// Bạn Nhật
void sol(int bot, int top ){
    if (bot> top) return;
    int mid = (bot + top)/2;

    if (check(mid)){
        res = mid; // Hay vãi lưu biến mid ra ngoài rồi bắt đầu mid + 1; 
        sol(mid+1, top);
    }
    else sol(bot, mid-1);

}
// Cách code 1 của Dũng
int binarySearch1(int bot, int top){
    
    if (bot > top) return;

    int mid = (bot + top)/2;

// Kiểm tra mid
    if (check(mid)) {
        // Trong này lại kiểm tra đoạn từ mid +1, đến top
        int tmp = binarySearch1(mid + 1, top);
        if (tmp != -1) return tmp;
        return mid;
    }
    else { // mid không thoả mãn
        // kiểm tra từ bot đến mid-1
        return binarySearch1(bot, mid-1);
    }
    return -1;

}




// Cách code 2 của Dũng
int binarySearch2(int bot, int top) {
    // Dũng quăng hết trường hợp nhỏ lên trên
    if (bot> top) return -1;
    if (bot == top) return bot;

    if (bot +1== top) {
        if (check(top)) return top;
        return bot;
    }

    int mid = (bot + top)/2;

    if (check(mid)) {
        return binarySearc2(mid, top);
    }
    else{
        return binarySearch2(bot, mid);
    }
    return -1;
}




// Đề bài là tìm vị trí cao nhất mà chặt ít nhất M mét
int main() {

//freopen("input.inp","r", stdin);
// freopen("output.inp","w", stdout);

cin>>N>>M;

vector<int> a(N, 0);

for (int i = 0; i<N; i++){
    cin>> a[i];
}

for (int i = 0; i<N; i++){
    if (a[i]> hi) hi = a[i];
}


//Binary Search không dùng đệ quy. 
// Code này không ổn, tất cả false thì sao thoát ra vòng lặp. 
// Một điểm khác nữa là lợi ích code này nó không phụ thuộc ans ở bên ngoài. 
while (lo <hi){
    if (hi == lo + 1) break; // Nếu ko có câu lệnh này thì vòng lặp vô hạn. true luôn ở dưới false. 
    mid = (lo + hi)/2;
    
    if (p(mid,N,a)) lo = mid;
    else hi = mid;
}



cout<<lo;
}

