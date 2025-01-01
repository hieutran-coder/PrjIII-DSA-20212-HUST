// Code Dũng

#include<iostream>

using namespace std;
int n, c;
int a[100100];
int bot, top, mid, ans;

bool check(int mid) {
    int last = a[1];
    int cnt = 1;

    for (int i = 2; i<=n; ++i)
        if (last + mid <=a[i]){
            cnt ++;
            last = a[i];
        }
    return cnt >=c;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    
    int ntest;  // Biến lấy số lượng test
    cin>> ntest;
    while(ntest--) {
        cin >> n>> c;
        for (int i = 1; i<=n; ++i){
            cin >>a[i];
        }

    sort (a+1, a+1+n); // Được dùng khi đi thi luôn. 

    bot = 0;
    top = 1e9;
    ans = -1;


    while (bot <= top){
        mid = (bot + top)/2;

        if (check(mid)) {
            ans = mid;
            bot = mid + 1; // tìm đáp an tốn hơn nữa 
        }
        else top = mid -1;;


    }
    
    cout << ans<<endl;

    }





}