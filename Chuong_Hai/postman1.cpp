#include<iostream>
using namespace std;
#include<vector>
#include<utility>


int n,k;
vector< pair<int,int> > neg,pos; 

bool com(pair<int, int> x, pair<int, int> y) {
    if (x.first<y.first) return true; // Vậy trường hợp lớn hơn
    if(x.first> y.first) return false; 


    if(x.second<y.second) return true; 
    return false;
}


void solve(vector<pair<int, int>> v){

}

// Đề bài toán  là mỗi lần chỉ vận chuyển tối đa 2 kiện hàng hay sao?.
            // Vậy nếu só hàng chẵn thì số lần chuyển bằng số hàng chia đôi.
            // Số hàng lẻ thì lấy phần nguyên, còn thừa 1 hàng chuyền lại điểm gần nhất với nóv[i-1]
    // Vậy cần 1 cấu trúc để lưu số lần cần chuyển tại các điểm v[1], v[2]... v[v.size-1]--> Cập nhập dần vector này.
                                                        
void solve1(vector<pair<int, int> > v){
    
    // sort lại toạn bồ phần tử
    // thứ tự mặc định của sort là tăng dần.
    // Ưu tiên so sánh first ở bên trái, nếu first bằng nhau thì so sánh second. 
    // Nếu muốn sắp xếp giảm dần tự xây dựng một hàm?
            // Hàm có tham số có kiểu dữ liệu đúng với kiểu dữ liệu của các đối tượng muốn sắp xếp
                    // Hàm này hoạt động như thế nào?. Làm sao biết thằng nào đứng trước, thằng nào đứng sau.
                                //Thằng thứ nhất đứng trước <---> Trả ra true
                                // Thằng thứ hai đứng trước <---> Trả ra false/. 
    sort(v.begin(), v.end()); // 3 tham số là Địa chỉ đầu, địa chỉ cuối và hàm so sánh. 

    int sz = v.size();
    int lef = 0;
    long long res = 0;  // res
    for(int i = sz-1; i>=0; --i) {


        int x = v[i].first;
        int m = v[i].second;


        // Lef có thể thừa từ vòng lặp lần i+1 hay lần gần nhất
        if(lef != 0) {
            if(left>=m){
                lef-=m;
                continue; // Không chạy xuống dưới
            }
            m -= lef; 
        }

        // số lần phải đi là bao nhiêu?.
        int t = m/k;
        // Trong trường hợp dư một lượng hàng bé thua k thì phải đi thêm 1 lần nữa.
        // Cũng có thể gọi là trần của t
        if (m%k != 0) t++;

        //res += t*x*2; // Độ dài quãng đưỡng cả đi và cả về
        //--> Cái cách nhân này thì có thể vượt quá int--> GIải pháp là thêm 1LL để ép kiểu thành longlong
        res += 1LL*t*x*2; // ép kiểu phép nhân này thành phép nhân kiểu longlong.
        // Cách khác là khai báo t và x thành long long.
       
        lef = t*k -m; // phần thừa
    }
    return res; 


}






int main() {
   // vector<int, int> neg, pos;  sai

    cin >> n>> k;

// Có n bộ . 
    for (int i = 1; i<=n; ++i){
            int x,m;
            cin >>x >>m; // vị trí và số hàng cần chuyển. Các toạ độ có thể rời rạc nhau?. 
                        // Cần hàm sort để sort dữ liệu.

            if (x<0) neg.push_back(make_pair(-x,m)); // chung 1 hàm để xử lý phần âm và phần dương
            if (x>0) pos.push_back(make_pair(x,m));
    }

    // xử lý phần riêng biệt
    cout<< solve(neg)+solve(pos);




}