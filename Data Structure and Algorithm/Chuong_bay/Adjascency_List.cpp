// #include <stdio.h>
// #include <stdlib.h>

// // Không biết nếu lưu Graph bằng C thf vất vã thế nào?. 

// // Node chứa đỉnh và trỏ đến node khác
// struct node {
//     int vertex;
//     struct node* next; 
// };

// struct node* createNode(int); // hàm nguyên mẫu?.

// struct Graph {
//     int numVertices;
//     struct node** adjList; // con trỏ kép 
// };

// // Tạo ra 1 node
// struct node* createNode(int v) {
//     // cấp phát bộ nhớ, toán tử sizeof
//     struct node* newNode = (struct node*)malloc(sizeof(struct node)); // vừa cấp phá bộ nhớ và éo kiểu?.
  
//     // Khởi tạo giá trị cho node đã được cấp phát?. 
//         newNode->vertex = v;
//         newNode->next = NULL;
//     return newNode;
// }

// // Tạo ra đồ thị
// struct Graph* createAGraph(int vertices) {
//     struct Graph* graph = (struct Graph*)malloc(sizeof( struct Graph)); // Cấp phát bộ nhớ cho con trỏ graph

//     // khởi tạo các trường cho con trỏ graph
//     graph->numVertices = vertices;
//     graph->adjList = (struct node**) malloc(vertices*sizeof(struct node*)); // khởi tạo 1 mảng các con trỏ là adjList?. 

//     int i;
// // KHởi tạo giá trị ban đầu cho các tất cả các con trỏ?.
//     for (i = 0; i < vertices; i++)
//         graph->adjList[i] = NULL;

//     return graph; 
// }

// // Thêm cạnh
// void addEdge(struct Graph* graph, int s, int d) {
//     // Thêm cạnh từ s tới d
//     // Tạo ra 1 node mới?. 

//     // Thêm node d vào danh sách kề s
//     struct node* newNode = createNode(d);

//     // Việc này giống như chèn vào đầu linker list mà thôi, vẽ nó ra thì sẽ dễ hiểu?.
//     newNode->next = graph->adjList[s]; 
//     graph->adjList[s] = newNode; 

//     // Thêm node s vào danh sách kề d
//     newNode = createNode(s);
//     newNode->next = graph->adjList[s];
//     graph->adjList[d] = newNode; 
// }

// // Khong có xóa 1 cạnh nhỉ?. Chắc là cũng tương tự việc delete 2 node trong cả 2 linker list
// //--> Hóa ra có thể áp dụng việc xóa thêm trong linker list vào graph được???. 

// // Output hay hiển thị Graph
// void printGraph(struct Graph* graph){
//     int v;
//     for (v = 0; v< graph->numVertices; v++) { // Duyệt hết tất cả các đỉnh
//         struct node* temp = graph->adjList[v];


//         printf("\n Vertex %d\n", v);
//         // duyệt hết tất cả phần tử của linker list temp. --> HÓa ra duyệt các phần tử trong linker list cũng áp dùng vào duyệt graph?. 
//         while(temp) {  // Thầy Trung thì là while Temp khác NULL?.
//             printf("%d -> ", temp->vertex);
//             temp = temp->next; 
//         }
//         printf("\n");
//     }
// }

// int main() {
//     struct Graph* graph = createAGraph(4); // tạo ra 4 đỉnh

//     addEdge(graph, 0 , 1);
//     addEdge(graph, 0, 2);
//     addEdge(graph, 0, 3);
//     addEdge(graph, 0, 4);

//     printGraph(graph);

//     return 0; 
// }

#include<iostream>

using namespace std;
#include<vector>
#include<list>


// Them edge
// Vãi code sử dụng thư viện thì đơn giản thật.
void addEdge(vector<int> adj[], int s, int d){ // Một danh sách các vector
    adj[s].push_back(d);
    adj[d].push_back(s); // Thêm s và thêm d và vector tương ung vs d và vector tương ứng vơis
}

// Output ra graph?.
void printGraph(vector<int> adj[], int V) {
  
    for (int d = 0; d< V; ++d){
        cout<<" \n đỉnh" << d<< ":";
    for (auto int x: adj[d]) // duyệt tất cả các phân tu trong vector cua d
        cout <<"->" << x; // 
    printf("\n"); 
    }
}

int main() {
    int V = 5;

    // Tạo ra 1 graph
    vector<int> adj[V];

    // THêm edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2); 
    printGraph(adj, V); 

}



