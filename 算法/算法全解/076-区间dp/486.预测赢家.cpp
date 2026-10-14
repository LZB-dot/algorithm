//
//#include<iostream>
//#include<vector>
//using namespace std;
//
////class Solution {
////
////private:
////    int f(const vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
////        if (dp[l][r] != -1) {
////            return dp[l][r];
////        }
////        
////        int ans = 0;
////        if (l == r) {
////            ans = nums[l];
////        }
////        else if (l + 1 == r) {
////            ans = max(nums[l], nums[r]); 
////        }
////        else {
////            int c1 = nums[l] + min(f(nums, l + 1, r - 1, dp), f(nums, l + 2, r, dp));
////            int c2 = nums[r] + min(f(nums, l + 1, r - 1, dp), f(nums, l, r - 2, dp));
////            ans = max(c1, c2);
////        }
////
////        dp[l][r] = ans;
////        return ans;
////    }
////public:
////    bool predictTheWinner(vector<int>& nums) {
////        int sum = 0;
////        for (int num : nums) {
////            sum += num;
////        }
////        int n = nums.size();
////        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
////        
////        int first = f(nums, 0, n - 1, dp);
////        int second = sum - first;
////
////        return first >= second;
////    }
////};
//
//
//class Solution {
//
//public:
//    bool predictTheWinner(vector<int>& nums) {
//        int sum = 0;
//        for (int num : nums) {
//            sum += num;
//        }
//        int n = nums.size();
//        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
//
//        for (int i = 0; i < n; ++i) {
//            dp[i][i] = nums[i];
//        }
//
//        for (int i = 0; i < n - 1; ++i) {
//            dp[i][i+1] = max(nums[i], nums[i + 1]);
//        }
//
//        for (int i = n - 3; i >= 0; --i) {
//            for (int j = i + 2; j < n; ++j) {
//                dp[i][j] = max(
//                    nums[i] + min(dp[i + 1][j - 1], dp[i + 2][j]),
//                    nums[j] + min(dp[i][j - 2], dp[i + 1][j - 1])
//                );
//            }
//        }
//        
//        return dp[0][n - 1] >= (sum - dp[0][n - 1]);
//    }
//};
