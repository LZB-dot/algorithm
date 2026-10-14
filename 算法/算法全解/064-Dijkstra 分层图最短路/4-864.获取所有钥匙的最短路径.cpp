//////https://leetcode.cn/problems/shortest-path-to-get-all-keys/
//
//#include<vector>
//#include<queue>
//#include<cctype>
//#include<string>
//using namespace std;
//
//
//class Solution {
//private:
//    int dx[4] = { 1,-1,0,0 };
//    int dy[4] = { 0,0,1,-1 };
//public:
//    int shortestPathAllKeys(vector<string>& grid) {
//        int n = grid.size();
//        int m = grid[0].size();
//        int sx = -1, sy = -1;
//        int k = 0;
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                if (grid[i][j] == '@') {
//                    sx = i;
//                    sy = j;
//                }
//                if (islower(grid[i][j])) 
//                    k++;
//            }
//        }
//
//        int full = (1 << k) - 1;
//        vector<vector<vector<bool>>> vis(1 << 6, vector<vector<bool>>(n, vector<bool>(m, false)));
//        queue<vector<int>> q;
//        q.push({ 0, sx, sy });
//        vis[0][sx][sy] = true;
//        int ans = 0;
//
//        while (!q.empty()) {
//            int sz = q.size();
//            for (int j = 0; j < sz; j++) {
//                auto cur = q.front();
//                q.pop();
//                int mask = cur[0];
//                int x = cur[1];
//                int y = cur[2];
//
//                if (mask == full) 
//                    return ans;
//
//                for (int i = 0; i < 4; i++) {
//                    int tx = x + dx[i];
//                    int ty = y + dy[i];
//                    if (tx < 0 || ty < 0 || tx >= n || ty >= m) 
//                        continue;
//
//                    char c = grid[tx][ty];
//                    if (c == '#') 
//                        continue;
//
//                    int newm = mask;
//                    if (islower(c)) {
//                        int p = c - 'a';
//                        newm = mask | (1 << p);
//                    }
//                    if (isupper(c)) {
//                        int p = c - 'A';
//                        if (!(mask & (1 << p))) 
//                            continue;
//                    }
//
//                    if (!vis[newm][tx][ty]) {
//                        vis[newm][tx][ty] = true;
//                        q.push({ newm, tx, ty });
//                    }
//                }
//            }
//            ans++;
//        }
//
//        return -1;
//    }
//};
