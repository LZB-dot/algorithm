//#include<iostream>
//#include<vector>
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, x;
//	cin >> n >> x;
//
//	vector<int>w, v;
//	ll ans = 0;
//	int a, b, h;
//	for (int i = 1; i <= n; ++i) {
//		cin >> a >> b >> h;
//		if (a - b > b) {
//			x += a - b - b;
//			ans += h;
//		}
//		else {
//			w.push_back(b - a + b);
//			v.push_back(h);
//		}
//	}
//
//	int m = w.size();
//	vector<ll>dp(x + 1);
//	for (int i = 0; i < m; ++i) {
//		for (int j = x; j >= w[i]; --j) {
//			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//		}
//	}
//
//	cout << ans + dp[x] << "\n";
//
//	return 0;
//}