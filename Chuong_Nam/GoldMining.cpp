#include<iostream>
#include<algorithm>
using namespace std;

int n, L1, L2;
int a[100000];
int res[100000];


//Max mà kết thúc tại k: Cách mình. 
int maxS(int k, int L1, int L2) {
    if (L1> k) return a[k];
    int max = a[k];  // Mỗi L sẽ sinh ra một max, và mình sẽ so sánh các max với nhau. 

    for (int L = L1; L <=L2; L++){
        int newS = 0;
        if (k < L)  continue;
        if (L2-L>=L1) 
        {
             newS =  a[k] + maxS(k-L,L1, L2-L);
        }else 
             newS = a[k] + a[k-L];

        if (newS> max)
                { 
                    max = newS;
                    cout<<" "<<max;
                }
    }
return max; 
}


Cách mình
int main(){

cin>>n>>L1>>L2;

for( int i = 0; i<n; i++){
    cin>> a[i];
}

int maxSumGold = 0;
 for(int k = 0; k<n; k++){
//     maxSumGold = max(maxSumGold,maxS(k,L1, L2)); 
    maxS(k ,L1, L2); 
    cout<< endl;

 }

// //cout<<" "<<maxSumGold<<endl; 

}

