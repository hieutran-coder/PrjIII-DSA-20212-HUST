#include<iostream>
using namespace std;
#include<vector>


// Đù đầu vào bây giờ là tham chiếu của 1 vector, còn hôm trước mình là 1 dãy)
// Thên const vào để lmaf gì?. Đe
    bool Binary_Search(const vector<int> &A, int lo, int hi, int x) {
        if (lo> hi)  // Tại sao ở đây người ta lại xét trường hộp low lớn hơn high
            return false; // Firrst Basecase
        
        int mid = (lo+hi)/2;
        
        if (A[mid] == x) return true; //Second Base Case
        
        if (x < A[mid])
            return Binary_Search(A, lo, mid -1, x); // trong trường hợp không có số nào thì đệ quy sẽ về trường hợp lo>hi
        // Bài này sẽ có khoảng bao nhiên lần gọi đến hàm Bianry_Search này?.
        //Tại sao decrease nhưng cuôi cùng vẫn O(Log(n))---> Vì mỗi lần gọi có có hằng số lệnh và log(n) lần gọi
        // Dãy thứ k  trong quá trình đệ quy sang dãy k+1 có giống cách mà lần đầu dãy biến đối không?.--> Có lần nào cũng làm tương tự.tự
    }
int main() {

    vector<int> a;

    a.push_back(10);
    a.push_back(-5);
    a.push_back(10);
    a.push_back(20);

    cout<< Binary_Search(a, 0, 4,10);

}


// Tại sao thầy lại ánh xạ tập chỉ số sang tập true false?. false 1 bên và true một bên?.
    //---> Tại sao và điều này có ứng dụng gì?. Có thể giải thĩch bằng ngôn từ khôg?. 
int x = 10, A[10] = {1,2,3,4,3,6,1,8,9,1};

bool p(int i) { 
    return A[i]>=x; // Thì những vị trí mà lớn hơn x thì trả true, vị trí nhị rhown x thì trả false?. 
}

// --> V
bool p1(double j){

}




int main() {

   int  n = 7;
   int lo = 0, hi = n - 1;
   
//////////////// SỐ NGUYÊN 
// Hàm đánh giá xem giá trị thứ i có lớn hơn hoặc bằng x hay khôg?. Đầu vào bình thường là A[i] nhưgn đây là i.
 
     //   Thầy dùng vòng while. 
        while(lo< hi) { // QUay vòng cho đến khi lo> hi hoặc lo bằng hi
        int mid = (lo+hi)/2; // chỉ số mid dang giảm dần?. 
        if (p(mid)) {
            hi = mid; // nếu giả trị mid vẫn trưe thì duyệt từ lo đến mid
        } else {
            lo = mid + 1; // duyệt từ mid+1 đến ho
        }
       
        }

    // Tại sao cần kiểm tra cả exp thứ 2
     if (lo == hi && p(lo) ){ // nếu lo bằng hi và giá trị ở lo thoải mãn lớn hơn hoặc bằng x thì hiển thị
            cout<<"first found mindex is"<<lo; 
        }else{
            // Một là lo>hi hoặc (giá trị tại vị trí lo nhỏ hơn x; --> Dự đoán trong trường hợp toàn bộ đều false, hay x lớn hơn tất cả A[i]);
            // Trong quá trình giảm ít nhất phải tồn tại 1 thằng true chứ?. 
        
            cout<<" Không tồn tại phần tử"<< x; 
        }



/////////////////// SỐ THỰC
double EPS = 1e-10, 
        lo = -1000.0,
        hi = 1000.0;
// Vậy giữa lo và hi có bao nhiêu số, mid là số thực thì làm sao index được?. Với index thực thì tính như thế nào?. 
    while(hi - lo > EPS){ // HƠn nữa biết đén bao giờ mới thoát ra khỏi vòng lặp này?. O((hi-lo)/EPS))
        double mid = (lo + hi) /2 ;

        if (p(mid)) { // mid real thì tính như thế nào đây?. Có thể tạo dãy real không?. 
            hi = mid; // Tại sao không phải mid + 1???. 
        } else{
            lo = mid; 
        }





}



// // code force
// float l = 0.0f, r = 1e14f;

// for(int i = 0; i < iteration_count && 1 + eps < r; ++i){
//     float mid = 0.5f * (1+r); // chia đôi

//     if ( check(mid))
//         r = mid;
//     else 
//         l = mid; 
// }