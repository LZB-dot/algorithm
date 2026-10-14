//
////https://leetcode.cn/problems/DFPeFJ/description/
//
//#include <vector>
//#include <queue>
//#include <cstring>
//#include <climits>
//using namespace std;
//
//class Solution {
//private:
//    int head[105], to[405], nxt[405], weight[405];
//    int edgeCnt;
//
//    void add(int u, int v, int w) {
//        to[edgeCnt] = v;
//        nxt[edgeCnt] = head[u];
//        weight[edgeCnt] = w;
//        head[u] = edgeCnt++;
//    }
//
//public:
//    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {
//        int n = charge.size();
//
//        edgeCnt = 1;
//        memset(head, 0, sizeof(head));
//
//        for (auto& it : paths) {
//            int u = it[0], v = it[1], w = it[2];
//            add(u, v, w);
//            add(v, u, w);
//        }
//
//
//        vector<vector<int>> dis(n, vector<int>(cnt + 1, INT_MAX));
//        vector<vector<bool>> vis(n, vector<bool>(cnt + 1, false));
//
//        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
//        dis[start][0] = 0;
//        pq.push({ 0, start, 0 });
//
//        while (!pq.empty()) {
//            auto cur = pq.top();
//            pq.pop();
//
//            int t = cur[0];
//            int u = cur[1];
//            int e = cur[2];
//
//            if (u == end)
//                return t;
//
//            if (vis[u][e])
//                continue;
//
//            vis[u][e] = true;
//
//            if (e < cnt) {
//                int newE = e + 1;
//                int newT = t + charge[u];
//
//                if (newT < dis[u][newE]) {
//                    dis[u][newE] = newT;
//                    pq.push({ newT, u, newE });
//                }
//            }
//
//            for (int i = head[u]; i; i = nxt[i]) {
//                int v = to[i];
//                int w = weight[i];
//                if (e >= w) {
//                    int newE = e - w;
//                    int newT = t + w;
//                    if (newT < dis[v][newE]) {
//                        dis[v][newE] = newT;
//                        pq.push({ newT, v, newE });
//                    }
//                }
//            }
//        }
//        return -1;
//    }
//};
