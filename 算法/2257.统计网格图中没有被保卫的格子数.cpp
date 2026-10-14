//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
//        vector<vector<int>>grid(m, vector<int>(n, 0));
//        for (auto& i: guards) {
//            int x = i[0], y = i[1];
//            grid[x][y] = 1;
//        }
//        for (auto& i : walls) {
//            int x = i[0], y = i[1];
//            grid[x][y] = 2;
//        }
//
//        vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//
//        for (auto& i : guards) {
//            int x = i[0], y = i[1];
//            for (auto& j : dirs) {
//                int dx = j.first + x;
//                int dy = j.second + y;
//                while (dx >= 0 && dx < m && dy >= 0 && dy < n) {
//                    if (grid[dx][dy] == 2 || grid[dx][dy] == 1) {
//                        break;
//                    }
//                    if (grid[dx][dy] == 0) {
//                        grid[dx][dy] = 3;
//                    }
//                    dx += j.first;
//                    dy += j.second;
//                }
//            }
//        }
//        int ans = 0;
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (grid[i][j] == 0) {
//                    ++ans;
//                }
//            }
//        }
//
//        return ans;
//    }
//};