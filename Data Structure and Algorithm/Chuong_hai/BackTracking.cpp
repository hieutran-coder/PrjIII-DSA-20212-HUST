#include<iostream>
#include<string>
using namespace std;

// Cấu trúc thuật toán quay lui:
/*  Với mỗi vị trí k, duyệt qua hết phần tử của tập A
PHần tử nào mà thỏa mãn điều kiện thì ta bắt đầu thứ gán
rồi xét tiếp đến vị trí k+1, và lại check tiếp?
Có 2 trường hợp?.
    Một là không tồn tại ứng cử viên cho vị trí k +1 nào?.
        ---> Phần tử đã chọn ở vị trí k ko có lời giải, bị loại hay ko phải là thành viên của 1 solution.
        ---> Các phần tử thứ 1--> k-1 thì chưa biết được.
        ---> Cần phải chọn phần tử khác ở vị trí k
                    --> Trong này thầy chọn theo thứ tự

    --> Nếu tồn tại ứng cử viên cho vị trí k+1: 2 trường hợp.
    Nếu đến được n thì n ứng cử viên cho n vị trí thành 1 lời giỉa luôn.

// Cách duyệt như thế nào?.
// Cách kiểm tra như thế nào?.
*/
// Liệt kê tất cả các xâu nhị phân

// HIển thị giải pháp: 

int n = 3;
int x[3];

// int check(int v, int k){
//     return 1; // Tại sao return 1?. 
// }
// output ra solution trên màn hình

// Kiểm tra xem có 2 số kề nhau bằng 1 không?. 
// int check(int v, int k){
//     if ((x[k-1] == 1)&&(v==1))
//         return 0;
//         else
//             return 1;

// }
void solution() {
    for(int i = 1; i <n; i++ )
        printf("%d", x[i]);
    printf("\n");
}

// HIển thị bằng việc thử nghiệm. 
// void Try(int k) {
//     for (int v = 0; v <= 1; v++){ // Hai phàn tử
//         if(check(v,k)){
//             x[k] = v;
//             if(k == n) solution();
//             else Try(k+1);
//         }

//     }
// }
//----------------------------------
// Xâu ko có 2 số liên tiếp bằng 1
// void Try(int k) {
//     for (int v = 0; v <= 1; v++){
//         if (check(v,k)) {
//             x[k] = v;
//             if(k==n) solution();
//             else Try(k+1);
//         }
//     }
// }
//-----------------------------
// Liêt kê các tổ hợp chập k?.
// int check (int v, int i){
//     if (v>x[i-1]) return 1; // Nếu số sau lớn hơn số trước thì return 
//      else return 0; 
// }

// int k = 5;

// void Try(int i){   // i là chỉ số phần tử?. 
//     for (int v = 1; v < n+1; v++){  // v là giá trị gán cho mỗi phần tử
//         if(check(v,i)) {
//             x[i] = v;
//             if(i ==k) solution();  // Được k số xếp theo thứ tự tăng dần rồi dừng. 
//             else Try(i+1);
//         }
//     }
// }
//---------------------------
// Bài toán hoán vị
// int check(int v, int k){
//     for(int i = 0; i<k; i++) // i là vị trí của các phần tứ trước phần tử k 
//         if( v == x[i]) return 0; // Kiểm tra xem ứng cử viên có khác các phần tử trước k không?. 
//     return 1;
// }

// void Try(int k ){
//     for (int v = 1; v< n+1; v++){ // tập ứng cưr vien từ 1--> n
//         if( check(v,k)){
//             x[k] = v; 
//             if( n == k) solution();
//             else Try(k+1);
//         }
//     }
// }

// Cách thầy?.
// Nếu không dùng mv thì các giá trị sẽ ko khác nhau?. 
// Tại sao thầy lại chuyển lại mv bằng False?.
    // ---> Có thể là v ko còn là như cũ phải ko?. 
    // Nó sẽ đi đệ quy sau đó cho dù thất bại hay success thì nó quay về vị trí i và duyệt thằng khác của tập v.
    // Mà đã thử thằng khác tại vị trí i thì thằng đã xét v cũ  bây giỡ quay lại tiếp tục làm ứng cử viên, cho các vị trí đằng sau i+1, i+2. 
    // Nếu vẫn để true thì các ví trị sau sẽ ko chọn v mà true này làm thành viên.
    //1 vị trí sẽ được liên tục quay lại duyệt?. 
// Oke check mv hiểu rồi, nhưng tại sao lại cần chuyển mv thành true? vì cuối cùng kiểu gì cũng về Faulse?. 
    // True là ở trong quá trình xây dựng 1 lời giải, False là đệ quy đã thành công hoặc thất bại, và quay sang xậy dưng một lời giải khác rồi?. 
        // True nằm 1 ở 1 nhánh?. False nằm ở 2 nhánh khác nhau?. 
int m[4];

void TRY(int i) {
    for (int v = 1; v<=n; v++){
        if(!m[v]) {
            x[i] = v;
            m[v] = 1;// đánh dấu phần tử này đã chọn khi xây dựng
            if (i == n) solution();
            else TRY(i+1);
            m[v] = false;// duyệt sang nhánh khác của vị trí i;
        }
    }
}


int main(){
   for(int v = 1; v<= n; v++){
       m[v] = false;
   }
   TRY(1);

   
    // Để duyệt số đầu từ 0 tới n;
    
//    while(j<= n){
//        x[0] = 1;
//        Try(1);  // Thực hiện việc xây dựng dãy?. // Và nếu thực hiện từ 0 thì ko thể có số trước để so sánh nên bắt đầu thực hiện từ 1
//        j++;         // Bắt đầu từ 1 số khác 
//    }
    


}
