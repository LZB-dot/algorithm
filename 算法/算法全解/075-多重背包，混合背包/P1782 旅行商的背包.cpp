//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 1e4 + 10; 
//
//ll cal(int a, int b, int c, int x) {
//    return 1LL * a * x * x + 1LL * b * x + c; 
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m, v;
//    cin >> n >> m >> v;
//
//    vector<ll> weight, value;
//
//    for (int i = 0; i < n; ++i) {
//        ll w, val, cnt;
//        cin >> w >> val >> cnt;
//
//        ll num = 1;
//        while (num <= cnt) {
//            weight.push_back(num * w);
//            value.push_back(num * val);
//            cnt -= num;
//            num <<= 1; 
//        }
//
//        if (cnt > 0) {
//            weight.push_back(cnt * w);
//            value.push_back(cnt * val);
//        }
//    }
//
//    vector<ll> dp(v + 1, 0);
//
//    for (int i = 0; i < weight.size(); ++i) {
//        ll w = weight[i];
//        ll val = value[i];
//        for (int j = v; j >= w; --j) {
//            dp[j] = max(dp[j], dp[j - w] + val);
//        }
//    }
//
//    for (int i = 0; i < m; ++i) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        vector<ll> tmp = dp; 
//
//        for (int j = 0; j <= v; ++j) {
//            for (int x = 0; x <= v - j; ++x) {
//                dp[j + x] = max(dp[j + x], tmp[j] + cal(a, b, c, x));
//            }
//        }
//    }
//
//    ll ans = 0;
//    for (int j = 0; j <= v; ++j) {
//        ans = max(ans, dp[j]);
//    }
//    cout << ans << "\n";
//
//    return 0;
//}