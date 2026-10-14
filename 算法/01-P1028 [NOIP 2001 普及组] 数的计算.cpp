//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//const int N = 1e4 + 10;
//int dp[N];
//
//int dfs(int n) {
//
//	if (dp[n] != -1)
//		return dp[n];
//
//	if (n == 1)
//		return 1;
//
//	int ans = 1;
//	for (int i = 1; i <= (n >> 1); ++i) {
//		ans += dfs(i);
//	}
//	dp[n] = ans;
//	return ans;
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n;
//	cin >> n;
//	memset(dp, -1, N);
//	cout << dfs(n) << endl;
//
//	return 0;
//}