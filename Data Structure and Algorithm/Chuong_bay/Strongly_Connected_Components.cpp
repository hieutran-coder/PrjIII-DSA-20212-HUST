#include<iostream>
#include<list>
#include<stack>

using namespace std;

class Graph{
    int V;


    list<int> *adj; // Con trỏ tro đến list, vậy đay ko phải trỏ đến 1 phần tử trong list?. 
// Các method:
    void fillOrder(int s, bool visitedV[], stack<int> &stack); // truyền vào tham chiếu của stack á???.

    void DFS(int s, bool visitedV[]);  // Tìm kiếm chiều sâu giúp giải quyết vấn đề gì trong bài toán này?.

    public:
        Graph(int V);
        // Các method
        void addEdge(int s, int d);
        void printSCC();
        Graph transpose(); 

};

// Định nghĩa các method?.
Graph::Graph(int V){
    // Khởi tạo đôi tượng
    this->V = V;
    adj = new list<int>[V]; // Truyền tham số v vào list<int>// adj sẽ trỏ đến V phần tử linker list?.  Có thể vẽ ra được ko?. 
}

// DFS
void Graph::DFS(int s, bool visitedV[]){ // visitedV là bảng kiểm tra thằng nào đã đi?. 
    visitedV[s] = true;// Đây ko phải basic steps?.                  // s là gì?. 
    cout << s << " "; 
    list<int>:: iterator i;

    for(i = adj[s].begin(); i !=adj[s].end(); ++i) {// Tại mỗi vị trí s là 1 linker list hay sao?. 
        if( !visitedV[*i]) // nếu mà chưa visited, lại sử dụng visited để mark lại những cái đã visited rồi. 
            DFS(*i, visitedV); // Sử dụng recusrsion?. 
    }
    // Basic steps là trường hợp nào?. 
}

// Thêm cạnh vào đồ thị
void Graph::addEdge(int s, int d) {
    adj[s].push_back(d); // S là điểm xuất phát, d là destination?. 
}

// Transpose
Graph Graph:: transpose() { // mục đích của hàm này là gì?. 
    Graph g(V); // Tạo đối tượng graph và truyền vào tham số V?. 

    for(int s = 0; s < V; s++){  // Duyệt tất cả các s?. 
        
        list<int>:: iterator i; // tạo pointer duyệt

        for(i = adj[s].begin(); i != adj[s].end(); ++i){  // adj[s] là gì?. cũng là 1 linker list  adj nó gồm nhiều thằng linker list hay sao?. 
            g.adj[*i].push_back(s); // Đăt s vào phía sau?. 
        }

    return g; 
    }
}

void Graph:: fillOrder(int s, bool visitedV[], stack<int> &Stack){ // FillOrder là gì?. 

        visitedV[s] = true;

        list<int> :: iterator i;

        for (i = adj[s].begin(); i != adj[s].end(); i++ ) {
                if( !visitedV[*i]) // Nếu mà thẳng i trong danh sách kề của s?. mà chưa được visited
                    fillOrder(*i, visitedV, Stack); // Đệ quy?>  
        }
    Stack.push(s); // đặt s vào stack nếu được visited đến 2 lần. 
}


void Graph::printSCC() {
    stack<int> Stack;

    bool *visitedV = new bool[V];// KHởi tạo con trỏ trỏ đến mảng gồm V giá trị true/false

    for(int i = 0; i < V; i++)
        visitedV[i] = false; 

    for(int i = 0; i < V; i++)
        if(visitedV[i] == false)
            fillOrder(i, visitedV, Stack);  // Fill từng đỉnh

    Graph gr = transpose();  

    for(int i = 0; i < V; i++)
        visitedV[i] = false; // Chuyển lại false hết

    while(Stack.empty() == false) {
        int s = Stack.top();
        Stack.pop(); // pop s ra

        if( visitedV[s] == false) {
            gr.DFS(s, visitedV); 
            cout << endl; 
        }
    }
}

int main() {
    Graph g(8);
    g.addEdge(0, 1); // Thêm đỉnh 1 vào tập đỉnh kề 0
    g.addEdge(1, 2); // Thêm đỉnh số 2 vào tập đỉnh kể với 1
    g.addEdge(2,3); // Thêm đỉnh số 3 vào tập đỉnh kề với 2
    g.addEdge(2,4); // Thêm đỉnh số 4 vòa danh sách đỉnh kề với 2
    g.addEdge(3,0); // Thêm đỉnh số 0 vào danh sách đỉnh kề với 3
    g.addEdge(4, 5); // Thêm đỉnh số 5 vào danh sách đỉnh kề với 4
    g.addEdge(5,6); // Thêm đỉnh số 6 vào danh sách đỉnh kề với 5
    g.addEdge(6, 4); // Thêm đỉnh số 4 vào danh sách đỉnh kề với 6
    g.addEdge(6, 7); // thêm đỉnh số 7 vào danh sách đỉnh kề với 6

    cout << "Các bộ phận kết nối mạnh với nhau: \n";
    g.printSCC(); // hàm print gọi đến hàm transpose?. và gàn fillOrder?. 
}