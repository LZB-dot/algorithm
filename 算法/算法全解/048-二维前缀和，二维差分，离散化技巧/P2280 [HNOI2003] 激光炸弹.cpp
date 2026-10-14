//#include<iostream>
//#include<vector>
//#include<climits>
//
//using namespace std;
//
//const int MAXN = 5005;
//
//int grid[MAXN][MAXN];
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    while (n--) {
//        int x, y, v;
//        cin >> x >> y >> v;
//        grid[x + 1][y + 1] += v;
//    }
//
//    for (int i = 1; i < MAXN; ++i) 
//        for (int j = 1; j < MAXN; ++j) 
//            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
//
//    int ans = INT_MIN; 
//    for (int i = m; i < MAXN; ++i) 
//        for (int j = m; j < MAXN; ++j) 
//            ans = max(ans, grid[i][j] - grid[i - m][j] - grid[i][j - m] + grid[i - m][j - m]);
//
//
//    cout << ans << "\n";
//    return 0;
//}