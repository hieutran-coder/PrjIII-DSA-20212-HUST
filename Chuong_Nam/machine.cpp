#include<iostream>
#include<algorithm>
using namespace std;

long long n;

struct period{
    long long s;
    long long t; 
    };


bool cmp(period p1, period p2){
    if (p1.s > p2.s) return false;
    else return true; 
}

int main() 
{

cin>> n;
long long  a[n+1];
period p[n+1]; 
a[0]=0;



// Khởi toạ p và a, cẩn thận quên sort
for (int i = 1; i <=n ; i++){
    cin>> p[i].s>> p[i].t ;// Với  t[i] và s[i] thì phải sort cả 2, còn p thì sort luôn p.
}

sort(p+1, p+n+1, cmp);  // Có 2 điểm cần phải để ý
for (int i = 1; i <=n ; i++){
    cout<<  p[i].s<<" "<< p[i].t<<endl ;
    a[i] = p[i].t-p[i].s;
}

for (int i = 1; i <=n ; i++){
    cout<<" "<<a[i];
}
cout<<endl;

long long res = a[1]; 

// Cập nhật a[i]:

// Chú ý là 
for (int i = 2; i<=n; i++){
    int j = i-1;

    // Tìm period tốt nhất
   // while (p[j].t> p[i].s&&j>0) j--; // Sai rồi  bởi vì j oke nhưng j-1 chưa chắc oke đâu 


    int max1 = 0;
    // Cái vòng for này  sẽ có nhiều j lặp đi lặp lại trùng lặp--> Có thể tối ưu viêcj xét không
    for (int j = 1; j<i; j++ ){
        if(p[j].t< p[i].s)
                 max1 = max((long long)max1, p[j].t-p[j].s);
    }

    cout<< max1<<"  ";
    a[i] += max1;
    cout<<i<<"  "<<a[i]<<" "<<max1<<endl;
    res = max(res, a[i]);
}
cout<<endl;
cout<<res<<endl;




}