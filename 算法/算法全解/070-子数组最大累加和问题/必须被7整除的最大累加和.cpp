//#include<iostream>
//#include<vector>
//#include<climits>
//#include<algorithm>
//using namespace std;
//
//// 动态规划解法（修正后）
//int maxSumDivisibleBy7(vector<int>& nums) {
//    int n = nums.size();
//    // dp[i][j]：前i个元素中，子序列和模7为j的最大累加和
//    vector<vector<int>> dp(n + 1, vector<int>(7, INT_MIN));
//    dp[0][0] = 0; // 初始状态：0个元素，和为0，模7为0
//
//    for (int i = 1; i <= n; ++i) {
//        int num = nums[i - 1];
//        int mod = num % 7;
//
//        // 先复制上一轮状态（不选当前元素的情况）
//        for (int j = 0; j < 7; ++j) {
//            dp[i][j] = dp[i - 1][j];
//        }
//
//        // 考虑选当前元素的情况
//        for (int j = 0; j < 7; ++j) {
//            if (dp[i - 1][j] != INT_MIN) { // 上一轮状态有效
//                int new_mod = (j + mod) % 7; // 新余数 = 上一轮余数 + 当前数余数，模7
//                dp[i][new_mod] = max(dp[i][new_mod], dp[i - 1][j] + num);
//            }
//        }
//    }
//
//    // 若所有子序列和都不能被7整除，返回0（题目隐含“可选择空序列”，和为0）
//    return dp[n][0] == INT_MIN ? 0 : dp[n][0];
//}
//
//// 递归验证函数（暴力枚举所有子序列，适合小规模数组验证）
//int violence(vector<int>& nums, int i, int current_sum) {
//    if (i == nums.size()) {
//        // 递归终止：若当前和能被7整除，返回当前和；否则返回0（空序列）
//        return current_sum % 7 == 0 ? current_sum : 0;
//    }
//    // 两种选择：不选当前元素 / 选当前元素，取最大值
//    int not_choose = violence(nums, i + 1, current_sum);
//    int choose = violence(nums, i + 1, current_sum + nums[i]);
//    return max(not_choose, choose);
//}
//
