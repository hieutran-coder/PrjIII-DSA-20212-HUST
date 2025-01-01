#include<iostream>

#include<stack>
using namespace std;
int iMem[1000][1000];
int X[1000], Y[1000];

int LCS(int i, int j) {

    // Base case
    if (i==0||j==0) return 0;


    /// Kiểm tra memory// Có cần gán giá trị 0 cho tất cả memory[i][0] và memory[0][i] không?. 
    if(iMem[i][j] != -1) return iMem[i][j];
    //    if(X[i] ==Y[i]) 
    //         {
    //             iMem[i-1][j-1] = LCS(i-1, j-1);
    //             return 1+ iMem[i-1][j-1];
    //         } else{
    //             iMem[i][j-1] = LCS(i,j-1);
    //             iMem[i-1][j] = LCS(i-1, j); // Có cần lưu trữ giá trị thứ 3 vào bộ nhớ hay trong quá trình gọi hai lệnh trên thì đã lưu vào bộ nhớ rồi.
    //             return max(iMem[i][j-1], iMem[i-1][j]);
    //         }
    // }

    // Ccode thay
    int res = 0;
    res = max(res, LCS(i, j-1));
    res = max(res, LCS(i-1, j));

    if(X[i] == Y[j]){
        res = max(res, 1 + LCS(i-1,j-1));
    }

    iMem[i][j] = res; // rõ ràng lưu ở cuối cùng thì đỡ mất công hơn nhiều.
    return res; 
}






// trace Back bằng đệ quy
void traceBack(int i, int j){

    // Làm sao biết nó đi theo đường nào?. Lời giải này sai ở đâu?
    // if(iMem[i][j] == iMem[i][j-1]) traceBack(i,j-1);
    // else if(iMem[i][j] == iMem[i-1][j]) trackBack(i,j-1);
    // else trackBack(i-1, j-1); 






    // Cách thầy: Dùng 3 if, với hướng traceback thứ 3 thầy kiểm tra x[i] có bằng x[j] không
    // Bài trước có kiểm tra exp (A[i] <A[j]), bài này không có kiểm tra na ná như thế nhỉ?
    if (i == 0||j == 0) return;

    if (iMem[i][j] == iMem[i-1][j]){
        traceBack(i-1,j);
        
        return;
    }

    if (iMem[i][j] == iMem[i][j-1]){
        traceBack(i, j-1);
        return;
    }



// Tại sao lại có điều kiện X[i] = X[j] nếu bỏ đi thì sao?. 
// Nếu đảo vị trí của khối lệnh này lên trên các khối lệnh khác thì sao?
    if (X[i] == X[j] && iMem[i][j] == 1 + iMem[i-1][j-1]){
        traceBack(i-1, j-1);
        //cout << A[i] << " "; Lệnh quái gì đây?. 
        cout<<X[i]; // chỉ trong trường hợp này mới count, còn trong các trường hợp kia ko có phần tử nào chung?. 
        return; 
    }
    // Nên cout các bộ chỉ số hay là cout giá trị của bộ đó?. Cout chỉ số thì ko biết số đó là gì?. 


}














int main() {

    memset(iMem, -1, sizeof(iMem)); 
    int n, m;

    cin >> n>>m; 

    // Truy vết bằng vòng lặp?

    for (int i = 0; i<= m; i++)
                X[i] = 50- rand()%100;
    for (int i = 0; i<= n; i++)
                Y[i] = 50- rand()%99;

    LCS(n, m); 

    int ans = iMem[n][m];

    cout<< ans<<endl;




    stack<int> S;

    for(int i = n, j = m, k = 0; k<ans; ++k) {

        // Thầy kiểm tra điều kiện 3 đầu tiên, tại sao nhỉ?. 
            if (X[i] == Y[j] && iMem[i][j] == 1+ iMem[i-1][j-1]){
                S.push(X[i]);
                --i, --j;
                 continue; //bỏ qua lần kiểm tra sau?
            }

            if (iMem[i][j] == 1+ iMem[i-1][j]) {
                --i;
                continue;
            }
            
            if (iMem[i][j] == 1 + iMem[i][j-1]){
                --j;
                continue; 
            }
            
        }  

    while(!S.empty()) {
        cout << S.top() << " ";// Tại sao thầy lại ghi cout S.Back?. 
        S.pop(); 
    }    
            

    return 0; 
    }



