//#include<iostream>
//#include<vector>
//using namespace std;
//
////class Solution {
////public:
////    int maxProfit(int k, vector<int>& prices) {
////        int n = prices.size();
////        int ans = 0;
////
////        if (k >= (n >> 1)) {
////            for (int i = 1; i < n; ++i) {
////                ans += max(prices[i] - prices[i - 1], 0);
////            }
////            return ans;
////        }
////
////        vector<vector<int>>dp(k + 1, vector<int>(n + 1, 0));
////
////        for (int t = 1; t <= k; ++t) {
////            for (int i = 1; i < n; ++i) {
////                dp[t][i] = dp[t][i - 1];
////
////                for (int j = 0; j <= i; ++j) {
////                    dp[t][i] = max(dp[t][i], dp[t - 1][j] + prices[i] - prices[j]);
////                }
////            }
////        }
////        
////        return dp[k][n - 1];
////
////    }
////};
//
//class Solution {
//public:
//    int maxProfit(int k, vector<int>& prices) {
//        int n = prices.size();
//        int ans = 0;
//
//        if (k >= (n >> 1)) {
//            for (int i = 1; i < n; ++i) {
//                ans += max(prices[i] - prices[i - 1], 0);
//            }
//            return ans;
//        }
//
//        vector<int>dp(n + 1, 0);
//
//        //for (int t = 1; t <= k; ++t) {
//        //    int best = dp[t - 1][0] - prices[0];;
//        //    for (int j = 1; j < n; ++j) {
//        //        dp[t][j] = max(dp[t][j - 1], best + prices[j]);
//        //        best = max(best, dp[t - 1][j] - prices[j]);
//        //    }
//        //}
//
//        for (int t = 1; t <= k; ++t) {
//            int best = dp[t - 1] - prices[0];
//            for (int j = 1; j < n; ++j) {
//                int tmp = dp[j];
//                dp[j] = max(dp[j - 1], best + prices[j]);
//                best = max(best, tmp - prices[j]);
//            }
//        }
//        return dp[n - 1];
//
//    }
//};