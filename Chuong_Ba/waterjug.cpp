#include<iostream>
using namespace std;

#include<queue>
#include<utility>
int const N = 1010;
int a, b, c,n;
bool mark[N][N];
int val[N][N];
queue< pair<int, int> > q;

void check(int x, int y, int u, int v) {

    if (mark[u][v] == true){
        mark[u][v] = false;
        val[u][v] = val[u][v] + 1;
        q.push(make_pair(u, v));
    }


}


int main() {
    cin >> a >> b >> c;
    int res = -1;
    memset(mark, true, sizeof(mark));
    memset(val, 0, sizeof(val));

// Cấu trúc code tương tự cấu trúc BFS, nhưng không có cạnh
    mark[0][0] = false;
    val[0][0] = 0;
    q.push(make_pair(0,0));

    while(!q.empty()) {  // Kiểm tra xem q có rỗng hay không. 
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
    
        if (x==c||y==c){
            res = val[x][y];
            break; 
        }

    //////////////////////////
        // // fill A
        // if (mark[a][y]){
        //     mark[a][y] = false;
        //     val[a][y] = val[x][y] + 1;
        //     q.push(make_pair(a,y));
        // }



        // //Fill B
        // if (mark[x][b]){  // biểu thức điều kiện nếu đỉnh (x,b) chưa được duyệt
        //     mark[x][b] = false;
        //     val[x][b] = val[x][y] + 1; // cập nhật giá trị cho bộ x, b, hay đường đi của nó.
        //     q.push(make_pair(x,b));  // 2 bước: khởi tạo pair(x,b) và đẩy nó vào hàng đợi.
        // }
        // // A-->B
        // // 2 th: nó đổ đầy b vẫn thừa nước
        // // trường hợp 2 là thiếu nước để đổ đầy b--> Vậy có thể ghép 2 trường hợp này trong 1 đk không?, giảm thứ cần code.
            //--> Min(x, b-y). Ko cần if.  
        // if (x>b-y)
        //     if (mark[x-(b-y)][b]){
        //         mark[x-b+y][b] = false;
        //         val[x-b+y][b] = val[x][y] + 1;
        //         q.push(make_pair(x-b+y, b));
        //     }
        //     else
        //     if (mark[0][y+x]){
        //         mark[0][y+x] = false; // đánh dấu là nó đã đi qua rồi. 
        //         val[0][y] = val[x][y] + 1; // tại vì x,y là đỉnh trước đó.
        //         q.push(make_pair(0, y+x));
        //     }



        // // B-->A
        //    if (y>a-x)
        //     if (mark[a][y-a+x]){
        //         mark[a][y-a+x] = false;
        //         val[a][y-a+x] = val[x][y] + 1;
        //         q.push(make_pair(a, y-a+x));
        //     }
        //     else
        //     if (mark[y+x][0]){
        //         mark[y+x][0] = false; // đánh dấu là nó đã đi qua rồi. 
        //         val[y+x][0] = val[x][y] + 1; // tại vì x,y là đỉnh trước đó.
        //         q.push(make_pair(y+x, 0));
        //     }


        // // Empty A
        //     if (mark[0][y]){
        //         mark[0][y] = false;
        //         val[0][y] = val[x][y] + 1;
        //         q.push(make_pair(0, y));
        //     }


        // // Empty B
        //     if (mark[x][0]){
        //         mark[x][0] = false;
        //         val[x][0] = val[x][y] + 1;
        //         q.push(make_pair(x,0));
        //     }

////////////////////////////////
    
    // fill a
    check(x,y, a, y);
    // fill b
    check(x, y, x, b);
    
    //A->B
     n = min(x, b-y);
    check(x, y, x-n, y+n);

    //B->A
    n = min(a-x, y);
    check(x, y, x+n, y-n);

    // empty A
    check(x, y, 0, y);
    // empty b
    check(x, y, x, 0);
    }

    cout<< res<<endl;




}