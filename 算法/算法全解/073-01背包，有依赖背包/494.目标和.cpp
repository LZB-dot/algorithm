 //#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
////class Solution {
////private:
////    unordered_map<int, unordered_map<int, int>>memo;
////    int dfs(const vector<int>& nums, int n, int target, int i,int sum) {
////        if (i == n) {
////            return sum == target ? 1 : 0;
////        }
////        if (memo.count(i) && memo[i].count(sum)) {
////            return memo[i][sum];
////        }
////
////        int case1 = dfs(nums, n, target, i + 1, sum + nums[i]);
////        int case2 = dfs(nums, n, target, i + 1, sum - nums[i]);
////
////        memo[i][sum] = case1 + case2;
////        return memo[i][sum];
////    }
////public:
////    int findTargetSumWays(vector<int>& nums, int target) {
////        int n = nums.size();
////        return dfs(nums, n, target, 0, 0);
////    }
////};
//
//
////class Solution {
////public:
////    int findTargetSumWays(vector<int>& nums, int target) {
////        int n = nums.size();
////        int total = 0;
////        for (int num : nums) {
////            total += num;
////        }
////        if (target > total || target < -total || (target + total) % 2 != 0) {
////            return 0;
////        }
////
////        //+:sumA    -:sumB
////        //sumA+sumB=target
////        //sumA-sumB=total
////        //相加得:sumA=(target+total)/2;
////        int sumA = ((target + total) >> 1);
////        //前i个元素和为j的可能数量
////        vector<vector<int>>dp(n + 1, vector<int>(sumA + 1, 0));
////        dp[0][0] = 1;
////        for (int i = 1; i <= n; ++i) {
////            for (int j = 0; j <= sumA; ++j) {
////                dp[i][j] = dp[i - 1][j];
////                if (j >= nums[i - 1]) {
////                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
////                }
////
////            }
////        }
////
////        return dp[n][sumA];
////    }
////};
//
//
//
//class Solution {
//public:
//    int findTargetSumWays(vector<int>& nums, int target) {
//        int n = nums.size();
//        int total = 0;
//        for (int num : nums) {
//            total += num;
//        }
//        if (target > total || target < -total || (target + total) % 2 != 0) {
//            return 0;
//        }
//
//        //+的放sumA    -的放sumB
//        //sumA+sumB=target
//        //sumA-sumB=total
//        //相加得:sumA=(target+total)/2;
//        int sumA = ((target + total) >> 1);
//        //和为j的可能数量
//        vector<int>dp(sumA + 1, 0);
//        dp[0] = 1;
//        for (int i = 1; i <= n; ++i) {
//            for (int j = sumA; j >= nums[i - 1]; --j) {
//                dp[j] += dp[j - nums[i - 1]];
//            }
//        }
//
//        return dp[sumA];
//    }
//};