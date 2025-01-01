//  Code Dũng
#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
using namespace std; 

////////////////////////////////////////////
int n, f;
double a[1001001];
double bot, top, mid, s, ep = 1e-9;
double pi = acos(-1);


bool check(double mid){
    int cnt = 0;

    for(int i =1; i<=n;++i){
        cnt += a[i]/mid; // cộng vào số piece có thể chia của mỗi bánh
    }
    return cnt >= f;
}


int main() {

    int ntest;
    cin >> ntest;

    while (ntest--){
        cin >> n>>f;
        f++; // ngoài friends ra còn có cả chủ nhân nữa. 

        for (int i = 1; i<=n; i++){
                cin >> a[i];
                a[i] = pi*a[i]*a[i];
                s+=a[i];
        }

        bot = 0;
        top = (double)s/f;

        while(top - bot>ep) {
            mid = (bot + top)/2;

            if (check(mid)) {
                bot = mid;
            }
            else top = mid; 
        }

        cout << setprecision(6)<<fixed<<bot<<endl;

    }



}