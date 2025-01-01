#include<stdio.h>
#define N 1000
int n, m; // n, m là số đỉnh và số cạnh của đồ thị?. 
int A[N][N]; // A[v] là danh sách các nodex kề với V?. // Sự khác biệt là cài đặt bằng mảng 2 chiều chứ ko phải các danh sách liên kết?.
//-> Chắc N là số lươgnj đỉnh là 1000 rồi
int szA[N]; // szA[v] là kích thước của mảng A[v];


// cấu trúc dữ liệu cho những thành phần liên thông hay kết nối với nhau?.
int ncc; // số lượng connection compoent???. 
int icc[N]; //icc[u] là chỉ số của thành phần liên thông của u---> Có tối đa 1000 chỉ số--> có 1000 đỉnh độc lập là max. 

// Nhập dữ liệu vào?.--> Cách thiêt lập đồ thị có vẻ khác?. -> Không sử dụng cấu trúc mà dùng chắc mảng?. 
void input(){ // Xây dụng graph
    scanf("%d%d", &n, &m); // đọc giá trị đầu vào của n và m
    
    for(int v = 1; v<= n; v++) szA[v] = 0; // Ta sẽ gán size của tập cạnh kề của tất cả đỉnh là 0, szA[v] giống như con trỏ trỏ tới đuoi.

    for(int k = 1; k <= m; k++) { // Ta sẽ duyệt m cạnh của đồ thị
        int u, v; 
        scanf("%d%d",&u, &v); // Xét có những cạnh nào trong m cạnh?. 

        // Cập nhật tập cạnh kề của (u,v)--> Update data structure
        A[v][szA[v]] = u;  // Thêm cạnh (u,v) vào tập cạnh kề của v
        A[u][szA[u]] = v;// Thêm cạnh (u, v) vào tập cạnh kệ của u

        szA[v] ++; szA[u]++; 
    }
}
// Gọi dfs trong 1 thành phần liên thông?  hàm này được hàm dfsGraph gọi đến?. 
void dfs(int u){
    icc[u] = ncc; //ncc là gì?. --> Am chi da duyet roi?. Ko chỉ như thế mà còn cho biết đỉnh u thuộc thành phàn liên thông nào?. 

    for(int i = 0; i < szA[u]; i++) { // Duyệt tất cả tập đỉnh kề của u
        int v = A[u][i]; // Đỉnh kề đầu tiên với u
        if(icc[v] == -1) { // Nếu đỉnh vChưa được duyệt
            dfs(v); // 
        }
        // Nếu định v đã được duyệt rồi tức icc = ncc thì sẽ duỵet sang đỉnh kề khác?. 
    }
}

void dfsGraph() {

    for(int v = 1; v <= n; v++) icc[v] = -1; // khởi tạo chỉ số liên thông của các định là -1
    ncc = 0; // Số lượng thành phần liên thông là 0. 

    for(int v = 1; v<=n; v++) // Duyệt tất cả các đỉnh
        if(icc[v] == -1){ // Nếu chưa được duyệt, hay là chưa xác định được thành phần liên thông?. 
            ncc++;  // Đánh dấu có 1 thêm 1 thành phần liên thông mới?. 
            dfs(v); // 
        }
    // Các thành phần liên thông
    for (int k = 1; k <= ncc; k++){
        printf("connected component %d: " ,k);  //????.

        for(int v = 1; v<=n; v++) if(icc[v] == k) printf("%d",v); // NÊu thàh phần liên thông của v là k thì print?. 
        printf("\n"); 
    }
}

int  main() {
    input();
    dfsGraph(); 
    return 0; 
}