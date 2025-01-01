#include<iostream>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;
double res;
int n,p1,p2;

// Dũng dùng Struct
struct point{
     long long  x, y;
     int id;  // điểm mới ở đây là có thêm cái id của từng điểm 

};
point a[1000100]; // Vãi trong C++ không cần dùng typedef luôn. 

// Sắp xếp theo trục x
bool cmp_x(point a, point b) {
    return a.x<b.x;
}

// Sắp xếp theo trục y
bool cmp_y(point a, point b){
    return a.y <b.y;
}

double dis(point a, point b) {
    return sqrt( (double)1LL* (a.x-b.x)*(a.x-b.x) + (double)1LL*(a.y-b.y)*(a.y-b.y));  // Phép nhân có thể tràn số
}
void update(point a, point b) {
    double x = dis(a,b);  

    if (x<res) {  // cập nhật res à
        res = x;

        // Phải lưu lại các 2 điểm?. 
       p1 = a.id;
        p2 = b.id;
    }
}
void closest(int l, int r) {
    // Trường hợp số lượng điểm ít
    cout<<l<<" "<<r<<endl;
    if (l>=r) return;
    if (l +1 == r){
        update(a[l], a[r]);
        return;
    }

    int mid = (l+r)/2;
    int mid_x = a[mid].x;

    closest(1,mid); // Tìm bên trái
    closest(mid+1, r); // Tìm bên phải.

    vector<point> v;
    for (int i =1; i<=r; ++i) 
        if (abs(a[i].x-mid_x)<=res){
            v.push_back(a[i]);
        }
    sort(v.begin(), v.end(), cmp_y);


    double tmp = res;
    for (int i = 0; i<v.size(); ++i) { // Xét từ dưới lên trên
        int j = i+1; // Chỉ lấy các đoạn từ dưới lên trên thôi sao, ko lấy nhảy cóc hay sao?. 
        while(j<v.size() && v[j].y-v[i].y <= tmp) { // Tại sao đây lại dùng vòng while và tại sao lại có điều kiện này
            update(v[i], v[j]); 
            j++;
        }
    }
}



int main() {

    cin>>n;
    for (int i = 1; i<=n; ++i){
        cin >> a[i].x>>a[i].y;
        a[i].id = i;
    }

    sort(a+1, a+1+n, cmp_x);
    res = 1e9;
    closest(1,n);
    cout<< setprecision(6)<<fixed<<min(p1,p2)<<" "<<max(p1,p2)<<" "<<res<<endl;
    //cout<<min(p1,p2)<<" "<<max(p1,p2)<<" "<<res<<endl;
}