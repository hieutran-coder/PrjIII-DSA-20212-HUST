// Liệt kê xâu nhị phân ko có 2 bit 1 đứng cạnh nhau?.
//
#include<iostream>
using namespace std;
#include<string>

int n=9; 
int x[9][9]; // gồm 5 phần tử 0,1,2, 3, 4 
void solution() {
    for(int i = 0; i <n; i++ )
        for(int j =0; j<n; j++) {
            printf("%d", x[i][j]);
            if(j==n-1) cout <<"\n";
        }
}

// BackTracking?. 
// int check(int v, int k){
//     for(int i = 1; i< k; i++) {
//         if ((v-x[i] == i - k)||(v-x[i] == k - i)||(v == x[i]) ) return 0;
//     }
//     return 1; 
// }

// void Try(int k) {
//     for ( int v = 1; v<=n; v++){
//         if( check(v,k)){
//             x[k]= v; 
//             if(k == n) solution();
//             else Try(k+1);
//         }
//     }
// 
bool check(int v, int r, int c) {
    // r, c là cột và hàng toạ độ của điểm 

    // kiểm tra trên hàng chứa và trên cột chứa có thằng nào trùng v ko?. 
    for(int i = 0; i <= r-1; i++)  // Duyệt trên cột
        if(x[i][c] == v) return false;
    for(int j = 0; j<= c-1; j++)  // Duyệt trên hàng?.
        if(x[r][j] == v) return false;
// Xác định (r,c) nằm trong ô 3 nhân 3 nào? trong 9 ô
    // Xác định phần nguyên
    int I = r/3;
    int J = c/3;

    // Phần dư 
    int i = r - 3*I;
    int j = c - 3*J;

// Vòng for này duyệt như thế nào?.(Vẫn đề lỗi để sau)
// Duyệt i1 thì theo hàng, duyệt j thì thoe cột?. 
//i1: Duyệt đến phần dư của toạ độ -1 Ok hiểu.
// Nhưng tại sao j1 lại duyệt hết 0,1,2 mà ko đến j-1 nhỉ?. 
        // Bởi vì quá trình xây dựng chạy theo con rắng từ trái sang phài rồi từ trên xuống?.
            // Thì các hàng trên của toạ độ đã full cả rồi ở 3 cột 0,1,2 trong ô 3 nhân 3 chúa toạ độ 
// Duyệt các hàng trên toạ độ
    for(int i1 = 0; i1<= i -1; i1++) //i là phần dư dọc theo côt
        for(int j1 = 0; j1<= 2; j1++)
            if( x[3*I+i1][3*J + j1] == v)
                return false;
// Duyệt các hàng ngang toạ độ, các hàng dưới toạ độ chưa có thông tin gì?. 3I + i = r    
    for(int j1 = 0; j1 <= j -1; j1++)
        if(x[3*I+i][3*J+j1] == v)
            return false;
    return true;            
}

void TRY(int r, int c){ // Bắt đầu từ 1 toạ độ
    for(int v = 1; v<= 9; v++){// Tập ứng cử viên
        if(check(v,r,c)){
            x[r][c]= v;

            if((r==8)&&(c==8)){
                solution();
            }
            else
                { if(c==8) TRY(r+1, 0);// Bắt đầu hàng mới
                    else TRY(r,c+1);// Tại sao ko cần TRY R= 8?. vì đi duyêt đi theo hàng, ngang, ta chỉ cần 1 bước chuyển.
                }
        }
    }
}




int main() {
   
    TRY(0, 0);


    return 0;
}

