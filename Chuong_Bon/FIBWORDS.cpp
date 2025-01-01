#include<iostream>

using namespace std;

#include<string>

//Cách 1: Ham tinh toan de ghep xau, cách dùng đệ quy
string Fibword(int n){
    if(n==0) return "A";
    if(n==1) return "B";

    return Fibword(n-1) + Fibword(n-2);
}
// Cách 2: Dùng đệ quy có nhớ.
// Cách 3: Dùng khử đệ quy

int  Find(int i, int n){
    // Xét đủ trường hợp nhỏ hay không?.
    if (i>n-1) return -1;
    if (n==1&&i==0) return 1;

    if(n==2){
        if(i==1) return 2;
        if(i ==0) return 1;  } // Coi nếu là kí tự A thì tương đương với 1, kí tự B thì tương đương với 2
 

    if (i> Fibword(n-2).length()) Find(i-Fibword(n-2).length(), n-1);
    else Find(i, n-2);
}




int main()
{





}