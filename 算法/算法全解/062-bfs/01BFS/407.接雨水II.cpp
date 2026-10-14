//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//class Solution {
//public:
//    int trapRainWater(vector<vector<int>>& heightMap) {
//        int n = heightMap.size();
//        int m = heightMap[0].size();
//
//        vector<vector<bool>>vis(n, vector<bool>(m, 0));
//        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>heap;
//
//        //加入边缘格子，从边缘最小的格子开始
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
//                    heap.push({ heightMap[i][j], i, j });
//                    vis[i][j] = 1;
//                }
//            }
//        }
//    
//        int move[] = { -1,0,1,0,-1 };
//        int ans = 0;
//        while (!heap.empty()) {
//            vector<int>cur = heap.top();
//            heap.pop();
//            int h = cur[0], x = cur[1], y = cur[2];
//
//            for (int i = 0; i < 4; ++i) {
//                int dx = x + move[i];
//                int dy = y + move[i + 1];
//
//                if (dx >= 0 && dy >= 0 && dx < n && dy < m && !vis[dx][dy]) {
//                    ans += max(0, h - heightMap[dx][dy]);
//                    heap.push({ max(h, heightMap[dx][dy]), dx, dy });
//                    vis[dx][dy] = 1;
//                }
//            }
//        }
//        return ans;
//    }
//};