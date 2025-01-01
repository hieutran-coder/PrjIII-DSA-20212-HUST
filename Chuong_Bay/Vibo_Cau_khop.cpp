#include<iostream>
#include<vector>
using namespace std;

#define task "GRAPH."
#define x first
#define y second

const int maxn = 1e5 + 10;


// Variables cnt_bridge, cnt_articulation count khớp và cầu

int n,m, time_dfs, cnt_bridge, cnt_articulation, low[maxn], number[maxn];
int is_articulation[maxn], cnt_child[maxn], par[maxn];
vector<int> adj[maxn];

void enter() {
    cin >> n>> m; // Tại sao phải nhập cả 2

    for (int i = 1; i<=m; ++i){
        int u, v;
        cin >> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u)
{

    low[u] = number[u] = ++time_dfs;

    for (int v: adj[u])
    {
        if (v == par[u]) // Nếu v là cha của u thì bỏ qua
            continue;
    
        if (!number[v]) // Nếu đỉnh v chưa được thăm
        {
            par[v] = u;  // u là cha của v;
            ++cnt_child[u]; // tính số lượng nhánh con của u

            dfs(v);

            low[u] = min(low[u], low[v]); // Cập nhật low[u];

            if (low[u] == number[v]) ++ cnt_bridge; // (u,v) là cầu

            // Tại sao biết u là chốt, và tại sao biết u có nhiều hơn 1 nhánh con?
            if (par[u] == -1)  // Có nghĩa u không có cha hay sao???--> Vô lý đỉnh nào chả có cha
            {
                if (cnt_child[u] >=2)
                    is_articulation[u] = 1; // đánh dấu u là khớp
            }
            else
                low[u] = min(low[u], number[v]);
            }
        }

    }


void solution()
{
    fill(par + 1, par + 1 + n, -1);

    for(int u = 1; u<=n; ++u)
        if (!number[u]) dfs(u); // nếu chưa duyệt u thì dfs u, tránh trường hợp đồ thiij không liên thông

    
    for (int u = 1; u<=n; ++u)
        cnt_articulation += is_articulation[u];

    cout << cnt_articulation << ' ' << cnt_bridge;

}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    enter(); solution();


} // tác giả dngf chắc main chả cần int