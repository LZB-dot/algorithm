//
////Bellman-Ford算法：计算单源最短路径，支持负权边，还能检测负权环
//
// ////https://leetcode.cn/problems/cheapest-flights-within-k-stops/
//
//#include<iostream>
//#include<vector>
//#include<climits>
//#include<algorithm>
//using namespace std;
//
//const int INF = 1e9;
//
//class Solution {
//public:
//    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//        vector<int>dis(n, INF);
//        dis[src] = 0;
//
//        for (int i = 0; i <= k; ++i) {
//            vector<int>nxt = dis;
//            for (auto& e : flights) {
//                int u = e[0];
//                int v = e[1];
//                int w = e[2];
//
//                if (dis[u] != INF)
//                    nxt[v] = min(dis[u] + w, nxt[v]);
//            }
//
//            dis = move(nxt);
//        }
//
//        return (dis[dst] != INF ? dis[dst] : -1);
//    }
//};