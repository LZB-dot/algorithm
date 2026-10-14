//#include<iostream>
//#include<vector>
//using namespace std;
//
////class Solution {
////private:
////    int f(const vector<int>& values, int l, int r, vector<vector<int>>& dp) {
////        if (dp[l][r] != -1) {
////            return dp[l][r];
////        }
////        int ans = INT_MAX;
////        if (l == r || l == r - 1) {
////            ans = 0;
////        }
////        else {
////            for (int m = l + 1; m < r; ++m) {
////                ans = min(ans, f(values, l, m, dp) + f(values, m, r, dp) + values[l] * values[m] * values[r]);
////            }
////        }
////
////        dp[l][r] = ans;
////        return ans;
////    }
////public:
////    int minScoreTriangulation(vector<int>& values) {
////        int n = values.size();
////        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
////
////        return f(values, 0, n - 1, dp);
////    }
////};
//
//
//class Solution {
//public:
//    int minScoreTriangulation(vector<int>& values) {
//        int n = values.size();
//        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
//
//        for (int len = 3; len <= n; ++len) {
//            for (int l = 0; l + len - 1 < n; ++l) {
//                int r = l + len - 1;
//                dp[l][r] = INT_MAX;
//
//                for (int m = l + 1; m < r; ++m) {
//                    dp[l][r]= min(dp[l][r], dp[l][m] + dp[m][r] + values[l] * values[m] * values[r]);
//                }
//            }
//        }
//
//        return dp[0][n - 1];
//    }
//};