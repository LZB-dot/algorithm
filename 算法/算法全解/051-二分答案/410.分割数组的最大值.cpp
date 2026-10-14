//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int splitArray(vector<int>& nums, int k) {
//
//        auto f = [&](int mid) {
//            int part = 1;
//            int sum = 0;
//            for (int num : nums) {
//                if (num > mid) {
//                    return INT_MAX;
//                }
//                if (sum + num > mid) {
//                    ++part;
//                    sum = num;
//                }
//                else {
//                    sum += num;
//                }
//            }
//            return part;
//        };
//
//        int r = 0;
//        for (int i : nums) {
//            r += i;
//        }
//
//        int l = *max_element(nums.begin(), nums.end());
//        int ans = r;
//        while (l <= r) {
//            //这可以避免相加越界
//            int mid = l + ((r - l) >> 1);
//            int parts = f(mid);
//            if (parts <= k) {
//                ans = mid;
//                r = mid - 1;
//            }
//            else {
//                l = mid + 1;
//            }
//        }
//
//        return ans;
//    }
//};