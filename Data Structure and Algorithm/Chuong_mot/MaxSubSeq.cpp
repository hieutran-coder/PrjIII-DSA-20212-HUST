#include <iostream>
#include <string>
using namespace std;

void swap( int &a, int &b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void displayArray(int a[], int n) { // Có nhiều cách display: Có thể là dọc và cũng có thể ngang
  
    for(int i = 0; i <n; i++ ) {
          cout<< " "<< a[i];
    }
    cout<< endl;

}


// int maxSubSeq3(int a[], int n) {
//    int  ans = -1000000000;
   
//     for(int i = 0; i<n; i++) {
//         for (int j = i; j<n; j++){
//             int s = 0;
//             for (int k = i; k<= j; k++)
//                 s = s + a[k];
//             if (s> ans) ans = s;

//         }
//     }
//     return ans;
// }

// Cái lời giải này nó chỉ xác định từ điểm đầu tiên và duyệt?. Lợi ích là có thể không cần phải tính lại 1 phần tổng mà tái sử dụng.
// VỚi mỗi tổng thì so sánh vs ans Vì mục đích là lấy ra tổng lớn nhất, thế là đủ.  
// int maxSubSeq2(int a[], int n){
//     int ans = -10^5;

//     for (int i = 0; i < n; i++){
//         int s = 0;
//         for (int j = i; j< n; j++){
//             s = s + a[j];
//             if (s > ans) ans = s;
//         }
//     }
//     return ans;

// }
int maxSubSeq1(int a[], int n){
    int s[n];
    s[0] = a[0];
    int ans = s[0];

    for (int i = 1; i< n; i ++){
        if (s[i-1] > 0){
                s[i] = s[i-1] + a[i];
        } else
            s[i] = a[i];

        if (ans < s[i]) ans = s[i];   
    }

    return ans;
}



int main() {
    int a[] = {2, -10, 11, -4, 13, -5, 2};
    cout << maxSubSeq1(a,7);
    

}