//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 1e4 + 10;
//
//
//class Solution {
//private:
//    int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], weight[MAXN << 1];
//    int cnt;
//
//    int stjump[MAXN][15], depth[MAXN];
//    int val[MAXN][15][27];
//
//    void init() {
//        memset(head, 0, sizeof(head));
//        memset(depth, 0, sizeof(depth));
//        memset(stjump, 0, sizeof(stjump));
//        memset(val, 0, sizeof(val));
//        cnt = 1;
//    }
//
//    void add(int u, int v, int w) {
//        nxt[cnt] = head[u];
//        to[cnt] = v;
//        weight[cnt] = w;
//        head[u] = cnt++;
//    }
//
//    void dfs(int u, int fa) {
//        depth[u] = depth[fa] + 1;
//        stjump[u][0] = fa;
//
//        for (int i = head[u]; i; i = nxt[i]) {
//            int v = to[i];
//            if (v == fa) {
//                int w = weight[i];
//                val[u][0][w] = 1;
//                break;
//            }
//        }
//
//        for (int p = 1; p < 15; ++p) {
//            stjump[u][p] = stjump[stjump[u][p - 1]][p - 1];
//            for (int i = 1; i < 27; ++i)
//                val[u][p][i] = val[u][p - 1][i] + val[stjump[u][p - 1]][p - 1][i];
//        }
//
//        for (int i = head[u]; i; i = nxt[i]) {
//            int v = to[i];
//            if (v != fa)
//                dfs(v, u);
//        }
//    }
//
//    int query(int u, int v) {
//        if (u == v)
//            return 0;
//
//        if (depth[u] < depth[v])
//            swap(u, v);
//
//        vector<int>cur(27);
//        for (int p = 14; p >= 0; --p) {
//            if (depth[stjump[u][p]] >= depth[v]) {
//                for (int i = 1; i < 27; ++i)
//                    cur[i] += val[u][p][i];
//                u = stjump[u][p];
//            }
//        }
//
//        if (u != v) {
//
//            for (int p = 14; p >= 0; --p) {
//                if (stjump[u][p] != stjump[v][p]) {
//                    for (int i = 1; i < 27; ++i) {
//                        cur[i] += val[u][p][i];
//                        cur[i] += val[v][p][i];
//                    }
//                    u = stjump[u][p];
//                    v = stjump[v][p];
//                }
//            }
//
//            for (int i = 1; i < 27; ++i) {
//                cur[i] += val[u][0][i];
//                cur[i] += val[v][0][i];
//            }
//        }
//
//        int sum = 0;
//        for (int i : cur)
//            sum += i;
//        int mx = *max_element(cur.begin(), cur.end());
//        sum -= mx;
//        return sum;
//    }
//public:
//    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
//        init();
//
//        for (auto it : edges) {
//            int u = it[0], v = it[1], w = it[2];
//            add(u, v, w);
//            add(v, u, w);
//        }
//
//        for (int i = 0; i < n; ++i) {
//            if (depth[i] == 0)
//                dfs(0, 0);
//        }
//
//        vector<int>ans;
//        for (auto it : queries) {
//            int u = it[0], v = it[1];
//            int res = query(u, v);
//            ans.push_back(res);
//        }
//
//        return ans;
//    }
//};