#include<vector>
using namespace std; 
#include<iostream>




int main() {

    // n là số lượng đỉnh và m là số lượng cạnh
    int n, u, v, m;

    cin >> n>> m;
    
    vector< vector<int> > A(n); // 

// Nhập m cạnh vào: 2 cách khác là nhập trong hàm intmain() hay khởi tạo random?. 
    for (int i = 0; i < m; i++)
    {
        cin>> u>>v;
      // tuong tu
        A[u].push_back(v);
        A[v].push_back(u);
    }

    // Xet tung dinh
    for(int i = 0; i<n; i++)
    {

        cout<< i<< " ----> "; // Bat dau tu 1 dinh 


        for(int j = 0; j < A[i].size(); j++){
                cout<<A[i][j]<<"-->";
                cout<< "\n";
        }


    }


}