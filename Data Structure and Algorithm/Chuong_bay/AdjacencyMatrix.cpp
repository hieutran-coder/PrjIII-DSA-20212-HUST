// #include<stdio.h>

// #define V 4

// // Khởi tạo bảng là 0
// void init(int arr[][V]) { // tại sao 1 tham số cố định V, 1 tham số lại trống
//     int i, j;
//     for( i = 0; i < V; i++)
//         for (j = 0; j < V; j++)
//             arr[i][j] = 0;
// }

// // Thêm các cạnh// xử lý dữ liệu 
// void addEdge(int arr[][V], int i, int j) {
//     arr[i][j] = 1;
//     arr[j][i] = 1;
// }

// //Hiển thị matrix, output
// void printAdjMatrix(int arr[][V]) {
//     int i, j;

//     for(i = 0; i < V; i++){
//         printf("%d", i);
//         for (j = 0; j< V; j++){
//             printf("%d", arr[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     int adjMatrix[V][V];

//     int(adjMatrix);

//     addEdge(adjMatrix, 0, 1);
//     addEdge(adjMatrix, 0, 2);

//     printAdjMatrix(adjMatrix);

//     return 0; 
// }

// Dùng C++ thì phải biết về Hướng đối tượng
#include<iostream>
using namespace std; 

class Graph{
    private:
    bool** adjMatrix; // Con tro 2 sao
    int numVertices; // Số lươgnj đỉnh

    public:
    // khởi tạo matrix zero
    Graph(int numVertices) {
        this->numVertices = numVertices; // khởi tạo giá trị 
        adjMatrix = new bool*[numVertices]; // adjMatrix là mảng các con trỏ true false?. Và có V con trỏ như thế ?. 

        for (int i = 0; i < numVertices; i++){ 
            adjMatrix[i] = new bool[numVertices]; // Con trỏ thứ i thì sẽ trỏ đến 1 mảng gồm V đỉnh, con trỏ này dùng toán tử truy cập
            // Nó ko cố định và có thể trỏ đến cái khác?. 
            // khởi tạo giá trị mảng đối tượng contro đến bằng false
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = false;  
        }
    }

    // Thêm các cạnh, tương tư bên C
    void addEdge(int i, int j){
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = false; 
    }

    // Output the matrix
     void toString() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
      }

    // HỦy graph
    ~Graph() {
    for (int i = 0; i < numVertices; i ++)
        delete[] adjMatrix[i];
    delete[] adjMatrix; 

};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);

    g.tostring(); 
}