//
////https://www.luogu.com.cn/problem/P2910
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//const int MAXN = 105;
//const int INF = 1e9;
//
//int dis[MAXN][MAXN]; 
//int n, m;
//
//void Floyd() {
//    for (int k = 1; k <= n; ++k) {
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= n; ++j) {
//                if (dis[i][k] != INF && dis[k][j] != INF) {
//                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
//                }
//            }
//        }
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> m;
//
//    vector<int> vis(m + 1);
//    for (int i = 1; i <= m; ++i)
//        cin >> vis[i];
//    
//
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            if (i == j) 
//                dis[i][j] = 0;
//            else
//                dis[i][j] = INF;
//        }
//    }
//
//    for (int i = 1; i <= n; ++i) 
//        for (int j = 1; j <= n; ++j)
//            cin >> dis[i][j];
//
//    Floyd();
//
//    int ans = 0;
//    for (int i = 2; i <= m; ++i) 
//        ans += dis[vis[i - 1]][vis[i]];
//    
//
//    cout << ans << "\n";
//
//    return 0;
//}