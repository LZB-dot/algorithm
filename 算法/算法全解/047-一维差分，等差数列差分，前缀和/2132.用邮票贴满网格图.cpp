//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
//        int n = grid.size();
//        int m = grid[0].size();
//
//        vector<vector<int>>sum(n + 1, vector<int>(m + 1, 0));
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                sum[i + 1][j + 1] = grid[i][j];
//            }
//        }
//        build(sum);
//
//        vector<vector<int> >diff(n + 2, vector<int>(m + 2, 0));
//        for (int a = 1, c = a + stampHeight - 1; c <= n; ++a, ++c) {
//            for (int b = 1, d = b + stampWidth - 1; d <= m; ++b, ++d) {
//                if ((sumRegion(sum, a, b, c, d)) == 0) {
//                    add(diff, a, b, c, d);
//                }
//            }
//        }
//        build(diff);
//
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                if (grid[i][j] == 0 && diff[i + 1][j + 1] == 0) {
//                    return false;
//                }
//            }
//        }
//        return true;
//
//    }
//
//
//    void build(vector<vector<int>>& sum) {
//        for (int i = 1; i < sum.size(); ++i) {
//            for (int j = 1; j < sum[0].size(); ++j) {
//                sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
//            }
//        }
//    }
//
//    void add(vector<vector<int>>& diff, int a, int b, int c, int d) {
//        diff[a][b] += 1;
//        diff[a][d + 1] -= 1;
//        diff[c + 1][b] -= 1;
//        diff[c + 1][d + 1] += 1;
//    }
//
//    int sumRegion(vector<vector<int>>& sum, int a, int b, int c, int d) {
//        return sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1];
//    }
//
//};