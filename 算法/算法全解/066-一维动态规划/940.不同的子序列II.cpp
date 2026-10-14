//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//    int distinctSubseqII(string s) {
//        int n = s.size();
//        const int MOD = 1e9 + 7;
//
//        vector<int> dp(26, 0); //以字符i结尾的不同子序列个数
//        long long all = 1; 
//
//        for (char ch : s) {
//            int c = ch - 'a';
//            // 新增的子序列数 = 之前所有子序列数 - 之前以i结尾的子序列数（避免重复）
//            long long newAdd = (all - dp[c] + MOD) % MOD;
//            // 总子序列数 += 新增的子序列数
//            all = (all + newAdd) % MOD;
//            // 更新以c结尾的子序列数（之前的 + 新增的）
//            dp[c] = (dp[c] + newAdd) % MOD;
//        }
//
//        // 减去初始的空子序列
//        return (all - 1 + MOD) % MOD;
//    }
//};