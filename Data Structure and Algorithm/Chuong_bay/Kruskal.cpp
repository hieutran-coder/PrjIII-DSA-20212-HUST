// #include<iostream>

// #define MAX 100001

// using namespace std;

// // Cấu trúc dữ liệu cho đồ thị input vào?.

// int N, M;
// int u[MAX];
// int v[MAX];
// int c[MAX]; // c chắc là trọng số???. 
// int ET[MAX];
// int nET; 
// // cấu trúc dữ liệu cho các tập không joint vào nhau? 

// int r[MAX]; // r[v] là hạng của tập v??. của nút v chứ nhỉ?. 
// int p[MAX]; // p[v] là cha của nút v

// long long rs;// Tại sao phải là long long

// void unify(int x, int y) { // Chả biết hàm unify ứng dụng vào thuật toán Kruskal như thế noà?. 
//     if(r[x]>r[y]) p[y] = x;
//     else{
//         p[x] = y; //y là cha của nút x?.
//         if(r[x] == r[y]) r[y] = r[y]+1; // rank của nút y tăng thêm 1?. 
//     }
// }
// //
// void makeSet(int x) {
//     p[x] = x; // Cha của x là x 
//     r[x] = 0;// Hạng của x là 0
// }

// // Lại dùng đệ quy??. 
// int findSet(int x) { // Tìm nút gốc?. 
//     if( x!=p[x]) // Nếu x khác cha của nó?. 
//         p[x] = findSet(p[x]); // Bài toán con?. 
//     return p[x]; // Trường hợp cơ sở là x = p[x] hay là gọi đến findSet của gốc?.
// }
// // 3 hàm này thầy xây dựng có vẻ đơn giản, ko biết trên mạng thế nào?. 



// void swap(int& a, int& b){ // sử dụng tham chiếu để swap 2 biến?. 
//     int tmp = a; a = b; b = tmp; 
// }

// // swap 2 cạnh?. gọi đến hàm swap 3 lần?. swap giữa các đỉnh giữa các cạnh?. 
// void swapEdge(int i, int j) { // hàm swap này dùng để làm gì?. 
//     swap(c[i],c[j]); 
//     swap(u[i],u[j]);
//     swap(v[i],v[j]);
//         // Thay đổi con trỏ i ko trỏ đến cạnh i nữa mà trỏ đến cạnh j và ngược lại phải ko?. 
//     // Có thể vẽ lại graph sau khi swap ko?. 
// }


// // Tái sử dụng code của quicksort? Nhưng thầy định ứng dụng quick Sort vào trong thuật toán Kruskal như thế nào?.

// // đối tượng là dãy các cạnh, khoá là trọng số.
// int partition(int L, int R, int index) {
//     int pivot = c[index];  //  wow định sắp xếp lại các trọng số
//     swapEdge(index, R);
    
//     int storeIndex = L;// first pointer
//     // second pointer
//     for(int i = L; i <= R-1; i++) {
//         if(c[i]<pivot) {
//             swapEdge(storeIndex, i); 
//             storeIndex++; 
//         }
//     }
//     swapEdge(storeIndex, R);
//     return storeIndex; 
// }

// void quickSort(int L, int R) {
//     if(L < R) {
//         int index = (L+R)/2;
//         index = partition(L, R, index);
//         if(L < index) quickSort(L, index - 1);
//         if(index < R) quickSort(index+1, R);
//     }
// }

// void quickSort() {
//     quickSort(0, M-1);// sắp xếp m cạnh?. 
// }

// void solve() {
//     for(int x = 1; x <= N; x++) makeSet(x); //  Tạo tập của x ??. Vậy lúc đầu các đỉnh đều đơn độc, và từ từ sẽ hợp lại?.
    
//     quickSort();
//     rs = 0; // rs là gì?.
//     int count = 0;
//     nET = 0; 

// // Ta sẽ bắt đầu duyệt 2 đỉnh của các cạnh từ cảnh nhỏ đến cạnh lớp?. 
//     for(int i = 0; i< M; i++) {
//         int ru = findSet(u[i]); // Tìm định danh của đỉnh thứ nhất?.
//         int rv = findSet(v[i]);// Tìm định danh của đầu mút thứ 2?. 
    
//     // NÊu ru = rv thì sao?. 
//         if( ru != rv) { // Định danh của 2 đầu mút khác nhau?.
//             unify(ru, rv); // Hợp ru và rv lại tại sao cần phải hợp lại?. 
//             // Tại sao hợp lại lại làm số lượng các canh tăng thêm 1?. Đây là 2 thành phần liên thông thì số cạnh phải tăng lên rất nhiều chứ??
           
//             // --> Ta sẽ thêm 2 cạnh nôi 2 thành phàn liên thông khác nhau?.
//             //--> Vậy tại sao thêm cạnh của 1 thành phần liên thông lại tạo nên chu trình?. 


//             nET++; // Chức năng của biến nET là gì?. 
//             ET[nET] = i;   //nET là gì??>.  đến 1 lúc nào đo nET khong tăng nhưng i lại tăng?. nếu ru = rv
//                 // Bổ sung cạnh i vào thành phần liên thông?. 
//             rs += c[i];// đã được sắp xếp?. rs chắc tổng trọng số nhỏ nhất/. 

//             count++; // Tại sao đã có biến nET mà lại dùng biến cao?.
//             if(count == N-1) break; // Nếu số lượng các cạnh bằng số lượng các đỉnh -1?. Cây khung?. 
//         }
//     }
//     cout << rs; 
// }

// void input(){
//     cin >> N >> M;

//     for(int i = 0; i < M; i++) {
//         cin >> u[i] >> v[i] >> c[i]; 
//     }
// }

// int main() {
//     input();
//     solve(); 
// }

//--------- Cách của cô?.
#include<iostream>
using namespace std;
#include<utility>
#include<vector>

#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;  // Vãi cô dùng cấu trúc Pair, còn thầy Trung thì cái gì cũng simple cả

// Biểu diễn các tập ko joint với nhau( Trong từng thời điểm xây dựng cây khung)

struct DisjointSets
{
    int *parent, *num;
    int n;

    DisjointSets(int n) 
    {
        this->n = n;
        parent = new int[n+1]; // Cấp phát bộ nhớ cho con trỏ parent;
        num = new int[n+1];// Cấp phát bộ nhớ cho con trỏ num; Con trỏ này có chức năng gì?.
        // Khởi tạo tập makeSet?. 
        for (int i  = 0; i<=n; i++){
            num[i] = 1; // num i có phải giống rank của đỉnh i bên code thầy Trung ko?. Ko, nó là số lượng node
            // Tất cả phần tử là cha của chính nó?.
            parent[i] = i; 
        }
    }

    int Find(int u)
{
    while(u != parent[u]) u = parent[u];  /// Ta sẽ đệ quy thôi đến khi nào gốc thì return vè
    return u;   
}

    void Union(int x, int y)
    {
        int u = Find(x), v = Find(y);
        // Joint less node tree to other node tree

        if(num[u] > num[v]) 
        {
            parent[v] = u; num[u] += num[v];
          }else {
              parent[u] = v; num[v] += num[u]; 
          }
    }
};


class Graph
{
    int V, E;
    vector< pair<int, iPair >  > edges; 

public:
    Graph(int V, int E); // hàm khởi tạo
    void addEdge(int u, int v, int weight) ; // thêm cạnh (u, v)
    int kruskalMST_DisjointSet(); // MST là gì?. 
};

// Đinh nghĩa các phương thức

// Phương thức khởi tạo 
Graph::Graph(int V, int E){
    this->V = V;
    this->E = E; 
}

// Định nghĩa phương thức thêm edge
void Graph:: addEdge(int u, int v, int weight)
{
    // 
    edges.push_back({weight,{u, v}}); // Cách cô tạo graph khác vl.
}

int Graph::kruskalMST_DisjointSet(){
    int mst_wt = 0; // save length

    // sort edges
    sort(edges.begin(), edges.end()); // Simple


    // Tạo đối tượng các tập disjoint
    DisjointSets ds(V); 


    // Travesal sorted Edges
    vector< pair<int, iPair> > ::iterator it;

    for(it = edges.begin(); it!=edges.end(); it++){

        int u = it->second.first; // ddaya la cac truong cua pair?. DDinh thu nhat
        int v = it->second.second; // Dinh thu 2

        int set_u = ds.Find(u);
        int set_v = ds.Find(v); 

        // Test u, v in same connected component?
        


        if(set_u != set_v)
        {
            cout <<"("<<u <<", "<< v <<"), "; // Add edge (u, v) to MST
            mst_wt += it->first; // Tang weight xay dung?. 
            ds.Union(set_u, set_v); 
        }




    }

    return mst_wt;

}


int main() {
    int V = 9, E = 14;

    Graph g(V, E);

    g.addEdge(0, 1, 4);    g.addEdge(1, 2, 8);    g.addEdge(2, 3, 7);    g.addEdge(2, 5, 4);


cout <<" Setting Kruskal algorithm using DISJOINT SET \n";

cout <<"- Min kruskal have: ";

int mst_wt = g.kruskalMST_DisjointSet();
cout <<" Độ dài cây khung nhỏ nhất là " << mst_wt; 

return 0; 
}