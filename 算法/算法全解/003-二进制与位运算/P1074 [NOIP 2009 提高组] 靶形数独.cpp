//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int grid[9][9];
//int score[9][9] = {
//    {6,6,6,6,6,6,6,6,6},
//    {6,7,7,7,7,7,7,7,6},
//    {6,7,8,8,8,8,8,7,6},
//    {6,7,8,9,9,9,8,7,6},
//    {6,7,8,9,10,9,8,7,6},
//    {6,7,8,9,9,9,8,7,6},
//    {6,7,8,8,8,8,8,7,6},
//    {6,7,7,7,7,7,7,7,6},
//    {6,6,6,6,6,6,6,6,6}
//};
//
//// 行、列、小九宫格的数字使用状态
//int row[9] = { 0 }, col[9] = { 0 }, block[9] = { 0 };
//int max_score = -1;
//
//// 计算小九宫格索引
//int get_block(int x, int y) {
//    return (x / 3) * 3 + (y / 3);
//}
//
//// 初始化已知数字的状态，并计算已知数字的总分
//int init() {
//    int base_score = 0; // 已知数字的总分
//    for (int i = 0; i < 9; ++i) {
//        for (int j = 0; j < 9; ++j) {
//            if (grid[i][j] != 0) {
//                int num = grid[i][j];
//                base_score += num * score[i][j]; // 累加已知数字的分数
//                int b = get_block(i, j);
//                row[i] |= (1 << (num - 1));
//                col[j] |= (1 << (num - 1));
//                block[b] |= (1 << (num - 1));
//            }
//        }
//    }
//    return base_score;
//}
//
//// 找到可选数字最少的空格
//pair<int, int> find_best_cell() {
//    int min_cnt = 10; // 初始值大于最大可选数9
//    int best_x = -1, best_y = -1;
//
//    for (int i = 0; i < 9; ++i) {
//        for (int j = 0; j < 9; ++j) {
//            if (grid[i][j] != 0) continue;
//
//            int cnt = 0;
//            int b = get_block(i, j);
//            // 枚举数字1~9，检查是否可填
//            for (int num = 1; num <= 9; ++num) {
// 
//                if (!(row[i] & (1 << (num - 1))) &&
//                    !(col[j] & (1 << (num - 1))) &&
//                    !(block[b] & (1 << (num - 1)))) {
//                    cnt++;
//                }
//            }
//
//            if (cnt < min_cnt) {
//                min_cnt = cnt;
//                best_x = i;
//                best_y = j;
//            }
//        }
//    }
//    return { best_x, best_y };
//}
//
//void backtrack(int current_score) {
//    pair<int, int> next = find_best_cell();
//    int x = next.first, y = next.second;
//
//    // 所有空格填充完成，更新最大分数
//    if (x == -1) {
//        max_score = max(max_score, current_score);
//        return;
//    }
//
//    int b = get_block(x, y);
//    // 枚举可填数字1~9
//    for (int num = 1; num <= 9; ++num) {
//        if (!(row[x] & (1 << (num - 1))) &&
//            !(col[y] & (1 << (num - 1))) &&
//            !(block[b] & (1 << (num - 1)))) {
//
//            // 标记数字已使用
//            row[x] |= (1 << (num - 1));
//            col[y] |= (1 << (num - 1));
//            block[b] |= (1 << (num - 1));
//            grid[x][y] = num;
//
//            // 累加当前数字的分数
//            backtrack(current_score + num * score[x][y]);
//
//            // 恢复状态
//            row[x] &= ~(1 << (num - 1));
//            col[y] &= ~(1 << (num - 1));
//            block[b] &= ~(1 << (num - 1));
//            grid[x][y] = 0;
//        }
//    }
//}
//
//int main() {
//
//    for (int i = 0; i < 9; ++i) {
//        for (int j = 0; j < 9; ++j) {
//            cin >> grid[i][j];
//        }
//    }
//
//    // 初始化并获取已知数字的总分
//    int base = init();
//    backtrack(base);
//    cout << max_score << endl;
//
//    return 0;
//}