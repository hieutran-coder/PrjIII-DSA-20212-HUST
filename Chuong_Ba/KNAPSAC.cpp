#include<iostream>
#include<vector>
using namespace std; // std la thu vien co ban



int n, b,res; // b la tui
int a[50], c[50], x[50];

// Quay lui không nhánh cận
// Chú ý code này không theo mô hình của slide
void attempt(int t){

    // Xét trường hợp chạy hết số lượng hay sao?. vậy nếu chỉ đựng được vài vật thì làm sao nó kết thúc?
    
     if(t>n){ // Tại sao Dũng phải xét đến khi t chạy vượt quá n mà không là t == n?
     // Nếu đổi lại biểu thức điều kiện  thành t ==n thì cái đồ vật  chọn hay không chọn ta vẫn chưa làm--> phải là t>n
        int suma = 0;
        int sumc = 0;

        for (int i = 1; i <=n; ++i){
                if (x[i] == 1){
                    suma +=a[i];
                    sumc += c[i];
                }
            cout<< x[i] << " ";
        }
        cout << suma << " "<< sumc <<endl;

        if (suma<=b)
            {
                res = max(res, sumc); // Rest nó sẽ lấy max của sumc, nhưng là trong trường trương hợp balo chứa được
                                      // Trong trường hợp ballo không chứa được thì nó không lấy 
            }

        return; // nếu không có lệnh này thì nó sẽ chạy xuống tiếp xét trường hợp chọn hay không chọn cho phần tử n+1
     }

/// VCL thế mang tính duyệt toàn bộ rồi. 
/// Kiểu một nhánh biết kiểu chi cũng không được vẫn đi vào. 
// Không chọn t hay sao?.
    cout << t << " 0"<< endl; // 0 là giá trị x[t]
    x[t] = 0;
    attempt(t+1); 

// chọn t hay sao?. 
    cout << t<< " 1" << endl;
    x[t] = 1;
    attempt(t+1);

}

// Quay lui nhánh cận 
// Nếu không có cận thì dùng cách này có được không?. 
void attempt1(int t, int suma, int sumc) {


    if (suma> b) return; // Đây là điều kiện nhánh cận. 
        // Có bạn hỏi ở đây có thể suma = b không?. Xác xuất này rất thấp.
        // Tại sao không phải suma + a[t] --> Nó đã cộng vào trong tham số rồi


    if (t>n){   // Bỏ đi vòng for
     //   if (suma <= b){
        res = max(res, sumc);
     //   }
        return;
    }



// PHần chính của chương trình
    //x[t] = 0; ko dùng x[t] nữa
    attempt1(t+1, suma, sumc); // Không dùng đồ vật thứ t, và chắc chắn sẽ không vượt túi b

    attempt1(t+1, suma + a[t], sumc + c[t]); 
    // Điểm mới là Dũng không cộng ở ngoài mà Dũng cộng vào trong tham số khi đệ quy luôn
    // Có lợi ích là đỡ phải thiết lập lại trạng thái ban đầu của cấu trúc dữ liệu phải không?. 






}



















int main() {

    cin >> n>> b;

    for (int i = 1; i<=n; ++i)
        cin>> a[i]>> c[i];  // a va c chac can nang va gia tri

    res = 0;
    attempt(1); 
    cout<< res<<endl;
}