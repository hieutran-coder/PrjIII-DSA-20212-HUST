#include<iostream>

using namespace std;

int Pow(int x, int n){
    if (n== 0) return 1; // Base case khi giảm số mủ

    if(n%2 !=0) 
        return x * Pow(x, n-1); // trường hợp n lẻ

    // qua được xuống đây thì n phải chẵn rồi
    int res = Pow(x, n/2);// Chia thành bài toán con
    return res* res; // Gộp 2 bài toán lại 
    /// có thể gồm 2 công viẹc này trong một câu lệnh
    //return Pow(x, n/2) * Pow(x, n/2); 


}

int main () {


}