//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MOD = 1e9 + 7;
//
//class Solution {
//private:
//    vector<vector<int>>memo;
//    int n;
//    int dfs(const string& s, int i, int less) {
//        if (i == n) {
//            return memo[i][less] = 1;
//        }
//
//        if (memo[i][less] != -1) {
//            return memo[i][less];
//        }
//
//        int ans = 0;
//        if (i == 0 || s[i - 1] == 'D') {
//            for (int next = 0; next < less; ++next) {
//                ans = (ans + dfs(s, i + 1, next)) % MOD;
//            }
//        }
//        else {
//            for (int next = less; next < n - i; ++next) {
//                ans = (ans + dfs(s, i + 1, next)) % MOD;
//            }
//        }
//
//        memo[i][less] = ans;
//        return ans;
//    }
//public:
//    int numPermsDISequence(string s) {
//        n = s.size() + 1;
//        memo.resize(n + 1, vector<int>(n + 1, -1));
//        return dfs(s, 0, n);
//    }
//};