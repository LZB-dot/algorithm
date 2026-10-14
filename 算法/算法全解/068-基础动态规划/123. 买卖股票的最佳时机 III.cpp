//#include<iostream>
//#include<vector>
//using namespace std;
//
//////class Solution {
//////public:
//////    int maxProfit(vector<int>& prices) {
//////        int n = prices.size();
//////        vector<int>dp1(n, 0);
//////        int mi = prices[0];
//////        for (int i = 1; i < n; ++i) {
//////            mi = min(mi, prices[i]);
//////            dp1[i] = max(dp1[i - 1], prices[i] - mi);
//////        }
//////
//////        vector<int>dp2(n, 0);
//////        for (int i = 1; i < n; ++i) {
//////            for (int j = 0; j < i; ++j) {
//////                dp2[i] = max(dp2[i], dp1[j] + prices[i] - prices[j]);
//////            }
//////        }
//////        return dp2[n - 1];
//////    }
//////};
////
////
////
////class Solution {
////public:
////    int maxProfit(vector<int>& prices) {
////        int n = prices.size();
////        vector<int>dp1(n, 0);
////        int mi = prices[0];
////        vector<int>best(n, 0);
////        best[0] = dp1[0] - prices[0];
////        vector<int>dp2(n, 0);
////
////        for (int i = 1; i < n; ++i) {
////            mi = min(mi, prices[i]);
////            dp1[i] = max(dp1[i - 1], prices[i] - mi);
////            best[i] = max(best[i - 1], dp1[i] - prices[i]);
////            dp2[i] = max(dp2[i - 1], best[i] + prices[i]);
////        }
////        return max(dp2[n - 1], dp1[n - 1]);
////    }
////};
//
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        int dp1 = 0;
//        int mi = prices[0];
//        int best = 0;
//        best = dp1 - prices[0];
//        int dp2 = 0;
//
//        for (int i = 1; i < n; ++i) {
//            mi = min(mi, prices[i]);
//            dp1 = max(dp1, prices[i] - mi);
//            best= max(best, dp1 - prices[i]);
//            dp2 = max(dp2, best + prices[i]);
//        }
//        return max(dp2, dp1);
//    }
//};