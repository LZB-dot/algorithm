//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//
//class Solution {
//public:
//    int maxProduct(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 1) {
//            return nums[0];
//        }
//
//        int maxVal = nums[0];
//        int minVal = nums[0];
//        int ans = nums[0];
//
//        for (int i = 1; i < n; ++i) {
//            int tmp = maxVal;
//            maxVal = max({ nums[i],maxVal * nums[i],minVal * nums[i] });
//            minVal = min({ nums[i],tmp * nums[i],minVal * nums[i] });
//            ans = max(maxVal, ans);
//        }
//
//        return ans;
//    }
//};