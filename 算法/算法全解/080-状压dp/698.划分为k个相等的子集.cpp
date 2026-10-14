//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    bool canPartitionKSubsets(vector<int>& nums, int k) {
//        int sum = 0;
//        for (int i : nums) {
//            sum += i;
//        }
//
//        if (sum % k != 0) {
//            return false;
//        }
//
//        int size = sum / k;
//        int n = nums.size();
//        vector<int>dp(1 << n);
//        return dfs(nums, size, (1 << n) - 1, 0, k, dp);
//    }
//
//    bool dfs(const vector<int>& nums, int target, int status,int cur, int rest, vector<int>& dp) {
//        if (rest == 0) {
//            return status == 0;
//        }
//
//        if (dp[status] != 0) {
//            return dp[status] == 1;
//        }
//
//        bool ans = false;
//        for (int i = 0; i < nums.size(); ++i) {
//            if ((status & (1 << i)) && cur + nums[i] <= target) {
//                if (cur + nums[i] == target) {
//                    ans = dfs(nums, target, status ^ (1 << i), 0, rest - 1, dp);
//                }
//                else {
//                    ans = dfs(nums, target, status ^ (1 << i), cur + nums[i], rest, dp);
//                }
//            }
//            if (ans) {
//                break;
//            }
//        }
//        dp[status] = ans ? 1 : -1;
//        return ans;
//    }
//};