//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 55;
//
//
//
//class Solution {
//private:
//    int head[MAXN], nxt[MAXN << 1], to[MAXN << 1];
//    int cnt = 1;
//
//    int stjump[MAXN][10], depth[MAXN];
//
//    int diff[MAXN];
//    int yes, no;
//
//    void add(int u, int v) {
//        nxt[cnt] = head[u];
//        to[cnt] = v;
//        head[u] = cnt++;
//    }
//
//    void build(int u, int fa) {
//        depth[u] = depth[fa] + 1;
//        stjump[u][0] = fa;
//
//        for (int p = 1; p < 10; ++p)
//            stjump[u][p] = stjump[stjump[u][p - 1]][p - 1];
//
//        for (int i = head[u]; i; i = nxt[i]) {
//            int v = to[i];
//            if (v != fa)
//                build(v, u);
//        }
//    }
//
//    int LCA(int u, int v) {
//        if (depth[u] < depth[v])
//            swap(u, v);
//
//        for (int p = 9; p >= 0; --p) {
//            if (depth[stjump[u][p]] >= depth[v])
//                u = stjump[u][p];
//        }
//
//        if (u == v)
//            return u;
//
//        for (int p = 9; p >= 0; --p) {
//            if (stjump[u][p] != stjump[v][p]) {
//                u = stjump[u][p];
//                v = stjump[v][p];
//            }
//        }
//
//        return stjump[u][0];
//    }
//
//    void dfs(int u, int fa) {
//        for (int i = head[u]; i; i = nxt[i]) {
//            int v = to[i];
//            if (v == fa)
//                continue;
//
//            dfs(v, u);
//            diff[u] += diff[v];
//        }
//    }
//
//    void dp(int u, int fa, const vector<int>& price) {
//        int curno = price[u - 1] * diff[u];
//        int curyes = price[u - 1] / 2 * diff[u];
//
//        for (int i = head[u]; i; i = nxt[i]) {
//            int v = to[i];
//
//            if (v == fa)
//                continue;
//
//            dp(v, u, price);
//            curno += min(no, yes);
//            curyes += no;
//        }
//
//        yes = curyes;
//        no = curno;
//    }
//
//public:
//    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
//
//        for (auto it : edges) {
//            int u = it[0] + 1;
//            int v = it[1] + 1;
//            add(u, v);
//            add(v, u);
//        }
//
//        build(1, 0);
//
//        for (auto it : trips) {
//            int u = it[0] + 1;
//            int v = it[1] + 1;
//            int father = LCA(u, v);
//
//            diff[u]++;
//            diff[v]++;
//            diff[father]--;
//            diff[stjump[father][0]]--;
//        }
//
//        dfs(1, 0);
//
//        dp(1, 0, price);
//
//        return min(no, yes);
//    }
//};