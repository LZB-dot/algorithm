//#include<iostream>
//#include<vector>
//using namespace std;
//
//////class Solution {
//////private:
//////    int f(const string& s, int l, int r, vector<vector<int>>& dp) {
//////        if (dp[l][r] != -1) {
//////            return dp[l][r];
//////        }
//////
//////        int ans = 0;
//////        if (l == r) {
//////            ans= 0;
//////        }
//////        else if (l + 1 == r) {
//////            ans= s[l] == s[r] ? 0 : 1;
//////        }
//////        else {
//////            if (s[l] == s[r]) {
//////                ans= f(s, l + 1, r - 1, dp);
//////            }
//////            else {
//////                ans= min(f(s, l + 1, r, dp), f(s, l, r - 1, dp)) + 1;
//////            }
//////        }
//////        dp[l][r] = ans;
//////        return ans;
//////    }
//////public:
//////    int minInsertions(string s) {
//////        int n = s.size();
//////        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
//////        return f(s, 0, n - 1, dp);
//////    }
//////};
////
////class Solution {
////
////public:
////    int minInsertions(string s) {
////        int n = s.size();
////        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
////        
////        for (int l = 0; l < n - 1; ++l) {
////            dp[l][l + 1] = (s[l] == s[l + 1]) ? 0 : 1;
////        }
////
////        for (int l = n - 3; l >= 0; --l) {
////            for (int r = l + 2; r < n; ++r) {
////                if (s[l] == s[r]) {
////                    dp[l][r] = dp[l + 1][r - 1];
////                }
////                else {
////                    dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
////                }
////            }
////        }
////
////        return dp[0][n - 1];
////    }
////};
//
//
//class Solution {
//
//public:
//    int minInsertions(string s) {
//        int n = s.size();
//        vector<int>dp(n + 1, 0);
//
//        for (int l = 0; l < n - 1; ++l) {
//            dp[l + 1] = (s[l] == s[l + 1]) ? 0 : 1;
//        }
//
//        for (int l = n - 3; l >= 0; --l) {
//            int pre = 0;
//            for (int r = l + 2; r < n; ++r) {
//                int tmp = dp[r];
//                if (s[l] == s[r]) {
//                    dp[r] = pre;
//                }
//                else {
//                    dp[r] = min(dp[r], dp[r - 1]) + 1;
//                }
//                pre = tmp;
//            }
//        }
//
//        return dp[n - 1];
//    }
//};