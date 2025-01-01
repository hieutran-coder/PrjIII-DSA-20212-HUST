#include<iostream>
using namespace std;

int iDist[1001][1001];


int Weight[1001][1001];






int main() {
int n = 10;

for(int i = 0; i<=n; i++)
    for(int j = 0; j<=n; j++){
        Weight[i][j]= rand()%250;
        cout<<"\n Trong luong tai canh " <<i<<" "<<j<< "la "<<Weight[i][j];
    }
// Ta sẽ khởi tạo các giá trị cho iDist
// Ddaay la do thi co huong sao?. 
for (int i = 0; i<=n; i++)
    for (int j = 0; j<=n; j++){
        iDist[i][j] = (i==j)? 0: Weight[i][j];
    }

for (int k = 0; k<=n; ++k){
    for (int i = 0; i<=n; ++i){
        for (int j = 0; j<=n; j++){
           
            iDist[i][j] = min(iDist[i][j], iDist[i][k] + iDist[k][j]); 
            // iDist[i][j],iDist[i][k]...  trong hàm min nó là khoảng cách cũ từ thời điểm k-1?.  
        }
    }
}

for(int i = 0; i<=n; i++)
    for(int j = 0; j<=n; j++)
        cout<<"\n Khoang cach ngan nhat di tu " <<i<<" toi "<< j<<" la "<<iDist[i][j]<<endl;

}