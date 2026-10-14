//#include<iostream>
//#include<vector>
//using namespace std;
////
////class Solution {
////private:
////    vector<vector<vector<int>>>dp;
////
////    bool dfs(int i, int j, int len, string s1, string s2) {
////        if (dp[i][j][len] != -1) {
////            return dp[i][j][len] == 1;
////        }
////        if (len == 1) {
////            return s1[i] == s2[j];
////        }
////
////        for (int k = 1; k < len; ++k) {
////            if (dfs(i, j, k, s1, s2) && dfs(i + k, j + k, len - k, s1, s2)) {
////                dp[i][j][len] = 1;
////                return true;
////            }
////
////            if (dfs(i, j + len - k, k, s1, s2) && dfs(i + k, j, len - k, s1, s2)) {
////                dp[i][j][len] = 1;
////                return true;
////            }
////        }
////
////        dp[i][j][len] = 0;
////        return dp[i][j][len];
////        
////    }
////public:
////    bool isScramble(string s1, string s2) {
////        int n = s1.size();
////        dp.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
////        return dfs(0, 0, n, s1, s2);
////    }
////};
//
//class Solution {
//public:
//    bool isScramble(string s1, string s2) {
//        int n = s1.size();
//        if (n != s2.size()) return false; // 长度不同直接返回false
//        if (n == 0) return true; // 空字符串特殊处理
//
//        // 初始化dp[i][j][len]：表示s1[i..i+len-1]与s2[j..j+len-1]是否为扰乱字符串
//        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
//
//        // 长度为1的子串：直接比较字符
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                dp[i][j][1] = (s1[i] == s2[j]);
//            }
//        }
//
//        // 按长度递增处理
//        for (int len = 2; len <= n; ++len) {
//            // s1的起始索引i，保证子串长度为len时不越界
//            for (int i = 0; i + len <= n; ++i) {
//                // s2的起始索引j，同样保证不越界
//                for (int j = 0; j + len <= n; ++j) {
//                    // 尝试拆分成长度k和len-k的两部分（k从1到len-1）
//                    for (int k = 1; k < len; ++k) {
//                        // 情况1：不交换，s1前k与s2前k匹配，后len-k与后len-k匹配
//                        if (dp[i][j][k] && dp[i + k][j + k][len - k]) {
//                            dp[i][j][len] = true;
//                            break;
//                        }
//                        // 情况2：交换，s1前k与s2后k匹配，后len-k与前len-k匹配
//                        if (dp[i][j + len - k][k] && dp[i + k][j][len - k]) {
//                            dp[i][j][len] = true;
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//
//        return dp[0][0][n];
//    }
//};