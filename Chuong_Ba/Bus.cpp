#include<iostream>
using namespace std;


// Code thầy Dũng
const int N = 100;
int n, Q;

 // Cấu trúc visited dùng để làm gfi?. 
bool visited[N];

int load;

double  d[N][N];
double f,dmin,f_best;
 int  x[N]; 
// Hàm check

// đọc dữ liệu từ file văn bản
void input() {
    // mở file và định hướng vào giá trị trị chuậ
    freopen("bus_demo.inp","r", stdin);  // tại sao lại đuôi không phải text mà là inp nhỉ?. 
    cin >> n>> Q;
    for (int i = 0; i<= 2*n; i++ )
        for (int j = 0; j<= 2*n; j++)
            {
                cin >> d[i][j];
                if(i != j && d[i][j] < dmin) dmin = d[i][j];
            }
}





bool check(int v, int k) {
    if (visited[v]) return false;
    
    // điểm đón
    if ( v<=n ){
        if (load>=Q) return false; // Xem có thêm người vào bus được không nếu ko thêm được thì bỏ qua điểm đón. 

    } else{
        // điểm đón tương ứng với điểm trả v chưa được thăm thì bỏ qua điểm trả này
        if(!visited[v-n]) return false; 
        }
    return true;
}

void updateBest(){

    if (f + d[x[2*n]][x[0]] <f_best){
        f_best = f + d[x[2*n]][x[0]];
        cout<<"update best "<< f_best<<endl;
    
    }

};

// Quay lui
void Try(int k){ // Thử tất cả giá trị cho x[k] khi đã biết các giá trị x[0], x[1], .. x[k-1]..

    // v là candiate là nơi mà xe buýt chọn có đi quay hay không.
    for (int v = 1; v <= 2*n ; v++){

        if (check(v,k)) {
            // v nó thoả mãn hay đủ điều kiện để đi thăm
                x[k] = v;
                visited[v] = true;
                
                f = f +d[x[k-1]][x[k]];

                if (v <= n) load +=1; else load -= 1; // Ta sẽ thêm người trong trường hợp là điểm đón,
                                                      // và bớt người trong trường hợp v là điểm trả
                if ( k == 2*n) updateBest(); // Trong trường hợp đã đi hết 2n vị trí. 
                else{
                    if(f+ dmin*(2*n+1-k)< f_best) // ta kiểm tra cận nhánh này có nhỏ hơn không
                        Try(k+1);
                    }
                // Tại sao thày Dũng lại thêm 1 dòng if sau đây nữa
                if (v<=n) load -= 1; else load +=1; // Chắc sẽ cập nhật bus nếu đã xong nhánh vào cây này.
                visited[v] = false;
                f = f - d[x[k-1]][x[k]];

        }
    }
}






int main() {

    input();

    for (int v = 1; v<= 2*n; v++) visited[v] = false;
    f = 0; load = 0;
    f_best = 1e9;
    x[0] = 0;
    Try(1);



}
