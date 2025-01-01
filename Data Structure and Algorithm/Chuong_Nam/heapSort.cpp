#include<iostream>

using namespace std; 


void heapify(int A[], int i, int N){ // Vun lại đống

    int L = 2*i ;  // vị trí con trái của i
    int R = 2*i+1;// vị trí con phải của i
    int max = i;

// Tìm con lớn hơn cha
    if( L <= N && A[L] > A[i])  // Nếu Con trái mà lớn hơn cha
        max = L;
    if(R <= N && A[R] > A[i]) // nếu con phải lớn hơn cha?. Tại sao cần đk R<=?. nếu R> N thì sao?.
        max = R;

// Vun tại nút nào sau nút i, tại nút chứa A[i]
    if(max != i){ // Tại sao lại xét điều kiện này?. 
        swap(A[i], A[max]);// Đổi vị trí cha cho con. max là vị trí mới của cha phải không?. 
        heapify(A, max, N);  // Dệ quy vậy heapify khi nào dừng?.--> Khi bỏ qua vòng if này?. --> max bằng i hay max ko bằng L, ko bẳng R, hay A[l], A[R] đều bé hơn A[i]
    } 
}

void buildHeap(int A[], int N) {
    for(int i = N/2; i >= 1; i--){ //vun đống tất cả những nút ko có lá phải ko?
        heapify(A, i, N);
    }
}

//buildheap khác gì heapify?. 
    // --> Nó sử dụng heapify để vun tất cả nút, còn heapify vun 1 nút?.
 
void heapSort(int A[], int N) {
    // vị trí đi từ  1--> N
    buildHeap(A, N); // vun đống các phần tử khác lá--> Nó sẽ tạo ra max-heap

    for(int i = N; i>1; i--){
        swap(A[1],A[i]); // PHần tử max ở đầu tiên xuống cuối và tách ra, phần tử cuôi nhảy lên đầu?.
        heapify(A,1, i-1);// tạo lại max heap bằng cách vun chắc phần tử đàu tiên?. --> Ko cần vun tất cả nút nữa?. 
    }
}



int main() {





}