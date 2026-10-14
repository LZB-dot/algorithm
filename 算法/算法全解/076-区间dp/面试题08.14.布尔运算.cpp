//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution {
//private:
//    vector<vector<vector<int>>> dp;
//
//    vector<int> dfs(const string& s, int l, int r) {
//        if (dp[l][r][0] != -1) return { dp[l][r][0], dp[l][r][1] };
//        if (l == r) {
//            int c0 = (s[l] == '0') ? 1 : 0;
//            int c1 = (s[l] == '1') ? 1 : 0;
//            dp[l][r][0] = c0;
//            dp[l][r][1] = c1;
//            return { c0, c1 };
//        }
//
//        int c0 = 0, c1 = 0;
//        for (int k = l + 1; k < r; k += 2) {
//            vector<int> left = dfs(s, l, k - 1);
//            vector<int> right = dfs(s, k + 1, r);
//            int a = left[0], b = left[1];  
//            int c = right[0], d = right[1];
//
//            switch (s[k]) {
//            case '&':
//                c0 += a * c + a * d + b * c;  // 0&0, 0&1, 1&0
//                c1 += b * d;                  // 1&1
//                break;
//            case '|':
//                c0 += a * c;                  // 0|0
//                c1 += a * d + b * c + b * d;  // 0|1, 1|0, 1|1
//                break;
//            case '^':
//                c0 += a * c + b * d;          // 0^0, 1^1
//                c1 += a * d + b * c;          // 0^1, 1^0
//                break;
//            }
//        }
//
//        dp[l][r][0] = c0;
//        dp[l][r][1] = c1;
//        return { c0, c1 };
//    }
//
//public:
//    int countEval(string s, int result) {
//        int n = s.size();
//        dp.resize(n, vector<vector<int>>(n, vector<int>(2, -1)));
//        vector<int> ans = dfs(s, 0, n - 1);
//        return result == 0 ? ans[0] : ans[1];
//    }
//};
