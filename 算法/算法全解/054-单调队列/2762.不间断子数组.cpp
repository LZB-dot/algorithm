//
//
//#include<iostream>
//#include<vector>
//#include<deque>
//using namespace std;
//
//
//class Solution {
//public:
//    long long continuousSubarrays(vector<int>& nums) {
//        long long ans = 0;
//        int n = nums.size();
//        deque<int>mindq, maxdq;
//        int l = 0;
//
//        mindq.push_back(0);
//        maxdq.push_back(0);
//        
//        for (int r = 0; r < n; ++r) {
//            while (!mindq.empty() && nums[r] <= nums[mindq.back()]) {
//                mindq.pop_back();
//            }
//            mindq.push_back(r);
//
//            while (!maxdq.empty() && nums[r] >= nums[maxdq.back()]) {
//                maxdq.pop_back();
//            }
//            maxdq.push_back(r);
//
//            while (nums[maxdq.front()] - nums[mindq.front()] > 2) {
//                if (maxdq.front() == l) {
//                    maxdq.pop_front();
//                }
//                if (mindq.front() == l) {
//                    mindq.pop_front();
//                }
//                l++;
//            }
//
//            ans += r - l + 1;
//        }
//
//        return ans;
//    }
//};