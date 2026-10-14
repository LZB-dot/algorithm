//#include<iostream>
//#include<vector>
//#include<cstring>  
//#include<algorithm> 
//using namespace std;
//
//class Solution {
//private:
//    const int MOD = 1e9 + 7;
//    int cnt[31];
//    // 预处理：每个数的质数因子状态（位掩码），0表示无效（含重复质数因子）
//    int own[31] = {
//        0b0000000000, // 0
//        0b0000000000, // 1
//        0b0000000001, // 2
//        0b0000000010, // 3 
//        0b0000000000, // 4 
//        0b0000000100, // 5 
//        0b0000000011, // 6 
//        0b0000001000, // 7 
//        0b0000000000, // 8 
//        0b0000000000, // 9 
//        0b0000000101, // 10 
//        0b0000010000, // 11 
//        0b0000000000, // 12 
//        0b0000100000, // 13 
//        0b0000001001, // 14 
//        0b0000000110, // 15 
//        0b0000000000, // 16 
//        0b0001000000, // 17 
//        0b0000000000, // 18 
//        0b0010000000, // 19 
//        0b0000000000, // 20
//        0b0000001010, // 21
//        0b0000010001, // 22 
//        0b0100000000, // 23 
//        0b0000000000, // 24 
//        0b0000000000, // 25 
//        0b0000100001, // 26 
//        0b0000000000, // 27 
//        0b0000000000, // 28 
//        0b1000000000, // 29 
//        0b0000000111  // 30 
//    };
//
//
//    int dp[31][1 << 10]; //dp[i][s]表示处理前i个数，状态为s时的好子集数量
//
//    //i是当前处理的数，status是已使用的质数状态，cnt是各数的计数数组
//    int dfs(int i, int status) {
//        if (dp[i][status] != -1) {
//            return dp[i][status];
//        }
//
//        int ans = 0;
//        if (i == 1) {
//            if (status == 0) {
//                ans = 1;
//                for (int j = 0; j < cnt[1]; ++j) {
//                    ans = (ans << 1) % MOD;
//                }
//            }
//        }
//        else {
//            ans = dfs(i - 1, status) % MOD;
//            if (own[i] != 0 && cnt[i] != 0 && (status & own[i]) == own[i]) {
//                ans = (int)((ans + (long long)dfs(i - 1, status ^ own[i]) * cnt[i]) % MOD);
//            }
//        }
//
//        dp[i][status] = ans;
//        return ans;
//
//    }
//
//public:
//    int numberOfGoodSubsets(vector<int>& nums) {
//
//        for (int num : nums) {
//            cnt[num]++;
//        }
//        memset(dp, -1, sizeof(dp));
//        int ans = 0;
//        for (int s = 1; s < (1 << 10); ++s) {
//            ans = (dfs(30, s) + ans) % MOD;
//        }
//        return ans;
//    }
//};