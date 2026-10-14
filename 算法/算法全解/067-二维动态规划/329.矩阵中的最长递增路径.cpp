//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//class Solution {
//private:
//    int dir[5] = { -1,0,1,0,-1 };
//
//    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
//        if (dp[i][j] != -1) {
//            return dp[i][j];
//        }
//        
//        int n = matrix.size(), m = matrix[0].size();
//        int len = 1;
//
//        for (int k = 0; k < 4; ++k) {
//            int x = dir[k] + i;
//            int y = dir[k + 1] + j;
//            if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > matrix[i][j]) {
//                int tmp = 1 + dfs(matrix, x, y, dp);
//                len = max(tmp, len);
//            }
//        }
//
//        dp[i][j] = len;
//        return len;
//    }
//public:
//    int longestIncreasingPath(vector<vector<int>>& matrix) {
//        int n = matrix.size(), m = matrix[0].size();
//        vector<vector<int>>dp(n, vector<int>(m, -1));
//
//        int ans = 0;
//
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                ans = max(ans, dfs(matrix, i, j, dp));
//            }
//        }
//
//        return ans;
//    }
//};