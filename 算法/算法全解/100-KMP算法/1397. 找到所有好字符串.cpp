//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define ll long long
//
//const int MOD = 1e9 + 7;
//const int MAXN = 505;
//const int MAXM = 55;
//
//class Solution {
//private:
//    int dp[MAXN][MAXM][2];
//    vector<int>nxt;
//
//    vector<int>getNxt(const string& s) {
//        int m = s.size();
//        if (m == 1)
//            return{ -1 };
//        vector<int>nxt(m);
//        nxt[0] = -1;
//        nxt[1] = 0;
//
//        int i = 2, cn = 0;
//        while (i < m) {
//            if (s[i - 1] == s[cn])
//                nxt[i++] = ++cn;
//            else if (cn > 0)
//                cn = nxt[cn];
//            else
//                nxt[i++] = 0;
//        }
//
//        return nxt;
//    }
//
//    //计算在当前匹配位置下，如果选择c的新的要匹配位置
//    int jump(int j, char c, const string& evil) {
//        while (j != -1 && c != evil[j])
//            j = nxt[j];
//        return j + 1;
//    }
//
//    int dfs(int n, const string& s, int m,
//        const string& evil, int i, int j, int free) {
//
//        if (j == m)
//            return 0;
//        if (i == n)
//            return 1;
//        if (dp[i][j][free] != -1)
//            return dp[i][j][free];
//
//        ll sum = 0;
//        if (free == 0) {
//            for (char c = 'a'; c < s[i]; ++c) {
//                sum = (sum + dfs(n, s, m, evil, i + 1, jump(j, c, evil), 1)) % MOD;
//            }
//            sum = (sum + dfs(n, s, m, evil, i + 1, jump(j, s[i], evil), 0)) % MOD;
//        }
//        else {
//            for (char c = 'a'; c <= 'z'; ++c) {
//                sum = (sum + dfs(n, s, m, evil, i + 1, jump(j, c, evil), 1)) % MOD;
//            }
//        }
//
//        dp[i][j][free] = sum;
//        return sum;
//    }
//
//    bool kmp(int n, const string& s, int m, const string& evil) {
//
//        int x = 0, y = 0;
//        while (x < n) {
//            if (s[x] == evil[y]) {
//                ++x; ++y;
//            }
//            else if (y > 0)
//                y = nxt[y];
//            else
//                ++x;
//
//            if (y == m)
//                return true;
//        }
//
//        return false;
//    }
//
//    void init() {
//        for (int i = 0; i < MAXN; ++i)
//            for (int j = 0; j < MAXM; ++j)
//                for (int k = 0; k < 2; ++k)
//                    dp[i][j][k] = -1;
//    }
//
//public:
//    int findGoodStrings(int n, string s1, string s2, string evil) {
//
//        nxt = getNxt(evil);
//
//        int m = evil.size();
//        init();
//        int p2 = dfs(n, s2, m, evil, 0, 0, 0);
//        init();
//        int p1 = dfs(n, s1, m, evil, 0, 0, 0);
//        ll ans = (p2 - p1 + MOD) % MOD;
//
//        if (!kmp(n, s1, m, evil))
//            ans = (ans + 1) % MOD;
//        return (int)ans;
//    }
//};