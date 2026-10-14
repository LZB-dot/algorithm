//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 1) {
//            return nums[0];
//        }
//
//        int case1 = work(nums, 1, n - 1);//不偷第0间
//        int case2 = work(nums, 0, n - 2);//不偷最后一间
//
//        return max(case1, case2);
//    }
//
//    int work(const vector<int>& nums, int l, int r) {
//        if (l > r) {
//            return 0;
//        }
//
//        if (l == r) {
//            return nums[l];
//        }
//
//        if (l + 1 == r) {
//            return max(nums[l], nums[r]);
//        }
//
//        int prePre = nums[l];
//        int pre = max(nums[l], nums[l + 1]);
//        for (int i = l + 2; i <= r; ++i) {
//            int cnt = max(pre, prePre + nums[i]);
//            prePre = pre;
//            pre = cnt;
//        }
//
//        return pre;
//    }
//};
//
