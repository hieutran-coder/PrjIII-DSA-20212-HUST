#include<iostream>
using namespace std;

#include<stack>
///////////////////////////////////////////////////////////////
int Memory[1000]; 

int a[1000]; 

int MaxSubArrayHasLast(int a[], int i) {

    int S[i+1]; // có i +1 phần tử từ 0 đến i.  
    int res = 0;
    S[0] = 1;
    if (i = 0) return S[0]; // Basecase


// Lúc này kiểu gì thằng i cũng lớn hơn 0. 
    for(int j = 0; j<i; j++) {
        if( a[j]<=a[i])    // Chỉ lọc ra những dãy nhỏ hơn?. 
            if (Memory[j] != -1) {

                Memory[j] =  MaxSubArrayHasLast(a,j);
                res = max(res, Memory[j]); 
             }
    }

    if (res = 0) return 1; // Tức là ko có dãy nào, -00>  số này là số nhỏ nhất.
        else return res+1; 
}


int MaximumSubArray(int a[], int n) {

    int MaxSubArray = 0; 

    for (int i = 0; i<=n; i++) { // Nên từ 0 đến n hay từ 0 đến n-1?.  nếu đến n thì dãy phải có n+1 phần tử?. Nếu từ o đến n-1 thì nó cũng sẽ hơi lằng nhằng phần trên?. 
        MaxSubArray = max(MaxSubArray, MaxSubArrayHasLast(a,i)); 
    }

    return MaxSubArray; 

}

// Cách dùng 
void  traceBack1(int n) {

    cout<<a[n]<<" "; // Hiện thị phần tử thứ n


    if(Memory[n] == 1){ // Nếu mà dãy kết thúc tại n chỉ có chắc a[n], bằng 1 hay a[n]
        return; 
    }

    for (int i = n; i>=0; i-- ){
        if (Memory[i] == -1){ Memory[i] = MaxSubArrayHasLast(a,i);}

        if (Memory[n] == Memory[i] + 1) // Thiếu kiểm tra thằng thứ i có bé hơn thằng n trong mảng A không?. 
            cout<<a[i]<<" "; 
            traceBack1(i);
            break; 
    }
    // Nếu ko trace back được thằng nào thì sao?.
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cách thầy
int A[1001]; 
int iMem[1001]; // bộ nhớ

int LIS(int i) {

    if (iMem[i] != -1) return iMem[i];//Nếu phần tử thứ i đã được tính rồi return?. Mình quên bước này

    int res = 1;

    for (int j = 1; j < i; ++j){
        if (A[j] < A[i]){// xét max của tất cả các dãy bé hơn?. dãy lớn hơn thì bỏ qua
            res = max(res, 1 + LIS(j)); // Đây không được dùng break giống như trackback?.
        }
    }
    
    iMem[i] = res; // Lưu trũ giá trị đã tính vào bộ nhớ. 
    return res;

}

void Trace(int i) {
    int res = 1; 
    for (int j = 1; j<i; j++){
        if (A[j] < A[i] && iMem[i] == 1 + iMem[j]){ // Cái ở trên mình thiếu
            Trace(j);
            break;  // Cái kiểu truy vết này giống quay lui nhỉ?. nhưng j ko đi từ từ
        }
    }
    cout << i<< " ";
}




int main() {


    memset(iMem, -1, sizeof(iMem));  // Tại sao cần có tham số thứ 3

    for (int i = 0; i< 1001; i++)
                A[i] = 50- rand()%100;
    

    int ans = 0, pos = 0;
    int n = 500;



    LIS(n);  

    for (int i = 1; i<= n; i++){
        ans = max(ans, iMem[i]); // tìm max;

        if (ans == iMem[i]) pos = i; // xác định vị trí cuối cùng của dãy max?. Đây là vị trí của ans
    }
    cout << ans; 

// Truy vết bằng vòng lặp thì thầy sử dụng stack?.  Tại sao dùng stack lại được?. Tại sao những bài trên ko dùng stack mà bài này lại dùng stack?. 

stack<int> S; 




// ans là gì?. Là số phần tử của dãy lớn nhất?. 
// pos được dùng cho bây giờ
for(int i = pos, k = 0; k < ans; ++k) { // cái biểu thức đầu là khối lệnh
    S.push(i); // Đẩy i vào S

    // Với mỗi i ta sẽ tìm thằng preposition của nó. 
    for (int j = 1; j < i; ++j){
        if (A[j] < A[i] && iMem[j] +1 == iMem[i]){
            i = j; // Tìm được j rồi thì đẩy vào?. 
            break; // Tìm được rồi thì break vòng for để làm gì?--> Tương tự nhưtreen
        } 
    }
    while (!S.empty()){
        cout << S.top() << " "; // Trả về phần tử cuối cùng hay sao?. 
        S.pop(); // Nếu như thế thì dẫn tới stack rỗng?.
    }

}



}