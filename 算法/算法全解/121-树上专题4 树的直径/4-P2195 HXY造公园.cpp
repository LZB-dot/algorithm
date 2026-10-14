//#include<iostream>
//#include<cstring> 
//#include<algorithm> 
//using namespace std;
//
//const int MAXN = 300005;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt;
//
//int n, m, k;
//int father[MAXN];
//int dist[MAXN];
//int diameter[MAXN];
//
//void init() {
//    memset(head, 0, sizeof(head));
//    memset(dist, 0, sizeof(dist));
//    memset(diameter, 0, sizeof(diameter));
//    for (int i = 1; i <= n; ++i)
//        father[i] = i;
//    cnt = 1;
//}
//
//void add(int u, int v) {
//    nxt[cnt] = head[u];
//    to[cnt] = v;
//    head[u] = cnt++;
//}
//
//int find(int u) {
//    if (father[u] != u)
//        father[u] = find(father[u]);
//    return father[u];
//}
//
//void unite(int u, int v) {
//    int fu = find(u);
//    int fv = find(v);
//    if (fu != fv) {
//        int p = (diameter[fu] + 1) / 2 + (diameter[fv] + 1) / 2 + 1;
//        diameter[fv] = max({ diameter[fu], diameter[fv], p });
//        father[fu] = fv;
//    }
//}
//
//void dfs(int u, int fa) {
//    for (int i = head[u]; i; i = nxt[i]) {
//        int v = to[i];
//        if (v != fa) {
//            dfs(v, u);
//
//            diameter[u] = max(diameter[u], max(diameter[v], dist[u] + dist[v] + 1));
//            dist[u] = max(dist[u], dist[v] + 1);
//        }
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> m >> k;
//    init();
//
//    for (int i = 1; i <= m; ++i) {
//        int u, v;
//        cin >> u >> v;
//        add(u, v);
//        add(v, u);
//        unite(u, v);
//    }
//
//    for (int i = 1; i <= n; ++i) {
//        if (i == father[i])
//            dfs(i, 0);
//    }
//
//    while (k--) {
//        int op;
//        cin >> op;
//        if (op == 1) {
//            int x;
//            cin >> x;
//            int fx = find(x);
//            cout << diameter[fx] << "\n";
//        }
//        else {
//            int x, y;
//            cin >> x >> y;
//            unite(x, y);
//        }
//    }
//
//    return 0;
//}