//#include <iostream>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//const int MAXN = 1e5 + 10; 
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt;
//
//int n, k;
//int C[MAXN][25]; 
//int weight[MAXN];
//
//void init(int n) {
//    cnt = 1;
//    memset(head, 0, sizeof(int) * (n + 5));
//    for (int i = 0; i <= n + 2; ++i) {
//        weight[i] = 0;
//        for (int j = 0; j <= 22; ++j)
//            C[i][j] = 0;
//    }
//}
//
//void add(int u, int v) {
//    nxt[cnt] = head[u];
//    to[cnt] = v;
//    head[u] = cnt++;
//}
//
//void dfs1(int u, int fa) {
//    for (int j = 0; j <= k; ++j) 
//        C[u][j] = weight[u];
//    
//    for (int i = head[u]; i; i = nxt[i]) {
//        int v = to[i];
//        if (v != fa) {
//            dfs1(v, u);
//            for (int j = 1; j <= k; ++j) 
//                C[u][j] += C[v][j - 1];
//            
//        }
//    }
//}
//
//void dfs2(int u, int fa) {
//    for (int i = head[u]; i; i = nxt[i]) {
//        int v = to[i];
//        if (v != fa) {
//
//            for (int j = k; j >= 1; --j) {
//                if (j >= 2) 
//                    C[v][j] += (C[u][j - 1] - C[v][j - 2]);
//                else 
//                    C[v][j] += C[u][j - 1];
//                
//            }
//            dfs2(v, u);
//        }
//    }
//}
//
//void solve() {
//    cin >> n >> k;
//    init(n);
//
//    for (int i = 1; i < n; ++i) {
//        int u, v;
//        cin >> u >> v;
//        add(u, v);
//        add(v, u);
//    }
//
//    for (int i = 1; i <= n; ++i)
//        cin >> weight[i];
//
//    dfs1(1, 0);
//    dfs2(1, 0);
//
//    for (int i = 1; i <= n; ++i)
//        cout << C[i][k] << "\n";
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    solve();
//
//    return 0;
//}