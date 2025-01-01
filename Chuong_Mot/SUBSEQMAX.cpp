#include<iostream>
using namespace std;

 int a[1000100]; // Chưa nói a thuộc khoảng nào thì để là int. 
 int n; 
 int w[1010][1010]; //Nên khai báo với số lượng bao nhiêu?. Với cách 2: tại sao có thể tăng số lượng hàng và cột của w?. 
                    // Khai báo mảng 10000 bị tràn bộ nhớ--> Giảm xuống 5000. Đây là điểm bản thân không để ý?. 
                    // Dùng w có thể khiến bị memory limit?. Làm sao để không cần dùng w nữa?. 
int f[1000100];


// THuật toán 10^3 chỉ đúng được 2 test?. Một test 80. Các test lớn hơn sẽ bị quá thời gian hoặc tràn. 
int main() {
// Chú ý định dạng input
 
    freopen("subsequencemax.inp", "r", stdin); // tức lại nó sẽ đọc file rồi cho vào stdin à. 
    freopen("subsequencemax.out", "w", stdout); 



   
    cin>>n; // lấy n từ cin?. 

    // dòng thứ 2 gồm n số nguyên?.
    for (int i = 1; i<= n; ++i)
        cin >>a[i];

    int res = -INT_MAX; // một số thật lớn.

   
   



// Cách 2?. Pointer 20 điểm??. 
// Làm sao cải tiến?. Tính w[i][j]+ w[j][k] = w[i][k]; giống như có nhớ
// w[i][j] = w[i][j-1] + a[j]; có thể sai khi i = j; thế nên cần phải xét trường hợp i= j riêng. 
// Giảm xuống còn 2 vòng for?. --> Nhưng bộ nhớ lại tăng?. Thêm n bình bộ nhớ. 
// Một question?.--> Tại sao lại sử dụng mảng 2 chiều. 
// Một bạn đề xuất vẽ hình ra
//  for (int i = 1; i<=n; i++) // i laf diem dau day, j la diem ket thuc day
//     for (int j = 1; j<=n; j++){
//         w[i][j] = 0;
//         for(int k = i; k<=j; ++k)
//             w[i][j] += a[k];
//         res = max(res, w[i][j]);
//     }

// Cách 3?. sử dụng temp?. --> Point lên 50?. 
// for (int i = 1; i<=n; ++i){
//     int tmp = 0;

//     // Với mỗi i tìm max mà có giá trị bắt đầu từ i?. 
//     for (int j = 0; j<=n; ++j){

//         tmp += a[i];
//         res = max(res, tmp);
//         cout << i <<" "<< j<< tmp <<endl;
//     }
// }

// Cách 4:
// for (int i = 1; i<=n; ++i){
//         f[i] = max(a[i], a[i]+ f[i-1]);
//         res = max(res, f[i]); 
// }



cout<<res; // chuyển res vào cout


}