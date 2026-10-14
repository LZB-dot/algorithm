//
//#include<iostream>
//#include<vector>
//#include<algorithm> 
//using namespace std;
//
//class Solution {
//public:
//    int lastStoneWeightII(vector<int>& stones) {
//        int total_sum = 0;
//        for (int stone : stones) {
//            total_sum += stone;
//        }
//
//        int target = total_sum / 2;
//
//        // dp[j] 表示在容量为 j 的背包中，能装下的最大石头重量
//        vector<int> dp(target + 1, 0);
//
//        // 0-1 背包问题求解
//        for (int stone : stones) {
//            // 从后往前遍历，防止同一个石头被多次使用
//            for (int j = target; j >= stone; --j) {
//                dp[j] = max(dp[j], dp[j - stone] + stone);
//            }
//        }
//
//        // 最终结果是 total_sum - 2 * dp[target]
//        return total_sum - 2 * dp[target];
//    }
//};
//
