#include<iostream>
using namespace std;

int h(int k, int i);

typedef struct ad{
    int key;
    int value; 
}ad;


ad T[10];
int m; 
 

int get(int k){
    // T là bảng
    int i = 0;
    while(i<m) { // lấy 1 địa chỉ bất kì trong m nơi
        int j = h(k,i); // tính toán địa chỉ j

        // kiểm tra có ở ô thứ j đã có khoá k chưa
        if(T[j].key = k) {
            return T[j];
        }
        // NẾu ko có khoá k ở địa chỉ J
        i = i +1; 

    }
    return NULL; // Đã duyệt tất cả ô nhưng ko có ô nào chứa khoá k?. 
}


int put(int k, int v) {
    ad x;
    x.key = k;
    x.value = v;

    int i = 0;

    while( i< m) {
        // Tìm chỗ nào vẫn còn choox
        int j = h(k,i); // Tính toán địa chỉ

// Vậy T là con trỏ hay sao?.--> Nếu thay thành con trỏ thì bị lỗi ở trên 
// Nếu để lại mảng thì bị lỗi ở đây?. //solution là set up tất cả thành âm vô cùng
        if( T[j].key = -9999) {
            T[j] = x; return j;
        }
        i = i+1; // Đôngj nghĩa tại chỗ vừa mới duyệt đã có key ở rồi
    }
    printf("Bảng băm đã tràn"); // ==> KO chèn được voà bảng nữa?.. 
}

int main(){

}