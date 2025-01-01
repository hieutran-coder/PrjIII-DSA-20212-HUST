#include<iostream>
#include<string>

using namespace std;

// Tính tổng các số
int sum(int n) {
    if ( n <= 1) return 1; // trường hợp cơ sở: Tức ko gọi đệ quy nữa.
    // Tại sao ko cần if (n>=2) nhỉ?. Tại sao ko cần else nhỉ?.
            // Nếu có if( n> =2) thì sao?.
            // Nếu ko có if(n>=2) thì sao?.
            // Nếu ko cần else cũng giống có else thì else  
            // Bởi giả sử câu lệnh if ko thực hiện thì câu lệnh sau vẫn thực hiện.
            //Bởi nếu câu lệnh if thực hiện nên các câu lệnh ở sau ko được thực hiện
            //--> Kết luận trong trường hợp này có thể thay bằng else?. 
    int s = sum(n-1);
    return n+s; // Tổng hợ lại lời giải.
}
//
// int C(int k, int n) {
//     int a,b;
//     if (n == 1) return 1;
//     if (k == n) return 1;

//     if (k >0){
//        a = C(k-1, n-1);
//         b = C(k,n-1);
//         return a+b;
//     }else return 1;
    
// }
// Tháp HN?.
// Bài này nó ko hiện ra kết quả?. Mà nó phải hiện thị quá trình chuyển
//==> Làm sao máy giải thích cho con người 1 quá trình nào đó.
//Giải thích thuật toán này như thế ddaya?> 
    // Cứ coi đĩa dưới cùng biến mất hay ở đó thì ko ảnh hưởng đến sự vận chuyển phái trên?.
// Vậy trường hợp cơ sở là gì?. CÓ những bài toán con nào?.
// mục đích move(a,b,c) c là trung gian
// move(n-1, a, c, b) kết quả là tất cả đều ở cọc c
// sau đó move(1,a,b,c) đưa a sang cọc b: Có thể dùng cái này hoặc dùng công thức khác
// Sau đó coi đĩa ở cọc b biến mất thì cọc a trung gian, cọc c điểm bắt đầu, đích đến là cọc b
// move(n-1,c,b,a)
// Thử dùng lối tư duy đệ quy của máy để thử trường hợp nhỏ xem sao?.


void move(int n, char A, char B, char C){
    if(n == 1){
        printf("Move 1 đĩa từ %c đến %c", A, B);
    }
    else{     // Tại sao bên các thuật toán bên trên ko có else nhưng đây lại có else
        move(n-1, A, B, C);
        move(1, A, B, C);
        move(n-1, C, B, A); // Ngay cả tập GYM cũng phải Move tạ cho chuẩn
    }
}



// Đệ quy có nhớ?. 
// 
int m[100][100];
int C(int k, int n){
    if(k==0||k==n)
        m[k][n] = 1;
    else{
        if(m[k][n] < 0){ // Điều kiện để đệ quy
        // Nếu m[k][n] lớn hơn 0 tức là trước đó nó sẽ phải trải qua giai đoạn từ <0 đến lớn hơn 0
            m[k][n] = C(k-1, n-1) + C(k,n-1);// WWow khác biệt là m[k][n] là thằng tổng hợp lời giải
        }
    }
    return m[k][n];

}



int main() {
    cout << sum(5);
    cout << C(3,6);
    int n = 3;
    move(n, 'A', 'B','C'); 

// Đoạn code nhập input vòa mảng
    for (int i = 0; i < 100; i ++)
        for (int j = 0; j< 100; j ++)
            m[i][j] = -1;
            
    printf("%d\n",C(16,32));// Code C. 


}
