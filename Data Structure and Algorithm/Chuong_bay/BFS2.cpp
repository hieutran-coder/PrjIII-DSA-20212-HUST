#include<stdio.h>

#define N 1000

// Cấu trúc dữ liệu cho hàng đợi
// Cách định nghĩa queue của thầy ko dùng struct
int q[N]; 

int head = -1, tail = -1; // Đầu và đuôi

// Cấu trúc dữ liệu của Graph?.
int n, m; // só lượng các đỉnh và các cạnh của đồ thị
int A[N][N]; // Danh sách các đỉnh kể của mỗi đỉnh trong đồ thị
int szA[N]; // kích thước của mỗi danh sách kề. 



//Cấu trúc dũ liệu cho các thành phần liên thông của BFS. 
int ncc; // Số lượng các thành phần liên thông
int icc[N]; // icc[v] chỉ số của thành phần liên thông
int d[N]; // khoảng cách từ đính gốc đến tất cả các đỉnh?.


// Tạo  các thao tác trên hàng đợi

void initQueue(){
    head = -1; tail = -1; // Tại sao là -1 mà ko phải là số khác?.
}

void pushQ(int v) {
    tail++; q[tail] = v;  // Tăng taill lên 1, nếu tail tràn thì sao?. --> Ko quan tâm giả sử tail infinity?.

    if(head == -1) // nó sẽ chạy điều kiện này khi nào?.  Nếu thêm 1 đỉnh vào queue sau khi khởi tạo, hoặc thêm đỉnh đầu tiên vào q. 
        head = tail; 
}

int popQ(){
    // Nếu không có đỉnh nào?. 
    if (head == -1) return -1; // queue rỗng

// Nếu có đỉnh?. 
    int v = q[head]; // Chọn đỉnh bốc ra là đỉnh đầu tiên


/////////////////   
    if(head == tail) {  // Nếu trước khi bốc đỉnh ra khỏi hàng đợi thì hàng đợi còn 1 đỉnh cuối cùng.
        head = -1; tail = -1;
    } else  // Trong trường hợp có nhiều đỉnh?. 
        head++;
    return v;
}
//////////////


int empty(){  // Làm rỗng hàng đợi?. 
    return head == -1&& tail == -1; 
}


// NHập dữ liệu vào cấu trúc đồ thị
void input(){
    scanf("%d%d", &n, &m);

    for(int v = 1; v <= n; v++) szA[v] = 0;

    for (int k = 1; k <= m; k++){
        int u, v;
        scanf("%d%d", &u, &v); // Nhập dữ liệu 2 đầu mút của cạnh vào?.

        A[u][szA[u]] = v; A[v][szA[v]] =u;
        szA[u]++; szA[v]++; 
    }
}

// thuật toán bfs

void bfs(int u) {
    initQueue();

    icc[u] = ncc; // chỉ số thành phần đỉnh u bằng ncc lấy từ hàm bfsgraph gọi nó?. 

    pushQ(u);// đẩy u vào đuôi của hàng đợi.
    d[u] = 0;

// Ta đổi màu đỉnh trước khi thêm vào queue?. và tất cả các đỉnh trước khi thêm vào stack đã được tính thông số khoảng cách?.
//--> Vậy sau khi lấy ra khỏi queue đã có thông số khoảng cách?. 
// ==> Ta lấy ra chỉ để tìm các đỉnh kề?. 
    while(!empty()) {   // Trong trường hợp hàng đợi khác rỗng
        int v = popQ(); // Lấy v ra từ hàng đợi 
        
        for(int i = 0; i<szA[v]; i++) {// duyệt các đỉnh kể với v
            int x = A[v][i]; // xét 1 đỉnh kề là x
            if(d[x] == -1){ // dx xem ta đã duyệt chưa( ngoài ra còn mục đích khác là tính khoảng cách đến gốc)
                d[x] = d[v] + 1; // Chứng tỏ chắc chắn d[v] phải được duyệt rồi?. 
                pushQ(x);
                icc[x] = ncc; //ncc trong trương hợp duyệt này sẽ fix. 
           }
        }
    }
}


void bfsGraph() {
    for(int v = 1; v <= n; v++) d[v] = -1;
    ncc = 0; //ncc lúc đầu bằng 0?.

    for(int v = 1; v <= n; v++) 
        if (d[v] == -1) { // Có thêm 1 connected component mới?.
            ncc++; 
            bfs(v);
        }

    for(int k = 1; k <= ncc; k++) {
        printf("Connected component %d: ",k);  //Thành phần liên thông
        for(int v = 1; v <= n; v++) if(icc[v] == k) printf("%d", v); // duyệt các đỉnh của 1 connected component?. 
        printf("\n");
    }
}

int main() {
    input();
    bfsGraph(); 
}