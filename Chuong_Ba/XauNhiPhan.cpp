#include<iostream>

using namespace std;

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
    
    for(int j = 0; j<=1; j++){ // Tập ứng cử viên
        a[i] = j;
        
        if(i == n-1) hienThi(a,n);
        else Try(i + 1);
    }
}

int main() {
    Try(0); 
    cout<< "Số giá trị print là " << count1; 
}