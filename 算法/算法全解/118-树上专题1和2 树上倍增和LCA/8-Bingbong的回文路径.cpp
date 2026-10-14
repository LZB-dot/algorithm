//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//typedef unsigned long long ull;
//
//const int MAXN = 100005;
//const int LIMIT = 20;
//const ull K = 499;
//
//int s[MAXN];
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], cnt;
//
//int depth[MAXN];
//int stjump[MAXN][LIMIT];
//
//ull kpow[MAXN];
//ull stup[MAXN][LIMIT];     // 上坡哈希 子->父
//ull stdown[MAXN][LIMIT];   // 下坡哈希 父->子
//int power;
//
//void build(int n) {
//    power = 0;
//    while ((1 << power) <= (n >> 1))
//        power++;
//    ++power;
//
//    cnt = 1;
//    memset(head, 0, sizeof(head));
//
//    kpow[0] = 1;
//    for (int i = 1; i <= n; i++)
//        kpow[i] = kpow[i - 1] * K;
//}
//
//void add(int u, int v) {
//    to[cnt] = v;
//    nxt[cnt] = head[u];
//    head[u] = cnt++;
//}
//
//void dfs(int u, int fa) {
//    depth[u] = depth[fa] + 1;
//    stjump[u][0] = fa;
//    stup[u][0] = stdown[u][0] = s[fa];
//
//    for (int p = 1; p < LIMIT; p++) {
//        int v = stjump[u][p - 1];
//        stjump[u][p] = stjump[v][p - 1];
//
//        stup[u][p] = stup[u][p - 1] * kpow[1 << (p - 1)] + stup[v][p - 1];
//        stdown[u][p] = stdown[v][p - 1] * kpow[1 << (p - 1)] + stdown[u][p - 1];
//    }
//
//    for (int i = head[u]; i; i = nxt[i]) {
//        int v = to[i];
//        if (v != fa)
//            dfs(v, u);
//    }
//}
//
//int LCA(int u, int v) {
//    if (depth[u] < depth[v])
//        swap(u, v);
//
//    for (int p = power; p >= 0; p--)
//        if (depth[stjump[u][p]] >= depth[v])
//            u = stjump[u][p];
//
//    if (u == v)
//        return u;
//
//    for (int p = power; p >= 0; p--)
//        if (stjump[u][p] != stjump[v][p])
//            u = stjump[u][p], v = stjump[v][p];
//
//    return stjump[u][0];
//}
//
//ull getHash(int sta, int lcaNode, int ed) {
//    ull up = s[sta];
//    int cur = sta;
//    for (int p = power; p >= 0; p--) {
//        if (depth[stjump[cur][p]] >= depth[lcaNode] && stjump[cur][p] != 0) {
//            up = up * kpow[1 << p] + stup[cur][p];
//            cur = stjump[cur][p];
//        }
//    }
//
//    if (ed == lcaNode)
//        return up;
//
//    ull down = s[ed];
//    int len = 1;
//    cur = ed;
//    for (int p = power; p >= 0; p--) {
//        if (depth[stjump[cur][p]] > depth[lcaNode]) {
//            down = stdown[cur][p] * kpow[len] + down; // 拼接到前面
//            len += (1 << p);
//            cur = stjump[cur][p];
//        }
//    }
//
//    return up * kpow[len] + down;
//}
//
//bool query(int u, int v) {
//    int ances = LCA(u, v);
//    ull h1 = getHash(u, ances, v);
//    ull h2 = getHash(v, ances, u);
//    return h1 == h2;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//    build(n);
//
//    for (int i = 1; i <= n; i++) {
//        char c;
//        cin >> c;
//        s[i] = c - 'a' + 1;
//    }
//
//    for (int i = 1; i <= n; i++) {
//        int fa;
//        cin >> fa;
//        add(i, fa);
//        add(fa, i);
//    }
//
//    dfs(1, 0);
//
//    int q;
//    cin >> q;
//    while (q--) {
//        int u, v;
//        cin >> u >> v;
//        if (query(u, v))
//            cout << "YES\n";
//        else
//            cout << "NO\n";
//    }
//
//    return 0;
//}