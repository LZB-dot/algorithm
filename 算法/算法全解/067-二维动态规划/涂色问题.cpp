//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MOD = 1e9 + 7;
//
//class Solution {
//public:
//    int ways(int n, int m) {
//        if (m > n) 
//            return 0; // 颜色数多于格子数，不可能全使用
//        if (m == 0) 
//            return (n == 0) ? 1 : 0; // 边界情况
//
//        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
//
//        // 初始化：0个格子用0种颜色有1种方法
//        dp[0][0] = 1;
//        // 用1种颜色涂i个格子，只有1种方法（全涂这一种）
//        for (int i = 1; i <= n; ++i) {
//            dp[i][1] = 1;
//        }
//
//        // 填充dp表
//        for (int i = 2; i <= n; ++i) {
//            // j最多为min(i, m)，因为j>i时不可能
//            for (int j = 2; j <= min(i, m); ++j) {
//                // 递推公式：两种情况相加
//                long long case1 = dp[i - 1][j] * j % MOD; // 用已有j种颜色
//                long long case2 = dp[i - 1][j - 1] * (m - j + 1) % MOD; // 新增1种颜色
//                dp[i][j] = (case1 + case2) % MOD;
//            }
//        }
//
//        return dp[n][m] % MOD;
//    }
//};