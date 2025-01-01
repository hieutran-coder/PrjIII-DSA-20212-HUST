#include<iostream>
#include<vector>
using namespace std;

const int n = 1001;


vector<int> Adj[n], Low(n), Num(n, -1);

int curnum = 0;

vector<pair<int, int> > iiBridges; // Là vector với các phần tử là các bộ cặp int

void Find_Bridges(int u, int p) { // u là đỉnh duyệt và p là parente

    Low[u] = Num[u] = ++curnum; // Đán số low và num

    for( int i = 0; i < Adj[u].size(); ++i) {
            // Xét tập tất cả cạnh kề với u
            int v = Adj[u][i];
            if (v == p) continue; // nếu v là parent thì bỏ qua

            if (Num[v] == -1)// Xét những đỉnh chưa được duyệt?.
            {
                Find_Bridges(v, u); // đệ quy với v là đỉnh tiếp theo và u là cha của v trên cây dfs
                
                
                Low[u] = min(Low[u], Low[v]); // Tại sao lại có công thức này. 
        
            } else {
                // Đỉnh đã duyệt trên cây dfs rồi 
                Low[u] = min(Low[u], Num[v]); 
            }

            if (Low[v] > Num[u])
                iiBridges.push_back(make_pair(u, v));
}
}


// Khởi tạo bằng cách thêm 1 cạnh vào?.
void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d); // Thêm d vào tập cạnh kề s;
    adj[d].push_back(s); // Thêm s vào tập cạnh kề d;
}


int main() {


    // Làm sao khởi tạo giá trị cho cấu trúc tập các cạnh kề?. 
    // addEdge(Adj, 0,1);
    // addEdge(Adj, 0, 2);
    // addEdge(Adj, 0, 3); 
    // addEdge(Adj, 1, 2); 



    //Làm sao khởi tạo 1 cách random 2 cạnh được nối hay hay cạnh không được nối.
    // int c; 
    // for (int i = 0; i<n-1; i++){
    //     for (int j = i+1; j<n;j++){
    //         c = rand()%2;
    //         if (c == 0 ) addEdge(Adj, i, j); 
    //     }
    // }

    for (int u = 1; u<=n; u++ ){
        if (Num[u] == -1)
            Find_Bridges(u, -1); 
    }


    for (int i = 0; i<iiBridges.size(); i++)
        cout<<iiBridges[i].first<< " "<<iiBridges[i].second<<endl;
}

