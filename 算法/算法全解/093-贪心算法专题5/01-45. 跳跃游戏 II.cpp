//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        int n = nums.size();
//        int right = 0;//当前cur覆盖范围下，下一步到达最远位置
//        int cur = 0;//当前跳跃步数达到的最远位置
//        int ans = 0;//步数
//        for (int i = 0; i < n - 1; ++i) {
//            right = max(right, nums[i] + i);
//            if (cur == i) {
//                ans++;
//                cur = right;
//            }
//        }
//
//        return ans;
//    }
//};