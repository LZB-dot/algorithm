//#include<iostream>
//#include<vector>
//using namespace std;
//
//
////class Solution {
////private:
////    const int N = 1e9 + 7;
////    vector<vector<vector<int>>> dp;
////    
////    int dfs(int i, int j, int r, vector<vector<int>>& grid, int k) {
////        int n = grid.size(), m = grid[0].size();
////        if (i == n - 1 && j == m - 1) {
////            return (grid[i][j] % k) == r ? 1 : 0;
////        }
////
////        if (dp[i][j][r] != -1) {
////            return dp[i][j][r];
////        }
////
////        int val = grid[i][j] % k;
////        int need = (r - val + k) % k;
////        int ans = 0;
////        if (i + 1 < n) {
////            ans = dfs(i + 1, j, need, grid, k);
////        }
////        if(j + 1 < m) {
////            ans = (ans + dfs(i, j + 1, need, grid, k)) % N;
////        }
////
////        dp[i][j][r] = ans;
////        return ans;
////    }
////public:
////    int numberOfPaths(vector<vector<int>>& grid, int k) {
////        int n = grid.size(), m = grid[0].size();
////        // ¶¯Ì¬³õÊ¼»¯dp[i][j][rem]£¬rem·¶Î§[0, k-1]
////        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));
////        return dfs(0, 0, 0, grid, k);
////    }
////};
//
//class Solution {
//private:
//    const int N = 1e9 + 7;
//
//
//public:
//    int numberOfPaths(vector<vector<int>>& grid, int k) {
//        int m = grid.size(), n = grid[0].size();
//        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, 0)));
//
//        int endVal = grid[m - 1][n - 1] % k;
//        dp[m - 1][n - 1][endVal] = 1;
//
//        for (int i = m - 2; i >= 0; --i) {
//            for (int r = 0; r < k; ++r) {
//                int val = grid[i][n - 1] % k;
//                int need = (r - val + k) % k;
//                dp[i][n - 1][r] = dp[i + 1][n - 1][need];
//            }
//        }
//
//        for (int j = n - 2; j >= 0; --j) {
//            for (int r = 0; r < k; ++r) {
//                int val = grid[m - 1][j] % k;
//                int need = (r - val + k) % k;
//                dp[m - 1][j][r] = dp[m - 1][j + 1][need];
//            }
//        }
//
//        for (int i = m - 2; i >= 0; --i) {
//            for (int j = n - 2; j >= 0; --j) {
//                for (int r = 0; r < k; ++r) {
//                    int val = grid[i][j] % k;
//                    int need = (r - val + k) % k;
//                    dp[i][j][r] = (dp[i + 1][j][need] + dp[i][j + 1][need]) % N;
//                }
//            }
//        }
//
//        return dp[0][0][0];
//
//    }
//};