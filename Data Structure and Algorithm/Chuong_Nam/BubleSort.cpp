#include<iostream>
using namespace std;

// Mỗi lần đổi chỗ của Buble Sort có tác dụng gì?.
void bubleSort(int array[], int size) {


    // vòng lặp để Truy cập đến mỗi Array element
    for(int step = 0; step < size; ++step) {

        // Vòng lặp để so sánh giữa các phần tử array
        for(int i = 0; i< size-step; ++i) { // Tại sao ko vét cạn dãy mà chỉ vét 1 phần?.--> PHần tử lớn nhất chắn chẵn sẽ đẩy về cuối cùng. 
            // Có 3 lệnh 
            if (array[i]> array[i+1]){
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }

}




// Optimizing Buble sort
void bubleSort(int A[], int N) {
    // index from 1 to N
    int swapped;

    do {
        // Vậy có chắc thuật toán này sẽ dừng ko?. 
        swapped = 0; // Gán lệnh này nếu như lần lặp trước đó có ít nhất 1 lần đổi
        // Wow đây chỉ mất một vòng lặp thôi
        for (int i = 1; i< N; i++){
            if( A[i]> A[i+1]) {
                // Cứ gặp thằng lớn hơn là đổi 
                int tmp = A[i];
                A[i] = A[i+1];
                A[i+1] = tmp;

                swapped = 1; //?. MỖi lần đổi swap bằng 1, xong hết N Lần thì swap bằng 1 tức vẫn còn ít nhất 1 lần đổi, vâỵ lặp lại lần nũa xem hội tụ hay ko?.
       
       
            }
        }
    }while( swapped == 1); // Kiểm tra xem trong N-1 lần thì có tồn tại ít nhất 1 lần đổi chỗ ko?.



}