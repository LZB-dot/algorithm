//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//private:
//    int dirs[8][2] = { {-2,1},{-1,2},{1,2},{2,1},
//                {2,-1},{1,-2},{-1,-2},{-2,-1} };
//
//    vector<vector<vector<double>>>dp;
//
//    double dfs(int n, int i, int j, int k) {
//        if (i < 0 || j < 0 || i >= n || j >= n) {
//            return 0.0;
//        }
//
//        if (k == 0) {
//            return 1.0;
//        }
//
//        if (dp[i][j][k] != -1) {
//            return dp[i][j][k];
//        }
//
//
//        double ans = 0.0;
//        for (auto& dir : dirs) {
//            int dx = i + dir[0];
//            int dy = j + dir[1];
//            ans += dfs(n, dx, dy, k - 1) / 8.0;
//        }
//        dp[i][j][k] = ans;
//        return ans;
//    }
//public:
//    double knightProbability(int n, int k, int row, int column) {
//        dp.resize(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
//        return dfs(n, row, column, k);
//    }
//};