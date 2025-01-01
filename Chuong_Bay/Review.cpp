#include<iostream>
#include<vector>

using namespace std;

const int n = 1001;



vector<int> Adj[n]; // đồ thị vô hướng
vector<int> Low(n), Num(n, -1);


int curnum = 0;


void AnalyzeDFS(int u, int p) {

    Low[u] = Num[u] = ++curnum; // Num[u] sẽ fix còn low[u] sẽ cập nhật


// Cấu trúc lời giải cũng giống vibo
    // Duyệt các đỉnh kề: Có 3 trường hợp
    for (int i = 0; i < Adj[u].size(); ++i) {
            int v = Adj[u][i];
            if (v == p) continue; // Bỏ qua
            // Chưa thăm đỉnh v
            if (Num[v] == -1){
                AnalyzeDFS(v,u);
                Low[u] = min(Low[v],Low[u]);
            } else {
            // Đã thăm đỉnh v--> Đỉnh v là tổ tiện, cạh kề này là ngược
                Low[u] = min(Low[u], Num[v]);
            // nhánh else này không duyệt vào v mần chi để đi đến vô hạn
            }


    }



}