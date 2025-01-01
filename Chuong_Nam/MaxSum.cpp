#include<iostream>

using namespace std;

int A[1001]; // mảng các dãy input đầu vào?. 

int iMem[1001];

bool bMark[1001]; // Tại sao không kiểm tra iMem luôn mà phải thông qua bMark?.
// Cấp phát bộ nhớ và size từng phần tử cuả mảng--> Dùng lệnh này đỡ dùng vòng for .





int MaxSum(int i ) {

    if (i == 1) return A[i]; // Trường hợp base case

    if(bMark[i])
        return iMem[i]; // Nếu đã tính trước đó rồi

        // Công thức quy hoạch động cho trường hộp dữ liệu mới
    int res = max(A[i], A[i] + MaxSum(i-1)); 

    // Lưu dữ liệu vào một mảng?. 
    iMem[i] = res;
    bMark[i] = true; 

    return res; 
}

// Hàm này có độ phức tạp là bao nhiêu?.
// Mình nghĩ là o(n)// Bộ nhớ cũnglaf o(n) cho stack?. 
void Trace(int i) {
    if(i != 1 &&iMem[i] == A[i] + iMem[i-1]) { 
        // Nếu không có i !=-1 vòng lặp sẽ đi đến vô hạn--> i=1 có thể là basecase
        // Còn điều kiện thứ 2 là nếu cái tổng iMem(i-1)>0 tức là có thể tiếp tục lùi được hay không hay truy vết được nữa hay không?. 
        Trace(i - 1);
    }

    cout << A[i]<< " "; // Lệnh này sẽ được thực hiện liên tiếp nhiều lần khi backtrack?. Nó sẽ hiện thị theo thứ tự tăng dần?. 
}







int main(void) {

    memset(bMark, 0, sizeof(bMark));    
    for (int i = 0; i< 1001; i++)
                A[i] = 50- rand()%100;
    
    int ans = 0;

     MaxSum(1000);
    for (int i = 0; i<1001; i++){
        ans = max(ans, iMem[i]); 
        
    }
    for(int i=0; i<1001; i++) cout<<A[i]<< " "<<iMem[i]<<endl;
    cout<<ans<<endl; 


 //Trace(7);
// Cách truy vết khác?. 

// ans là trổ đến giá, pos là trỏ đến index(1 cách nhìn, và 2 con trỏ này song song với nhau).
int pos = -1;

// Tìm giá trị max và vị trí của giá trị max đó 
for (int i = 0; i<1001; i++) {
    ans = max(ans, iMem[i]); // 
    if(ans == iMem[i]) {
        pos = i; // nếu ans thay đổi thì lưu vị trí của nó và i
        break; 
}
}
cout << ans<< endl;
cout<< pos<<endl; 
int first = pos, last = pos, sum = A[pos];

while(sum != ans) {
    --first; // Giả first
    sum += A[first];
}
cout << first<<" "<< last; //??? Tại sao nó lại cháy từ 999-1



}