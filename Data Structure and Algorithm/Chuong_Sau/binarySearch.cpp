#include<iostream>

using namespace std;

int binarySearch(int X[], int L, int R, int Y) {
        // Trường hợp cơ sở
        if(L = R) {
            if(X[L] = Y) return L; 
            return -1; // tức là trong dãy 1 phần tử này khác Y; 
        }


int mid = (L + R)/2;

if( X[mid] = Y) return mid;

// bài toán con
if( X[mid] >Y) 
    return binarySearch(X, mid+1, R, Y); 
if( X[mid]< Y)
    return binarySearch(X,L, mid-1, Y);

}


// Câp số cộng, dãy cấp 3

// Xem có dãy cấp 3 không?.

// Bước 1 là sort dãy, bước 2 là duyệt
int main() {

int n = 100;
int a[n+1];


// Cách duyệt tất cả các bộ 3
for(int i = 1; i < n-1; i++) {
    for(int j = i + 1; j < n; j++){
        long key = 2*a[j] - a[i];
        for ( int k = j+1; k<=n; k++)
            if ( a[k] == key){
                printf("Đúng, bộ 3 csc dầu tiên  là %li %li %li", a[i], a[j], a[k]); 
            }
    }
}
// Cách duyệt dãy cấp 3 áp dụng binarySearch?

for(int i = 1; i< n-1; i++) {
    for(int j = i+1; j< n; j++){
        long key = 2*a[j] - a[i];
        int k = binarySearch(a, j+1, n, key);
            if( k != -1 && a[k] == key){
                 printf("Đúng, bộ 3 csc dầu tiên  là %li %li %li", a[i], a[j], a[k]); 
            }
    }
}



}
