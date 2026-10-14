//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 5e4 + 10;
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt;
//
//int depth[MAXN];
//int stjump[MAXN][16];
//
//class TreeAncestor {
//private:
//    void init() {
//        cnt = 1;
//        memset(head, 0, sizeof(head));
//        memset(depth, 0, sizeof(depth));
//        memset(stjump, -1, sizeof(stjump));
//    }
//
//    void add(int u, int v) {
//        to[cnt] = v;
//        nxt[cnt] = head[u];
//        head[u] = cnt++;
//    }
//
//    void dfs(int u, int fa) {
//        if (fa == -1)
//            depth[u] = 1;
//        else
//            depth[u] = depth[fa] + 1;
//        stjump[u][0] = fa;
//
//        for (int p = 1; p < 16; ++p) {
//            if (stjump[u][p - 1] != -1)
//                stjump[u][p] = stjump[stjump[u][p - 1]][p - 1];
//        }
//
//        for (int i = head[u]; i; i = nxt[i]) {
//            int v = to[i];
//            if (v != fa)
//                dfs(v, u);
//        }
//    }
//
//
//
//
//public:
//    TreeAncestor(int n, vector<int>& parent) {
//        init();
//
//        for (int i = 1; i < n; ++i)
//            add(parent[i], i);
//
//        dfs(0, -1);
//    }
//
//    int getKthAncestor(int node, int k) {
//        if (k == 0)
//            return node;
//
//        if (depth[node] <= k)
//            return -1;
//
//        int tar = 0;
//        while ((1 << tar) <= (k >> 1))
//            ++tar;
//
//        for (int p = tar; p >= 0; --p) {
//            if ((1 << p) <= k && stjump[node][p] != -1) {
//                k -= (1 << p);
//                node = stjump[node][p];
//            }
//        }
//
//        return k == 0 ? node : -1;
//    }
//};
