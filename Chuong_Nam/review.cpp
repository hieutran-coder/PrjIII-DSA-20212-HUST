// #include<iostream>

// using namespace std;

// int INF = 10000000;
// int D[11] = {200, 599, 1000, 2000, 5000, 10000, 20000, 50000};
// int iMem[11][100001];

// // Hàm tìm min number of coin
// int MinCoin(int i, int x){

//     if(x<0) return INF;
//     if (x == 0) return 0;
//     if (i == 0) return INF;


//     if (iMem[i][x] != -1) return iMem[i][x];

//     int res = INF;
//     res = min(res, 1 + MinCoin(i, x-D[i]) );
//     res = min(res, MinCoin(i-1, x));
//     iMem[i][x] = res;

//     return res;

// }


// void Trace(int i, int x) {

//     if(x<0||x==0||i==0) return;

//     int res = INF;

//     if(iMem[i][x] == 1 + iMem[i][x-D[i]]){
//         cout << D[i] <<" ";
//         Trace(i, x - D[i]);
//     }else {
//         Trace(i-1,x);
//     }

// }

// int main() {

//     memset(iMem, -1, sizeof(iMem));
//     cout<<MinCoin(10, 15000);

//     cout<<" Want trace??";
//     char check; cin >> check;


//     if ((check != 'y')||(check != 'Y')) return 0;
    
    
//     int n, x;
//     cin >>n>>x;

//     int ans = iMem[n][x];
//     cout << ans << endl;

//     for (int i = n, k = 0; k <ans; ++k){
//         if (iMem[i][x] == 1 + iMem[i][x-D[i]] ){
//                     cout << D[i]; // show mđ
//                     x -= D[i];
//         } else {
//             --i;
//         }
//     }
// }


// #include<iostream>
// using namespace std;

// #include<map>

// map<int, int> Mem;

// int fibonacci(int n) {

//     if (n <= 2) return 1;

//     if (Mem.find(n) != Mem.end()) return Mem[n];

//     int res = fibonacci(n-2) + fibonacci(n-1);

//     Mem[n] = res;
//     return res;
// }


// int iMem[1001];

// int Fib(int n) {
//     if (n<=2) return 1;
//     if (iMem[n] != -1) return iMem[n];

//     int res = Fib(n-1) + Fib(n-2);

//     iMem[n] = res;
//     return res;
// }

// int main() {
//     int i = 0;

// // Vòng lặp while, hay khối lệnh while có thê thay bằng memset
//     while (i<1001){
//         iMem[i] = -1; ++i;
//     }

//     int a = Fib(19);
//     cout <<a;
// }


// #include<iostream>
// using namespace std;
// #include<stack>

// // int Memory[1000];
// // int a[1000];


// // int MaxSubArrayHasLast(int a[], int i) {

// //     int S[i+1], res = 0;
// //     S[0] = 1;
// //     if (i = 0) return S[0];

// //     //i >=1
// //     for (int j = 0; j<i; j++){
// //         if (a[j] <= a[i])
// //             if (Memory[j] != -1){
// //                 Memory[j] = MaxSubArrayHasLast(a,j);
// //                 res = max(res, Memory[j]);
// //             }
// //     }

// //     return res + 1;
// // }


// // int MaximumSubArray(int a[], int n) {

// //     int MaxSubArray = 0;

// //     for (int i = 0; i<=n; i++){
// //         MaxSubArray = max(MaxSubArray, MaxSubArrayHasLast(a,i));
// //     }

// //     return MaxSubArray;

// // }

// // void traceBack1(int n){

// //     cout << a[n] <<" "; // Show element n

// //     if (Memory[n] == a[n]) return; 

// //     for (int i = n; i>=0; i--){
        
// //         if (Memory[i] == -1){
// //             Memory[i] = MaxSubArrayHasLast(a,i);
// //         }

// //         if (Memory[n] = Memory[i] + 1)
// //             cout <<a[i] <<" ";
// //             traceBack1(i);
// //             break;
// //     }
// // }

// int A[1001];
// int iMem[1001];


// int LIS(int i) {

//     if (iMem[i] != -1 ) return iMem[i];

//     int res = 1;

//     for (int j = 1; j<i; ++j){
//         if (A[j] < A[i]){ // Của thầy ko phải cộng 1 mà là bé thua
//             res = max(res, 1+ LIS(j));
//         }
//     }

//     iMem[i] = res; // Store value vào bộ nhớ
//     return res;
// }

// void Trace(int i ) {
//     int res = 1;

//     for (int j = 1; j<i; j++){
//         if (A[j] < A[i] && iMem[i] == 1 + iMem[j]){  // Cái expression 1 không bỏ được
//             Trace(j);
//             break;
//         }
//     }
//     cout << i << " ";
// }


// int main() {

//     memset(iMem, -1, sizeof(iMem)); // Tại sao cần có tham số thứ 3

//     for (int i = 0; i< 1001; i++)
//             A[i] = 50 - rand()%100;

//     int ans = 0, pos = 0;
//     int n = 500;

//     LIS(n);

//     for (int i = 1; i<=n; i++){
//         ans = max(ans, iMem[i]); // Find max;

//         if (ans == iMem[i]) pos = i;
//     }
//     cout << ans;

//     stack<int> S;

//     // Giai đoạn bỏ vào
//     for(int i = pos, k = 0; k < ans; ++k) {
//         S.push(i); // push i vào S

//         // For every i, find preposition
//         for (int j = 1; j<i; ++j){
//             if (A[j] < A[i]) && iMem[j] + 1 == iMem[i]){
//                 i = j;
//             }
//         }
//     }
//         // S chỉ có 1 phần tử hay sao?. Giai đoạn bốc ra
//         while (!S.empty()) {
//             cout << S.top() << " ";
//             S.pop(); 
//         }

// } }

// #include<iostream>
// #include<stack>

// using namespace std;

// int iMem[1000][1000];
// int X[1000], Y[1000];

// int LCS(int i, int j) {

//     // Base case
//     if (i == 0||j == 0) return 0;

//     if (iMem[i][j] != -1) return iMem[i][j];

//     int res = 0;
//     res = max(res, LCS(i, j-1));
//     res = max(res, LCS(i-1, j));

//     if (X[i] == Y[j]){
//         res = max(res, 1 + LCS(i-1,j-1));
//     }
//     iMem[i][j] = res;
//     return res;

// }

// // Trace Back by recursion

// void traceBack(int i, int j) {

//     if (i == 0||j == 0) return;

//     if (iMem[i][j] == iMem[i-1][j]){
//         traceBack(i, j-1);
//         return;
//     }

//     if (iMem[i][j] == iMem[i][j-1]){
//         traceBack(i,j-1);
//         return;
//     }

//     if (X[i] == X[j] && iMem[i][j] == 1 + iMem[i-1][j-1]){
//         traceBack(i-1,j-1);
//         cout << X[i];
//         return;
//     }
// }

// #include<iostream>
// #include<algorithm>

// using namespace std;

// long long a[100000];
// long long dp[100000];

// int n, l1, l2;
// int main() {
//     cin >> n >> l1 >> l2;

//     for (int i =1; i<=n; i++) cin >> a[i];

//     dp[0] = 0;
//     int res = 0;

//     for (int i = 1; i<=n; ++i){
//         long long tmp = 0;
//         int st = max(0, i- l1);
//         int fi = max(0, i - l2);

// // Cái sau xây lên từ cái trước, không cần đệ quy giống  như m
//         for (int j = st; j<=fi; ++i)
//             tmp = max((long long )tmp, dp[j]);
        
//         dp[i] = a[i] + tmp;
//         cout << " "<< dp[i];
//         res = max( (long long)res, dp[i]);
//     }
//     cout << res << endl;
// }


#include<iostream>
#include<iterator>
#include<set>
#include<cmath>
#include<stack>

using namespace std;

// mã thầy
const int N = 20;
const int INF = 100000000;

int C[N][N];
int iMem[N][1<<N];

int TSP(int i, int S){

    if (S == ((1<<N)-1)) return C[i][0];

    // Check memory
    if(iMem[i][S] != -1) return iMem[i][S];
    int res = INF;

    for (int j = 0; j <N; j++){
            if (S &(1<<j)) continue;

            res = min (res, C[i][j] + TSP(j, S|(1<<j)));
    }

    iMem[i][S] = res;
    return res;
}


//traceback
void trace(int i, int S) {
    cout << i << " ";
    int res = iMem[i][S];

    for (int j = 0; j<N; j++){
        if ( S&(1<<j) ) continue;
        if(res = C[i][j] + iMem[j][S|(1<<j)]) { 
            trace(j, S|(1<<j)); break;
        }
    }
}


int main () {

    memset(iMem, -1, sizeof(iMem));

    for (int i = 0; i<N; i++)
        for (int j = i +1 ;j<N ; j++){  // i bằng j thì sao??
            C[j][i] = rand()%100;
            C[j][i] = C[i][j];
            cout << C[i][j]<<" ";
        }

    cout <<endl;
    cout <<endl;

    cout << TSP (0, 1<<0) <<endl;

    trace(1, 1<<0);


    // trace by loop
    int ans = iMem[0][1];
    cout << ans <<endl;

    stack<int> Stack;
    Stack.push(0); 

    for (int i = 0, S = 1, k = 0; k < N-1; ++k){


        for (int j = 0; j<N; j++){

            // Còn phải kiểm tra biểu thức đầu nữa!!
            if (!(S&(1<<j)) && (iMem[i][S] == C[i][j] + iMem[j][S|(1<<j)])){
                        Stack.push(i);

                        // Start traceBack from j??
                        i = j;
                        S = S|(1<<j);
            }
        }
    
        while( !Stack.empty()) {
            Stack.pop();
        }
    }

}



