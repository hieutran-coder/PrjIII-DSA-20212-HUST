#include<iostream>

using namespace std;

int n,m, res, mina;
bool mark[50];
int a[50][50], x[50];

// cur là vị trí đang đứng trước khi đi đến vị trí i.
// Cachs không dùng cận
void attempt(int t, int sum, int cur) {
   if (t >n){
        res = min(res, sum + a[cur][0]); // Thêm vào để tạo thành chu trình
    }
    for (int i = 1; i<=n;i++){
            if (mark[i] == false) continue;
            mark[i] = false;

            attempt(t+1, sum + a[cur][i]+ a[i][i+n], i+n); // Quay về điểm i và đi đến điểm n. 
            mark[i] = true; 
        }

}
// Cách dùng cận.
void attempt2(int t, int sum, int cur) {
    if (sum >= res) return; // Cận đơn giản nhất. 
    if (sum + mina*( 2*(n+1-t) + 1) >= res) return; // Cận cải tiện của 1 bạn
   if (t >n){
        res = min(res, sum + a[cur][0]); // Thêm vào để tạo thành chu trình
    }
    for (int i = 1; i<=n;i++){
            if (mark[i] == false) continue;
            mark[i] = false;

            attempt(t+1, sum + a[cur][i]+ a[i][i+n], i+n); // Quay về điểm i và đi đến điểm n. 
            mark[i] = true; 
        }

}

int main() {

    cin>>n;
    m = 2*n;
    mina = 1e9;


    for (int i =0;i<=m;i++)
        for (int j = 0; j<=m; j++){
            cin >> a[i][j];
            if (i != j) mina = min(mina, a[i][j]);
    }

    memset(mark, true, sizeof(mark));
    res = 1e9;

    attempt(1,0,0);
    cout <<res<<endl;

}


/*
2
0 8 5 1 10
5 0 9 3 5
6 6 0 8 2
2 6 3 0 7
2 5 3 4 0

*/

