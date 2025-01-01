#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct edge{
    int u, v;
    double weight;
    edge(int _u, int _v, int  _weight) {
        u = _u;
        v = _v;
        weight = _weight; 
    }



};
vector<vector<edge> > Adj;
vector <edge > mst(int n, vector <vector <edge >> Adj){
    priority_queue < pair <int ,int >, vector <pair <int ,int >>, greater<pair <int ,int >> > PQ; // Các tham số như thế nào?. Tham số cuôi thể hiện nó là heap hay sao?. 
    vector<edge> res; // Edge of cây khung
 
    vector<int> iBest_W(n+1, 1e9), iBest_A(n+1, -1); // Khởi tạo 2 mảng khoảng cách nhỏ nhất đến cây khung và, tập các đỉnh thuộc cây khung gần nhấ.t 

    iBest_W[1] = 0;
    PQ.push({iBest_W[1], 1}); // Vậy thì phần tử thứ nhất lfa cái dùng để so sanh
                            // PHần tử thứ 2 là đỉnh?. 
    while(res.size() < n-1) {
        while(!PQ.empty() && PQ.top().first != iBest_W[PQ.top().second]) // Câu lệnh này là gì?. 
                            // Vế trái là khoảng cahcs đến cây khung, vế phải là ??
        PQ.pop();

        if (PQ.empty()) return res; // G_ ko connected
        int w = PQ.top().first, v= PQ.top().second, u =iBest_A[v];

        // cập nhật
        for (edge e: Adj[v])
            if( iBest_W[e.v] > e.weight) {
                iBest_W[e.v] = e.weight;
                iBest_A[e.v] = e.u;
                PQ.push({iBest_W[e.v],e.v});
            }
    if (v != 1) res.push_back({u,v,w});
    }
    return res;
}

int main() {

    int n = 10;
int k; 
double w;


// Khởi tạo tập cạnh kề?.  
for (int i = 0; i<=n-1; i++){
    for(int j = i+1; j<=n; j++){
            k = rand()%2; // Chọn thêm cạnh nào?. 
            w = rand()%250; 

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


}