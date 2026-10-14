//
////https://leetcode.cn/problems/cherry-pickup/description/
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//const int MAXN = 55;
//
//class Solution {
//private:
//    int memo[MAXN][MAXN][MAXN];
//
//    int dfs(int a, int b, int c, int n, const vector<vector<int>>& grid) {
//        int d = a + b - c;
//
//        if (a >= n || b >= n || c >= n || d >= n || d < 0)
//            return -1;
//
//        if (grid[a][b] == -1 || grid[c][d] == -1)
//            return -1;
//
//        if (a == n - 1 && b == n - 1)
//            return grid[a][b];
//
//        if (memo[a][b][c] != -2)
//            return memo[a][b][c];
//
//        int nxt = -1;
//        nxt = max(nxt, dfs(a + 1, b, c + 1, n, grid));
//        nxt = max(nxt, dfs(a + 1, b, c, n, grid));
//        nxt = max(nxt, dfs(a, b + 1, c + 1, n, grid));
//        nxt = max(nxt, dfs(a, b + 1, c, n, grid));
//
//        if (nxt == -1)
//            return memo[a][b][c] = -1;
//
//        int tmp = ((a == c && b == d) ? grid[a][b] : grid[a][b] + grid[c][d]);
//        return memo[a][b][c] = nxt + tmp;
//    }
//
//public:
//    int cherryPickup(vector<vector<int>>& grid) {
//        int n = grid.size();
//
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j)
//                for (int k = 0; k < n; ++k)
//                    memo[i][j][k] = -2;
//        }
//
//        int res = dfs(0, 0, 0, n, grid);
//
//        return max(0, res);
//    }
//};