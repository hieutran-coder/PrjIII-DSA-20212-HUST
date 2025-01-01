#include<iostream>
#include<vector>
using namespace std;


int main() {    
    int n;
    vector<int> a;     
    // Bởi vì có nhiều bộ testcase nên dùng vòng while?. 
    long long res = 0;
    while(true) {

        // Nhập bộ dữ liệu vào
        cin>>n;
        if (n==0) break;

        for (int i = 1; i<=n; ++i)
            cin >> a[i];


        // Xử lý dữ liệu
        res = 0;
        for (int l =1; l <=n; ++l){

            int m = a[l]; // Cọc bên trái?. 
            for (int r = l; r<=n; ++r){
                
                m = min(m, a[r]); //Lấy minh của các cọc từ trái sang phải?. 
                res = max(res, 1LL*m*(r-l+1) );
            }

        }
        cout<<res<<endl;

    }




}