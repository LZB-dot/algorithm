//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//class Solution {
//public:
//    int nthUglyNumber(int n) {
//        vector<int>dp(n + 1, 0);
//        dp[1] = 1;
//        int i2 = 1, i3 = 1, i5 = 1;
//        for (int i = 2; i <= n; ++i) {
//            int a = dp[i2] * 2;
//            int b = dp[i3] * 3;
//            int c = dp[i5] * 5;
//
//            dp[i] = min({ a,b,c });
//
//            if (a == dp[i]) {
//                i2++;
//            }
//
//            if (b == dp[i]) {
//                i3++;
//            }
//
//            if (c == dp[i]) {
//                i5++;
//            }
//
//        }
//        return dp[n];
//    }
//};