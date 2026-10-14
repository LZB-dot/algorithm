//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int maxProfit(vector<int>& prices, int fee) {
//        int n = prices.size();
//        int pre = -prices[0] - fee;
//        int none = 0;
//        for (int i = 1; i < n; ++i) {
//            none = max(none, pre + prices[i]);
//            pre = max(pre, none - prices[i] - fee);
//        }
//        return none;
//    }
//};