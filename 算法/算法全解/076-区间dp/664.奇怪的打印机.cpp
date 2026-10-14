////#include<iostream>
////#include<vector>
////using namespace std;
////
////class Solution {
////private:
////    vector<vector<int>>dp;
////
////    int f(const string& s, int l, int r) {
////        if (dp[l][r] != -1) {
////            return dp[l][r];
////        }
////
////        if (l == r) {
////            dp[l][r] = 1;
////            return 1;
////        }
////
////        if (l == r - 1) {
////            if (s[l] == s[r]) {
////                dp[l][r] = 1;
////                return 1;
////            }
////            else {
////                dp[l][r] = 2;
////                return 2;
////            }
////        }
////
////        int ans = INT_MAX;
////        if (s[l] == s[r]) {
////            ans = f(s, l + 1, r);
////        }
////        
////        for (int k = l; k < r; ++k) {
////            ans = min(ans, f(s, l, k) + f(s, k + 1, r));
////        }
////
////        dp[l][r] = ans;
////        return ans;
////    }
////public:
////    int strangePrinter(string s) {
////        int n = s.size();
////        dp.resize(n + 1, vector<int>(n + 1, -1));
////        return f(s, 0, n - 1);
////    }
////};
//
//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//class Solution {
//public:
//    int strangePrinter(string s) {
//        int n = s.size();
//        vector<vector<int>>dp(n + 1, vector<int>(n + 1, INT_MAX));
//        
//        for (int i = 0; i < n; ++i) {
//            dp[i][i] = 1;
//        }
//        for (int i = 0; i < n - 1; ++i) {
//            dp[i][i + 1] = s[i] == s[i + 1] ? 1 : 2;
//        }
//
//        for (int i = n - 3; i >= 0; --i) {
//            for (int j = i + 1; j < n; ++j) {
//                if (s[i] == s[j]) {
//                    dp[i][j] = dp[i + 1][j];
//                }
//                for (int k = i; k < j; ++k) {
//                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
//                }
//            }
//        }
//        return dp[0][n - 1];
//    }
//};
//
//int main() {
//    string s;
//    cin >> s;
//    Solution sol;
//    cout << sol.strangePrinter(s) << endl;
//    return 0;
//}
//
