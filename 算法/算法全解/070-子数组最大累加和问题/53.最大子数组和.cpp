//#include<iostream>
//#include<vector>
//using namespace std;
//
////class Solution {
////public:
////    int maxSubArray(vector<int>& nums) {
////        int n = nums.size();
////        vector<int>dp(n + 1, INT_MIN);
////        dp[0] = nums[0];
////        int ans = dp[0];
////        for (int i = 1; i < n; ++i) {
////            if (dp[i - 1] + nums[i] > nums[i]) {
////                dp[i] = dp[i - 1] + nums[i];
////            }
////            else {
////                dp[i] = nums[i];
////            }
////
////            if (dp[i] > ans) {
////                ans = dp[i];
////            }
////        }
////        return ans;
////    }
////};
//
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int n = nums.size();
//        int pre = nums[0];
//        int ans = pre;
//        for (int i = 1; i < n; ++i) {
//
//            pre = max(pre, pre + nums[i]);
//
//            if (pre > ans) {
//                ans = pre;
//            }
//        }
//        return ans;
//    }
//};