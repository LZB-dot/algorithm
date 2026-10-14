//#include<iostream>
//#include<vector>
//#include<deque>
//using namespace std;
//
////³¬Ê±
////class Solution {
////public:
////    int maxResult(vector<int>& nums, int k) {
////        int n = nums.size();
////        vector<int>dp(n + 1, INT_MIN);
////        dp[0] = nums[0];
////        for (int i = 1; i < n; ++i) {
////            for (int j = max(0, i - k); j < i; ++j) {
////                dp[i] = max(dp[i], dp[j] + nums[i]);
////            }
////        }
////
////        return dp[n - 1];
////    }
////};
//
//
//
//class Solution {
//public:
//    int maxResult(vector<int>& nums, int k) {
//        int n = nums.size();
//        vector<int>dp(n + 1, INT_MIN);
//        deque<int>q;
//        dp[0] = nums[0];
//        q.push_back(0);
//        for (int i = 1; i < n; ++i) {
//            while (!q.empty() && q.front() < i - k) {
//                q.pop_front();
//            }
//
//            dp[i] = dp[q.front()] + nums[i];
//
//            while (!q.empty() && dp[q.back()] < dp[i]) {
//                q.pop_back();
//            }
//            q.push_back(i);
//
//        }
//
//        return dp[n - 1];
//    }
//};