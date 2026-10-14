//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//const int MOD = 1e9 + 7;
//
//class Solution {
//public:
//    int countPalindromicSubsequences(string s) {
//        int n = s.size();
//        if (n == 0)
//            return 0;
//
//
//        vector<int> last(256, -1);
//        // left[i]：i位置的左边和s[i]字符相等且最近的位置，不存在则为-1
//        vector<int> left(n, -1);
//        for (int i = 0; i < n; ++i) {
//            left[i] = last[s[i]];
//            last[s[i]] = i;
//        }
//
//        // right[i]：i位置的右边和s[i]字符相等且最近的位置，不存在则为n
//        vector<int> right(n, n);
//        fill(last.begin(), last.end(), n); 
//            for (int i = n - 1; i >= 0; --i) {
//                right[i] = last[s[i]];
//                last[s[i]] = i;
//            }
//
//
//        // dp[i][j]：i...j范围上有多少不同的回文子序列，i>j时dp[i][j]=0
//        vector<vector<long long>> dp(n, vector<long long>(n, 0));
//        for (int i = 0; i < n; ++i) {
//            dp[i][i] = 1;
//        }
//
//        for (int i = n - 2; i >= 0; --i) {
//            for (int j = i + 1; j < n; ++j) {
//                if (s[i] != s[j]) {
//                    // 因为要取模，减操作后加mod保证非负
//                    dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + MOD) % MOD;
//                }
//                else {
//                    int l = right[i];
//                    int r = left[j];
//                    if (l > r) {
//                        // i...j内部没有s[i]字符
//                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 2) % MOD;
//                    }
//                    else if (l == r) {
//                        // i...j内部有一个s[i]字符
//                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 1) % MOD;
//                    }
//                    else {
//                        // i...j内部有多个s[i]字符，减操作后加mod
//                        dp[i][j] = (dp[i + 1][j - 1] * 2 - dp[l + 1][r - 1] + MOD) % MOD;
//                    }
//                }
//                dp[i][j] %= MOD;
//            }
//        }
//
//        return (int)dp[0][n - 1];
//    }
//};