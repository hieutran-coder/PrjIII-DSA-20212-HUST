#include<iostream>
#include<vector>

using namespace std;


vector<int> Adj[1001];
vector<bool> bVisited(1001, false);
vector<bool> bMarked(1001, false);

void DFS(int u) {

    // KIểm tra xem đã khám phá hết đỉnh u chưa oke thì bỏ qua
         // bMarked ngăn chặn việc vòng lặp vô hạn phải không!!!, xác định anh đã duyệt rồi thì ko vào nữa
         
    // MỘt mình bVisited khong đủ hay sao?. Tại sao lại cần bMarked? 
    if (bMarked[u]){ 
            return
    ;}
    // Nếu chưa khám phá thì bắt đầu khám phá
    bMarked[u] = true; // nếu đổi câu lệnh này sang vị trí cuối cùng thì sao?, tại vì đáng lẽ phải explore xong thì mới có câu lệnh này chứ nhỉ
// chứ đây mới bắt dầu explore mà?.
    // đã thăm thằng này
    bVisited[u] = true; // Đã có lệnh dưới cần gì lệnh trên này nữa nhỉ?. --> Lặp lại à?.

    for (int i = 0; i <Adj[u].size(); ++i) {
            int v = Adj[u][i];
            // Băt đầu thăm thằng v
            bVisited[v] = true;
                // Thấy bVistied được gọi trước bMark thế nên 
                // bVisted cho ta thấy thứ tự thăm của DFS, kết luận này đúng không?
                       //--> Mình nghĩ là sai, bMark mới cho ta thấy thứ tự thăm của DFS
                        

            DFS(v); 
        }
}


int main() {

    // Khởi tạo như thế nào?. 

}