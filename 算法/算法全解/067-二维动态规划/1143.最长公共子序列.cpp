//#include<iostream>
//#include<vector>
//using namespace std;
//
////class Solution {
////public:
////    int longestCommonSubsequence(string text1, string text2) {
////        int s1 = text1.size();
////        int s2 = text2.size();
////        vector<vector<int>>dp(s1 + 1, vector<int>(s2 + 1, 0));
////
////        //i,j都是长度
////        for (int i = 1; i <= s1; ++i) {
////            for (int j = 1; j <= s2; ++j) {
////                if (text1[i - 1] == text2[j - 1]) {
////                    dp[i][j] = dp[i - 1][j - 1] + 1;
////                }
////                else {
////                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
////                }
////            }
////        }
////
////        return dp[s1][s2];
////    }
////};
//
//
//class Solution {
//public:
//    int longestCommonSubsequence(string text1, string text2) {
//        //保证s1是较长的字符串，减少空间消耗
//        if (text1.size() < text2.size()) {
//            swap(text1, text2);
//        }
//        
//        int s1 = text1.size();
//        int s2 = text2.size();
//
//        vector<int>dp(s2 + 1, 0);
//
//        //i,j都是长度
//        for (int i = 1; i <= s1; ++i) {
//            int leftUp = 0;
//            for (int j = 1; j <= s2; ++j) {
//                int tmp = dp[j];
//                if (text1[i - 1] == text2[j - 1]) {
//                    dp[j] = leftUp + 1;
//                }
//                else {
//                    dp[j] = max(dp[j], dp[j - 1]);
//                }
//
//                leftUp = tmp;
//            }
//        }
//
//        return dp[s2];
//    }
//};