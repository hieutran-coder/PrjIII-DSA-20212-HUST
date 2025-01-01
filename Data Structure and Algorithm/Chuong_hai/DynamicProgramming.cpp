#include <iostream>
using namespace std;


// Bài toán dãy con liên tiếp có tổng lớn nhất

// Bài toán con là dãy con liên tiếp có tổng lớn nhất đến phần tử thứ i. Solution là s
    // Solultion của bài toán thứ i+1 có thể tính qua bài toán thứ i?.

// Bài toán dãy con tăng dần có số lượng pahnaf tử là lớn nhất?. 
// Bài toán con là Dãy con dài nhất, tăng dần, và tận cùng là vị trí thứ i

// Vị trí thứ i +1; 
        // Ta xét các tập bài toán con mà phẩn tử i+1 lớn hơn hoặc bằng?. Ta sẽ chọn dãy nào lớn nhát trong đó rồi ghép lại--> Để tạo ra lời giả thứ i+1
        // Còn đối vơi tập bài toán còn lại thì ko cần xét?.
        // Số lượng bài toán con là o(n) là đa thức// phù hợp với điều kiện thuật toán quy hoahcj động. 

// int n= 11; 
// int S[11];
// int rs;
// int a[11] = {0,1,2,1,4,5,6,1,9,9,10};
// void solve() {
//     S[0] = 1 ; // Ví trí đầu tiên thì có số phần tử là 1
//     rs = S[0]; 
//     for(int i = 1; i<n; i++){
//         S[i] = 1;
//         for(int j = i-1; j>=0; j--){
//             if(a[i]>a[j]){          // Ta duyệt những bài toán con nào mà bé hơn thôi       
//                 if(S[j] + 1> S[i])  // Ta sẽ lấy bài toán con nào có số phần tử lớn nhất// điều kiện này là kiểm trã xem số phần tử có đủ nhiều hơn cái lần trươc sko?.
//                     S[i] = S[j] + 1;
//             }
//         }
//         // Đã xây dựng xong solution tại vị trí i?.--> Cần kiểm tra xem vị trí i lớn hơn rs ko?.
//         rs = S[i]>rs?S[i]:rs; 
//     }
    
//     cout<< "Số lượng phần tử của dãy tăng dần nhiều nhất là "<< rs; 
// }


// int main(){
//     solve(); 
// }


// Dãy con chung dài nhất?. Cũng là bài toán trên, nhưng bây giờ là dãy con chung của 2 dãy?. Chỉ cần chung là được?. Ko cần tăng dần. 
// Nếu trong trường hợp 3 dãy thì có giải quyết tương tự như 2 dãy được ko?.


int rs;
int m = 10, n=11;
int X[10];
int Y[11];
int S[11][10];
// Sẽ có m *n bài toán con?. 
// Lời giải/(Thực ra là kết quả của lời giải)  Các bài toán con được lưu trữ như thế nào?--> mảng 2 chiều
// Solution thứ n+1 sẽ truy hồi như thế nào?.
    // Nêú 2 phần tử giống nhau thì cứ cộng 1 thôi. 
// Cái việc phân tích và thiết kế thì khó nhưng cài đặt thì ko khó phải ko?.


void solve() {
    rs = 0;
    for(int i = 0; i<= n; i++) S[i][0] = 0;
    for(int j = 0; j <=m; j++) S[0][j] = 0;    
    
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=m; j++){
            if(X[i] == Y[i]) S[i][j] = S[i - 1][j - 1] + 1;
            else{
                S[i][j] = S[i-1][j]> S[i][j-1] ? S[i-1][j]:S[i][j-1];
        }
        // Đã tính xong lời giải tại vị trí i,j
        rs = S[i][j] > rs?S[i][j]:rs; // So sánh thì dùng 2 lần cái này luôn?. VCL?. 
    }
    }
    cout<< "    "<< rs; 
}

int main() {
    solve(); 
}



