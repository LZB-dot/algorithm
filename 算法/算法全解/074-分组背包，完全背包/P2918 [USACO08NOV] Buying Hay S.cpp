//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int main() {
//	int n, h;
//	cin >> n >> h;
//	vector<int>val(n + 1);
//	vector<int>cost(n + 1);
//	int maxv;
//	for (int i = 1; i <= n; ++i) {
//		cin >> val[i] >> cost[i];
//		maxv = max(maxv, val[i]);
//	}
//
//	int m = h + maxv;
//	vector<vector<int> >dp(n + 1, vector<int>(m + 1, INT_MAX));
//	dp[0][0]= 0;
//
//	for (int i = 1; i <= n; ++i) {
//		//µ±j==val[i]Ê±£¬ÓÐdp[i][0]
//		for (int j = 1; j <= m; ++j) {
//			dp[i][j] = dp[i - 1][j];
//			if (j >= val[i] && dp[i][j - val[i]] != INT_MAX) {
//				dp[i][j] = min(dp[i][j], dp[i][j - val[i]] + cost[i]);
//			}
//		}
//	}
//	int ans = INT_MAX;
//	for (int j = h; j <= m; ++j) {
//		ans = min(ans, dp[n][j]);
//	}
//	cout << ans << endl;
//
//	return 0;
//}