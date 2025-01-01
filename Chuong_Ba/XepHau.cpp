#include<iostream>

using namespace std;

static int  count1 = 0; 
void hienThi(int a[], int n) {
    count1 = count1 + 1;
    for(int i = 1; i<=n; i++){
        cout<<a[i]; 
    }
    cout<<endl; 
}

int n = 5; 



int iRes[100]; // Vị trí của các quân hậu nên n cột

// 1 tức là đường chéo đó ổn, 0 tức là đã có hậu nắm giữu?. 
int bDiag1[100]; // Sử dụng biến bool tiết kiệm bộ nhớ hơn biến int?. 
int bDiag2[100];
// 1 tức là cột đó ổn?. 0 tức là có quân hậu trên cột đó?. 
int bCol[100];
void Try(int i) { // Xét hàng i
    for(int j = 0; j <= n-1; j++){ // xét cột 1 đến cột n hay vị trí (i,1); (i,2 )--->i,n)
        if(bCol[j]&& bDiag1[i+j] && bDiag2[i-j+n]) {// nếu vị trí mới này : không có con hậu nào trên cùng cột nàyj
        // Không có vị trí trên đường chéo 
            iRes[i] = j; // Chấp nhân ứng cử viên j;

            // Cập nhật các trạng thái mới; false; tức không đi được?. 
            bCol[j] = 0;
            bDiag1[i+j] = 0;
            bDiag2[i-j+n] = 0;
            
            // Kiểm tra đã đến hàng thứ n chưa
            if (i == n) hienThi(iRes, n);
            else Try(i+1);

            // Đi sang 1 nhánh khác khác nhánh j rồi
            // set up lại trạng thái
            bCol[j] = 1;
            bDiag1[j + i] = 1;
            bDiag2[i - j+n] = 1; 
        }
    }  
}

int main() {


    for (int i =0; i<=99; i++){
        bDiag1[i] = 1; 
        bDiag2[i] = 1;
        bCol[i] = 1; 

    }
    Try(1);
     
    cout<< "Số giá trị print là " << count1; 
}