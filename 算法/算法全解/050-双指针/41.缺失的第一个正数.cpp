//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int firstMissingPositive(vector<int>& nums) {
//        int n = nums.size();
//        int l = 0, r = n - 1;
//
//        // 原地哈希：将有效正整数放到正确位置（nums[x-1] = x）
//        while (l <= r) {  //循环到 l > r，确保所有元素处理完毕
//            if (nums[l] == l + 1) {
//                // 当前元素位置正确，处理下一个
//                ++l;
//            }
//            else if (nums[l] <= l || nums[l] > r + 1 || nums[nums[l] - 1] == nums[l]) {
//                // 元素无效（<=当前左边界/超出右边界/已存在重复值），交换到末尾并缩小右边界
//                swap(nums[l], nums[r--]);
//            }
//            else {
//                // 元素有效但位置错误，交换到正确位置（nums[x-1]）
//                swap(nums[l], nums[nums[l] - 1]);
//            }
//        }
//
//        // 遍历数组，找到第一个缺失的正整数
//        for (int i = 0; i < n; ++i) {
//            if (nums[i] != i + 1) {
//                return i + 1;
//            }
//        }
//
//        // 所有正整数都存在，返回 n+1
//        return n + 1;
//    }
//};