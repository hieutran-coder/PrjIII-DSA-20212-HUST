#include<iostream> 
#include<vector> 
using namespace std;

int a[100000];

int n, L1, L2; 
// Nên dùng vector động hay mảng tĩnh?
vector<int> sol; // lưu các chỉ số hay lưu lượng vàng--> Lưu chỉ số
bool marked[100000];

// Có cần làm thêm hàm check nữa không, hay để hàm check trong này
// Có cần dùng cấu trúc để lưu id không?. 

void backTrack(int k){ // chọn a[i] đặt vào vị trí thứ k của sol
    
// Sẽ chọn gold theo thứ tự từ trái phải của trên toạ độ. 
        // nếu đăt vào vị trí i thì phải có chỉ số lớn hơn vị trí trước đó. --> Có cần lưu chỉ số không?.  Có


int sl = 0; // kiểm tra số lượng UCV không được chọn, nếu bằng n thì sẽ dừng lại.
for (int i = 0; i<n; i++){ // Có n UCV cho vị trí thứ k
    if (marked[i] == false && i-sol[k-2]>=L1&& i-sol[0]<=L2){
                marked[i] = true;
                sol.push_back(i);

                // Nến đã chọn tối đa là n
                if (k == n){  
                    for(int j = 0; j<sol.size(); j++) {
                        cout <<" "<<j;
                    }
                    cout <<endl;
                } else  backTrack(k+1); // Ta không biết độ dài của xâu sol thì sẽ phải làm gì đây, tức là không biết khi nào nó dừng.
                                                // 2 cách, cứ cho nó chạy đến hết, và khởi tạo là là 0. Hoặc ...
                
                marked[i] = false;
                sol.pop_back(); // câu lệnh này đúng không. --> Đây là điểm ko ổn của vector động so với tĩnh. 
    } else// vẫn ko chạy vào backtrack(k+1)
        sl++; // Liệu nó có nhầm với sl bên trong khi đệ quy ko không??.

}

if (sl == n) {// Nhánh này không triển được nữa.
    for (int i = 0; i <sol.size();i++){
        cout<<" "<<i; 
    }
    cout<<endl;
}


}

int main() {

cin>>n>>L1>>L2;

for (int i = 0; i<n; i++){
    cin >>a[i];
}
sort(a, a+n);
memset(marked, false, n);

for (int i = 0; i<n; i++){
    sol[0] = i;
    backTrack(2);
}

}