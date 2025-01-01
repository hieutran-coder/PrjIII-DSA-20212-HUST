#include<iostream>
#include<vector>

using namespace std;

struct edge{
    int u, v;
    double weight;

    edge(int _u, int _v, double _weight){
        u = _u;
        v = _v;
        weight = _weight; 
    }
};

vector<edge> Adj[1001];

double INF = 10000000;

vector<int> iDist(100, INF);

void Bellman_Ford(int n, int start) {

// Ta ko dùng priority queue nữa
    iDist[start] = 0; // 
    // ta sẽ có n vòng 
    for(int i = 1; i< n-1; ++i) {
        // Duyệt và làm việc với từng đỉnh bất kì?. 
        for(int u = 1; u<=n; ++u){
            // với mỗi đỉnh duyệt các đỉnh kề của nó?.
            for (int j = 0; j < Adj[u].size(); ++j) {     //

                    // Lấy 2 thông tin, đỉnh và cạnh từ u đến v
                    int v = Adj[u][j].v; 
                    int w = Adj[u][j].weight;

                    // Cập nhật nếu khoảng cách mới từ start đến v nó nhỏ hơn. 
                    iDist[v] = min(iDist[v], w + iDist[u]); // Cập nhật là khoảng cách đến v
            }
        }
    }

}


int main() {



// Làm sao khởi tạo được đồ thị có trọng số?. 
// Cái cấu trúc này thầy sử dụng khác với cấu trúc của thằng FLoyd_Warshall.cpp. Cách thức khởi tạo tương tự. 
int n = 10;
int k; 
double w;


// Khởi tạo tập cạnh kề?.  
for (int i = 0; i<=n-1; i++){
    for(int j = i+1; j<=n; j++){
            k = rand()%2; // Chọn thêm cạnh nào?. 
            w = rand()%250-100; 

        if(k)
        {
            //addEdge(Adj, edge(i,j,w)); // Nếu chắc chắn hơn thì add luôn cả 2?> 
            Adj[i].push_back(edge(i,j,w));
            Adj[j].push_back(edge(j,i,w)); 
        }
    }
}

// HIển thị tập cạnh đã khởi tạo 
for(int i = 0; i <=n; i++) {
    cout<<"Tập cạnh kề của đỉnh "<<i<<"là"<<endl;
    for (int j = 0; j<Adj[i].size(); j++ ){
            cout<< "("<<Adj[i][j].u<<","<<Adj[i][j].v <<","<<Adj[i][j].weight<<")";
    }
    cout<<"\n";
}

 Bellman_Ford(n,0);
 for(int i = 0; i<=n; i++) 
    cout<<"\n Đường đi ngắn nhất từ đỉnh số 0 đến đỉnh "<<i<<" : "<<iDist[i]; // HƠi lỗi






}