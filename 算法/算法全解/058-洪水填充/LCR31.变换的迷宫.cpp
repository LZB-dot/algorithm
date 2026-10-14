//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//class Solution {
//public:
//    int dx[5] = { 0, 1, 0,-1,0 };
//    int dy[5] = { 1, 0,-1,0,0 };
//
//    int n; 
//    int m;
//    int step; 
//
//    bool vis[55][55][105][2][2] = { false };  
//    bool dfs(int x, int y, int cnt, bool f1, bool f2, const vector<vector<string>>& maze) {
//        if (vis[x][y][cnt][f1][f2] == true) 
//            return false; 
//        vis[x][y][cnt][f1][f2] = true;
//        if (x == n - 1 && y == m - 1) 
//            return true;
//        if (cnt == step) 
//            return false;
//        if (step - cnt < n - 1 - x + m - 1 - y)
//            return false; 
//        for (int i = 0; i < 5; i++) {
//            int tx = x + dx[i];
//            int ty = y + dy[i];
//            if (tx >= 0 && tx < n && ty >= 0 && ty < m) { 
//                if (maze[cnt + 1][tx][ty] == '.') { 
//                    if (dfs(tx, ty, cnt + 1, f1, f2, maze)) 
//                        return true;
//                }
//                else { 
//                    if (!f1) { 
//                        if (dfs(tx, ty, cnt + 1, true, f2, maze)) 
//                            return true;
//                    }
//                    if (!f2) {
//                        for (int i = cnt + 1; i <= step; i++) {
//                            if (dfs(tx, ty, i, f1, true, maze)) 
//                                return true;
//                        }
//                    }
//                }
//            }
//        }
//        return false;
//    }
//    bool escapeMaze(vector<vector<string>>& maze) {
//        n = maze[0].size();
//        m = maze[0][0].size();
//        step = maze.size() - 1;
//        return dfs(0, 0, 0, false, false, maze);
//    }
//};
