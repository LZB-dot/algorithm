//#include<iostream>
//#include<vector>
//using namespace std;
//
////class Solution {
////private:
////    const int N = 1e9 + 7;
////    int dp[101][101][101];//处理到第i个工作，剩余j个员工，还差k利润达标的方案
////
////    int dfs(int i, int j, int k, vector<int>& group, vector<int>& profit) {
////        if (j <= 0) {
////            return k <= 0 ? 1 : 0;
////        }
////
////        if (i == group.size()) {
////            return k <= 0 ? 1 : 0;
////        }
////
////        if (dp[i][j][k] != -1) {
////            return dp[i][j][k];
////        }
////
////        int case1 = dfs(i + 1, j, k, group, profit) % N;
////        int case2 = 0;
////        if (group[i] <= j) {
////            int newK = max(0, k - profit[i]);
////            case2 = dfs(i + 1, j - group[i], newK, group, profit) % N;
////        }
////
////        dp[i][j][k] = (case1 + case2) % N;
////        return dp[i][j][k];
////    }
////public:
////    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
////        memset(dp, -1, sizeof(dp));
////        return dfs(0, n, minProfit, group, profit);
////    }
////};
//
////class Solution {
////private:
////    const int MOD = 1e9 + 7;
////public:
////    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
////        int m = group.size();
////        //前i个工作，用≤j个员工，利润≥k的方案数
////        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
////
////        for (int j = 0; j <= n; ++j) {
////            dp[0][j][0] = 1;
////        }
////
////        for (int i = 1; i <= m; ++i) {
////            int g = group[i - 1];  // 当前工作需要的员工数
////            int p = profit[i - 1]; // 当前工作的利润
////            for (int j = 0; j <= n; ++j) {
////                for (int k = 0; k <= minProfit; ++k) {
////                    //不选第i个工作
////                    dp[i][j][k] = dp[i - 1][j][k];
////
////                    //选第i个工作（员工数足够）
////                    if (j >= g) {
////                        // 选后利润 = 前i-1个工作的利润 + p
////                        // 若前i-1个工作利润≥max(0, k - p)，则选后利润≥k
////                        int prev_k = max(0, k - p);
////                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - g][prev_k]) % MOD;
////                    }
////                }
////            }
////        }
////
////        return dp[m][n][minProfit];
////    }
////};
//
//class Solution {
//private:
//    const int MOD = 1e9 + 7;
//public:
//    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
//        int m = group.size();
//        vector<vector<int>>dp(n + 1, vector<int>(minProfit + 1, 0));
//    
//        for (int i = 0; i <= n; ++i) {
//            dp[i][0] = 1;
//        }
//
//        for (int g = 0; g < m; ++g) {
//
//            for (int i = n; i >= group[g]; --i) {
//                for (int j = minProfit; j >= 0; --j) {
//                    int remain = max(0, j - profit[g]);
//                    dp[i][j] = (dp[i][j] + dp[i - group[g]][remain]) % MOD;
//                }
//            }
//        }
//
//        return dp[n][minProfit];
//    }
//};