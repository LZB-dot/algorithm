//
////https://leetcode.cn/problems/maximize-grid-happiness/description/
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 6;
//const int MAXS = 243;
//const int MAXP = 7;
//int dp[MAXN][MAXN][MAXP][MAXP][MAXS];
//
//
//class Solution {
//private:
//    int get(int s, int bit) {
//        return (s / bit) % 3;
//    }
//
//    int set(int s, int bit, int v) {
//        return s - bit * get(s, bit) + v * bit;
//    }
//
//    int dfs(int n, int m, int i, int j, int in, int out, int s, int bit) {
//        if (i == n)
//            return 0;
//
//        if (j == m)
//            return dfs(n, m, i + 1, 0, in, out, s, 1);
//
//        if (dp[i][j][in][out][s] != -1)
//            return dp[i][j][in][out][s];
//
//        int l = (j == 0) ? 0 : get(s, bit / 3);
//        int up = get(s, bit);
//
//        int ans = dfs(n, m, i, j + 1, in, out, set(s, bit, 0), bit * 3);
//        int neighbor = 0;
//        int pre = 0;
//
//        if (up != 0) {
//            neighbor++;
//            pre += (up == 1 ? -30 : 20);
//        }
//        if (l != 0) {
//            neighbor++;
//            pre += (l == 1 ? -30 : 20);
//        }
//
//        if (in > 0) {
//            int nxt = 120 - neighbor * 30 + pre
//                + dfs(n, m, i, j + 1, in - 1, out, set(s, bit, 1), bit * 3);
//            ans = max(ans, nxt);
//        }
//
//        if (out > 0) {
//            int nxt = 40 + neighbor * 20 + pre
//                + dfs(n, m, i, j + 1, in, out - 1, set(s, bit, 2), bit * 3);
//            ans = max(ans, nxt);
//        }
//
//        return dp[i][j][in][out][s] = ans;
//    }
//public:
//    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
//        memset(dp, -1, sizeof(dp));
//        if (m < n)
//            swap(n, m);
//
//        return dfs(n, m, 0, 0, introvertsCount, extrovertsCount, 0, 1);
//    }
//};