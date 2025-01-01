#include<iostream>
using namespace std;

#include<map>

map<int, int> Mem;


int fibonacci(int n) {

    // Base case thì nó gồm 2 trường hợp là bài toán con với kích thước là 1 và bài toán con với kích thước là 2
    if (n <= 2)
        return 1; // Nếu đệ quy thông thường thì tất cả recursion đều trở về base case này?.

// Cái dòng này kiểm tra xem khi đệ quy xuống những bài toán con thì đã được giải và có trong bộ nnhớ chưa?. Nếu có rồi thì tái sử dung
// Nếu chưa có thì phải giải nó thôi :))
    if (Mem.find(n)!= Mem.end())
        return Mem[n];

    int res = fibonacci(n-2) + fibonacci(n - 1);

    Mem[n] = res;

    return res;

}

// Cài đặt bằng cấu trúc dữ liệu khác?. 
int iMem[1001];

int Fib(int n) {

    if ( n<=2) return 1;

    if (iMem[n] != -1) return iMem[n];

    int res = Fib(n-1) + Fib(n-2);

    iMem[n] = res;
    return res;

}


int main() {
    int i = 0; 
    while(i<1001)
    {
        iMem[i] = -1; 
        ++i; 
    }

    int a = Fib(19); 
    cout<<a; 
}