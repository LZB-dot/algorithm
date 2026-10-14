//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//#define ll long long
//
//const int mod = 1e5 + 3;
//const int N = 1e5 + 5;
//int n, k;
//int dp[N];
//
//int dfs(int i) {
//	if (i == n)
//		return 1;
//
//	if (dp[i] != -1)
//		return dp[i];
//
//	ll res = 0;
//	int ed = min(n, i + k);
//
//	for (int j = i + 1; j <= ed; ++j) {
//		res = (res + dfs(j)) % mod;
//	}
//
//	dp[i] = res;
//	return res;
//
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> k;
//	memset(dp, -1, sizeof(dp));
//	cout << dfs(0) << "\n";
//
//	return 0;
//}