//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int largest1BorderedSquare(vector<vector<int>>& grid) {
//        int n = grid.size();
//        int m = grid[0].size();
//        build(n, m, grid);
//
//        if (sum(0, 0, n - 1, m - 1,grid) == 0) {
//            return 0;
//        }
//
//        int ans = 0;
//
//        for (int a = 0; a < n; ++a) {
//            for (int b = 0; b < m; ++b) {
//                for (int c = a + ans, d = b + ans, k = ans + 1;
//                    c < n && d < m; c++, d++, k++) {
//                    if (sum(a, b, c, d, grid) - sum(a + 1, b + 1, c - 1, d - 1, grid)
//                        == (k - 1) << 2) {
//                        ans = k;
//                    }
//                }
//            }
//        }
//        return ans * ans;
//    }
//
//    void build(int n, int m, vector<vector<int> >&grid) {
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                grid[i][j] += get(i - 1, j, grid) + get(i, j - 1, grid)
//                    - get(i - 1, j - 1, grid);
//            }
//        }
//    }
//
//    int get(int i, int j, vector<vector<int> > &grid) {
//        return (i < 0 || j < 0) ? 0 : grid[i][j];
//    }
//
//    int sum(int a, int b, int c, int d, vector<vector<int> >&grid) {
//        return a > c ? 0 : (grid[c][d] - get(c, b - 1, grid) 
//            - get(a - 1, d, grid) + get(a - 1, b - 1, grid));
//    }
//};
