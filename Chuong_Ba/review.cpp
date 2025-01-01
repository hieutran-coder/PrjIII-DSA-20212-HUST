// #include<iostream>

// using namespace std;

// #include<vector>
// #include<queue>

// queue<int> q; //?để làm gì
// int n, m;
// int const N = 100; 

// vector<int> a[N]; // Có N vector???

// bool mark[N];
// int val[N];

// int main() {

//     freopen("bfs.inp", "r", stdin);
//     freopen("bfs1.out", "w", stdout);

//     cin >> n>> m;

// // Sử dụng cấu trúc tập đỉnh kề??
//     for (int i = 1; i<=m; ++i){
//         int x, y;
//         cin >>x>>y; // 1 canh
//         a[x].push_back(y);
//         a[y].push_back(x);
//     }

//     memset(mark, true, sizeof(mark));
//     memset(val, 0, sizeof(val));

//     mark[1] = false;
//     val[1] = 0;
//     q.push(1);

//     while(!q.empty() ) {
//         int x = q.front();
//         q.pop();
//         cout <<"______"<<x<<" "<< val[x]<<endl;



//         for (int i = 0; i<a[x].size(); i++){ // Xét tập đỉnh kề x
//             int y = a[x][i];

//             if (mark[y] == true){
//                 mark[y] = false;
//                 val[y] = val[x] + 1;
//                 cout<<"**"<< y<<" "<< mark[y] << " " << val[y]<<endl; 
//                 q.push(y);
//             }
//         }

//     }

//     // Output
//     for (int i = 1; i<=n; i++){
//         cout <<i<<" "<< val[i]<<endl;
//     }
// }

// #include<iostream>

// using namespace std;


// static int count1 = 0;

// void hienThi(int a[], int n) {
  
//     count1 = count1 + 1;

//     for(int i = 0; i<n; i++) {
//         cout <<' '<<a[i];
//     }
//     cout <<endl;
// }

// int n = 5;
// int m = 20;
// int x[6];
// int z;
// int f = 0;

// void Try(int k ) {
    
//     if (k == n){
//         x[k] = m-f;
//         hienThi(x, n+1);
//     }else {
//     z = 15- f + k;

//     for (int v = 1; v <= z; v = v+1){
//         x[k] = v; 
//         f = f+ v;
//         Try(k +1);
//         f = f-v;
//     }
//     }
// }

// int main() {
//     x[0] = 0;
//     Try(1);
//     cout <<"Số gía trị print là "<< count1;
// }


#include<iostream>
using namespace std;


const int N = 100;
int n, Q;

bool visited[N];

int load;

double d[N][N];
double f, dmin, f_best;
int x[N];

void input() {

    freopen("bus_demo.inp", "r", stdin);
    cin >> n>> Q;

    for (int i = 0; i<= 2*n; i++)
        for (int j = 0; j<=2*n; j++){
            cin >> d[i][j];
            if (i != j && d[i][j]<dmin) dmin = d[i][j];
        }
}

bool check(int v, int k){
    if (visited[v]) return false;

    // điểm đón---> Đã duyệt hết trường hợp chưa
    if ( v<=n ){
        if (load >= Q) return false;
    } else{
        if (!visited[v-n]) return false;
    }

return true;
}

void updateBest() {

    if (f + d[x[2*n]][x[0]] <f_best){
        f_best = f + d[x[2*n]][x[0]];
        cout <<"update best"<< f_best<<endl;
    }
}

void Try(int k) {

    for (int v = 1; v <= 2*n; v++){
        if (check(v,k)) {
            x[k] = v;
            visited[v] = true;

            f = f + d[x[k-1]][x[k]];

            if ( v<= n) load += 1; else load -= 1;

            if (k == 2*n ) updateBest();
            else {
                if (f + dmin*(2*n +1-k) <f_best) Try(k+1);
            }

        if (v<=n) load -=1; else load +=1;
        visited[v] = false;
        f = f - d[x[k-1]][x[k]];

        }

    }

}

int main() {

    input();

// khởi tạo
    for (int v = 1; v<= 2*n; v++) visited[v] = false;
    f = 0; load = 0;
    f_best = 1e9; x[0] = 0;
    
    
     Try(1);
}







