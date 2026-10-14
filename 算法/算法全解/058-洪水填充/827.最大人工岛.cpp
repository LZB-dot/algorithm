//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//
//class Solution {
//private:
//    int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
//    int n, m;
//
//    void dfs(int x, int y, int id, vector<vector<int>>& grid, vector<int>& size) {
//        if (x >= n || x < 0 || y < 0 || y >= m || grid[x][y] != 1) {
//            return;
//        }
//        grid[x][y] = id;
//        size[id]++;
//        for (int i = 0; i < 4; ++i) {
//            int dx = x + dir[i][0];
//            int dy = y + dir[i][1];
//            dfs(dx, dy, id, grid, size);
//        }
//    }
//public:
//    int largestIsland(vector<vector<int>>& grid) {
//        n = grid.size();
//        m = grid[0].size();
//        int id = 2;
//        vector<int>size(25005, 0);
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                if (grid[i][j] == 1) {
//                    dfs(i, j, id, grid, size);
//                    ++id;
//                }
//            }
//        }
//
//        int ans = 0;
//        for (int i = 2; i < id; ++i) {
//            ans = max(ans, size[i]);
//        }
//
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                if (grid[i][j] == 0) {
//                    bool vis[25005] = { 0 };
//                    int cur = 1;
//                    for (int k = 0; k < 4; ++k) {
//                        int dx = i + dir[k][0];
//                        int dy = j + dir[k][1];
//                        if (dx >= 0 && dx < n && dy >= 0 && dy < m) {
//                            int tmp = grid[dx][dy];
//                            if (tmp > 1 && !vis[tmp]) {
//                                cur += size[tmp];
//                                vis[tmp] = 1;
//                            }
//                        }
//                    }
//                    ans = max(ans, cur);
//                }
//            }
//        }
//        return ans;
//    }
//};