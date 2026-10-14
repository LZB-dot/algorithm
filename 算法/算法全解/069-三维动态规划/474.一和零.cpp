//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
////
//////class Solution {
//////private:
//////    //处理到第i个字符串剩余z个1，o个0的最长子集个数
//////    int dp[60][101][101];
//////    int len;
//////
//////    void countZO(const string& s, int& zeros, int& ones) {
//////        zeros = 0; ones = 0;
//////        for (char c : s) {
//////            if (c == '0') {
//////                zeros++;
//////            }
//////            else {
//////                ones++;
//////            }
//////        }
//////    }
//////
//////    int dfs(vector<string>& strs, int i, int z, int o) {
//////        if (i == len) {
//////            return 0;
//////        }
//////
//////        if (dp[i][z][o] != -1) {
//////            return dp[i][z][o];
//////        }
//////
//////        // 情况1：不选当前字符串
//////        int case1 = dfs(strs, i + 1, z, o);
//////        // 情况2：选当前字符串（初始化为0，默认不选）
//////        int case2 = 0;
//////        int zero, one;
//////        countZO(strs[i], zero, one);
//////        // 若能选，则更新case2为选中后的结果
//////        if (zero <= z && one <= o) {
//////            case2 = 1 + dfs(strs, i + 1, z - zero, o - one);
//////        }
//////        // 取两种情况的最大值
//////        dp[i][z][o] = max(case1, case2);
//////        return dp[i][z][o];
//////    }
//////public:
//////    int findMaxForm(vector<string>& strs, int m, int n) {
//////        len = strs.size();
//////        memset(dp, -1, sizeof(dp));
//////        return dfs(strs, 0, m, n);
//////    }
//////};
////
////class Solution {
////public:
////    int findMaxForm(vector<string>& strs, int m, int n) {
////        int len = strs.size();
////        //前i个字符串使用z个0和o个1的最大子集长度
////        vector<vector<vector<int>>>dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
////
////        for (int i = 1; i <= len; ++i) {
////            string s = strs[i - 1];
////            int zeros = 0, ones = 0;
////            for (char c : s) {
////                c == '0' ? zeros++ : ones++;
////            }
////
////            for (int z = 0; z <= m; ++z) {
////                for (int o = 0; o <= n; ++o) {
////                    dp[i][z][o] = dp[i - 1][z][o];
////                    if (z >= zeros && o >= ones) {
////                        dp[i][z][o] = max(dp[i][z][o], dp[i - 1][z - zeros][o - ones] + 1);
////                    }
////                }
////            }
////
////        }
////
////        return dp[len][m][n];
////    }
////};
//
//class Solution {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
//
//        for (string s : strs) {
//            int zeros = 0, ones = 0;
//            for (char c : s) {
//                c == '0' ? zeros++ : ones++;
//            }
//
//            for (int i = m; i >= zeros; --i) {
//                for (int j = n; j >= ones; --j) {
//                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
//                }
//            }
//        }
//
//        return dp[m][n];
//    }
//};