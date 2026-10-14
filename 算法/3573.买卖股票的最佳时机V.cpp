//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//class Solution {
//public:
//    long long maximumProfit(vector<int>& prices, int k) {
//        int n = prices.size();
//
//        //到第i天完成j次交易的最大利益
//        //k状态判断：0无股票    1买入还没卖出     2卖出还没买入
//        vector<vector<vector<long long>>> dp(
//            n + 1,
//            vector<vector<long long>>(k + 1, vector<long long>(3, LLONG_MIN))
//        );
//
//        //第一天0次交易
//        dp[1][0][0] = 0;
//        //买入了
//        dp[1][0][1] = -(long long)prices[0];
//        //卖出了
//        dp[1][0][2] = (long long)prices[0];
//
//        for (int i = 2; i <= n; ++i) {
//            for (int j = 0; j <= k; ++j) {
//                // 初始值为前一天状态0
//                dp[i][j][0] = dp[i - 1][j][0]; 
//                // 前一天状态1已经买入了，今天可以卖出（完成交易）
//                if (j >= 1 && dp[i - 1][j - 1][1] != LLONG_MIN) {
//                    dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][1] + prices[i - 1]);
//                }
//                // 前一天状态2已经卖出了，今天可以买回（完成交易）
//                if (j >= 1 && dp[i - 1][j - 1][2] != LLONG_MIN) {
//                    dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][2] - prices[i - 1]);
//                }
//
//                // 初始值为前一天状态1
//                dp[i][j][1] = dp[i - 1][j][1];
//                //前一天状态0手上没股票
//                if (dp[i - 1][j][0] != LLONG_MIN) {
//                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][0] - prices[i - 1]);
//                }
//
//                // 初始值为前一天状态2
//                dp[i][j][2] = dp[i - 1][j][2]; 
//                //前一天状态0手上没股票
//                if (dp[i - 1][j][0] != LLONG_MIN) {
//                    dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][0] + prices[i - 1]);
//                }
//            }
//        }
//
//        // 遍历所有交易次数，取状态0的最大值
//        long long ans = 0;
//        for (int j = 0; j <= k; ++j) {
//            if (dp[n][j][0] != LLONG_MIN) {
//                ans = max(ans, dp[n][j][0]);
//            }
//        }
//        return ans;
//    }
//};
