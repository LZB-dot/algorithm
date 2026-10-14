//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//const int MAXN = 1005;
//int grid[MAXN][MAXN];
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m, c;
//    cin >> n >> m >> c;
//
//    for (int i = 1; i <= n; ++i)
//        for (int j = 1; j <= m; ++j)
//            cin >> grid[i][j];
//
//    for (int i = 1; i <= n; ++i)
//        for (int j = 1; j <= m; ++j)
//            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
//
//    int ans = INT_MIN;
//    int x = 0, y = 0; 
//    for (int i = c; i <= n; ++i)
//        for (int j = c; j <= m; ++j) {
//            int cur = grid[i][j] - grid[i - c][j] - grid[i][j - c] + grid[i - c][j - c];
//            if (ans < cur) {
//                ans = cur;
//                x = i;
//                y = j;
//            }
//        }
//
//    x = x - c + 1;
//    y = y - c + 1;
//    cout << x << " " << y << "\n";
//
//    return 0;
//}