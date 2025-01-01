#include<iostream>
#include<vector> 
using namespace std; 

// Thầy dùng cấu trúc struct ko phải class?. 
struct edge {
    int u, v; 
    int weight;

    // Khởi tạo giá trị
    edge(int _u, int _v, int _w){
        u = _u;
        v = _v;
        weight = _w; 
    }
};





struct Union_Find{
    vector<int> iParent;

    // Phương thức khởi toạ
    Union_Find(int n) {
        iParent = vector<int>(n);  // iParent gồm n thành phần

    // Duyệt từ 0 đến n-1:  Đang có n tập
        for(int i = 0; i < n; ++i){
            iParent[i] = i;  // Cha của nó là chíh nó?. 
        } 
    }
};

int Find(int x) {
    if (iParent[x] == x) return;
    else {
            iParent[x] = Find(iParent[x]);
            return iParent[x]; 
    }
}

void Unite(int x, int y) {

    // Đưa cây con của đại diện x vào ghép với cây của y. 
    iParent[Find(x)] = Find(y);
}



vector<edge> Adj[5];

int main() {

    Adj[1].push_back(edge(1,2, 9)); // Đặt edge vào đỉnh kề của 1
    Adj[1].push_back(edge(1,3,-7)); // chú ý thứ tự argument khởi taọ cạnh. 

    Adj[2].push_back(edge(2,1,9));
    Adj[2].push_back(edge(2,3,0));

    Adj[3].push_back(edge(3,4,5.1));
   
    Adj[4].push_back(edge(4,3,5.1));




}