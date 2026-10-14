//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
////
////class Solution {
////public:
////    int minCost(int n, vector<int>& cuts) {
////        int m = cuts.size();
////        sort(cuts.begin(), cuts.end());
////        vector<int>arr(m + 2);
////        arr[0] = 0;
////        for (int i = 1; i <= m; ++i) {
////            arr[i] = cuts[i - 1];
////        }
////        arr[m + 1] = n;
////        vector<vector<int>>dp(m + 2, vector<int>(m + 2, -1));
////
////        return dfs(arr, 1, m, dp);
////    }
////
////    int dfs(const vector<int>& arr, int l, int r, vector<vector<int>>& dp) {
////        if (dp[l][r] != -1) {
////            return dp[l][r];
////        }
////
////        int cost = INT_MAX;
////
////        if (l > r) {
////            cost = 0;
////        }
////        else {
////            for (int k = l; k <= r; ++k) {
////                cost = min(cost, dfs(arr, l, k - 1, dp) + dfs(arr, k + 1, r, dp) );
////            }
////            cost += arr[r + 1] - arr[l - 1];
////        }
////        dp[l][r] = cost;
////        return cost;
////    }
////};
//
//
//
//class Solution {
//public:
//    int minCost(int n, vector<int>& cuts) {
//        int m = cuts.size();
//        sort(cuts.begin(), cuts.end());
//        vector<int>arr(m + 2);
//        arr[0] = 0;
//        for (int i = 1; i <= m; ++i) {
//            arr[i] = cuts[i - 1];
//        }
//        arr[m + 1] = n;
//        vector<vector<int>>dp(m + 2, vector<int>(m + 2, 0));
//
//        for (int l = m; l >= 1; --l) {
//            for (int r = l; r <= m; ++r) {
//                if (l == r) {
//                    dp[l][r] = arr[r + 1] - arr[l - 1];
//                }
//                else {
//                    dp[l][r] = INT_MAX;
//                    for (int k = l; k <= r; ++k) {
//                        dp[l][r] = min(dp[l][r], dp[l][k - 1] + dp[k + 1][r]);
//                    }
//                    dp[l][r] += arr[r + 1] - arr[l - 1];
//                }
//            }
//        }
//        return dp[1][m];
//    }
//
//};