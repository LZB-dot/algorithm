//#include<iostream>
//#include<vector>
//#include<unordered_set>
//using namespace std;
//
//class Solution {
//private:
//    int n = 9;  // 数独大小
//    // 修正：成员变量在构造函数或初始化列表中初始化，此处仅声明
//    vector<unordered_set<char>> row;  // 存储每行已有的数字
//    vector<unordered_set<char>> col;  // 存储每列已有的数字
//    vector<unordered_set<char>> box;  // 存储每个九宫格已有的数字
//
//    // 回溯函数：填充空格，返回是否成功
//    bool back(vector<vector<char>>& board) {
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (board[i][j] == '.') {  // 找到空格
//                    // 尝试填入1-9
//                    for (char c = '1'; c <= '9'; ++c) {
//                        if (isValid(i, j, c)) {  // 检查合法性
//                            // 填入数字并更新集合
//                            board[i][j] = c;
//                            row[i].insert(c);
//                            col[j].insert(c);
//                            int idx = (i / 3) * 3 + (j / 3);
//                            box[idx].insert(c);
//
//                            // 递归填充下一个空格，成功则返回
//                            if (back(board)) {
//                                return true;
//                            }
//
//                            // 回溯：恢复空格和集合
//                            board[i][j] = '.';
//                            row[i].erase(c);
//                            col[j].erase(c);
//                            box[idx].erase(c);
//                        }
//                    }
//                    // 1-9都无法填入，当前路径错误
//                    return false;
//                }
//            }
//        }
//        // 所有空格填满，返回成功
//        return true;
//    }
//
//    // 检查(i,j)位置填入c是否合法（利用预存的集合，O(1)检查）
//    bool isValid(int i, int j, char c) {
//        int idx = (i / 3) * 3 + (j / 3);  // 九宫格索引
//        // 行、列、九宫格中均不含c，则合法
//        return row[i].count(c) == 0
//            && col[j].count(c) == 0
//            && box[idx].count(c) == 0;
//    }
//
//public:
//    void solveSudoku(vector<vector<char>>& board) {
//        // 初始化三个集合（必须在构造函数或成员函数中初始化，不能直接在声明时用n）
//        row.resize(n);
//        col.resize(n);
//        box.resize(n);
//
//        // 预处理：将已有数字存入集合
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                char c = board[i][j];
//                if (c != '.') {
//                    int idx = (i / 3) * 3 + (j / 3);
//                    row[i].insert(c);
//                    col[j].insert(c);
//                    box[idx].insert(c);
//                }
//            }
//        }
//
//        // 调用回溯函数求解
//        back(board);
//    }
//};