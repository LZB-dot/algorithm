//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//class Solution {
//public:
//    int minimumObstacles(vector<vector<int>>& grid) {
//        int n = grid.size();
//        int m = grid[0].size();
//        int move[] = { -1,0,1,0,-1 };
//        
//        deque<pair<int, int> >dq;
//        vector<vector<int> >dis(n, vector<int>(m, INT_MAX));
//
//        dq.emplace_back(0, 0);
//        dis[0][0] = 0;
//
//        while (!dq.empty()) {
//            pair<int, int>tmp = dq.front();
//            int x = tmp.first, y = tmp.second;
//            dq.pop_front();
//
//            if (x == n - 1 && y == m - 1) {
//                return dis[x][y];
//            }
//
//            for (int i = 0; i < 4; ++i) {
//                int dx = move[i] + x;
//                int dy = move[i + 1] + y;
//
//                if (dx >= 0 && dy >= 0 && dx < n && dy < m) {
//                    int newDis = dis[x][y] + grid[dx][dy];
//                    if (newDis < dis[dx][dy]) {
//                        dis[dx][dy] = newDis;
//                        if (grid[dx][dy] == 0) {
//                            dq.emplace_front(dx, dy);
//                        }
//                        else {
//                            dq.emplace_back(dx, dy);
//                        }
//                    }
//                }
//            }
//        }
//        return -1;
//    }
//};