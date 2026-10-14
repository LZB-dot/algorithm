//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//class Solution {
//public:
//    bool canIWin(int maxChoosableInteger, int desiredTotal) {
//        if (desiredTotal == 0) {
//            return true;
//        }
//        int sum = maxChoosableInteger * ((maxChoosableInteger + 1) >> 1);
//        if (sum < desiredTotal) {
//            return false;
//        }
//
//        //0未计算，1当前状态先手赢，-1当前状态先手输
//        vector<int>dp(1 << (maxChoosableInteger + 1), 0);
//        return dfs(maxChoosableInteger, 0, desiredTotal, dp);
//    }
//
//    bool dfs(int n, int status, int rest, vector<int>& dp) {
//        if (dp[status] != 0) {
//            return dp[status] == 1;
//        }
//
//        for (int i = 1; i <= n; ++i) {
//            //数字未被选该状态为0
//            if (((1 << i) & status) == 0) {
//                if (i >= rest) {
//                    dp[status] = 1;
//                    return true;
//                }
//                if (!dfs(n, status | (1 << i), rest - i, dp)) {
//                    dp[status] = 1;
//                    return true;
//                }
//            }
//        }
//        dp[status] = -1;
//        return false;
//    }
//};