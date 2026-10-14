//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> sortArrayByParityII(vector<int>& nums) {
//        int n = nums.size();
//        for (int even = 0, odd = 1; odd < n && even < n;) {
//            if ((nums[n - 1] & 1) == 1) {
//                swap(nums[n - 1], nums[odd]);
//                odd += 2;
//            }
//            else {
//                swap(nums[n - 1], nums[even]);
//                even += 2;
//            }
//        }
//        return nums;
//    }
//};