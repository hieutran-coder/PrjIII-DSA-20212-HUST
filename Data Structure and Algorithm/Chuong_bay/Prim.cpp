#include<cstring>
#include<iostream>

using namespace std;

#define INF 9999999

// số lượng đỉnh trên 1 graph
#define V 5

// Khởi Tạo mảng 2 chiều với kích thướng 5*5, Cách khởi toạ như thế nào?. 
// Ma trận tập các cạnh kề mô tả  đồ thị --> Wow  sử dụng mảng mà ko sử dụng 

// Dùng cấu trúc matrix khác với cấu trúc cạnh kề. 

int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
};


int main() {
    int no_edge; // số lượng cạnh

    // Tạo ra 1 dãy để track các vertex đã được chọn?. WHY?.

    int selected[V];  // tậpđã đưuojc select

    //
    memset(selected, false, sizeof(selected)); // set selected thành false lúc đầu

    // set số lượng cạnh về 0
    no_edge = 0;

    //số lượng cạnh trên minimum spanning tree luôn ít hơn hơn hoặc bằng v-1,

    // chọn vertex thứ 0--> Chuyển nó thành true
    selected[0] = true;

    int x; // số  hàng
    int y; // số cột

    //HIển thị edge và weight
    cout <<"Edge" << " : " <<"Weight";

    cout << endl;

    while(no_edge < V-1) {
        //Với tất cả vertex trên tập S, tìm tất cả các đỉnh kề với nó?.
        // tính toán đường đi từ vertex đã select.
        // Trong trường hợp vertex này cũng ở tập S thì bỏ qua nó và chọn đỉnh khác gần nhất với đỉnh lúc đầu?.
        int min = INF;
        x = y = 0;
        
        
        /// Tìm khoảng cách min nhất nối từ tập được chọn vào tập chưa được chọn?. 
        for(int i = 0; i< V; i++) {
            if( selected[i]) {
                for (int j = 0; j < V; j ++){
                    if (!selected[j] && G[i][j]){ // nếu nó chưa được select và có khoảng cách từ i đến j à???
                            if(min>G[i][j]){
                                min = G[i][j]; //min gán cho trọng số này?. Tại sao?.
                                x = i;
                                y = j;
                            }
                    }
                }


            }

        }
        // Thoát ra vòng for???
        cout << x<< y<< G[x][y];
        cout << endl;
        selected[y] = true; // Thêm vào trong cây khung, 
        no_edge++; 

    }



}