// #include<iostream>
// #include<vector>
// using namespace std;

// int Pow(int x, int n){

//     if (n == 0) return 1;

//     if (n%2 != 0) return x* Pow(x, n-1); // với n lẻ

//     int res = Pow(x, n/2);
    
//     return res*res;

// }

// bool Binary_Search(const vector<int> &A, int lo, int hi, int x) {

//     if (lo > hi) return false;

//     int mid = (lo + hi)/2;

//     if (A[mid] == x) return true;

//     if (x < A[mid]) return Binary_Search(A, lo, mid-1, x);
//     else return Binary_Search(A, mid+1, hi, x);

// }


// bool p1(double j){}


// int main(){

// }


// #include<iostream>
// using namespace std;

// #include<vector>

// int N, F, T, r[10000];

// double S(int r) {
//     return (double)r*r*3.1459;
// }

// int check (double V, int *r, int N, int F){

//     int k = 0; 

//     double remain_pie;

//     for (int i = N-1; i>=0; i--){
//         remain_pie = S(r[i]);
        
//         while(remain_pie>V) {
//             remain_pie = remain_pie -V;
//             k++;
//             if (k == F+1) return 1;
//         }
//     }
// return 0;
// };


// int main() {

// cin >> T;

// while(T--) {

//     cin>>N>>F;
//     double V_max = 0, V_min = 0;

//     for(int i = 0; i<N; i++) {
//         cin >> r[i];
//         V_max += S(r[i]);
//     }
//     sort(r, r + N);

//     V_max = V_max/(F*1.0);

//     cout<<V_max<<endl;

//     double EPS = 0.000001, res;

//     while(V_max-V_min> 1e-6){
//         double mid = (V_max + V_min)/2;

//         if( check(mid, r, N, F)) {
//             V_min = mid;
//             res = mid;
//         }
//         else V_max = mid;
//     }

//     cout<<res;
// }

// }


#include<iostream>
#include<math.h>
#include<vector>
#include<iomanip>

using namespace std;
double res;
int n, p1, p2;

struct point {
    long long x, y;
    int id;
};

point a[1000100];


bool cmp_x(point a, point b) {
    return a.x < b.x;
}

bool cmp_x(point a, point b) {
    return a.x<b.x;
}

bool cmp_y(point a, point b){
    return a.y < b.y;
}

double dis(point a, point b) {
    return sqrt( (double)1LL*(a.x-b.x)*(a.x-b.x) + (double)1LL*(a.y-b.y)*(a.y-b.y));
}

void update(point a, point b) {
    double x = dis(a,b);

    if (x<res){
        res = x; p1 = a.id; p2 = b.id;
    }
}


void closest(int l, int r) {

    cout <<l <<" "<<r<<endl;
    if(l>=r) return;

    if (l + 1 == r){
        update(a[l],a[r]);
        return;
    }

    int mid = (l + r)/2;
    int mid_x = a[mid].x;

    closest(1, mid);
    closest(mid + 1, r);

    vector<point> v;

    for(int i = 1; i<=r; ++i) {
        if ( abs(a[i].x - mid_x)<= res){
            v.push_back(a[i]);
        }

    sort(v.begin(), v.end(), cmp_y); // Sắp xếp theo trục y

    double tmp = res;



    for (int i = 0; i<v.size(); ++i) {
    
            int j = i+1;
            while(j<v.size() && v[j].y - v[i].y <= tmp){
                update(v[i], v[j]);
                j++;
            }

}
 }

}
int main() {

    cin >> n;

    for (int i = 1; i<=n; ++i){
        cin >> a[i].x>>a[i].y;
        a[i].id = i;
    }

    sort(a+1, a+1+n, cmp_x);
    res = 1e9;
    closest(1,n);

    cout<< setprecision(6)<<fixed<<min(p1, p2)<<" "<<max(p1, p2)<<" "<<res<<endl;
}