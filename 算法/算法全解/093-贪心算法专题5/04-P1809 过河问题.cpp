//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//#define ll long long
//
//int n;
//vector<int>times;
//vector<ll>dp;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n;
//	times.resize(n);
//	for (int i = 0; i < n; ++i)
//		cin >> times[i];
//
//	sort(times.begin(), times.end());
//	dp.resize(n + 1, 0);
//	if (n >= 1)
//		dp[0] = times[0];
//	if (n >= 2)
//		dp[1] = times[1];
//	if (n >= 3)
//		dp[2] = times[0] + times[1] + times[2];
//
//	for (int i = 3; i < n; ++i) {
//		int p1 = times[0] + times[i] + dp[i - 1];
//		int p2 = times[0] + times[1] + times[1] +times[i] + dp[i - 2];
//		dp[i] = min(p1, p2);
//	}
//
//	cout << dp[n - 1] << endl;
//	return 0;
//}