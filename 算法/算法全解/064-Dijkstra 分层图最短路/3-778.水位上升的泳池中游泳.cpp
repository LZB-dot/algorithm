//
//////https://leetcode.cn/problems/swim-in-rising-water/description/
//
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//class Solution {
//private:
//    int dx[4] = { 1,-1,0,0 };
//    int dy[4] = { 0,0,1,-1 };
//public:
//    int swimInWater(vector<vector<int>>& grid) {
//        int n = grid.size();
//        int m = grid[0].size();
//
//        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
//        pq.push({ grid[0][0],0,0 });
//        vector<vector<int>>dis(n, vector<int>(m, -1));
//
//        while (!pq.empty()) {
//            auto it = pq.top();
//            pq.pop();
//
//            int w = it[0];
//            int x = it[1];
//            int y = it[2];
//
//            if (dis[x][y] != -1)
//                continue;
//
//            dis[x][y] = w;
//
//            if (x == n - 1 && y == m - 1)
//                return dis[x][y];
//
//
//            for (int i = 0; i < 4; ++i) {
//                int tx = x + dx[i];
//                int ty = y + dy[i];
//
//                if (tx >= 0 && ty >= 0 && tx < n && ty < m && dis[tx][ty] == -1) {
//                    int mx = max(w, grid[tx][ty]);
//                    pq.push({ mx,tx,ty });
//                }
//
//
//            }
//        }
//
//        return -1;
//    }
//};