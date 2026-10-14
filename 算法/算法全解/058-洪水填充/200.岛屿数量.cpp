//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//private:
//    int rows, cols;
//    void dfs(vector<vector<char>>& grid, int x, int y) {
//        if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] != '1') {
//            return;
//        }
//        grid[x][y] = '0';
//        dfs(grid, x - 1, y);
//        dfs(grid, x + 1, y);
//        dfs(grid, x, y - 1);
//        dfs(grid, x, y + 1);
//    }
//public:
//    int numIslands(vector<vector<char>>& grid) {
//        rows = grid.size();
//        cols = grid[0].size();
//        int ans = 0;
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < cols; ++j) {
//                if (grid[i][j] == '1') {
//                    ++ans;
//                    dfs(grid, i, j);
//                }
//            }
//        }
//        return ans;
//    }
//};