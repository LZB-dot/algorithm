//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//#define ll long long
//
//ll dp[21][21][21];
//
//
//ll dfs(ll a, ll b,ll c) {
//	if (a <= 0 || b <= 0 || c <= 0)
//		return 1;
//
//	if (a > 20 || b > 20 || c > 20)
//		return (ll)dfs(20, 20, 20);
//
//	if (dp[a][b][c] != -1)
//		return dp[a][b][c];
//
//	if (a < b && b < c)
//		return dp[a][b][c] = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
//
//	return dp[a][b][c] = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c)
//		+ dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	ll a, b, c;
//	memset(dp, -1, sizeof(dp));
//	while (cin >> a >> b >> c) {
//		if (a == -1 && b == -1 && c == -1)
//			break;
//		printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, dfs(a, b, c));
//	}
//	
//
//	return 0;
//}