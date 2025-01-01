#include<iostream>
#include<string>
using namespace std;

//Dãy sắp xếp theo thứ tự tăng và tìm vị trí mà x[i] = y


// int bSearch(int x[],int start,int finish, int y) {
//         if( start == finish) {// chỉ có 1 phần tử
//             if (x[start] == y)
//                 return start;
//                 else return -1;

//         }else{ // Sẽ có 2 phần tử trở lên
//             int m = (start + finish)/2 ;// Câu hỏi đặt ra là số này ko nguyên thì sao?.
//             if(x[m] == y) return m; // nếu có nhiều số bằng y thì sao?.
//             if(x[m]< y)
//                 return bSearch(x, m+1, finish, y); // Đây là thực hiện 2 job, job 1 là giải bài toán con, job2 là return lời giải bài toán con
//             else // Trường hợp này x[m] lớn hơn y
//                 return bSearch(x, start, m-1, y); // có 2 số ở vị trí 0 và 1 thì lấy đâu ra m-1???.--> Nếu mình thay bằng m thì sao?. 
//         }  
// }
//   int binarySearch(int array[], int left, int right, int x)
//     { 
//         // nếu chỉ số left > right dừng lại và return -1 không có kết quả
//         if (left > right) return -1;
//         // tìm chỉ số ở giữa của mảng
//         int mid = (left + right) / 2;
        
//         // nếu số cần tìm bằng số ở giữa của mảng thì return
//         if (x == array[mid]) 
//             return mid;
        
//         // nếu số cần tìm nhỏ hơn số ở giữa của mảng thì tìm sang nửa bên trái
//         if (x < array[mid]) 
//             return binarySearch(array, left , mid-1, x);
  
//         // nếu số cần tìm lớn hơn số ở giữa của mảng thì tìm sang nửa bên phải
//         if (x > array[mid]) 
//             return binarySearch(array, mid+1 , right, x);
//     }
// int main() {
//     int a[] = {1,2,3};

//     cout << bSearch(a,0,2,2); 
//     return 0;
// }







//----------------------
// Tìm dãy con cực đại?.
// Nếu có nhiều dãy con có tổng cực đại thì sẽ lấy dãy noà?.
int maxLeft(int* a, int l, int r) {  // Trong này thầy truyền vào 1 con trỏ
    int max = -9999999; // Max là con số âm vô cùng
    int s= 0;

    for(int i = r; i>= l; i--){ // ko biết --i, và i-- có khác nhau như thế nào?.
        s += a[i];
        if (s> max) max = s;
    }
    return max; 
}

int maxRight(int *a, int l, int r) {
    int max = -99999999;
    int s = 0;

    for(int i = l; i<=r; i++){
        s+=a[i];
        if(s>max) max = s;  
    }
    return max; 
}

int maxSeq(int* a, int l, int r){ // l, r là phần tử đầu và phàn tử cuối trong dãy à
    if(l==r) return a[l];
    
    int max;
    int mid = (l+r)/2;

    // Chia để trị Thành 3 bài toán con
    // max bên trái, max bên phải, và max xuyên từ trái sang phải?.
    int mL = maxSeq(a,l,mid);
    int mR = maxSeq(a, mid+1, r);

    int mLR = maxLeft(a,l,mid)+ maxRight(a,mid+1,r);
    max = mL;
    if(max < mR) max = mR;
    if(max < mLR) max = mLR;
    return max; 
}





int main() {
    int a[] = {1,2,3,4,5,6,7,8,9};
    int rs = maxSeq(a, 0, 7);

    cout << rs;
}


