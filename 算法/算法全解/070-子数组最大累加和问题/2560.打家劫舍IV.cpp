//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int minCapability(vector<int>& nums, int k) {
//        int n = nums.size();
//        int left = INT_MAX, right = INT_MIN;
//        for (int num : nums) {
//            left = min(num, left);
//            right = max(num, right);
//        }
//        int ans = 0;
//        while (left < right) {
//            int mid = left + ((right - left) >> 1);
//            if (rob(nums, n, mid) >= k) {
//                ans = mid;
//                right = mid - 1;
//            }
//            else {
//                left = mid + 1;
//            }
//        }
//
//        return ans;
//    }
//
//    int rob(const vector<int>& nums, int n, int mid) {
//        if (n == 1) {
//            return nums[0] <= mid ? 1 : 0;
//        }
//
//        if (n == 2) {
//            return (nums[0] <= mid || nums[1] <= mid) ? 1 : 0;
//        }
//
//        int prePre = nums[0] <= mid ? 1 : 0;
//        int pre = (nums[0] <= mid || nums[1] <= mid) ? 1 : 0;;
//
//        for (int i = 2; i < n; ++i) {
//            int cnt = max(prePre + (nums[i] <= mid ? 1 : 0), pre);
//            prePre = pre;
//            pre = cnt;
//        }
//
//        return pre;
//    }
//};