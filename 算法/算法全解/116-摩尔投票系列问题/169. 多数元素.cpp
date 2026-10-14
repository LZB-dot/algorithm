//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int majorityElement(vector<int>& nums) {
//        int n = nums.size();
//
//        int tar;
//        int cnt = 0;
//        for (int i : nums) {
//            if (cnt == 0) {
//                tar = i;
//                cnt++;
//            }
//            else if (cnt != 0) {
//                if (i == tar)
//                    cnt++;
//                else
//                    cnt--;
//            }
//        }
//
//        cnt = 0;
//        for (int i : nums)
//            if (i == tar)
//                ++cnt;
//
//        if (cnt >= (n + 1) / 2)
//            return tar;
//        else
//            return -1;
//    }
//};