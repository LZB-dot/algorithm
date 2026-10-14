//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//
//
//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        int n = nums.size();
//        if (n <= 1) {
//            return true;
//        }
//        int best = 0;
//        for (int i = 0; i < n; ++i) {
//            if (i <= best) {
//                best = max(best, i + nums[i]);
//                if (best >= n - 1) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//};