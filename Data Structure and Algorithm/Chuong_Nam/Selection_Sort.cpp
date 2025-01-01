#include<iostream>
using namespace std;


void selectionSort(int A[], int N) {
    // chỉ số đi từ 1 đến n

    for(int k = 1; k< N; k++){
        int min = k; // Chỉ số của phần tử nhỏ nhất--> Đi tìm phần tử nhỉ nhất

        for(int j = k +1; j<=N; j ++){
            if( A[min] > A[j] ) min = j;
    }
    int tmp = A[min];

    // Giá trị cũ của A[min] là gì?. Giá trị mới của A[min] là gì?. 
    A[min] = A[k]; // Đổi giá trị A[min] thành gía trị A[k]
    A[k] = tmp; // Đôi giá trị Ạ[k] thành A[min]

    }
}





int main() {






}