//#include<algorithm>
//#include<vector>
//#include<string>
//using namespace std;
//
//
////class Solution {
////public:
////    int numDistinct(string s, string t) {
////        const int N = 1e9 + 7;
////        int n = s.size(), m = t.size();
////        vector<vector<long long>>dp(n + 1, vector<long long>(m + 1, 0));
////        for (int i = 0; i <= n; ++i) {
////            dp[i][0] = 1;
////        }
////        for (int i = 1; i <= n; ++i) {
////            for (int j = 1; j <= m; ++j) {
////                //末尾不相等，更新为用s的前i-1个字符匹配
////                if (s[i - 1] != t[j - 1]) {
////                    dp[i][j] = dp[i - 1][j];
////                }
////                else {
////                    //末尾相等，变为用和不用s的第i个字符之和
////                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % N;
////                }
////            }
////        }
////
////        return dp[n][m] % N;
////    }
////};
//
//
//class Solution {
//public:
//    int numDistinct(string s, string t) {
//        const int N = 1e9 + 7;
//        int n = s.size(), m = t.size();
//        vector<long long>dp(m + 1, 0);
//        dp[0] = 1;
//        for (int i = 1; i <= n; ++i) {
//            //使用逆序的原因，依赖于上一轮的状态
//            for (int j = m; j >= 1; --j) {
//                if (s[i - 1] == t[j - 1]){
//                    //末尾相等，变为用和不用s的第i个字符之和
//                    dp[j] = (dp[j] + dp[j - 1]) % N;
//                }
//            }
//        }
//        return dp[m] % N;
//    }
//};