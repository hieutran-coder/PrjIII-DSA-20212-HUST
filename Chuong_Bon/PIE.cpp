#include<iostream>
using namespace std;
#include<vector>

int N, F,T;
int r[10000];

double S(int r) {
    return (double) r*r*3.14159265359; // PI không lấy đủ chữ số là điểm sai thứ hai. 
}

int check(double V, int *r, int N,int F){
    int k=0; // biến tích luỹ số người 
    double remain_pie;
    cout<<"--------------------"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Kích cỡ piece cần cắt là: "<<V<<endl;
    for (int i = N-1; i>=0;i--){ // Từ cái bánh to nhất đến cái bánh nhỏ nhất: Tham lam
         remain_pie = S(r[i]);
         cout<<"Volume của chiếc bánh thứ "<<i<<"Là: "<<remain_pie<<endl;
        while(remain_pie>V){
            remain_pie = remain_pie-V;
           cout<<"Volume của bánh sau khi cắt là: "<< remain_pie <<endl;
            k++; // tăng số người có bánh lên
            cout<<"Giá trị của k là:"<<k<<endl;
            if(k==F+1) return 1;  // F là điểm sai đầu tiên
        }
    }

return 0;
};



int main() {
  
// freopen("input.inp","r",stdin);
// freopen("output.inp","w",stdout);

cin>>T;
while(T--){
    cin>>N>>F;
    double V_max = 0, V_min = 0;
    for(int i = 0; i<N; i++) {
        cin>>r[i];
        V_max += S(r[i]);
    }
    sort(r,r+N);

    V_max = V_max/(F*1.0);
    cout<<V_max<<endl;
   // cout<< check(V_max,r,N,F);

// Binary search
    double EPS = 0.000001; // Có phải theo sai số này không
    double res; 
    while(V_max-V_min>1e-6) {
        double mid = ( V_max + V_min)/2;
        
        if(check(mid, r, N,F)){
            V_min = mid;
            res = mid;
            }
        else V_max = mid; 
    }

    cout<<res;
}



}