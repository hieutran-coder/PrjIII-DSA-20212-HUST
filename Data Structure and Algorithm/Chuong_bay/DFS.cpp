// #include<stdio.h>
// #include<stdlib.h>

// struct node {
//     int vertex;
//     struct node* next;
// };

// struct node* createNode(int v); // Tạo ra 1 node


// struct Graph {
//     int numVertices;
//     int * visited; // store những thằng trên graph đã duyệt?.

//     // chúng ta cần int ** để lưu trữ mảng 2 chiều.
//     // Tương tự, chúng ta cần struct node** để lưu trữ 1 dãy các linked lists.
//     struct node** adjLists;
// };


// // Thuật toán DFS

// void DFS(struct Graph* graph, int vertex) {// khi nào cũng thế, với 1 struct người ta truyền vào con trỏ trỏ đến nó thôi hè?.
//     struct node* adjList = graph->adjLists[vertex]; // adjList là 1 con trỏ trỏ đến 1 linker list của đính vertex
//     struct node* temp = adjList;


//     graph->visited[vertex] = 1; // Đã duỵet

//     printf("visited %d \n", vertex); //  ouput ra đỉnh đã duyệt

//     while(temp != NULL) { // temp khác nul có nghĩa là trong list đó vẫn còn có thằng để duyệt?. 
//         int connectedVertex = temp->vertex; // trỏ đến đỉnh của node tương ứng?. 

//         if (graph->visited[connectedVertex] == 0){ // Xem connectedVertext đã duyệt chưa?. 
//             DFS(graph, connectedVertex);  // Đệ quy// hay là duyệt sâu vào connectedVertext??.
//         }
//         temp = temp->next; 
    
//     }
// }

// // Tạo ra 1 node
// struct node* createNode(int v) {

//     // Cấp phảt bộ nhớ cho node đó
//     struct node* newNode = (struct node*)malloc(sizeof(struct node)); // Cấp phát 1 node thôi

//     // KHởi tạo các giá trị cho newNode?.
//     newNode->vertex = v;
//     newNode->next = NULL;
   
//     return newNode; 
// }


// // Tạo đồ thị
// struct Graph* createGraph(int vertices) {
//   struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

//     // Khởi tại các trường của đồ thị graph
//     graph->numVertices = vertices;

//     graph->adjLists = (struct node**)malloc(vertices*sizeof(struct node*)); //cấp phát số lương con tro bang so dinh

//     graph->visited = (int*)malloc(vertices*sizeof(int)); 

//     int i;

//     // Khởi tạo các phần tử của đồ thị?.
//     for(i = 0; i < vertices; i++){
//         graph->adjLists[i] = NULL;
//         graph->visited[i] = 0; 
//     }
//     return graph; 
// }

// // Thêm cạnh
// void addEdge(struct Graph* graph, int src, int dest) {
//     // thêm cạnh từ src đến dest
//     struct node* newNode = createNode(dest);

//     newNode->next = graph->adjLists[src];
//     graph->adjLists[src] = newNode; 

//     newNode = createNode(src);
//     newNode->next = graph->adjLists[dest];
//     graph->adjLists[dest] = newNode; 
// }


// // Output ra đồ thị

// void printGraph(struct Graph* graph) {
//     int v;

//     for( v= 0; v < graph->numVertices; v++) {
//         struct node* temp = graph->adjLists[v]; 
        
//         printf("\n Danh sách kề của đỉnh %d \n", v);
//         while(temp) {
//             printf("%d ->", temp->vertex);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
// }

// int main() {
//   struct Graph* graph = createGraph(4);
//   addEdge(graph, 0, 1);
//   addEdge(graph, 0, 2);
//   addEdge(graph, 1, 2);
//   addEdge(graph, 2, 3);

//   printGraph(graph);

//   DFS(graph, 2);

//   return 0;
// }

#include<iostream>
#include<list>

using namespace std;

class Graph{
    int numVertices; // Số lươgnj đỉnh
    
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};

// Khởi tạo đồ thị
Graph:: Graph(int vertices) {
    numVertices = vertices;

    adjLists = new list<int>[vertices]; // Khởi tạo các danh sách kề cho con trỏ?. 
    visited = new bool[vertices]; // khởi tạo tập các biến true false?.
}


// Thêm cạnh
void Graph::addEdge(int src, int dest){
    adjLists[src].push_front(dest); // Chỉ 1 chiều thôi à?. Chắc cũng đủ duyệt rồi
}


// DFS algorithm
void Graph::DFS(int vertex){
    
    visited[vertex] = true;
    list<int> adjList = adjLists[vertex];

    cout << vertex<< " ";

    list<int>::iterator i;

    for(i = adjList.begin(); i!= adjList.end(); ++i)
        if(!visited[*i]) DFS(*i); // Nếu chưa visit thì sẽ visit nó?. 


}

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.DFS(2);
    return 0; 
}