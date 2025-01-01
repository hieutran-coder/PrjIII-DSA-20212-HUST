#include<iostream>
#include<vector>
#include<stack> 
using namespace std;

int a[1000100];
int l[1000100];
int main() {    
    int n;
         
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

        stack<int> st;
        for (int i = 1; i<=n; ++i){
            
            while (!st.empty() && a[st.top()] >= a[i]){
                st.pop();
            }

        // st rỗng: bỏ nó vào stack. 
            if (st.empty()) l[i] = 0;
                else l[i] = st.top();
            st.push(i);
        
        }

        for (int i = 1; i<=n; i++){
                cout<<i<<" "<<l[i]<<endl;
        }

        // Tương tự tìm right thì sẽ đi từ cuôi về. 
        cout<<res<<endl;

    }


}

// using namespace std;

// int n;int a[1000100], l[1000100], r[1000100];long long res;

// int main() {while (true) {cin >> n;if (n == 0) break;

// for (int i = 1; i <= n; ++i)cin >> a[i];

// res = 0;

// stack <int> st;for (int i = 1; i <= n; ++i) {while (!st.empty() && a[st.top()] >= a[i]) {st.pop();}

// if (st.empty()) l[i] = 0;else l[i] = st.top();st.push(i);}

// stack <int> st1;for (int i = n; i >= 1; --i) {while (!st1.empty() && a[st1.top()] >= a[i]) {st1.pop();}

// if (st1.empty()) r[i] = n + 1;else r[i] = st1.top();st1.push(i);}

// for (int i = 1; i <= n; ++i) {res = max(res, 1LL * a[i] * (r[i] - l[i] - 1));}

// cout << res << endl;}

// }

