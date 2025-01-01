#include<iostream>
#include<iterator>
#include<set>
#include<cmath>
#include<stack> 
using namespace std;

// Cài đặt?. 

// Ý tưởng sử dụng tập set?. 
//  int C[1000][1000];
//  int n;
//  int iMem[1000][100000000];
// set<int> s;

// int TSP(int i, set<int> s){

// // Nếu đã đi hết các đỉnh?. 
//     if(s.size() == n) return C[i][0];

// for(int i =0; i<n; i++) {
// }
 
// Ý tưởng sử dụng bitmask?. 

// int INFINITY = 999999999;

// int TSP(int i, int S) {

//     if (S == pow(2,n+1)-1) return C[i][0];

//     int res = INFINITY;
    
//     for (int j = 1; j<n; j++){

//         if (S & pow(2,j) != (int)pow(2,j)){
//                 res = min(res, C[i][j] + TSP(j, S|(int)pow(2,j)));
//         }
//     }
//     iMem[i][S] = res; 
//     return res;

// }

// Code thầy
const int N = 20;
const int INF = 100000000;

int C[N][N];
int iMem[N][1<<N];

int TSP(int i, int S) {

    if (S==((1<<N) - 1)) return C[i][0]; // nếu đã duyệt qua n đỉnh

    // Kiểm tra bộ nhớ đã lưu chưa
    if (iMem[i][S] != -1) return iMem[i][S];

    int res = INF;

    // Ta sẽ kiểm tra những đỉnh nào chưa thuộc tập S thì sẽ thêm vào
    for (int j = 0; j < N; j++){
            
            if (S & (1 << j)) // Nếu gặp thằng thuộc tập con thì bỏ qua, lệnh này nó tối ưu hơn lệnh bằng bằng.
                continue;
            // res dùng để so sánh các th j khác nhau
            res = min (res, C[i][j] + TSP(j, S| (1<<j)));
    }
    iMem[i][S] = res;
    return res; 
}


//traceback
// Tại sa thầy dùng biến res nhỉ?. 
void trace(int i, int S){
    cout<<i<<" ";
    int res = iMem[i][S];

    for (int j = 0; j<N; j++){
        if (S & (1<<j)) continue; // bỏ qua những đứa đã thuộc tạp S. 
        if (res == C[i][j]+ iMem[j][S|(1<<j)]){ 
            trace(j,S|(1<<j)); // Tại sao item trên có C[i][j] mà đây không có
            break; // chú ý không thiéu?. Đã tìm được rồi thì ko cần duyệt tiếp phần còn lại nữa. 
    }

}

}






int main() {
    memset(iMem, -1, sizeof(iMem));
    for (int i = 0; i< N; i++)
        for (int j = i+1; j<N; j++){
                C[i][j] = rand()%100;
                C[j][i] = C[i][j];
                cout<< C[i][j]<<" ";

        }
    cout<<endl;
    cout<<endl; 
    cout << TSP(0, 1<<0)<<endl; // Lệnh này lỗi rồi. 



    trace(1, 1<<0);
    

    // truy vết bằng vòng lặp
    int ans = iMem[0][1];
    cout << ans <<endl;

    stack<int> Stack;
    Stack.push(0); // đình đẩu tien hay sao?

    for (int i = 0, S = 1, k = 0; k < N-1; ++k){  // vai trò của k là gì?. 
        
        for (int j = 0; j < N; ++j){ // Vai trò của j là gì?. 

            // Tại sao phải cần check exp1
            if (!(S&(1<<j)) && (iMem[i][S] == C[i][j] + iMem[j][S|(1<<j)])){
                    Stack.push(j);

                    // Bắt đầu trackback từ j?. 
                    i = j;
                    S = S| (1 << j);
            }    
        }

    while( !Stack.empty()) {
        //cout << Stack.back()<< " ";
        Stack.pop(); 
    }
    }

}


