
////https://www.luogu.com.cn/problem/P1896
//// 
////#include <iostream>
////#include <cstring>
////using namespace std;
////
////typedef long long ll;
////const int MAXN = 9;
////const int MAXK = MAXN * MAXN;
////const int MAXM = 1 << MAXN;
////
////int n, k;
////ll dp[MAXN][MAXN][MAXM][2][MAXK];
////
////inline int get(int s, int j) {
////    return (s >> j) & 1;
////}
////
////inline int set(int s, int j, int v) {
////    if (v == 1)
////        return s | (1 << j);
////    return s & (~(1 << j));
////}
////
////ll dfs(int i, int j, int s, int lup, int remain) {
////    if (i == n)
////        return remain == 0 ? 1 : 0;
////    if (j == n)
////        return dfs(i + 1, 0, s, 0, remain);
////    if (dp[i][j][s][lup][remain] != -1)
////        return dp[i][j][s][lup][remain];
////
////    int l = (j > 0 ? get(s, j - 1) : 0);
////    int up = get(s, j);
////    int rup = (j == n - 1 ? 0 : get(s, j + 1));
////
////    ll ans = dfs(i, j + 1, set(s, j, 0), up, remain);
////
////    if (remain > 0 && l == 0 && up == 0 && lup == 0 && rup == 0)
////        ans += dfs(i, j + 1, set(s, j, 1), up, remain - 1);
////
////
////    return dp[i][j][s][lup][remain] = ans;
////}
////
////int main() {
////    ios::sync_with_stdio(false);
////    cin.tie(nullptr);
////
////    cin >> n >> k;
////
////    memset(dp, -1, sizeof(dp));
////    cout << dfs(0, 0, 0, 0, k) << "\n";
////    return 0;
////}


//#include <iostream>
//#include <cstring>
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 9;
//const int MAXK = MAXN * MAXN;
//const int MAXM = 1 << MAXN;
//
//int n, k;
//ll dp[MAXN + 1][MAXM][2][MAXK];
//ll prepare[MAXM][MAXK];
//
//inline int get(int s, int j) {
//    return (s >> j) & 1;
//}
//
//inline int set(int s, int j, int v) {
//    return v == 1 ? (s | (1 << j)) : (s & (~(1 << j)));
//}
//
//void solve() {
//    int maxs = 1 << n; 
//
//    memset(prepare, 0, sizeof(prepare));
//    for (int s = 0; s < maxs; s++) 
//        prepare[s][0] = 1; 
//
//    for (int i = n - 1; i >= 0; --i) {
//        for (int s = 0; s < maxs; ++s) {
//            for (int king = 0; king <= k; ++king) {
//                dp[n][s][0][king] = prepare[s][king];
//                dp[n][s][1][king] = prepare[s][king];
//            }
//        }
//
//        for (int j = n - 1; j >= 0; --j) {
//            for (int s = 0; s < maxs; ++s) {
//                for (int lup = 0; lup <= 1; lup++) {
//                    for (int king = 0; king <= k; ++king) {
//                        int l = (j == 0) ? 0 : get(s, j - 1);
//                        int up = get(s, j);
//                        int rup = (j == n - 1) ? 0 : get(s, j + 1);
//
//                        ll ans = dp[j + 1][set(s, j, 0)][up][king];
//
//                        if (king > 0 && l == 0 && up == 0 && lup == 0 && rup == 0)
//                            ans += dp[j + 1][set(s, j, 1)][up][king - 1];
//                        
//
//                        dp[j][s][lup][king] = ans;
//                    }
//                }
//            }
//        }
//
//        for (int s = 0; s < maxs; ++s) 
//            for (int king = 0; king <= k; ++king) 
//                prepare[s][king] = dp[0][s][0][king];
//
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> k;
//
//    solve();
//    cout << dp[0][0][0][k] << "\n"; 
//
//    return 0;
//}