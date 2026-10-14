//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//#define ll long long
//
//bool check1(int mask) {
//    return !(mask & (mask << 1));
//}
//
//bool check2(int mask1, int mask2) {
//    //上下
//    if (mask1 & mask2)
//        return false;
//    //左上到右下
//    if ((mask1 << 1) & mask2)
//        return false;
//    //右上到左下
//    if ((mask1 >> 1) & mask2)
//        return false;
//
//    return true;
//}
//
//ll cal(const vector<int>& row, int mask) {
//    ll sum = 0;
//    int col = 0;
//    while(mask){
//        if (mask & 1)
//            sum += row[col];
//        ++col;
//        mask >>= 1;
//    }
//
//    return sum;
//}
//
//void solve() {
//    int n, m;
//    cin >> n >> m;
//
//    vector<vector<int>> nums(n, vector<int>(m)); 
//    for (int i = 0; i < n; ++i)
//        for (int j = 0; j < m; ++j)
//            cin >> nums[i][j];
//
//    vector<vector<ll>> dp(n, vector<ll>(1 << m, -1));
//
//    for (int mask = 0; mask < (1 << m); ++mask) {
//        if (check1(mask))
//            dp[0][mask] = cal(nums[0], mask);
//    }
//
//    for (int i = 1; i < n; ++i) {
//
//        for (int m2 = 0; m2 < (1 << m); ++m2) {
//            if (!check1(m2))
//                continue;
//
//            for (int m1 = 0; m1 < (1 << m); ++m1) {
//                if (dp[i - 1][m1] == -1)
//                    continue;
//                if (!check2(m1, m2))
//                    continue;
//
//                ll cur = cal(nums[i], m2);
//                dp[i][m2] = max(dp[i][m2], cur + dp[i - 1][m1]);
//            }
//        }
//    }
//
//    ll ans = 0;
//    for (int mask = 0; mask < (1 << m); ++mask)
//            ans = max(ans, dp[n-1][mask]);
//    cout << ans << "\n";
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int T;
//    cin >> T;
//    while (T--) 
//        solve();
//
//    return 0;
//}