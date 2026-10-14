////
////删除至少几个字符可以变成另一个字符串的子串
////给定两个字符串s1和s2
////返回s1至少删除多少字符可以成为s2的子串
//
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//	int minDelete(string s1, string s2) {
//		int n = s1.size(), m = s2.size();
//		vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
//
//		for (int i = 0; i <= n; ++i) {
//			dp[i][0] = i;
//		}
//
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= m; ++j) {
//				if (s1[i-1] == s2[j-1]) {
//					dp[i][j] = dp[i - 1][j - 1];
//				}
//				else {
//					dp[i][j] = 1 + dp[i - 1][j];
//				}
//			}
//		}
//
//		int ans = 0;
//		for (int j = 0; j <= m; ++j) {
//			ans = min(ans, dp[n][j]);
//		}
//
//		return ans;
//	}
//};