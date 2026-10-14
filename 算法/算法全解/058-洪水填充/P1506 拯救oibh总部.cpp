//#include<iostream>
//#include<vector>
//using namespace std;
//
//int n, m;
//vector<vector<char>>grid;
//vector<vector<bool>>vis;
//
//int d[] = { -1,0,1,0,-1 };
//
//void dfs(int x, int y) {
//
//    if (x >= n || y >= m || x < 0 || y < 0 || grid[x][y] == '*')
//        return;
//
//    if (vis[x][y])
//        return;
//
//    vis[x][y] = true;
//
//    for (int i = 0; i < 4; ++i) {
//        int dx = d[i] + x;
//        int dy = d[i + 1] + y;
//        dfs(dx, dy);
//    }
//
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> m;
//    grid.resize(n, vector<char>(m ));
//    vis.resize(n, vector<bool>(m, false));
//
//    for (int i = 0; i < n; ++i)
//        for (int j = 0; j < m; ++j) 
//            cin >> grid[i][j];
//        
//
//    for (int i = 0; i < n; ++i) {
//        if (grid[i][0] == '0')
//            dfs(i, 0);
//        if (grid[i][m - 1] == '0')
//            dfs(i, m - 1);
//    }
//
//    for (int j = 0; j < m; ++j) {
//        if (grid[0][j] == '0')
//            dfs(0, j);
//        if (grid[n - 1][j] == '0')
//            dfs(n - 1, j);
//    }
//    int ans = 0;
//    for (int i = 0; i < n; ++i)
//        for (int j = 0; j < m; ++j) {
//            if (grid[i][j] == '0' && !vis[i][j])
//                ans++;
//        }
//
//    cout << ans << "\n";
//
//    return 0;
//}