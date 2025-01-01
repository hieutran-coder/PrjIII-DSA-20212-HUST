#include <iostream>
#include <string>
#include<sstream>
using namespace std;

int main() {
//     string str1 = "123";
//     int x = stoi(str1);
//     cout << "stoi(\"" << str1 << "\") is " << x << '\n';
// }
    string str1 = "123";
    int x = stoi(str1); // hàm chuyển đổi string sang int, mà nó không chuyển đổi char.
    cout<<"stoi(\""<< str1 << "\") is "<< x<<"\n";

// https://www.softwaretestinghelp.com/cpp-character-conversion-functions/


// Chuyển đổi từ character đến int.
// Cách 1 là by casting.

char a = 'A';
int num = (int)a;
 a = '2'; // tái sự dụng a  
 num = a-48; //number character sang int
cout<<num;


// sử dụng stringstream? cách 2;
stringstream str; // Đối tượng xtr;

str<<"5"; 
int x;
str >> x; // Cái dấu>> nó được dùng khi nào?. Và dùng như thế nào?. Nó lấy đata từ thằng str và lưu vào biến x. 
          // chuyển str sang x; 
cout<<"Giá trị được converted của charater 5 là"<<x; // nó lấy data vào lưu vào stream rồi cho chạy ra màn hình?. 

// convert charater to string--> Char to string?.

// Cách 1:

// Sử dụng constructor?.
string str2(1,'A'); // Tham số đầu là size của string, tham số sau charater để convert to string

//cách 2: 
// Sử dụng +=, = thì overload for character(đa hình

// Cách 3 thì sử dụng các method khác nhau của string?. push_back, append, assign, insert.










}