//
//////https://leetcode.cn/problems/closest-subsequence-sum/
//
//
////#include<iostream>
////#include<vector>
////#include<algorithm>
////using namespace std;
////
////class Solution {
////private:
////    void compute(int s, int e, long long cnt,
////        vector<long long>& sum, const vector<int>& nums) {
////        if (s > e) {
////            sum.push_back(cnt);
////            return;
////        }
////
////        compute(s + 1, e, cnt + nums[s], sum, nums);
////        compute(s + 1, e, cnt , sum, nums);
////    }
////public:
////    int minAbsDifference(vector<int>& nums, int goal) {
////        int n = nums.size();
////        int mid = n >> 1;
////        vector<long long>lsum, rsum;
//// 
////        compute(0, mid, 0, lsum, nums);
////        compute(mid + 1, n - 1, 0, rsum, nums);
//// 
////        sort(lsum.begin(), lsum.end());
////        sort(rsum.begin(), rsum.end());
//// 
////        int j = rsum.size() - 1;
////        int ans = INT_MAX;
//// 
////        for (long long i : lsum) {
////            long long target = goal - i;
////            while (j >= 0 && rsum[j] > target) {
////                ans = min(ans, (int)(rsum[j] - target));
////                --j;
////            }
////            
////            if (j >= 0) {
////                ans = min(ans, (int)abs(rsum[j] - target));
////            }
////        }
////        return ans;
////    }
////};
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//typedef long long ll;
//
//class Solution {
//private:
//    void dfs(int l, int r, ll cur, vector<ll>& sum, const vector<int>& nums) {
//        if (l > r) {
//            sum.push_back(cur);
//            return;
//        }
//
//        dfs(l + 1, r, cur, sum, nums);
//        dfs(l + 1, r, cur + nums[l], sum, nums);
//    }
//
//public:
//    int minAbsDifference(vector<int>& nums, int goal) {
//        int n = nums.size();
//        int mid = n / 2;
//
//        vector<ll> lsum, rsum;
//
//        dfs(0, mid - 1, 0, lsum, nums);
//        dfs(mid, n - 1, 0, rsum, nums);
//
//        sort(lsum.begin(), lsum.end());
//        lsum.erase(unique(lsum.begin(), lsum.end()), lsum.end());
//
//        sort(rsum.begin(), rsum.end());
//        rsum.erase(unique(rsum.begin(), rsum.end()), rsum.end());
//
//        ll ans = llabs((ll)goal);
//
//        for (ll a : lsum) {
//            ll target = (ll)goal - a;
//            auto it = lower_bound(rsum.begin(), rsum.end(), target);
//
//            if (it != rsum.end()) 
//                ans = min(ans, llabs(*it - target));
//            
//            if (it != rsum.begin()) 
//                ans = min(ans, llabs(*prev(it) - target));
//            
//            if (ans == 0) 
//                break; 
//        }
//
//        return ans;
//    }
//};