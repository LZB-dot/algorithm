//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        int mi = prices[0], ans = 0;
//        for (int i = 1; i < n; ++i) {
//            mi = min(prices[i], mi);
//            ans = max(prices[i] - mi, ans);
//        }
//        return ans;
//    }
//};