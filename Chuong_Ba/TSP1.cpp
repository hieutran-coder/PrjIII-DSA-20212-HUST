#include<iostream>
using namespace std;
int n, m;

int const N = 25;
int res; 
int a[N][N];
int mark[N];

void attempt(int t, int sum, int cur) {

    if (sum >= res) return; // ko đi theo nhánh này nữa



    // t đã đi hết n điểm rồi
    if (t> n){
        // Kiểm tra xem có đường đi từ đỉnh hiện tại đến 1 không
        if(a[cur][1] !=-1){
            res = min(res, sum + a[cur][1]);            

        }
        return;
    }

    // t<=n
    for (int j = 2; j<=n; j++){

            //if(mark[j]== true){ // thiếu kiểm tra có đường đi
            if (mark[j]&& a[cur][j] != -1){
                mark[j] = false;
                attempt(t+1, sum+ a[cur][j], j);
                mark[j] = true; 
            }
    }
}





int  main() {

    cin >> n>> m;  // Nhập số lượng đỉnh và số lượng cạnh

    // Lưu bằng ma trận hoặc bằng vector các đỉnh kề

    memset(a, -1, sizeof(a)); // 
    // Cách khởi tạo bằng while(Bình thường m dùng bằng for)
    // input các cạnh 
    while (m--){
        int x, y, w;
        cin >>x >> y>>w;
        a[x][y] = w; 
    }



    memset(mark, true, sizeof(mark));
    mark[1] = false; 
    res = 1e9;
    // Bắt đầu từ đỉnh số 2 vì đỉnh đầu tiên là đỉnh 1, vói sum là 0 vì chưa đi đâu. 
    attempt(2, 0, 1);
    cout <<res; 

}