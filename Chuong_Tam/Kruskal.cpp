#include<iostream>
#include<vector> 
using namespace std; 

// Thầy dùng cấu trúc struct ko phải class?. 
struct edge {
    int u, v;  // THử tự đỉnh sẽ được tính như thế nào?. 
    int weight;

    // Khởi tạo giá trị
    edge(int _u, int _v, int _w){
        u = _u;
        v = _v;
        weight = _w; 
    }
};

// Chỉ là danh sách cạnh?> 
vector<edge> e;

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

    int Find(int x) {
    if (iParent[x] == x) return x;
    else {
            iParent[x] = Find(iParent[x]);
            return iParent[x]; 
    }
}

    void Unite(int x, int y) {

    // Đưa cây con của đại diện x vào ghép với cây của y. 
    iParent[Find(x)] = Find(y);
}

};

// int Find(int x) {
//     if (iParent[x] == x) return;
//     else {
//             iParent[x] = Find(iParent[x]);
//             return iParent[x]; 
//     }
// }



//Thú nhất ta ko modify dữ liệu nên ta sẽ chuyền tham chiếu để đỡ tốn bộ nhớ.
// THứ hai mục đích của hàm này để so sánh trọng số các cạnh ? Vàm tìm ra
bool Edge_Cmp(const edge &a, const edge &b) {
    return a.weight < b.weight; 
}



// Minumum spanning tree
vector<edge> MST(int n, vector<edge> edges) {

    Union_Find UF(n); // Tạo ra bộ gồm n phần tử

    sort(edges.begin(), edges.end(), Edge_Cmp); // Edge_Cmp là cách so sánh?. cái này lớn hơn cái kia khi nào?. 
    // --> sẽ sắp xếp lại các cạnh


    vector<edge> res; // 

    for (int i = 0; i < edges.size(); ++i) {
        // xét những cặp nối với nhau?. 
            int u = edges[i].u;
            int v = edges[i].v;
        
        // Xét trường hpwj 2 thằng này ko thuộc cùng 1 tập set.--> Thuộc 2 set rời nhau?. 
        // Nếu ko set thì có xét nhầm 2 dỉnh thuộc cùng 1 set:--> Trước đó đã được nối với nhau bởi 1 dường khác ko bao gồm cạnh đnag xét?.
        //--> Vào 1 thời điểm thứ i'<i đã xảy ra điều này. 
        // --> Nếu push back bằng cạnh này--> dẫn tới tạo thành chu trình khi hợp với đường đi trước đó. 
        if (UF.Find(u) != UF.Find(v)){
                    UF.Unite(u, v);
                    res.push_back(edges[i]);
        }
    }
    return res;
}







int main() {
// Làm sao khởi tạo được đồ thị có trọng số?. 
// Cái cấu trúc này thầy sử dụng khác với cấu trúc của thằng FLoyd_Warshall.cpp. Cách thức khởi tạo tương tự. 
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
            // Vấn đề đặt ra là có edge i, j có cần add edge j, i nữa không?> Hay cái vai trò như nhau nên ko cần thì phải?. 
            // Mst dùng cho đồ thị vô hướng hay có hướng?. 
            e.push_back(edge(i,j,w));
        }
    }
}

// HIển thị tập cạnh đã khởi tạo 
for(int i = 0; i<=e.size(); i++) {
            cout<< "("<<e[i].u<<","<<e[i].v <<","<<e[i].weight<<")";
            cout<<"\n";
    }

//Làm sao xử lý mảng trả về?.





 vector<edge> mst =  MST(n, e); 

cout<<"\n Tập cạnh của cây khung là : \n";

// Không liên thông--> Đồ thị vốn từ đầu đã không liên thông
                //--> Trường hợp khác là cài đặt sai. 
for (int i = 0; i< mst.size(); i++) {
            cout<< "("<<mst[i].u<<","<<mst[i].v <<","<<mst[i].weight<<")";
            cout<<"\n";
}


}