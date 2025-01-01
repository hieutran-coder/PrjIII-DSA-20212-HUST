#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> Adj[1001];
vector<bool> bVisited(1001, false); // mảng này có cả ở DFS vs BFS nhỉ?. 

queue<int> Q; // Ko dùng được đẹ quy với BFS hay sao?. 


int main (){

    int start = 500;    
    
    Q.push(start);

    bVisited[start] = true;

// NẾu q rỗng tức là đã duyệt hết đỉnh trong 1 tplt
    while(!Q.empty()) { // Trong trường hợp  nếu Q không rỗng


    // Ta chọn đối tượng xem xét từ dâu?. 
        int u = Q.front(); Q.pop(); // lấy ra


        // Duyệt các cạnh kề của đỉnh u được lấy ra từ stack?. 
        for (int i = 0; i < Adj[u].size(); ++i) {
                int v = Adj[u][i];

                if (!bVisited[v]){
                    Q.push(v);
                    bVisited[v] = true; 
                }
        }
    }







}

