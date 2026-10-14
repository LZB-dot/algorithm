//#include<iostream>
//#include<vector>
//#include<deque>
//using namespace std;
//
//class Solution {
//public:
//    int shortestSubarray(vector<int>& nums, int k) {
//        int n = nums.size();
//        vector<long long>sum(n + 1, 0);
//        
//        for (int i = 0; i < n; ++i) {
//            //sum[i]是到i-1个元素的前缀和
//            sum[i + 1] = sum[i] + nums[i];
//        }
//        
//        deque<int>dq;
//        int ans = INT_MAX;
//        for (int r = 0; r <= n; ++r) {
//            //从队头找满足条件的最小j
//            while (!dq.empty() && sum[r] - sum[dq.front()] >= k) {
//                ans = min(ans, r - dq.front());
//                dq.pop_front();
//            }
//            //维护单调性确保sum[dq]严格递增
//            while (!dq.empty() && sum[dq.back()] >= sum[r]) {
//                dq.pop_back();
//            }
//
//            dq.push_back(r);
//        }
//        return ans == INT_MAX ? -1 : ans;
//    }
//};