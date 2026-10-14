//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//private:
//    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
//        int n = board.size(), m = board[0].size();
//        int s = word.size();
//        if (k == s) {
//            return true;
//        }
//
//        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '1' || board[i][j] != word[k]) {
//            return false;
//        }
//
//        char tmp = board[i][j];
//        board[i][j] = '1';
//        bool res = dfs(board, word, i + 1, j, k + 1) ||
//            dfs(board, word, i - 1, j, k + 1) ||
//            dfs(board, word, i, j + 1, k + 1) ||
//            dfs(board, word, i, j - 1, k + 1);
//        board[i][j] = tmp;
//        return res;
//    }
//public:
//    bool exist(vector<vector<char>>& board, string word) {
//        int n = board.size(), m = board[0].size();
//
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                if (dfs(board, word, i, j, 0)) {
//                    return true;
//                }
//            }
//        }
//
//        return false;
//
//    }
//};