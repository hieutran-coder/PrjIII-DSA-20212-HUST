#include<iostream>

using namespace std;
#include<vector>

// Danh sách cạnh kề
vector<int> Adj[1001];

//Đỉnh nào thuộc component nào hay sao?.
vector<int> iComponent(1001, -1); // Cảm giác khả giống bộ nhớ trong bài quy hoạch động. 


// Biến cur_comp là gì?. Là chỉ số cômpoent?.  Có phải là bắt đầu từ đỉnh u rồi mới tìm các compoent hay ko?. KO?. 
void Find_Component(int cur_comp, int u) {

    if (iComponent[u] != -1) return; // Đây ko phải basecase chỉ đơn giả trước khi bắt đầu duyệt, ta kiểm tra
    // nó đã thuộc thành phần liên thông nào hay đã duyệ trước đó hay chưa?.--> Nếu chưa thì bắt đầu explore nó. 

    iComponent[u] = cur_comp;


    //duyệt qua tập cạnh kề của u. Theo nguyên tắc DFS. 
    for(int i = 0; i < Adj[u].size(); ++i) {
            int v = Adj[u][i]; //là đỉnh kề của u
            Find_Component(cur_comp, v); // Tất cả đỉnh liên thông với u đểu là cur_comp hết?. 
    }
}
// Khởi tạo code programiz fit với code thầy
// Khởi tạo bằng cách thêm 1 cạnh vào ?

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d); // Thêm d vào tập cạnh kề s;
    adj[d].push_back(s); // Thêm s vào tập cạnh kề d;
}


// HIển thị
void printGraph(vector<int> adj[], int V) {
    
    // duyệt V đỉnh
    for(int d = 0; d < V; ++d) {
        cout <<" \n Vertex" << d << " : ";
        
        for (int x = 0; x<adj[d].size(); x++){
            cout << "-> " << adj[d][x];
            printf("\n"); 
        }
    }
}


int main() {

// Làm sao khởi tạo giá trị cho cấu trúc tập các cạnh kề?. 
    addEdge(Adj, 0,1);
    addEdge(Adj, 0, 2);
    addEdge(Adj, 0, 3); 
    addEdge(Adj, 1, 2); 


int n = 10; 
int num_comp = 0; // Số lượng component là không?.



for (int u = 1; u <= n; ++u){
   
    // Với những đỉnh mà chưa xác đỉnh được thành phần liên thông?.
    if (iComponent[u] == -1){
        Find_Component(num_comp, u);
        num_comp++; 
    }  
}





}