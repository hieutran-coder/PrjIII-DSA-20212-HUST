#include<iostream>
#include<vector>
#include<queue> 
using namespace std;

int INF = 99999999;

// Thầy dùng cấu trúc. 
struct edge{
    int u, v;
    double weight;

    edge(int _u, int _v, int _weight) {
            u = _u;
            v = _v;
            weight = _weight;

    }

};

// Ko cần tydef mà có thể dùng luông từ "edge"; 
void addEdge(vector<edge> adj[], edge e) {
    // Có nhất thiết phải đảo vị trí như thế này không--> Dòng thứ 64 luôn mặc định là v cả?. 
        adj[e.u].push_back(edge(e.u,e.v,e.weight));
        adj[e.v].push_back(edge(e.v, e.u, e.weight)); 
}

// void addEdge(vector<int> adj[], int s, int d) {
//   adj[s].push_back(d);
//   adj[d].push_back(s);
// }



vector<edge> Adj[100]; // Khởi tạo cấu trúc cạnh kề?. 
vector<int> iDist(100, INF); // 100 phần tử là INF; cái thứ 2 chắc để so sánh

    // Xét phần tử bắt đầu làm đầu vào.

    // Tại sao gọi thuật toán này là thuật toán tham lam??. 
    // NÓ có phải thuật toán chính xác không?. 
void Dijkstra(int start){
    iDist[start] = 0; // khoảng cách từ start --> start là 0

    // Các phần tử là pair<int>, So sánh theo heap hay sao ấy?. 
    priority_queue<    pair<int, int>,    vector<pair<int, int> >,   greater<pair<int, int> >    > PQ;

    PQ.push(make_pair(iDist[start], start)); // 


// Trong trường hợp PQ khác rỗng : Khi nào PQ bằng rỗng?.
                            /// Và tại sao PQ khác rỗng?.--> Do ta cập nhật được khoảng cách đến đỉnh đó?.
                            // Khi nào cập nhật được và khi nào không cập nhật được?. 
                                // Không cập nhật được thì ta đã cập nhật rồi, và có thể gặp nhều lần, có lúc gặp thì cập nhật, có lúc gặp thì ko cập nhật
                                // Cập nhật được bởi vì lần đầu tiên gặp hoặc tìm được đường đi đến nó ngắn hơn, nếu đi lần 2,3
    while(!PQ.empty()) {
        int u = PQ.top().second; // 1 là lấy thằng gần với start nhất. và lấy cái đỉnh ra

        PQ.pop(); // bỏ thằng đang xét ra khỏi stack, stack giảm đi một,
                // Nếu không bỏ ra thì sẽ bị đơ ở đây???.

        // Xét từng cặp (khoảng cách đến đỉnh đó, và đỉnh đó) Và ta sẽ cập nhật và bỏ vào stack nếu thoả mãn
        for (int i = 0; i < Adj[u].size(); i++) {
                int v = Adj[u][i].v; // xét đỉnh kề đầu tiên;
                int w = Adj[u][i].weight;// Xét khoảng cahcs

                // nếu khoảng cách cũ từ start đến v tệ hơn khoảng cahcs mới thì cập nhật
                if (w+iDist[u]< iDist[v]){  
                        iDist[v] = w+iDist[u];
                        PQ.push(make_pair(iDist[v], v)); // push cái mới cập nhật vào?. nếu đỉnh này trước đõ đã bỏ vào rồi thì sẽ đẩy cái cũ ra sao??. priority_queue tự làm thế hay so?. 
                }
        }
}


}


int main() {

// Làm sao khởi tạo được đồ thị có trọng số?. 
// Cái cấu trúc này thầy sử dụng khác với cấu trúc của thằng FLoyd_Warshall.cpp. Cách thức khởi tạo tương tự. 
int n = 100;
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

 Dijkstra(0);
 for(int i = 0; i<=n; i++) 
    cout<<"\n Đường đi ngắn nhất từ đỉnh số 0 đến đỉnh "<<i<<" : "<<iDist[i]; // HƠi lỗi



}