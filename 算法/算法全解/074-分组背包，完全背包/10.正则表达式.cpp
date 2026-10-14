////#include<iostream>
////#include<vector>
////#include<string>
////using namespace std;
////
////class Solution {
////private:
////    bool f(string s, string p, int i, int j, vector<vector<int>>& dp) {
////
////        if (dp[i][j] != 0) {
////            return dp[i][j] == 1;
////        }
////        bool ans;
////        if (i == s.size()) {
////            if (j == p.size()) {
////                ans = true;
////            }
////            else {
////                ans=j + 1 < p.size() && p[j + 1] == '*' && f(s, p, i, j + 2,dp);
////            }
////        }
////        else if (j == p.size()) {
////            ans=false;
////        }
////        else {
////            if (j + 1 == p.size() || p[j + 1] != '*') {
////                ans= (s[i] == p[j] || p[j] == '.') && f(s, p, i + 1, j + 1,dp);
////            }
////            else{
////                bool case1 = f(s, p, i, j + 2,dp);
////                bool case2 = (s[i] == p[j] || p[j] == '.') && f(s, p, i + 1, j,dp);
////                ans = case1 || case2;
////            }
////        }
////        dp[i][j] = ans ? 1 : 2;
////        return ans;
////    }
////public:
////    bool isMatch(string s, string p) {
////        int n = s.size(), m = p.size();
////        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
////        return f(s, p, 0, 0, dp);
////    }
////};
//
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        int n = s.size(), m = p.size();
//        vector<vector<bool>>dp(n + 1, vector<bool>(m + 1, 0));
//        dp[n][m] = 1;
//        for (int j = m - 1; j >= 0; --j) {
//            dp[n][j] = (j + 1 < m && p[j + 1] == '*') && dp[n][j + 2];
//        }
//
//        for (int i = n-1; i >= 0; --i) {
//            for (int j = m - 1; j >= 0; --j) {
//                if (j + 1 == m || p[j + 1] != '*') {
//                    dp[i][j] = (s[i] == p[j] || p[j] == '.') && dp[i + 1][j + 1];
//                }
//                else {
//                    dp[i][j] = dp[i][j + 2] || (s[i] == p[j] || p[j] == '.') && dp[i + 1][j];
//                }
//                
//            }
//        }
//        return dp[0][0];
//    }
//};