//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//
//
//class Solution {
//public:
//    int maxDistance(vector<vector<int>>& grid) {
//        int move[] = { -1,0,1,0,-1 };
//        int n = grid.size();
//        if (n == 0) {
//            return -1;
//        }
//        int m = grid[0].size();
//        queue<pair<int, int>>q;
//        vector<vector<bool>>vis(n, vector<bool>(m, 0));
//        int seas = 0;
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                if (grid[i][j] == 1) {
//                    q.emplace(i, j);
//                    vis[i][j] = 1;
//                }
//                else {
//                    seas++;
//                }
//            }
//        }
//
//        if (seas == 0 || q.empty()) {
//            return -1;
//        }
//
//        int level = 0;
//        while (!q.empty()) {
//            int s = q.size();
//            for (int i = 0; i < s; ++i) {
//                pair<int, int>tmp = q.front();
//                q.pop();
//
//                for (int d = 0; d < 4; ++d) {
//                    int dx = move[d] + tmp.first;
//                    int dy = move[d + 1] + tmp.second;
//                    if (dx >= 0 && dy >= 0 && dx < n && dy < m
//                        && !vis[dx][dy] && grid[dx][dy] == 0) {
//                        q.emplace(dx, dy);
//                        vis[dx][dy] = 1;
//                    }
//                }
//            }
//            level++;
//        }
//
//        return level - 1;
//    }
//};