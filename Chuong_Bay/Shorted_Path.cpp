#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> Adj[1001];
vector<int> iDist(1001, -1); // Hàm tính khoảng cách các đỉnh

queue<int> Q;




int main() {

    int a = 100;
    int b= 200; 

    // Làm sao chọn 1 đỉnh là đỉnh đầu tiên duyệt?. 
    Q.push(a); /// cho a là start trên cây DFS?. 
    iDist[a] = 0; 

while( !Q.empty() ){

    int u = Q.front(); Q.pop(); 

    for (int i = 0; i< Adj[u].size(); ++i){
            int v = Adj[u][i];

            if (iDist[v] == -1){ //Nếu qoantr đườn đến v chưa được tính hay v chưa được duyệt?. 
                Q.push(v); 
                iDist[v] = 1 + iDist[u]; //iDist có 2 mục tiêu luôn
            }
    }
}

cout<< iDist[b]<< endl;



}