#include<iostream>
using namespace std;
#include<vector>
#include<queue>

queue<int> q;
int n, m;
int const N = 100;
vector<int> a[N];
using namespace std;
bool mark[N];
int val[N]; // Dũng đặt tên đối tượng val bởi vì nói theo kiểu đánh số, mình nghĩ d là hợp lý hơn
int main() {
    // Mở file đọc và mở file để ghi. 
      freopen("bfs.inp", "r", stdin);
      freopen("bfs1.out", "w", stdout);   // Taok sap có những lúc nó không output ra được. 


    cin >>n>>m;

// m là số lượng các cạnh
    for (int i = 1; i<=m; ++i){
        int x, y;
        cin >>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

// Khởi tạo giá trị cho cấu trúc dữ liệu mark và val
    memset(mark, true, sizeof(mark)); 
    memset(val, 0, sizeof(val));


    mark[1] = false; // Tại sao Dũng lại ngược như thế?. 
    val[1] = 0;
    q.push(1);

    while(!q.empty()) {
        int x = q.front(); // lấy phần tử ở trước q, mục đích là để duyệt các định kề nó
        q.pop(); // bỏ phần tử đó ra khỏi hàng đợi
        cout <<"______"<<x<<" "<< val[x]<<endl;


        for(int i = 0; i<a[x].size(); i++){ // xét tập các đỉnh kề với x
            int y = a[x][i];
            // Trong trường hợp đỉnh chưa từng được thăm hay chưa được đánh dấu.
            if (mark[y] == true){
                    mark[y] = false;
                    val[y] = val[x] + 1;
                    cout <<"** "<< y<< " "<< mark[y] << " "<< val[y] <<endl;
                    q.push(y);
            }
        }


    }

    
    // output
    for (int i = 1; i<=n; i++){
        cout <<i <<" "<< val[i] <<endl;
    }


}