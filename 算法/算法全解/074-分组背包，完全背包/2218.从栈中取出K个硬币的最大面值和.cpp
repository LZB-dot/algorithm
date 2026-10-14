//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//
//class Solution {
//public:
//    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//        int n = piles.size();
//        vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));
//
//        for (int i = 1; i <= n; ++i) {
//            auto& tmp = piles[i - 1];
//            int t = min((int)tmp.size(), k);
//            vector<int>pre(t + 1, 0);
//            for (int j = 0; j < t; ++j) {
//                pre[j + 1] = pre[j] + tmp[j];
//            }
//
//            for (int j = k; j >= 1; --j) {
//                dp[i][j] = dp[i - 1][j];
//                for (int x = 1; x <= t; ++x) {
//                    if (x <= j) {
//                        dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + pre[x]);
//                    }
//                }
//            }
//        }
//
//        return dp[n][k];
//    }
//};