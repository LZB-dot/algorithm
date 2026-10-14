//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//typedef long long ll;
//const ll INF = 1e18;
//const int MAXN = 40000;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
//    int n;
//    ll m;
//    cin >> n >> m;
//
//    vector<int> k(n), c(n);
//    for (int i = 0; i < n; ++i)
//        cin >> k[i];
//    for (int i = 0; i < n; ++i)
//        cin >> c[i];
//
//    //花费cost币时能达到的最大方案数
//    vector<ll> dp(MAXN, 0);
//    dp[0] = 1;
//
//    for (int i = 0; i < n; ++i) { //遍历每个英雄
//
//        for (int cost = MAXN - 1; cost >= 0; --cost) {
//            if (dp[cost] == 0) 
//                continue; //该花费不可达，跳过
//
//            //给第i个英雄买 j 个皮肤
//            for (int j = 1; j <= k[i]; ++j) {
//                int nc = cost + j * c[i]; 
//                if (nc >= MAXN) 
//                    break; //超出最大花费，跳过
//
//                ll tmp = dp[cost] * j;
//                if (tmp > m) 
//                    tmp = m; // 超过m则记为m，避免溢出
//
//                if (tmp > dp[nc]) {
//                    dp[nc] = tmp;
//                }
//            }
//        }
//    }
//
//    for (int cost = 0; cost < MAXN; ++cost) {
//        if (dp[cost] >= m) {
//            cout << cost << endl;
//            return 0;
//        }
//    }
//
//    return 0;
//}