//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int m = 3;
//        int cnts[32] = { 0 };
//        for (int num : nums) {
//            for (int i = 0; i < 32; ++i) {
//                cnts[i] += (num >> i) & 1;
//            }
//        }
//
//        int ans = 0;
//        for (int i = 0; i < 32; ++i) {
//            if (cnts[i] % m != 0) {
//                ans = ans | (1 << i);
//            }
//        }
//
//        return ans;
//    }
//};