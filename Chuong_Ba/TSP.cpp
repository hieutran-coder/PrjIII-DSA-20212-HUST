#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
#define INFINITY 9999; 


int n = 4;
bool bVisited[5]; 
int iRes[5];
int C[5][5]; // Con số 101 là số lượng, chứ không phải toán tử truy cập. 
int cmin = 1; 
int f = 0;
// Initializing data structure?
int f0 = INFINITY;  // khởi tạo giá trị kỉ lục



void Try(int k) {
    // duyệt qua n đỉnh?. 
    cout<<"-------------Duyệt sang đỉnh số "<<k<<" ------"<<endl;
    for(int v = 1; v <= n; ++v) {
        // Xét những giá trị chưa được visit?. Tập ứng cử viên?.
        if(!bVisited[v]) {
            iRes[k] = v;
            bVisited[v] = true;
            f = f + C[iRes[k-1]][v]; 
        // Trường hợp cơ sỏ
            if (k == n){
                // So sánh với f0 kỉ lục  trước đó?. nếu bé hơn thì sẽ ập nhật, không thì bo qua
                if (f + C[v][iRes[1]] < f0) 
                    f0  = f + C[v][iRes[1]];
                    cout<<"        Khoảng cách đi từ đỉnh số "<<iRes[k]<<"sang đỉnh số "<< 1 << " là "<<C[iRes[k]][iRes[1]]; 
                    cout<<"    Giá trị kỉ lục mới là "<<f0<<endl; 
        }else {
            // Tính cận dưới nếu k nhỏ hơn n
                int g = f + (n-k + 1)*cmin;
                cout<<"        Khoảng cách đi từ đỉnh số "<<iRes[k-1]<<"sang đỉnh số "<< v << " là "<<C[iRes[k-1]][v];
                cout<<"        Giá trị g là "<< g<<"  Gía trị của f là "<<f<<endl;
                if(g < f0) // nếu cận dưới cập nhật vẫn oke
                    Try(k+1);
        }
        // Thiết lâp lại trạng thái trước đó
        f = f - C[iRes[k-1]][v];        
        bVisited[v] = false; 
    }
}

}


// Cái cách mày mình code thì luôn có đường đi giữa 2 đỉnh rồi, và nó là 1 chiều. --> Ko tổng quát tốt.
    //-->> Nếu không có đường nôi giữa 2 cạnh thì sao.
    //--> Nếu có đường 2 chiều thì sao. 
int main() {
    srand(time(NULL));
    for (int i = 1; i<=n; i++){
        for (int j = i+1; j <=n ; j++){
            
            C[i][j] = rand()%10 + 1;
            C[j][i] = C[i][j];
            cout<<"C["<<i<<"]"<<"["<<j<<"]="<<C[i][j]<<" ";
             }
    }

    for (int v = 1; v <= n; ++v)
        bVisited[v] = false; // đánh dấu là chưa đi đỉnh nào?. 

    iRes[1] = 1; // Chọ đỉnh 1 là đỉh xuất phất?.
    bVisited[1] = true;
    Try(2);
    cout<<"Giá trị kỉ lục là "<< f0; 
    return 0;
}