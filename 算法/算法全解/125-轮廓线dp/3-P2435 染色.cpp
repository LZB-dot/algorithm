////
//////https://www.luogu.com.cn/problem/P2435
////
////#include <iostream>
////#include <vector>
////#include <cstring>
////using namespace std;
////
////typedef long long ll;
////
////const int MOD = 376544743;
////const int MAXN = 100;   
////const int MAXM = 8;     
////const int MAXK = 1 << (MAXM * 2); 
////
////ll dp[MAXN][MAXM][MAXK];
////int n, m, k;
////vector<int> ft, ed;    
////int fts, eds;           
////
////inline int get(int s, int j) {
////    return (s >> (j * 2)) & 3;
////}
////
////inline int set(int s, int j, int v) {
////    return (s & ~(3 << (j * 2))) | (v << (j * 2));
////}
////
////inline bool check(int s) {
////    for (int j = 0; j < m; ++j) {
////        if (get(s, j) == get(eds, j)) {
////            return false;
////        }
////    }
////    return true;
////}
////
////ll dfs(int i, int j, int s) {
////    if (i == n - 1) 
////        return check(s) ? 1 : 0;
////    
////    if (j == m) 
////        return dfs(i + 1, 0, s);
////
////    if (dp[i][j][s] != -1) 
////        return dp[i][j][s];
////
////    ll ans = 0;
////    int p1 = get(s, j);      
////    int p2 = (j == 0) ? -1 : get(s, j - 1); 
////
////    for (int color = 0; color < k; ++color) {
////        if (color != p1 && color != p2) {
////            ans = (ans + dfs(i, j + 1, set(s, j, color))) % MOD;
////        }
////    }
////
////    return dp[i][j][s] = ans;
////}
////
////int main() {
////    ios::sync_with_stdio(false);
////    cin.tie(nullptr);
////
////    cin >> n >> m >> k;
////    ft.resize(m);
////    ed.resize(m);
////
////    for (int i = 0; i < m; ++i) 
////        cin >> ft[i];
////    for (int i = 0; i < m; ++i) 
////        cin >> ed[i];
////
////    if (n == 1) {
////        for (int i = 0; i < m; ++i) {
////            if (ft[i] != ed[i]) {
////                cout << 0 << "\n";
////                return 0;
////            }
////        }
////        cout << 1 << "\n";
////        return 0;
////    }
////
////    if (k == 1) {
////        cout << 0 << "\n";
////        return 0;
////    }
////
////    if (k == 2) {
////        bool valid = true;
////        if (n % 2 == 1) { 
////            for (int i = 0; i < m; ++i) {
////                if (ft[i] != ed[i]) {
////                    valid = false;
////                    break;
////                }
////            }
////        }
////        else {
////            for (int i = 0; i < m; ++i) {
////                if (ft[i] == ed[i]) {
////                    valid = false;
////                    break;
////                }
////            }
////        }
////        cout << (valid ? 1 : 0) << "\n";
////        return 0;
////    }
////
////    memset(dp, -1, sizeof(dp));
////    fts = 0;
////    eds = 0;
////    for (int j = 0; j < m; ++j) {
////        fts = set(fts, j, ft[j]);
////        eds = set(eds, j, ed[j]);
////    }
////
////    cout << dfs(1, 0, fts) << "\n";
////
////    return 0;
////}
//
//
//#include <iostream>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//typedef long long ll;
//
//const int MOD = 376544743;
//const int MAXN = 100;
//const int MAXM = 8;
//const int MAXK = 1 << (MAXM * 2);
//
//ll dp[MAXM + 1][MAXK];;
//ll prepare[MAXK];
//int n, m, k;
//vector<int> ft, ed;
//int fts, eds;
//
//inline int get(int s, int j) {
//    return (s >> (j * 2)) & 3;
//}
//
//inline int set(int s, int j, int v) {
//    return (s & ~(3 << (j * 2))) | (v << (j * 2));
//}
//
//inline bool check(int a, int b) {
//    for (int j = 0; j < m; ++j) {
//        if (get(a, j) == get(b, j)) {
//            return false;
//        }
//    }
//    return true;
//}
//
//ll solve() {
//
//    for (int s = 0; s < MAXK; ++s)
//        prepare[s] = check(s, eds) ? 1 : 0;
//
//    for (int i = n - 2; i >= 1; --i) {
//
//        for (int s = 0; s < MAXK; ++s)
//            dp[m][s] = prepare[s];
//
//        for (int j = m - 1; j >= 0; --j) {
//            for (int s = 0; s < MAXK; ++s) {
//                ll ans = 0;
//
//                int p1 = get(s, j);
//                int p2 = (j == 0) ? -1 : get(s, j - 1);
//
//                for (int color = 0; color < k; ++color) {
//                    if (color != p1 && color != p2) {
//                        ans = (ans + dp[j + 1][set(s, j, color)]) % MOD;
//                    }
//                }
//                dp[j][s] = ans;
//            }
//        }
//
//        for (int s = 0; s < MAXK; ++s)
//            prepare[s] = dp[0][s];
//    }
//
//    return dp[0][fts];
//
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> m >> k;
//    ft.resize(m);
//    ed.resize(m);
//
//    for (int i = 0; i < m; ++i)
//        cin >> ft[i];
//    for (int i = 0; i < m; ++i)
//        cin >> ed[i];
//
//    if (n == 1) {
//        for (int i = 0; i < m; ++i) {
//            if (ft[i] != ed[i]) {
//                cout << 0 << "\n";
//                return 0;
//            }
//        }
//        cout << 1 << "\n";
//        return 0;
//    }
//
//    if (k == 1) {
//        cout << 0 << "\n";
//        return 0;
//    }
//
//    if (k == 2) {
//        bool valid = true;
//        if (n % 2 == 1) {
//            for (int i = 0; i < m; ++i) {
//                if (ft[i] != ed[i]) {
//                    valid = false;
//                    break;
//                }
//            }
//        }
//        else {
//            for (int i = 0; i < m; ++i) {
//                if (ft[i] == ed[i]) {
//                    valid = false;
//                    break;
//                }
//            }
//        }
//        cout << (valid ? 1 : 0) << "\n";
//        return 0;
//    }
//
//    memset(dp, -1, sizeof(dp));
//    fts = 0;
//    eds = 0;
//    for (int j = 0; j < m; ++j) {
//        fts = set(fts, j, ft[j]);
//        eds = set(eds, j, ed[j]);
//    }
//
//    cout << solve() << "\n";
//
//    return 0;
//}