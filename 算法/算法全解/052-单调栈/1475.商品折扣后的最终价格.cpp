//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> finalPrices(vector<int>& prices) {
//        int n = prices.size();
//
//        vector<int>ans(n, 0);
//        for (int i = 0; i < n; ++i) {
//            ans[i] = prices[i];
//        }
//
//        vector<int>stack;
//        for (int i = 0; i < n; ++i) {
//            while (!stack.empty() && prices[i] <= prices[stack.back()]) {
//                int tmp = stack.back();
//                stack.pop_back();
//                ans[tmp] -= prices[i];
//            }
//            stack.push_back(i);
//        }
//
//        return ans;
//    }
//};