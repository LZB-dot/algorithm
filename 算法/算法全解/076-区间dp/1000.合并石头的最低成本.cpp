//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int mergeStones(vector<int>& stones, int k) {
//        int n = stones.size();
//        // 可行性判断
//        if ((n - 1) % (k - 1) != 0) {
//            return -1;
//        }
//
//        // 前缀和数组
//        vector<int> pre(n + 1, 0);
//        for (int i = 0; i < n; ++i) {
//            pre[i + 1] = pre[i] + stones[i];
//        }
//
//        // dp[l][r]：合并区间[l, r]内的石头到“不能再合并”状态的最小成本
//        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
//
//        // 初始化：长度为1的区间，成本为0
//        for (int i = 0; i < n; ++i) {
//            dp[i][i] = 0;
//        }
//
//        // 逆序枚举左端点l
//        for (int l = n - 2; l >= 0; --l) {
//            // 枚举右端点r
//            for (int r = l + 1; r < n; ++r) {
//                // 枚举中间点m，步长为k-1
//                for (int m = l; m < r; m += k - 1) {
//                    // 如果子区间无法合并（成本为INT_MAX），则跳过
//                    if (dp[l][m] == INT_MAX || dp[m + 1][r] == INT_MAX) {
//                        continue;
//                    }
//                    dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
//                }
//
//                //判断区间[l, r]是否能合并成一堆
//                if ((r - l) % (k - 1) == 0) {
//                    // 如果前面的合并是可行的（dp[l][r]不是INT_MAX）
//                    if (dp[l][r] != INT_MAX) {
//                        dp[l][r] += pre[r + 1] - pre[l];
//                    }
//                    // 如果前面的合并不可行，但区间长度允许合并成一堆，
//                    // 说明可以直接合并，成本就是区间和
//                    else {
//                        dp[l][r] = pre[r + 1] - pre[l];
//                    }
//                }
//            }
//        }
//
//        return dp[0][n - 1];
//    }
//};