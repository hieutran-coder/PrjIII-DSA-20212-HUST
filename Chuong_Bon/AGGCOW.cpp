#include<iostream>
#include<vector> 
using namespace std;

int T;
int N, C;

// Check xem Có tồn tại min ít nhất là k không?. 
// j
int   check(long long k, int C, const vector<long long>& x, int N){
    vector<long long > a(C, 0); 
    a[0] = x[0];  
    int i = 1,j = 1; // i là chỉ số của vị trí con bò, j là chỉ số của vị trí stall
    while (j < N&&i<C ){
        if (x[j]-a[i-1]>=k) {
            a[i] = x[j];

            i++; j++;
        }else{
            j++;
        }
    }
    cout <<"Giá trị số con bò nhập chuồng là : "<< i<<endl; 
    cout <<"VỊ trí của chúng là "<<endl;
    for(int z = 0; z<C; z++) {
        cout<<"Vị trí con bò thứ "<<z<<"là: "<<a[z]<<endl;
    }
    if (i == C) return 1;
        else return 0; 
}

int main() {
    
// freopen("input.inp","r", stdin);
// freopen("output.inp", "r", stdout);


cin>>T>>N>>C;
vector<long long> x(N, 0);
for (int i = 0; i<N; i++){
    cin >> x[i];
}
sort(x.begin(), x.end());



long long k_max = (long long)x[N-1]/(C-1); // Giới hạn giá trị của k_max
long long k_min = 0;
 

//cout<<check(1, C, x, N);

// //Cách 1 là nhị phân:
while (k_min < k_max){
    cout<<"Giá trị 2 cận là: "<<k_max<<" "<<k_min<<endl;
    long long  mid = (k_min + k_max)/2;
    if (k_max == k_min+1) break; 

    // tìm true lớn nhất.   
    if (check(mid, C, x, N)) { // min ít nhất là k
                k_min = mid; // k_mid = mid + 1 được ko?
    }else{
        k_max = mid -1; // Tại vì mid là false. 
        }
 }
//Cách 2 là duyệt từ dưới lên trên


cout<< k_min; 




}

