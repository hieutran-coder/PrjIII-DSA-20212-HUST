// Code Dũng
#include<iostream>
#include<algorithm> 
using namespace std;
long long  a[100000];
long long  dp[100000];
int n, l1, l2;
int main() {
    cin >> n>> l1 >> l2;

// Dũng chọn bắt đầu từ 1 không phải bắt đầu từ 0. 
    for (int i = 1; i<=n; ++i)
        cin >> a[i];

    // dp của phần tử biên 0 là 0 và ta sẽ bắt đầu từ phần tử thứ 1.
    dp[0] = 0;

    int res = 0; 
    for (int i = 1; i <=n; ++i ){
        long long  tmp = 0;
        int st = max(0, i-l1); // đỡ phải xét trường hợp giống như code bạn Dương
        int fi = max(0, i-l2);

        for (int j  = st; j <= fi; ++i)
            tmp = max((long long)tmp, dp[j]); // Tìm xem trong những thằng trước đó thì thằng nào max. 

        dp[i] = a[i] + tmp;
        cout <<" "<<dp[i];
        res = max((long long )res, dp[i]);
    }
    cout << res << endl;
}