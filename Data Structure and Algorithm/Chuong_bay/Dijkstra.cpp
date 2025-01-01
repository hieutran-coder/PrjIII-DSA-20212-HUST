#include<stdio.h>
#include<vector>

#define MAX 100001
#define INF 1000000

using namespace std;

// Thầy dùng cấu trúc vector chứ ko dùng nhu kruskal nữa?.
vector<int> A[MAX]; // A[v][i]// là node kề thứ i với v.// Mỗi node sẽ có 1 vector riêng

vector<int> c[MAX]; // c[v][i] là trọng lượng của khoảng cách từ v đến i 


int n, m; // số lượng nodes và arcs của một graph đã cho

int s, t; // node nguồn và node gốc?.

// Cấu trúc hàng đợi có ưu tiên( Sử dụng heap nhị phân)
int d[MAX]; // d là cận trên của khoảng cách ngắn nhất từ s tới v?. 
int node[MAX]; // node[i] là phần tử thứ i của HEAP?. 
int idx[MAX]; // idx[v] là chỉ số của đỉnh v trên heap. // idx[node[i]] = 1

int sH; // size của heap

bool fixed[MAX];;

// Tai sao lai can phai swap?--> Chac de doi node dau va node cuoi?. 
void swap(int i, int j) {
    int tmp = node[i]; node[i] = node[j]; node[j] = tmp; 

    idx[node[i]] = i; idx[node[j]] = j; // Trao lai chi so?.
}


// down heap de lam gi?.--> Chắc dùng cho việc delete??. 
void downHeap(int i){

    int L = 2*i + 1; // NOde con trai
    int R = 2*i + 2; // Node con phai? 
    int maxIdx = i;

    if(L < sH && d[node[L]] < d[node[maxIdx]]) maxIdx = L; // Neu con trai ma be hon cha thi gan maxIdex = L=--> De lam gi?. Chac chon thang be nhat trong 2 thag
    if(R < sH && d[node[R]] < d[node[maxIdx]])maxIdx = R; // Nếu con phải có khoá bé nhất?. hay khoảng cách ntừ nguồng đến con phỉa là bé nhất?
        // Cach cai cung tuong tu max heap?.
    if( maxIdx!= i){
        swap(i, maxIdx); downHeap(maxIdx); // Tiep tuc day maxidx xuong?. Toi thoi gian la h?. 
        // De quy dung khi maxIdx = i; hay cha be thua 2 con
    }
}

void upHeap(int i) {
    if (i == 0) return;
    while( i> 0){
        int pi = (i-1)/2;   // Là cha phải ko?. 
        if(d[node[i]] < d[node[pi]]){ // Nếu con bé thua cha?.
            swap(i, pi); // ta tráo con với cha?> 
        }else{
            break; // ra khỏi vòng while?. 
        }
        i = pi; // đệ quy lên vị trí mới của con?. và tiếp tục?. 
    }
}
// Cách giải của thầy không dùng đến struct?. 
void insert(int v, int k){
    // thêm phần tử key = k; giá trị v vào heap?
    d[v] = k;
    node[sH] = v; // vị trí cuối cùng bằng v; nếu ta lại tiếp tục chèn thêm 1 phàn tử nữa thì SH tăng lên công 1??.
    idx[node[sH]] = sH; 
    upHeap(sH); // hoá ra upHeap là dùng cho việc insert?.
    sH++; 
}

int inHeap(int v) {
    return idx[v] >= 0; // trả về chỉ số của đỉnh v trong heap?. 
    // Nếu đỉnh v không ở trong heap thì trả về số 0?. 
}


void updateKey(int v, int k) { // update khoảng cách?.
    if( d[v] > k) { // nếu khoảng cahcs nhỏ hơn
        d[v] = k; 
        upHeap(idx[v]); // Ta sẽ đưa đỉnh v lên trê
    } else {
        d[v] = k;
        downHeap(idx[v]); // Ngược lại sẽ đưa đỉnh v xuống dưới. 
    }
}

// Ồ, thầy ko code bài chương 5 heap chắc để cho chương 7?. 
int deleteMin() { // Xoá node đầu tiên?.
    int sel_node = node[0];

    swap(0, sH-1); // Đổi node đầu tiên cho node cuôi kip

    sH--; // Giảm kích thước--> Tức loại bỏ phần tử 
    downHeap(0); // downheap node mới đầu tiên?.
    return sel_node; 
}

// Nhập các dữ liệu đầu vào?> 
void input() {
    scanf("%d%d", &n, &m); // đọc số lượng nodes và arcs được nhập vào?.

    for(int k = 1; k <= m; k++) {
        int u, v, w; 
        scanf("%d%d%d", &u, &v, &w); // Đọc các phần tử u, v, w
        A[u].push_back(v); // Không cần A[v] push back u nhỉ?. 
        c[u].push_back(w);


    }
    scanf("%d%d", &s, &t); // Nhập nguồn và đích?.
}


void init(int s) {
    sH = 0;

    for (int v = 1; v <= n; v++){
       fixed[v] = false; idx[v] = -1;  // fixed s có nghĩa là d[s] sẽ không thay đổi nữa??. 
    }

    d[s] = 0; fixed[s] = true; 


    for ( int i = 0; i < A[s].size(); i++){
        int v = A[s][i];
        insert(v, c[s][i]); // Thêm tất cả những đỉnh kề với s vào priority queue hay sao??.
    }
}

void solve() {
    init(s); //

    while( sH > 0){ /// cái gì đã làm sH giảm xuống 0--> Ko có hàm này m thấy cả?. 
        int u = deleteMin(); fixed[u] = true; // có nghĩa là sau này sẽ ko thay đổi d[u] nữa--> Ko duỵet nữa?.
            // chắc do deletemin mới làm sH giảm?. 
        for(int i = 0; i < A[u].size(); i++) { // Xét tập các đỉnh kề với u?.
            int v = A[u][i]; 
            if(fixed[v]) continue; // nếu những đỉnh kề v đã duyệt rồi thì bỏ qua

            if(!inHeap(v)){ // Có những đỉnh chưa duyệt và chưa in priority quêu?. ?. Chắc ko có những đỉnh inheap mà chưa duyệt đâu nhỉ?.
                                                                 //-> Có chứ, tập các đỉnh kề s là inheap mà đã duỵet đâu?. 
                int w = d[u] + c[u][i];//  Tập đỉnh này thậm chí còn chưa có trong số?.
                insert(v, w); // chèn đỉnh v với trọng số w vào priority queue?. 
            }else { // nếu đã inheap tức là có trong số rồi, kiểm tra trọng số mới xem bé hơn ko?.

                if(d[v] > d[u] + c[u][i]) updateKey(v, d[u] + c[u][i]); // thay đổi khoá của 1 đỉnh trên priority queue?. 

                
            }
        }
    }
    int rs = d[t]; if(!fixed[t]) rs = -1; 
    printf("%d", rs);
}

int main() {
    input(); 
    solve(); 
}
