//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//const int N = 10000; // 最大节点数
//int trie[N][26];     // 前缀树节点表
//int pass[N];         // 节点经过次数
//string ed[N];        // 以当前节点结束的单词
//int total = 1;       // 节点计数器，根节点为1
//
//class Solution {
//public:
//    // 构建前缀树
//    void build(vector<string>& words) {
//        // 每次构建前先清空之前的状态（关键修正）
//        clear();
//        for (string& word : words) {
//            int cur = 1;
//            pass[cur]++;
//            for (char c : word) {
//                int path = c - 'a';
//                // 检查字符是否合法（防止非小写字母导致越界）
//                if (path < 0 || path >= 26) break;
//                if (trie[cur][path] == 0) {
//                    trie[cur][path] = ++total;
//                }
//                cur = trie[cur][path];
//                pass[cur]++;
//            }
//            ed[cur] = word;
//        }
//    }
//
//    // 清理前缀树
//    void clear() {
//        for (int i = 1; i <= total; i++) {
//            memset(trie[i], 0, sizeof(trie[i]));
//            pass[i] = 0;
//            ed[i].clear();
//        }
//        total = 1;
//    }
//
//    // 深度优先搜索
//    int dfs(vector<vector<char>>& board, int i, int j, int t, vector<string>& ans) {
//        // 边界检查修正：i判断行数，j判断列数
//        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
//            return 0;
//
//        char temp = board[i][j];
//        // 已访问过的格子（被标记为0）直接返回
//        if (temp == 0) return 0;
//
//        int path = temp - 'a';
//        // 检查字符是否合法
//        if (path < 0 || path >= 26) return 0;
//
//        t = trie[t][path];
//        if (t == 0 || pass[t] == 0)
//            return 0;
//
//        int fix = 0;
//        if (!ed[t].empty()) {
//            ans.push_back(ed[t]);
//            ed[t].clear(); // 避免重复添加
//            fix++;
//        }
//
//        // 标记为已访问
//        board[i][j] = 0;
//
//        // 四个方向搜索
//        fix += dfs(board, i - 1, j, t, ans); // 上
//        fix += dfs(board, i + 1, j, t, ans); // 下
//        fix += dfs(board, i, j - 1, t, ans); // 左
//        fix += dfs(board, i, j + 1, t, ans); // 右
//
//        // 回溯：恢复原字符
//        board[i][j] = temp;
//
//        // 更新经过次数，用于剪枝
//        pass[t] -= fix;
//        return fix;
//    }
//
//    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//        vector<string> ans;
//        // 处理空输入情况
//        if (board.empty() || board[0].empty() || words.empty())
//            return ans;
//
//        build(words);
//        for (int i = 0; i < board.size(); i++)
//            for (int j = 0; j < board[0].size(); j++)
//                dfs(board, i, j, 1, ans);
//        clear();
//        return ans;
//    }
//};
