#include<iostream>

using namespace std;

// int D[9] = {1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000};

// int MMem[10000000][9];

// int INFINITY = 999999;

// int minNumberOfMoney(int x, int n) {

//     // Base case
//     if(x < 0) return INFINITY; 
//     if (x== 0) return 0; 
//     if (n == 1){
//         if(x==D[0]) return 1;
//         else return INFINITY;
//     }

//     // Lưu vào bộ nhớ?. 
//     if (MMem[x][n] != -1) return MMem[x][n];


//     //recursion
//     int t1 = minNumberOfMoney(x, n-1);
//     int t2 = minNumberOfMoney(x-D[n], n) + 1;
//     MMem[x][n] = min(t1,t2); 

//     return MMem[x][n]; 
// }


// int main() {
//     memset(MMem, -1, sizeof(MMem)); 

//     //cout<< MMem[40000][5];

//     cout<< minNumberOfMoney(3000, 3); // Tại sao nó vẫn return về 999999?. 

// }
//----------------------------------------------

int INF = 10000000;
int D[11] ={200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000};
int iMem[11][10001];

//Hàm tìm số lượng các đồng tiền nhỏ nhất cần?.--> Optimizing số lượng giấy
int MinCoin(int i, int x) {

    if (x < 0) return INF;
    if (x == 0) return 0;
    if (i == 0) return INF;

    if ( iMem[i][x] != -1) return iMem[i][x]; // kiểm tra xem giá trị min coi với i mệnh đề đã được lưu chưa--> Lưu rồi thì lấy dùng thôi

    int res = INF;

    res = min(res, 1 + MinCoin(i, x - D[i])); // so sánh với tổng đầu tiên
    res = min(res, MinCoin(i-1, x));
    iMem[i][x] = res;
    return res; 
}


// Nếu 2 nhành bằng nhau thì đi theo nhánh nào cũng được hay soa?. 
void Trace(int i, int x) {

    // 3 trường hợp base case x có thể rót xuống dưới 0. 
    if (x<0) return;
    if (x == 0) return;
    if (i == 0) return;

    int res = INF; // Bắt đầu từ vô hạn

    // Kiểm tra xem nó đi theo nhánh nào?. Nếu nó đi theo nhánh này thì print mệnh giá mà nó dùng và trace tiếp?.
    if (iMem[i][x] == 1 + iMem[i][x-D[i]]){
        cout << D[i] << " ";
        Trace(i, x - D[i]); 
    }else
        {
            Trace(i-1, x); // trace thoe nhánh khác--> Tức không dùng mệnh đề D[i] nữa
        }
}





int main () {
    memset(iMem, -1, sizeof(iMem)); 
    cout<<MinCoin(10,15000);


//Traceback thẳng trên memory luôn, đỡ lằng nhằng?.
    cout<<" Do you want to trace back ?";
    char check;
    cin>>check; 
    if ((check != 'y')||(check != 'Y' ))
            return 0; 

    int n, x;
    cin>>n>>x; 

    int ans = iMem[n][x];
    cout << ans << endl; // cout số lượng tiền nhỏ nhất mà x cần đổi?. 


    for (int i = n, k = 0; k <ans; ++k){
        if (iMem[i][x] == 1 + iMem[i][x-D[i]]){ // nếu đúng nhánh này
                cout << D[i]; // Hiện thị mệnh đề
                x -= D[i]; // Bớt mệnh đề D[i] đi
        } else {
            --i; 
        }
    }
}


