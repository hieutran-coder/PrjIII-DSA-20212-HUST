// Cách bạn Dương làm

#include<iostream>
using namespace std;
int main() {
    int n, l1, l2;
    cin >> n>> l1 >> l2;
    int a[n], res[n], max_s;

    for (int i = 0; i<n; ++i)
        cin >> a[i];

    for (int i = 0; i< l1; ++i){
        res[i] = a[i];  // Đù res chắc là bộ nhớ đây, khởi tạo res ở đoạn này
    }

    max_s = res[0];

    // Không dùng hàm riêng luôn
    for (int i =l1; i <n; i++){
        res[i] = a[i];  

        // Xét với vị trí thứ i thì cập nhật ngược lại
        for (int j = i-l1; j>= i - l2; --j){  
            if (j < 0) break;
            res[i] = min (res[i], a[i] + res[j]); // cập nhật res[i]
        }

        // cout << res[i] << endl;
        max_s = max(max_s, res[i]);

    }
    cout<< max_s; 

}