//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        if (n < 2) {
//            return 0;
//        }
//        int done1 = max(0, prices[1] - prices[0]);
//        int done2 = 0;
//        int pre = max(-prices[0], -prices[1]);
//        for (int i = 2; i < n; ++i) {
//            int cur = max(done1, pre + prices[i]);
//            pre = max(pre, done2 - prices[i]);
//            done2 = done1;
//            done1 = cur;
//        }
//        return done1;
//    }
//};