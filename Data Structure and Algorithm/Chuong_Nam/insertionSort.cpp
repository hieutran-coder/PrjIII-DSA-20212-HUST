#include<iostream>
using namespace std;

void insertionSort(int A[], int N){ //  Thầy ko dùng con trỏ truyền vào?. 
    // Chỉ số từ 1 đến N

    for(int k = 2; k <= N; k ++){
        int last = A[k];
        int j = k;
        
        // Nêu ko có j>1 thì giả sử tất cả các phần tử đến lới hơn last thì nó có thể đi đến A[0], 1 phần tử không có.
        while(j >1 && A[j-1]> last){
            A[j] = A[j-1];// đẩy sang phải?.
            j--;
        }
        A[j] = last;// Quay vòng?. j nó sẽ giảm tới  sau vị trí A[j-1]<=last, hay trước thằng nhỏ nhất lớn hơn mình thì mình sẽ chèn vào vị trí j_
    }
}

int main() {






}