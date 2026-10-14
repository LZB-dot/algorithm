//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//private:
//    vector<int>memory;
//
//    int f1(string s,int i) {
//        if (i == s.size()) {
//            return 1;
//        }
//
//        int ans = 0;
//
//        if (memory[i] != -1) {
//            return memory[i];
//        }
//
//        if (s[i] == '0') {
//            return 0;
//        }
//        else {
//            ans = f1(s, i + 1);
//            if (i + 1 < s.size() && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26) {
//                ans += f1(s, i + 2);
//            }
//        }
//        memory[i] = ans;
//        return ans;
//    }
//
//    int f2(string s) {
//        int n = s.size();
//        //从第i位开始的解码次数
//        vector<int>dp(n + 1, 0);
//        dp[n] = 1;
//        for (int i = n - 1; i >= 0; --i) {
//            if (s[i] == '0') {
//                dp[i] = 0;
//            }
//            else {
//                dp[i] = dp[i + 1];
//                if (i + 1 < s.size() && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26) {
//                    dp[i] += dp[i + 2];
//                }
//            }
//        }
//        return dp[0];
//    }
//
//    int f3(string s) {
//        int n = s.size();
//        int next = 1, nextNext = 0;
//        int ans = 0;
//        for (int i = n - 1; i >= 0; --i) {
//            if (s[i] == '0') {
//                ans = 0;
//            }
//            else {
//                ans = next;
//                if (i + 1 < s.size() && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26) {
//                    ans += nextNext;
//                }
//            }
//            nextNext = next;
//            next = ans;
//        }
//        return ans;
//    }
//public:
//    int numDecodings(string s) {
//        memory.resize(s.size(), -1);
//        //return f1(s, 0);
//        //return f2(s);
//        return f3(s);
//    }
//};
