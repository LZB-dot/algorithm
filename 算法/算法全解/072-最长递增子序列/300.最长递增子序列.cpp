//#include<iostream>
//#include<vector>
//using namespace std;
//
////class Solution {
////public:
////    int lengthOfLIS(vector<int>& nums) {
////        int n = nums.size();
////
////        vector<int>dp(n + 1, 1);
////        int ans = 1;
////
////        for (int i = 0; i < n; ++i) {
////            for (int j = 0; j < i; ++j) {
////                if (nums[j] < nums[i]) {
////                    dp[i] = max(dp[i], dp[j] + 1);
////                }
////            }
////            ans = max(ans, dp[i]);
////        }
////
////        return ans;
////    }
////};
//
//class Solution {
//private:
//    //二分查找在ends数组中找到第一个大于等于num的位置
//    int binarySearch(vector<int>& ends, int len, int num) {
//        int left = 0, right = len - 1;
//        int pos = -1;
//        while (left <= right) {
//            int mid = left + ((right - left) >> 1);
//            if (ends[mid] >= num) {
//                pos = mid;
//                right = mid - 1;
//            }
//            else {
//                left = mid + 1;
//            }
//        }
//        return pos;
//    }
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        int n = nums.size();
//        vector<int>ends(n + 1, 0);
//        int len = 0;
//
//        for (int i = 0; i < n; ++i) {
//            int pos = binarySearch(ends, len, nums[i]);
//            if (pos == -1) {
//                ends[len++] = nums[i];
//            }
//            else {
//                ends[pos] = nums[i];
//            }
//        }
//
//        return len;
//    }
//};