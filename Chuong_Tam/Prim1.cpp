#include<iostream>
#include<vector>
using namespace std;


// Tái sử dụng
struct edge {

    int u, v;
    int weight;

// Intializing values
edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }


};

// sn là gì?.
// Cách cài đặt 1
vector<edge> Prim(int n, vector<vector<edge> > Adj) {

    vector<bool> bIn_T(n+1, false); // Tại sao lại là n+1 mà không phải n; false tức là sao?. 
    vector<edge> res; // tập cạnh của cây khung?. 

    vector<int> iBest_W(n+1, 1e9), iBest_A(n+1, -1) ; // iBes_W và iBest_A là gì?

    iBest_W[1] = 0;  // khoảng cách từ đỉnh số 1 đến T là 0<--> Việc 1 thuộc tập T






    // Có n đỉnh thì đáng lẽ phải <n chứ nhỉ?. 
    while(res.size() < n-1) { // Nếu tập cạnh vẫn chưa đủ n-1 cạnh--> Biểu thức điều kiện này nó liên hệ nhiều lệnh dưới. 

        int u = -1, v = -1, w = 1e9; // trọng số vô hạn

        for(int x = 1;  x <= n; ++x) // Xét n đỉnh?. 
            if (bIn_T[x] == false && iBest_W[x] < w){   // Xét 1 đỉnh ko thuộc cây khung và khoảng cách từ đỉnh đó đến cây khung nhỏ hơn w. 
                u = iBest_A[x], v= x, w = iBest_W[x]; // Thì gán u cho đỉnh gần x nhất và đỉnh u này thuộc ây khung, w là khoảng cách từ x đến u
                // Nhưng mà tại sao lại gán như thế này?. --> x tăng thì lại gán lại tiếp?.????. PHí thời gian, rồi chi phí gán nữa ??. 
                    //---> Để chọn ra thằng có w nhỏ nhất hay là khoảng cách đến cây khung nhỏ nhất và x ko thuộc khung?. 
            }

        if (v == -1) return res; // Xảy ra khi nào?--> không thực hiện 1 if nào?. Có 2 khả năng?. 
                                //  --> tất cả x thuộc cây khung: --> vậy đã thêm trước đó, vô lý vì bắt đầu vào vòng lặp thì <n-1
                                // --> vi phạm cái iBest-W[x] <w--> vi phạm biểu thức này vì:
                                                // Ta đã cập nhật tất cả cạnh kề ở vòng lặp trước đó  nên ko có chuyện iBest_w vẫn vô hạn được
                                                // Mà cái iBest-W ko được cập nhật, có nghĩa nó ko nối đến một đỉnh bất kì để mà được cập nhật. 
                                                //--> Hay đồ thị ko liên thông? ở thời điểm res.size().
                                // Tại sao lệnh này thì đồ thị lại không liên thông nhỉ?. Câu trả lời bên trên?. 


        bIn_T[v] = true; // v đã thuộc cây khung?.





// Cập nhật cấu trúc dữ liệu tất cả đỉnh kề v nằm ngoài T. Tại sao cần phải cập nhật?. 
        for (edge e: Adj[v]) // xét tập đỉnh kề của v
            if (iBest_W[e.v] > e.weight){ // Nếu khoảng các từ v đến cây khung lớn hơn khoảng cách đến u( Có 2 đỉnh làm sao biết chắc e.v khong phải v)
                                            // Có lq gì đến câu lệnh for không?. 
                // Cập nhật khoảng cahcs gần nhất đến cây khung
                // Cập nhật đỉnh gần nhất trên cây khung?. 
                iBest_W[e.v] = e.weight;
                iBest_A[e.v] = e.u;       
            }


// Đưa cạnh uv vào cây khung nếu v kahcs 1. 
    if (v != 1) res.push_back(edge(u, v, w)); // Tại sao đây cần kiểm tra v ! hay bằng 1 nữa?.---> Xem lại video?. 
    // Cái này để tránh bị chu trình phải ko?. Vậy tai sao ko kiểm tra đỉnh số khác mà chỉ đỉnh 1.
        // 1 có thuộc cây khung không--> Có và là đỉnh đầu tiên.     
        // HƠn nữa nó đã kiểm tra bằng false rồi?. 
        // Có phải chỉ có đk này dkd kiểm tra chu trình không?. 
    }
    return res; 
}


vector<vector<edge> > Adj;

int main() {

    
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



//  vector<edge> mst =  Prim(n, Adj); 

// cout<<"\n Tập cạnh của cây khung là : \n";

// // Không liên thông--> Đồ thị vốn từ đầu đã không liên thông
//                 //--> Trường hợp khác là cài đặt sai. 
// for (int i = 0; i< mst.size(); i++) {
//             cout<< "("<<mst[i].u<<","<<mst[i].v <<","<<mst[i].weight<<")";
//             cout<<"\n";
// }



}