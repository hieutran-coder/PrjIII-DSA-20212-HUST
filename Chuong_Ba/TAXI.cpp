#include<iostream>

using namespace std;

int n,m, res;
bool mark[50];
int a[50][50], x[50];

void attempt(int t) {

   if (t >n){
        int tmp = 0;
        tmp = a[0][x[1]]; // Khoảng cách từ điểm số 0 đi đến x[1];      
        for (int i = 1; i<=n; i++){
            tmp += a[x[i]][x[i] + n];

           if(i<n) tmp += a[x[i] + n][x[i+1]]; // vì i+1 có thể vượt quá n nên cần if
        }
        tmp += a[x[n]+n][0];

        res = min(res, tmp);
        return;
    }

    for (int i = 1; i<=n;i++){
        
        if (mark[i] == false) continue;
        cout << t <<" "<< i <<endl;
        mark[i] = false;
        x[t] = i;
        attempt(t+1);
        mark[i] = true;
    }

}


int main() {

    cin>>n;
    m = 2*n;

    for (int i =0;i<=n;i++){
        for (int j = 0; j<=n; j++)
            cin >> a[i][j];
    }

    memset(mark, true, sizeof(mark));
    res = 1e9;

    attempt(1);
    cout <<res<<endl;



}