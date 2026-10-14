//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//
//class Solution {
//private:
//    int n, m;
//    vector<vector<int>> g;
//    int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
//
//    //用栈模拟递归，避免递归栈溢出
//    int dfs(int i, int j) {
//        if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] != 1) {
//            return 0;
//        }
//        stack<pair<int, int>> stk; //存储待处理的坐标
//        stk.push({ i, j });         //起始坐标入栈
//        g[i][j] = 2;              //标记为稳定砖块（值为2）
//        int cur = 1;              //自身是一个稳定砖块
//
//        while (!stk.empty()) {
//            //取出栈顶坐标
//            int x = stk.top().first;
//            int y = stk.top().second;
//            stk.pop();
//
//            //遍历四个方向
//            for (auto& d : dir) {
//                int nx = x + d[0]; 
//                int ny = y + d[1]; 
//                if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == 1) {
//                    g[nx][ny] = 2; //标记为稳定砖块
//                    cur++;         //稳定砖块数+1
//                    stk.push({ nx, ny }); //新坐标入栈，继续处理其邻居
//                }
//            }
//        }
//        return cur;
//    }
//
//    //判断恢复砖块后是否能成为稳定砖块的起点
//    bool worth(int i, int j) {
//        if (g[i][j] != 1) 
//            return false; //必须是恢复后的砖块（值为1）
//        //位于顶部，或相邻有稳定砖块（值为2）
//        return (i == 0) ||
//            (i > 0 && g[i - 1][j] == 2) ||
//            (i < n - 1 && g[i + 1][j] == 2) ||
//            (j > 0 && g[i][j - 1] == 2) ||
//            (j < m - 1 && g[i][j + 1] == 2);
//    }
//
//public:
//    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
//        g = grid;
//        n = g.size();
//        if (n == 0) 
//            return {}; 
//        m = g[0].size();
//        int hitSize = hits.size();
//        vector<int> ans(hitSize, 0); 
//
//        //先移除所有待打的砖块
//        for (auto& h : hits) {
//            int x = h[0], y = h[1];
//            g[x][y]--;
//        }
//
//        //从顶部行标记初始稳定的砖块（值为2）
//        for (int j = 0; j < m; ++j) {
//            if (g[0][j] == 1) { //顶部未被打掉的砖块
//                dfs(0, j);
//            }
//        }
//
//        //逆向恢复砖块，统计每次掉落的砖块数
//        for (int i = hitSize - 1; i >= 0; --i) {
//            int x = hits[i][0], y = hits[i][1];
//            //恢复砖块（原是空气则恢复为0，原是砖块则恢复为1）
//            if (g[x][y] == -1) {
//                g[x][y] = 0;
//                continue;
//            }
//            g[x][y] = 1; //恢复被打的砖块
//
//            //若恢复后可稳定，计算新增稳定砖块数（即正向掉落数）
//            if (worth(x, y)) {
//                ans[i] = dfs(x, y) - 1; // 减1：排除自身（自身是恢复的，不是掉落的）
//            }
//        }
//
//        return ans;
//    }
//};