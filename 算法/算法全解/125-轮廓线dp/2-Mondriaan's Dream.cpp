////
//////http://poj.org/problem?id=2411
////
////#include<iostream>
////#include<vector>
////#include<cstring>
////
////using namespace std;
////
////typedef long long ll;
////const int MAXN = 11;
////const int MAXM = 1 << 11;
////
////int n, m;
////ll dp[MAXN][MAXN][MAXM];
////
////inline int get(int s, int j) {
////	return (s >> j) & 1;
////}
////
////inline int set(int s, int j, int v) {
////	if (v == 1)
////		return s | (1 << j);
////	else
////		return s & (~(1 << j));
////}
////
////ll dfs(int i, int j, int mask) {
////	if (i == n)
////		return 1;
////
////	if (j == m)
////		return dfs(i + 1, 0, mask);
////
////	if (dp[i][j][mask] != -1)
////		return dp[i][j][mask];
////
////	ll ans = 0;
////	if (get(mask, j) == 1)
////		ans = dfs(i, j + 1, set(mask, j, 0));
////	else {
////		if (i + 1 < n)
////			ans = dfs(i, j + 1, set(mask, j, 1));
////
////		if (j + 1 < m && get(mask, j + 1) == 0)
////			ans += dfs(i, j + 2, mask);
////	}
////
////	return dp[i][j][mask] = ans;
////}
////
////int main() {
////	ios::sync_with_stdio(false);
////	cin.tie(nullptr);
////
////
////	while (cin >> n >> m && (n || m)) {
////		if (n < m)
////			swap(n, m);
////
////		memset(dp, -1, sizeof(dp));
////
////		ll ans = dfs(0, 0, 0);
////		cout << ans << "\n";
////	}
////
////
////	return 0;
////}
//
//#include<iostream>
//#include<vector>
//#include<cstring>
//
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 11;
//const int MAXM = 1 << 11;
//
//int n, m;
////多加一列记录下一行第0列
//ll dp[MAXN + 1][MAXM];
//ll prepare[MAXM];
//
//inline int get(int s, int j) {
//	return (s >> j) & 1;
//}
//
//inline int set(int s, int j, int v) {
//	if (v == 1)
//		return s | (1 << j);
//	else
//		return s & (~(1 << j));
//}
//
//ll solve() {
//	for (int i = 0; i < MAXM; ++i)
//		prepare[i] = 1;
//
//	for (int i = n - 1; i >= 0; --i) {
//
//		for (int mask = 0; mask < MAXM; ++mask)
//			dp[m][mask] = prepare[mask];
//
//		for (int j = m - 1; j >= 0; --j) {
//			for (int mask = 0; mask < MAXM; ++mask) {
//				ll ans = 0;
//
//				if (get(mask, j) == 1)
//					ans = dp[j + 1][set(mask, j, 0)];
//				else {
//					if (i + 1 < n)
//						ans = dp[j + 1][set(mask, j, 1)];
//
//					if (j + 1 < m && get(mask, j + 1) == 0)
//						ans += dp[j + 2][mask];
//				}
//
//				dp[j][mask] = ans;
//			}
//		}
//
//		for (int mask = 0; mask < MAXM; ++mask)
//			prepare[mask] = dp[0][mask];
//	}
//
//	return dp[0][0];
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//
//	while (cin >> n >> m && (n || m)) {
//		if (n < m)
//			swap(n, m);
//
//		memset(dp, -1, sizeof(dp));
//
//		cout << solve() << "\n";
//	}
//
//
//	return 0;
//}