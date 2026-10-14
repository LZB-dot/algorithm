//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//
//class Solution {
//public:
//    int smallestDistancePair(vector<int>& nums, int k) {
//        sort(nums.begin(), nums.end());
//
//        auto f = [&](int mid) {
//            int n = nums.size();
//            int cnts = 0;
//            //[l,r)
//            for (int l = 0, r = 0; l < n; ++l) {
//                while (r < n && nums[r] - nums[l] <= mid) {
//                    ++r;
//                }
//                cnts += r - l - 1;
//            }
//            return cnts;
//            };
//        int l = 0, r = nums.back() - nums[0];
//        int ans = 0;
//        while (l <= r) {
//            int mid = l + ((r - l) >> 1);
//            int times = f(mid);
//            if (times >= k) {
//                ans = mid;
//                r = mid - 1;
//            }
//            else {
//                l = mid + 1;
//            }
//        }
//        return ans;
//    }
//};
