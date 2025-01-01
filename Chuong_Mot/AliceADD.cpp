#include<iostream>
#include<string> 
using namespace std;


// Cách 1: 
// int main() {
//     unsigned long long a,b;
//     cin >> a;
//     cin >> b;

//     cout << a+b; 

//     unsigned long long a1, a2, b1, b2;
//     a1 = a/10;// Loại chữ số cuoi cùng a1.
//     a2 = a%10;

//     b1 = b/10;
//     b2 = b%10;


//     unsigned long long s1, s2;// Lúc đó không thể cộng số âm được nữa. 

//     s1 = a1 + b1; // 2^63+ 2^63/10--> Nhỏ hơn 2^63?. 
//     s2 = a2 + b2;

//     if (s2>=10){
//         s1++;
//         s2 -= 10; 
//     }

// if (s1 !=0 )  cout << s1;
// cout << s2;

// }


int main() {
    string a,b; // dùng string để lưu số lớn?. 

    cin >> a;
    cin >> b;
// Số lượng chữ số?. 
//--> Cần chỉnh sửa để a, b có cùng số thứ tự tự?.--> Để thứ tự các hàng dóng với nhau trong phép cộng.
//--> Giải pháp là thêm vào đầu a hoặc đầu b số kí tự
    while(a.size() < b.size()) a = "0" + a; // Trong C thì phải dụng hàm?. chứ ko được cộng như thế này. 
    while(a.size()> b.size()) b = "0" + b;  // Chú ý sự khác biệt giữa character và string?. String trong ngoặc kép, character 

    string res = "";
    int ln = a.size(); // ln là độ dài của xâu a;

    int nho = 0; 
    for (int i = ln-1; i>=0; --i){

    //    //  int x = int(a[i] + b[i]+nho); Lỗi sai một 
    //   //  int x = stoi(a) + stoi(b[i]) + nho; KO được stoi chỉ dùng được string, không dùng được cho char
    //    // Sử dụng atoi?. ko được
    //     int x = int(a[i])-48 + int(b[i]) - 48 + nho; // Cách 3, hơi củ chuôi và phải nhớ số 48. 
    //     nho = 0;
    //     if (x>=10){
    //         x-= 10; // Cần thận nếu nó bé hơn 10. 
    //         nho = 1;
    //     }
    //     // 'x' và "x" giống nhau đều cộng được phải không?. 
    //     res =  to_string(x)+ res ; // Vậy còn trường hợp vị trí hàng đầu tiên và có nhớ là 1 thì sao/.

   ////////////////////     
    // code Dũng
    int tmp = (a[i] -'0')+ (b[i]-'0') + nho; // Không lấy character trừ string được. 
    nho = tmp/10; // lấy nhớ
    tmp = tmp %10; // lấy chữ số đơn vị

    char c = tmp + '0'; // Chuyển từ int sang char, dấu cộng này chỉ dùng trong char thôi.
    res = c + res; // concencate c vs res lại với nhau/. 
    }   

    if (nho == 1) {
        res = '1' + res; 
        nho = 0; 
        }
    cout<<res;


}