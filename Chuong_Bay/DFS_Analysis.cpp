#include<iostream>
using namespace std;
#include<vector>


const int n = 1001;

vector<int> Adj[n];
// Num là mảng dùng để làm gì?. 
vector<int> Low(n), Num(n, -1); 

int curnum = 0; // biết này có chức năng gì?. 

// PHân tích DFS để làm gì?. để xác định num và low và tail luôn nếu cần

// u là gì và p là gì?. u là đỉnh bắt đầu phân tích, của p là parent của u]
// mỗi u chỉ có 1 parent thôi
// Ví dụ trên Vibo thì tác giả xây dựng hàm parent cmnr
void AnalyzeDFS(int u, int p) {


    Low[u] = Num[u] = ++curnum;

    // Xét tâp cạnh kề của u?. 
    for (int i = 0; i < Adj[u].size(); ++i){
            int v = Adj[u][i];
            if (v == p) continue; // p là đỉnh ngay trước sao?.

            if (Num[v] == -1){
                AnalyzeDFS(v, u); // Phân tích DFS của v
                Low[u] = min(Low[u],Low[v]); //? Không hiểu. 
            } else{
                Low[u] = min(Low[u], Num[v]); 
            }
    }

}


// Cahcs code khác
int time_dfs = 0; // Là thời điểm DFS

int num[n], low[n], par[n], tail[n];

void dfs(int u) {

   num[u] = low[u] = ++time_dfs;

    for (int v: Adj[u]){
        if (v == par[u]) continue;
    
       // Nếu chưa có num[v] tức cây DFS chưa xây đến V
        if (!num[v]){
            par[v] = u;
            dfs(v);
            low [u] = min(low[v], low[u]);
        } 
        else{
            low[u] = min(low[u], num[v]);
        }
    
    
    tail[u] = time_dfs;
    }




}
