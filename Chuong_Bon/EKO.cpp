// Code Dũng
#include<iostream>
using namespace std;

long long  n, m;
long long a[1000100];
long long bot, top, mid, ans; 
bool check(int mid) {

    long long sum = 0;

    for (int i = 0; i<=n; ++i){
        if (a[i]> mid) sum += a[i] - mid;
    }

    return sum >= m;
}


int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cin.tie(0);

    // cin >>n>>m;
    // for(int i = 1; i<=n; ++i){
    //     cin >> a[i];
    //     top = max(top, a[i]);
    // }

    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <=n; ++i){
        scanf("%lld", &a[i]);
        top = max(top, a[i]);
    }




    bot = 0;
    ans = -1;

// Cách code 1
// Lấy bao gồm cả bot và top
    while (bot <= top){
        mid = (bot+top)/2;

        if (check(mid)) {
            ans = mid; // ghi nhận đáp án
            // ko cần tìm lại mid nữa Bắt đầu mid+1
            bot = mid +1;
        }{ // check là false thế nên đáp án nằm ở phía dưới, nhưng mid -1 nó có thể xuổng-1 không
           // không ghi nhận đáp án
            top = mid -1;
        }
    }

// Cách code 2; Dễ bị lặp vô hạn.
    while(bot < top) {
        mid = (bot+top)/2;
        if (check(mid)) {
            bot = mid;
        }
        else{
            top= mid -1; }
    }










    printf("%lld", ans);




}