#include<iostream>
#include<vector>


using namespace std;


vector<int> Adj[1001];
vector<bool> bVisited(1001, false);
vector<int> iOrder;


void Topo_Sort(int u) {

    if (bVisited[u]) return; // nếu đã duyệt rồi thì bỏ qua?.
    // Trường hợp này xảy ra khi nào?. --> Khi duyệt xong rồi. ko đúng
    // Khi đi vòng?. 
    // Nó ko quan tâm đến duyệt xong hay chưa xong nhỉ?. 
    //--> Duyệt chưa xong và duyệt xong, chỉ cần đã duyêtj là ko đi đó nữa. 

    bVisited[u] = true; 

// Duyệt từng dỉnh?. Thứ tự duyệt các đỉnh kề là thứ tự ta add vào đồ thị. 
    for (int i = 0; i < Adj[u].size(); ++i) {
            int v = Adj[u][i];
            Topo_Sort(v); 
    }
    iOrder.push_back(u); // Đặt u vào sau dãy iOrder
}

// Khởi tạo bằng cách thêm 1 cạnh vào?.
void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d); // Thêm d vào tập cạnh kề s;
    adj[d].push_back(s); // Thêm s vào tập cạnh kề d;
}




int main() {

    
// Làm sao khởi tạo giá trị cho cấu trúc tập các cạnh kề?. 
    addEdge(Adj, 0,1);
    addEdge(Adj, 0, 2);
    addEdge(Adj, 0, 3); 
    addEdge(Adj, 1, 2); 

    int n = 1000; 



    for (int u = 0; u <=n; u++){
            if (bVisited[u] == false)
                Topo_Sort(u);
    }

    for(int u  = 0; u <=n; u++){
        cout<<iOrder[u]<<" "; //? tại sao lại có thứ tự duyệt như thế này?. 
    }
}