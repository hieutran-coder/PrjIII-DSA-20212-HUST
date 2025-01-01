#include<iostream>
using namespace std;
#include<vector>
#include<stack>


int n = 1000;


vector<int> Adj[10001]; // Tại sao thầy lại chọn con số này
vector<int> Low(10001), Num(10001,-1); // 2 con số này cũng quan trọng trong strong component hay sao?. 

vector<bool> bConnect(10001, false); // Chức năng mảng này là gì

int curnum = 0; //current-number??

stack<int> iComp; //  bài compnent co đồ thị có hướng bắt buộc phải dùng stack hay sao?.
                  // Tại sao?. 

void SCC(int u){

        // Đẩy u vào stack iComp
        iComp.push(u);

        bConnect[u] = true;

        // Câu lệnh này giống với bài component cho vô hướng
        Low[u] = Num[u] = ++curnum;

        for (int i = 0; i< Adj[u].size(); ++i) {
            int v = Adj[u][i];

            if (Num[v] == -1){
                    SCC(v); // đệ quy?.
                    Low[u] = min(Low[u], Low[v]);
            } else if (bConnect[v]){  //bConnect để kiểm tra cái gì?. 
                Low[u] = min(Low[u], Num[v]); 
            }
    }

    // Nếu bằng nhau thì thuộc chung 1 component??> 
        if (Num[u] == Low[u]){
            cout<< "TPLT: ";
            while(true) { // vòng lặp vô hạn
                int cur = iComp.top();
                iComp.pop();
                bConnect[cur] = false;// xoá ra khỏi hay sao?.

                cout << cur << " ";
                if (cur == u) break; // Tại sao?. 
            }
            cout<< endl; 
        }
    }



int main() {
    
    for (int i = 0; i < n; ++i){
        if (Num[i] == -1)  // xét những đỉnh chưa được duyệt/. 
            SCC(i);
    }




}