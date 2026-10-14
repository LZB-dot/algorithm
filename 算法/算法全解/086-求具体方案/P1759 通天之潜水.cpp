////#include<iostream>
////#include<vector>
////#include <string>
////#include <algorithm>
////using namespace std;
////
////const int MAXN = 101;
////const int MAXM = 201;
////int m, v, n;
////int a[MAXN], b[MAXN], c[MAXN];
////int dp[MAXN][MAXM][MAXM];
////string path[MAXN][MAXM][MAXM];
////
////void init() {
////    for (int i = 0; i <= n; ++i)
////        for (int j = 0; j <= m; ++j)
////            for (int k = 0; k <= v; ++k) {
////                path[i][j][k] = "";
////                dp[i][j][k] = -1;
////            }
////}
////
////int dfs(int i, int j, int k) {
////    if (i == 0) {
////        path[i][j][k] = "";
////        return 0;
////    }
////
////    if (dp[i][j][k] != -1)
////        return dp[i][j][k];
////
////    int p1 = dfs(i - 1, j, k);
////    string cur1 = path[i - 1][j][k]; 
////
////    int p2 = -1;
////    string cur2 = "";
////    if (j >= a[i] && k >= b[i]) { 
////        p2 = dfs(i - 1, j - a[i], k - b[i]) + c[i];
////        cur2 = path[i - 1][j - a[i]][k - b[i]];
////        if (cur2.empty())
////            cur2 = to_string(i);
////        else
////            cur2 += " " + to_string(i);
////    }
////
////    // 选时间更长的；相等选字典序更小的
////    if (p1 > p2) {
////        dp[i][j][k] = p1;
////        path[i][j][k] = cur1;
////    }
////    else if (p1 < p2) {
////        dp[i][j][k] = p2;
////        path[i][j][k] = cur2;
////    }
////    else {
////        dp[i][j][k] = p1;
////        path[i][j][k] = min(cur1, cur2);
////    }
////
////    return dp[i][j][k];
////}
////
////int main() {
////    cin >> m >> v >> n;
////    for (int i = 1; i <= n; ++i)
////        cin >> a[i] >> b[i] >> c[i];
////
////    init();  
////    cout << dfs(n, m, v) << endl;
////    cout << path[n][m][v] << endl;
////
////    return 0;
////}
//
//
//#include<iostream>
//#include<vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//const int MAXN = 101;
//const int MAXM = 201;
//int m, v, n;
//int a[MAXN], b[MAXN], c[MAXN];
//int dp[MAXM][MAXM];
//// 记录每个状态的最优选择路径
//string path[MAXM][MAXM];
//
//int main() {
//    cin >> m >> v >> n;
//    for (int i = 1; i <= n; ++i) {
//        cin >> a[i] >> b[i] >> c[i];
//    }
//
//    for (int j = 0; j <= m; ++j) {
//        for (int k = 0; k <= v; ++k) {
//            dp[j][k] = 0;
//            path[j][k] = "";
//        }
//    }
//
//    for (int i = 1; i <= n; ++i) {
//        // 逆序遍历容量，保证01背包特性
//        for (int j = m; j >= a[i]; --j) {
//            for (int k = v; k >= b[i]; --k) {
//                int new_val = dp[j - a[i]][k - b[i]] + c[i];
//                string new_path = path[j - a[i]][k - b[i]];
//                // 拼接当前物品编号（保持升序）
//                if (new_path.empty()) {
//                    new_path = to_string(i);
//                }
//                else {
//                    new_path += " " + to_string(i);
//                }
//
//                if (new_val > dp[j][k] || (new_val == dp[j][k] && new_path < path[j][k])) {
//                    dp[j][k] = new_val;
//                    path[j][k] = new_path;
//                }
//            }
//        }
//    }
//
//    cout << dp[m][v] << endl;
//    cout << path[m][v] << endl;
//
//    return 0;
//}