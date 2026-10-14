//#include<iostream>
//#include<vector>
//using namespace std;
//
//
////class Solution {
////public:
////    int jump(vector<int>& nums) {
////        int n = nums.size();
////        vector<int>dp(n + 1, INT_MAX);
////        dp[0] = 0;
////        for (int i = 1; i < n; ++i) {
////            for (int j = 0; j < i; ++j) {
////                if (nums[j] + j >= i && dp[j] != INT_MAX) {
////                    dp[i] = min(dp[i], dp[j] + 1);
////                    break;
////                }
////            }
////        }
////
////        return dp[n - 1];
////    }
////};
//
//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        int n = nums.size();
//        int last = n - 1;
//        int steps = 0;
//        while (last > 0) {
//            for (int i = 0; i < last; ++i) {
//                if (nums[i] + i >= last) {
//                    last = i;
//                    steps++;
//                    break;
//                }
//            }
//        }
//        return steps;
//    }
//};