#include<iostream>
#include<vector>
#include<stdlib.h> 

using namespace std;

vector<int> Adj[1001]; // Thầy cài đặt ko bằng các vector edge nữa?. 
vector<int> iSide(1001, -1); // Khoi tao cac gia tri cho doi tuong iSide
                // Tai sao lai -1, neu luc dau ta khoi tao la 0 thi co duoc khong?. 


bool is_bipartite = true; 

// Dinh u la dinh bat dau
void Check_Bipartite(int u){ 

    // Xe tap canh ke
    for (int i = 0; i < Adj[u].size(); ++i) {
        int v = Adj[u][i];
        
        if(iSide[v] == -1){
            iSide[v] = 1 - iSide[u]; // Thay dung dau tru, minh dinh xe 2 truong hop cua u de cho v?
                                    //--> Vay thi u co the co gia tri bao nhieu, v co the gia tri iSide bao nhieu? 2 gia tri 0, 1

            Check_Bipartite(v); //DFS rooif

    } else if(iSide[u] == iSide[v]){
        is_bipartite = false; // Ko tao duoc do thi 2 phia, tai sao o day khong break luon?. 
    }
}


}

// Add edge
void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}


int main() {

// Làm sao để cài đặt được?. 
// Làm sao để kiểm tra khi nó(đồ thị ) không thiết lập được đồ thị 2 phía?.
// Đi theo DFS: --> Đánh số 1 và Đánh số 0?. Những đỉnh đánh số rồi thì thôi, bỏ qua.
// Tại sao lại không đi theo BFS???. 

// CUối cùng duyệt qua các cạnh--> Kiểm tra xem có 2 đỉnh nào trùng 1 hoặc trùng 0?. 
    // Có thể kiểm tra luôn trong lúc duyệt để đỡ mất công không?. --> Xét những đỉnh đã duyệt rồi thì khoan hẵng bỏ qua mà phải so sánh-
     //   --> Nếu có thì break luôn, đồ thị này ko tạo được. 

// Lam sao khoi tao tap canh ke day??. Khởi tạo một loạt luôn?. 
// Add một cách random các cạnh?. 

// Thôi dùng tạm matrix khởi tạo
int n = 100; 
int m = 500; 
int edge[1001][1001];

// Khoi tao do thi canh ke
    for (int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){

            edge[i][j] = rand()%2;
            edge[j][i] = edge[i][j];
            if(edge[i][j]) addEdge(Adj,i,j);
            cout<<"Canh "<<i<<" "<<j<<" "<<edge[i][j]<<"\n";
        }
    }



// printf do thi canh ke
    for(int i = 0; i<n; i++)
        {
            cout<<i<<" ----> ";
            for (int j = 0; j <Adj[j].size(); j++)
                cout<<Adj[i][j]<<" -->";
            cout<<"\n  \n";
        }
        





    for (int u = 0; u < n; u++){
        // Xet nhung dinh nao chua duoc duyet
        if(iSide[u] == -1){  
            iSide[u] = 0; // 
            Check_Bipartite(u); 
        }
    }

    cout<<"Do thi co 2 phia khong?"<<int(is_bipartite)<<endl; 




}