#include<iostream>
 
using namespace std;

int partition(int A[], int L, int R, int indexPivot){

    int pivot = A[indexPivot]; // là vị trí của thằng chọn làm pivot phải không ?. 
    

    swap(A[indexPivot], A[R]); // Tại sao swap luôn?. Chọn phần tử cuôi.--> Đẩy pivot ra cuối?. Tại sao ko xử lý luôn mà đẩy pivot ra cuối?. 

    int storeIndex = L; // Biến StoreIndex để làm gì?.
// Duyệt từ đầu tới cuôi?. Thằng nào mà bé hơn pivot thì gán lại theo thứ tự thôi
// Sau khi đã đẩy được tất cả phần tử bé hơn về ben trái?. Ko chỉ như thế mà các phần tử bé hơn đều sát nhau, có nghĩa ko tồn tại
        // phần tử lớn hơn trong này--> các phần tử lớn hơn đã được swap sang phải rồi. 

    for(int i = L;  i<= R-1; i++){ // Tại sao lại đến R-1?  vì R làm pivot 
        if ( A[i] < pivot){ // bên trái 
            swap(A[storeIndex], A[i]);
            storeIndex ++; // storeindex ko tăng thì Thằng A[i]> pivot phải không ?. 
        }// Tại sao store index luôn trỏ đến phần tử lớn hơn pivot?.
            //-->nếu store pivot mà đi chậm hơn j tức là store pivot đang trò tới phần tử lớn hơn?. 
    }
    

    swap(A[storeIndex], A[R]); // Storeindex là vị trí đầu tiên từ trái qua phải lớn hơn pivot thì cần đổi lại vị tí?. 
    return storeIndex; 
}

// Cách trên youtube thì dùng second pointer??> 


void quickSort(int A[], int L, int R) {
    if(L<R) {
        int index = (L + R)/2;
        index = partition(A, L, R, index);


// Trường hợp nào mà ko thực hiện 2 lệnh if này?
// Khi nào index nằm ngoài L, R ?
// Khi nào L > R???
        if( L< index)
            quickSort(A, L, index-1);
        if(index < R)
            quickSort(A, index + 1, R); 

    }
}

