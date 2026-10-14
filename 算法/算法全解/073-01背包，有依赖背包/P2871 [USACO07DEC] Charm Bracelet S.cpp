//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, m;
//	cin >> n >> m;
//	vector<int>w(n + 1), v(n + 1);
//	for (int i = 1; i <= n; ++i)
//		cin >> w[i] >> v[i];
//
//	vector<int>dp(m + 1, 0);//容量为i的最大价值
//
//	for (int i = 1; i <= n; ++i) 
//		for (int j = m; j >= w[i]; --j) 
//			dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
//
//
//	cout << dp[m] << "\n";
//
//	return 0;
//}
//
//
//
//
//
//
