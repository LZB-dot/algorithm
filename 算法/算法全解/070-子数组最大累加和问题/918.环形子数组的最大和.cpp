//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int maxSubarraySumCircular(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 1) {
//            return nums[0];
//        }
//
//        //子数组不跨越首尾即正常求
//        //子数组跨越首尾则用整个数组减去不跨越首尾的最小和
//        int sum = nums[0];
//        int maxSum = nums[0];
//        int minSum = nums[0];
//        int maxPre = nums[0];
//        int minPre = nums[0];
//
//        for (int i = 1; i < n; ++i) {
//            sum += nums[i];
//            maxPre = max(nums[i], nums[i] + maxPre);
//            maxSum = max(maxSum, maxPre);
//            minPre = min(nums[i], nums[i] + minPre);
//            minSum = min(minSum, minPre);
//        }
//
//        //数组全为负数，则等于单个元素的最大值
//        return sum == minSum ? maxSum : max(maxSum, sum - minSum);
//    }
//};