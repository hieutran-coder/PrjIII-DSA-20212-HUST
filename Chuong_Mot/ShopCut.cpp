
#include<iostream>
using namespace std; 
int main() {
    // Lệnh này để làm gì? stdio.h của c?. 
    ios_base::sync_with_stdio(0);

    // Input trước rồi output sau?. 
    cin.tie(0); cout.tie(0);
    int iProfit[4];
    int T; cin>> T;
    for( int i = 0; i < T; i++){
        cin >> iProfit[0] >> iProfit[1];
        cin >> iProfit[2] >> iProfit[3]; 

        // NHập vào và xử lý luôn
        sort(iProfit, iProfit + 4);

        int sum = 0;

        if (iProfit[0] < 0) sum+=iProfit[0]; // một với hai là lợi nhuận bé nhất?. 
        if (iProfit[1] < 0) sum+=iProfit[1];
        cout << sum << endl; 
    }
    return 0; 
}