//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int M = 1010;
//int t, m;
//int w[M], v[M];
//int dp[M] = { 0 };
//
//int work() {
//	for (int i = 0; i <m; ++i) {
//		for (int j = t; j >= w[i]; --j) {
//			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//		}
//	}
//	return dp[t];
//}
//
//int main() {
//
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> t >> m;
//	for (int i = 0; i < m; ++i) {
//		cin >> w[i] >> v[i];
//	}
//
//	cout << work() << endl;
//	return 0;
//
//}