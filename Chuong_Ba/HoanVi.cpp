#include<iostream>

using namespace std;

// Duyệt toàn bộ back Tracking?.

// Hàm ouput

static int  count1 = 0; 
void hienThi(int a[], int n) {
    count1 = count1 + 1;
    for(int i = 0; i<n; i++){
        cout<<a[i]; 
    }
    cout<<endl; 
}
int n = 5;
int a[100];
bool bitMark[100];

void Try(int i) {
    
    for(int j = 1; j<=n; j++) { // Tập ứng cử viên là 1--> n
        if(bitMark[j] == true) continue; 
        bitMark[j] = true; // Đánh dấu là giá trị này đã được chọn rồi?. 
        a[i] = j; // Chọn ứng cử viên
        if (i==n-1) hienThi(a, n); // kiểm tra xem đã đủ chưa rồi hiện thị, đâu cũng là base case?.
            else Try(i+1); // nếu chưa đủ thì đi sâu vào
        bitMark[j] = false; // Khi nó quay lui thì set up lại trạng thái lúc đầu. 
    }
}

int main() {
    Try(0); 
    cout<< "Số giá trị print là " << count1; 
}