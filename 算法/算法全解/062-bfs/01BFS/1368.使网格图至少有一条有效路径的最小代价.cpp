//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//
//class Solution {
//public:
//    int minCost(vector<vector<int>>& grid) {
//        int n = grid.size();
//        int m = grid[0].size();
//
//        vector<vector<int> >move = { {},{0,1},{0,-1},{1,0},{-1,0} };
//        vector<vector<int> >cost(n, vector<int>(m, INT_MAX));
//        deque<pair<int, int> >dq;
//
//        dq.emplace_back(0, 0);
//        cost[0][0] = 0;
//
//        while (!dq.empty()) {
//            pair<int, int>cur = dq.front();
//            int x = cur.first, y = cur.second;
//            dq.pop_front();
//            if (x == n - 1 && y == m - 1) {
//                return cost[x][y];
//            }
//
//            for (int i = 1; i <= 4; ++i) {
//                int dx = x + move[i][0];
//                int dy = y + move[i][1];
//                int flag = (grid[x][y] == i) ? 0 : 1;
//                if (dx >= 0 && dy >= 0 && dx < n && dy < m) {
//                    int newCost = cost[x][y] + flag;
//                    if (newCost < cost[dx][dy]) {
//                        cost[dx][dy] = newCost;
//                        if (flag == 0)
//                            dq.emplace_front(dx, dy);
//                        else
//                            dq.emplace_back(dx, dy);
//                    }
//                }
//            }
//        }
//        return -1;
//    }
//};
//
