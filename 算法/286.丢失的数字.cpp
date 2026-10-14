//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int a = 0, b = 0;
//        for (int i = 0; i < nums.size(); ++i) {
//            a ^= i;
//            b ^= nums[i];
//        }
//        a ^= nums.size();
//        int ans = a ^ b;
//        return ans;
//    }
//};