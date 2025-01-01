#include <iostream>
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


// // Nếu ko muốn thay đổi dãy cũ mà sinh ra dãy mà sinh ra 1 dãy mới sắp xếp thì sao?. Truyền tham trị vào
// void selectionSort1(int a[] ,int n) {
//     for (int k = 0; k < n; k ++){
//       int min = k;
    
//       for (int j = k + 1; j < n; j++) {
//          if ( a[min] > a[j])
//                min = j;
//       }
//     swap(a[k], a[min]);
//     }

//   }

// Intersection sort
void intersectionSort(int a[], int n) {
  for (int k = 1; k < n; k ++){
      int last = a[k]; 
      int j = k; // k là chỉ số phần tử cuối cùng đã duyệt
                // Chỉ số j duyệt ngược lại để thực hiện việc chèn. 
      while((j>1)&&(a[j-1]>last)){
        // với mỗi k ta có last, ta kiểm tra phần tử thứ k có bé ko?
        //--> Nếu vẫn lớn hơn thì đi đến k tiếp theo?.  Sử dụng liên tục các phép gán theo chiều kim đồng hồ. 
          a[j] = a[j-1];
          j--;
      }
      // Chỗ chèn của last là phẩn từ đầu tiên mà last lớn hơn
      a[j] = last;
  }
}


int main() {
  
  int a[] = {1,2,3, 2};
 // selectionSort2(a,4);
  intersectionSort(a,4);
  displayArray(a, 4);



  return 0;
}