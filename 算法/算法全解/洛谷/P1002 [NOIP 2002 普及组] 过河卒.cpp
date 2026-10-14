////#include<iostream>
////using namespace std;
////
////const int MAXN = 22;
////bool vis[MAXN][MAXN];  
////
////int dx[2] = { 1, 0 }; 
////int dy[2] = { 0, 1 };
////
////int ans = 0;
////int ex, ey;  
////int hx, hy;  
////
////
////void dfs(int x, int y) {
////
////    if (x == ex && y == ey) {
////        ans++;
////        return;
////    }
////
////    if (x > ex || y > ey) {
////        return;
////    }
////
////    for (int i = 0; i < 2; ++i) {
////        int cx = x + dx[i];
////        int cy = y + dy[i];
////
////
////        if (cx >= 0 && cy >= 0 && cx <= ex && cy <= ey && !vis[cx][cy]) {
////            vis[cx][cy] = true; 
////            dfs(cx, cy);
////            vis[cx][cy] = false; 
////        }
////    }
////}
////
////int main() {
////
////    cin >> ex >> ey >> hx >> hy;
////
////    vis[hx][hy] = true;
////    int horse_dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
////    int horse_dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
////    for (int i = 0; i < 8; ++i) {
////        int cx = hx + horse_dx[i];
////        int cy = hy + horse_dy[i];
////        if (cx >= 0 && cx <= ex && cy >= 0 && cy <= ey) {
////            vis[cx][cy] = true;
////        }
////    }
////
////    if (vis[0][0]) {
////        cout << 0 << endl;
////        return 0;
////    }
////
////    vis[0][0] = true;  
////    dfs(0, 0);
////
////    cout << ans << endl;
////    return 0;
////}
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int main() {
//    int n, m, hx, hy;
//    cin >> n >> m >> hx >> hy;
//
//    // 标记马的位置和控制范围
//    bool blocked[21][21] = { false };
//
//    // 马的8个控制点
//    int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
//    int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
//
//    // 标记马的位置
//    blocked[hx][hy] = true;
//    // 标记马的控制范围
//    for (int i = 0; i < 8; ++i) {
//        int x = hx + dx[i];
//        int y = hy + dy[i];
//        if (x >= 0 && x <= n && y >= 0 && y <= m) {
//            blocked[x][y] = true;
//        }
//    }
//
//    // 起点或终点被阻塞，直接返回0
//    if (blocked[0][0] || blocked[n][m]) {
//        cout << 0 << endl;
//        return 0;
//    }
//
//    // dp[i][j]表示到达(i,j)的路径数
//    long long dp[21][21];
//    memset(dp, 0, sizeof(dp));
//    dp[0][0] = 1;  // 起点只有一种方式
//
//    // 填充第一行（只能从左边过来）
//    for (int j = 1; j <= m; ++j) {
//        if (!blocked[0][j]) {
//            dp[0][j] = dp[0][j - 1];
//        }
//    }
//
//    // 填充第一列（只能从上面过来）
//    for (int i = 1; i <= n; ++i) {
//        if (!blocked[i][0]) {
//            dp[i][0] = dp[i - 1][0];
//        }
//    }
//
//    // 填充其他位置：到达(i,j)的路径数 = 上面来的 + 左边来的
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            if (!blocked[i][j]) {
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//    }
//
//    cout << dp[n][m] << endl;
//    return 0;
//}
//
