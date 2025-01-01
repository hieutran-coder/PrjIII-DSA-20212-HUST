#include<iostream>
using namespace std;

void merge(int A[], int L, int M, int R) { //
    // merge 2 array was sorted. L-->M vs M+1--> R;
    int TA[R];
    int i = L; int j = M + 1; // điểm start

    for (int k = L; k <= R; k++){

        // Trường hợp dãy bên trái và bên phải chạy hết rồi?. 
        if(i >M){ // Khi nào xảy ra trường hợp i lớn hơn m?. khi một  nửa dãy bên trái đã duyệt hết. 
            TA[k] = A[j]; j++; 
        }
        else if(j>R){ TA[k] = A[i]; i++;} //

        // So sánh 2 dãy với nhau?. 
        else{
            if(A[i] < A[j]){
                TA[k] = A[i]; i++;
            }
            else {
                TA[k] = A[j] ; j++; 
            }
        }
    }
    for(int k = L; k<= R; k++) A[k] = TA[k]; 

}



void mergeSort(int A[], int L, int R){
    if(L < R){
        
        int M = (L + R)/2; // Chia để trị

        mergeSort(A, L, M); // Đệ quy cho thằng bên trái hay bài toán con 1

        mergeSort(A, M+1, L);// Đệ quy thăng bên phải?. hay bài toán con 2

        merge(A,L,M,R); // tổng hợp 2 lời giải và xử lý. Tại sao gọi là trộn thì chắc key nằm ở cái này?. 

    }
}
 


int main(){

}