#include<iostream>

using namespace std;

static int  count1 = 0; 

void hienThi(int a[], int n) {
    count1 = count1 + 1;
    for(int j = 0; j<n; j++){
        cout<<a[j]; 
    }
    cout<<endl; 
}
int n = 5;
int m = 4; // k chạy từ 0 đến 3 nên có 4 giá trị?. 
int a[100];
bool bitMark[100];

// Xây dựng giá trị a[k]
void Try(int k) {
    
    for(int i = a[k-1] + 1; i<= n-m+1+k ; i++){ // Tập ứng cử viên, bởi ta sẽ in theo thứ tự tăng dần, nên phần tử tiếp thoe ít nhất là bằng pt trức + 1
    // Và nó chạy đến số để thoả mãn vẫn còn chỗ cho m-k số lớn hơn nó
        a[k] = i;
        if(k == m-1) hienThi(a,m);
        else Try(k + 1);
    }
}

int main() {
    for(int l = 1; l<= n-m+1; l++){
        a[0] = l; 
        Try(1); 
    }
    cout<< "Số giá trị printed là " << count1; 
}