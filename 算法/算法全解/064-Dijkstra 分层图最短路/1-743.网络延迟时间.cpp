//
//////https://leetcode.cn/problems/network-delay-time/
//
//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<climits>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 105;
//const int MAXE = 10010;
//
//class Solution {
//
//private:
//    int head[MAXN], to[MAXE], nxt[MAXE], weight[MAXE];
//    int cnt;
//
//    void init(int n) {
//        cnt = 1;
//        memset(head, 0, sizeof(int) * (n + 1));
//    }
//
//    void add(int u, int v, int w) {
//        to[cnt] = v;
//        nxt[cnt] = head[u];
//        weight[cnt] = w;
//        head[u] = cnt++;
//    }
//
//public:
//    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//
//        init(n);
//
//        for (auto& it : times) {
//            int u = it[0];
//            int v = it[1];
//            int w = it[2];
//            add(u, v, w);
//        }
//
//        vector<int>dis(n + 1, INT_MAX);
//        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//        pq.push({ 0,k });
//        dis[k] = 0;
//        
//        while (!pq.empty()) {
//            auto it = pq.top();
//            pq.pop();
//            int w = it.first;
//            int u = it.second;
//            
//            if (w > dis[u])
//                continue;
//
//            for (int i = head[u]; i; i = nxt[i]) {
//                int v = to[i];
//                int edge_w = weight[i];
//                if (dis[v] > dis[u] + edge_w) {
//                    dis[v] = dis[u] + edge_w;
//                    pq.push({ dis[v],v });
//                }
//            }
//        }
//
//        int ans = 0;
//        for (int i = 1; i <= n; ++i) {
//            if (dis[i] == INT_MAX)
//                return -1;
//            ans = max(ans, dis[i]);
//        }
//        return ans;
//    }
//};
