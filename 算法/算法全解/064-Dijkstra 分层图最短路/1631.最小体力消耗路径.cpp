//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int minimumEffortPath(vector<vector<int>>& heights) {
//        int n = heights.size(), m = heights[0].size();
//
//        vector<vector<int>>dis(n, vector<int>(m, INT_MAX));
//        vector<vector<bool>>vis(n, vector<bool>(m, false));
//        priority_queue < vector<int>, vector<vector<int>>, greater<vector<int>>>heap;
//
//        int move[] = { -1,0,1,0,-1 };
//        heap.push({ 0,0,0 });
//        while (!heap.empty()) {
//            vector<int>tmp = heap.top();
//            //w是到当前位置的最大花费
//            int w = tmp[0], x = tmp[1], y = tmp[2];
//            heap.pop();
//            if (vis[x][y]) {
//                continue;
//            }
//            if (x == n - 1 && y == m - 1) {
//                return w;
//            }
//            vis[x][y] = 1;
//            for (int i = 0; i < 4; ++i) {
//                int dx = x + move[i];
//                int dy = y + move[i + 1];
//                if (dx >= 0 && dy >= 0 && dx < n && dy < m && !vis[dx][dy]) {
//                    int dw = max(abs(heights[dx][dy] - heights[x][y]), w);
//                    if (dw < dis[dx][dy]) {
//                        dis[dx][dy] = dw;
//                        heap.push({ dw,dx,dy });
//                    }
//                }
//            }
//        }
//
//        return -1;
//    }
//};