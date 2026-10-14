//#include<iostream>
//#include<vector>
//using namespace std;
//
//
////const int MOD = 1e9 + 7;
////
////class Solution {
////public:
////    int kInversePairs(int n, int k) {
////        //前i个数逆序对数为k的次数
////        vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));
////        dp[1][0] = 1;
////        for (int i = 2; i <= n; ++i) {
////            dp[i][0] = 1;//0个逆序对只有升序排列
////            for (int j = 1; j <= k; ++j) {
////                if (i > j) {
////                    for (int p = 0; p <= j; ++p) {
////                        dp[i][j] =(dp[i - 1][p]+dp[i][j])%MOD;
////                    }
////                }
////                else {
////                    for (int p = j - i + 1; p <= j; ++p) {
////                        dp[i][j] =(dp[i - 1][p]+dp[i][j])%MOD;
////                    }
////                }
////            }
////        }
////        return dp[n][k];
////    }
////};
//
//
//const int MOD = 1e9 + 7;
//
//class Solution {
//public:
//    int kInversePairs(int n, int k) {
//        //前i个数逆序对数为k的次数
//        vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));
//        dp[1][0] = 1;
//        for (int i = 2; i <= n; ++i) {
//            dp[i][0] = 1;//0个逆序对只有升序排列
//            int window = 1;
//            for (int j = 1; j <= k; ++j) {
//                if (i > j) {
//                    window = (window + dp[i - 1][j]) % MOD;
//                }
//                else {
//                    window = ((window + dp[i - 1][j]) % MOD - dp[i - 1][j - i] + MOD) % MOD;
//                }
//                dp[i][j] = window;
//            }
//        }
//        return dp[n][k];
//    }
//};