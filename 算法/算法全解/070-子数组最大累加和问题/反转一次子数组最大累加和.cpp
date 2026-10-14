//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//    int maxSumReverse(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 0) return 0;
//
//        // 1. 计算不翻转时的最大子数组和（Kadane 算法）
//        int max_kadane = kadane(nums);
//
//        // 2. 计算翻转后可能的最大子数组和
//        // left_max[i]: nums[0..i] 的最大后缀和
//        vector<int> left_max(n);
//        left_max[0] = nums[0];
//        for (int i = 1; i < n; ++i) {
//            left_max[i] = max(nums[i], left_max[i - 1] + nums[i]);
//        }
//
//        // right_max[i]: nums[i..n-1] 的最大前缀和
//        vector<int> right_max(n);
//        right_max[n - 1] = nums[n - 1];
//        for (int i = n - 2; i >= 0; --i) {
//            right_max[i] = max(nums[i], right_max[i + 1] + nums[i]);
//        }
//
//        // 枚举分割点 i，拼接 left_max[i] 和 right_max[i+1]
//        int max_reverse = INT_MIN;
//        for (int i = 0; i < n - 1; ++i) {
//            max_reverse = max(max_reverse, left_max[i] + right_max[i + 1]);
//        }
//
//        // 3. 取最大值
//        return max(max_kadane, max_reverse);
//    }
//
//private:
//    int kadane(vector<int>& nums) {
//        int max_current = nums[0];
//        int max_global = nums[0];
//        for (int i = 1; i < nums.size(); ++i) {
//            max_current = max(nums[i], max_current + nums[i]);
//            max_global = max(max_global, max_current);
//        }
//        return max_global;
//    }
//};