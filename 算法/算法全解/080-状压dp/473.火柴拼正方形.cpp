//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//class Solution {
//public:
//    bool makesquare(vector<int>& matchsticks) {
//        int sum = 0;
//        for (int i : matchsticks) {
//            sum += i;
//        }
//
//        if (sum % 4 != 0) {
//            return false;
//        }
//
//        int side = sum >> 2;
//        int n = matchsticks.size();
//        vector<int>dp(1 << n, 0);
//        return dfs(matchsticks, side, (1 << n) - 1, 0, 4, dp);
//    }
//
//    bool dfs(const vector<int>& matchsticks, int side, int status, int cur, int rest, vector<int>& dp) {
//        if (rest == 0) {
//            return status == 0;
//        }
//
//        if (dp[status] != 0) {
//            return dp[status] == 1;
//        }
//
//        bool ans = false;
//        for (int i = 0; i < matchsticks.size(); ++i) {
//            if (((1 << i) & status) && cur + matchsticks[i] <= side) {
//                if (cur + matchsticks[i] == side) {
//                    ans = dfs(matchsticks, side, (1 << i) ^ status, 0, rest - 1, dp);
//                }
//                else {
//                    ans = dfs(matchsticks, side, (1 << i) ^ status, cur + matchsticks[i], rest, dp);
//                }
//            }
//            if (ans) {
//                break;
//            }
//        }
//
//        dp[status] = ans ? 1 : -1;
//        return ans;
//    }
//};