//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int trap(vector<int>& height) {
//        int ans = 0;
//        int n = height.size();
//        int l = 1, r = n - 2;
//        int lmax = height[0], rmax = height[n - 1];
//
//        while (l <= r) {
//            if (lmax <= rmax) {
//                ans += max(0, lmax - height[l]);
//                lmax = max(lmax, height[l]);
//                l++;
//            }
//            else {
//                ans += max(0, rmax - height[r]);
//                rmax = max(rmax, height[r]);
//                r--;
//            }
//        }
//
//        return ans;
//    }
//};