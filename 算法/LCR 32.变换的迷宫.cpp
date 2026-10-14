#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int dx[5] = { 0, 1, 0,-1,0 };
    int dy[5] = { 1, 0,-1,0,0 };
    int n;
    int m;
    int max_step; //最大步数
    bool vis[55][55][105][2][2] = { false };
    bool dfs(int x, int y, int step, bool f1, 
        bool f2, const vector<vector<string>>& maze) {
        if (vis[x][y][step][f1][f2] == true) 
            return false; 

        vis[x][y][step][f1][f2] = true;

        if (x == n - 1 && y == m - 1) 
            return true;
        if (step == max_step) 
            return false;
        if (max_step - step < n - 1 - x + m - 1 - y) return false; // 不可能再走到终点了 剪枝
        for (int i = 0; i < 5; i++) { //尝试每一种next_state
            int fx = x + dx[i];
            int fy = y + dy[i];
            if (fx >= 0 && fx < n && fy >= 0 && fy < m) { //如果在地图内
                if (maze[step + 1][fx][fy] == '.') { //如果是空地可以直接踩过去
                    if (dfs(fx, fy, step + 1, f1, f2, maze)) return true;
                }
                else { //如果是陷阱则需要魔法才能踩过去
                    if (f1 == false) { //使用临时魔法，在下一时刻踩过去
                        if (dfs(fx, fy, step + 1, true, f2, maze)) return true;
                    }
                    if (f2 == false) {//使用永久魔法，在下一时刻至最后一个时刻，选择一个时刻踩过去
                        for (int i = step + 1; i <= max_step; i++) {
                            if (dfs(fx, fy, i, f1, true, maze)) return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool escapeMaze(vector<vector<string>>& maze) {
        n = maze[0].size();
        m = maze[0][0].size();
        max_step = maze.size() - 1;
        return dfs(0, 0, 0, false, false, maze);
    }
};
