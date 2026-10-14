
//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//
//class Solution {
//public:
//    int minimumIndex(vector<int>& nums) {
//        int n = nums.size();
//
//        int tar;
//        int cnt = 0;
//
//        for (int i : nums) {
//            if (cnt == 0) {
//                tar = i;
//                ++cnt;
//            }
//            else {
//                if (tar == i)
//                    ++cnt;
//                else
//                    --cnt;
//            }
//        }
//
//        cnt = 0;
//        for (int i : nums)
//            if (i == tar)
//                ++cnt;
//
//        int ln = 0, rn = 0;
//
//        for (int i = 0; i < n - 1; ++i) {
//            if (nums[i] == tar)
//                ++ln;
//
//            rn = cnt - ln;
//
//            if (ln > (i + 1) / 2 && rn > (n - i - 1) / 2)
//                return i;
//
//        }
//        return -1;
//    }
//};