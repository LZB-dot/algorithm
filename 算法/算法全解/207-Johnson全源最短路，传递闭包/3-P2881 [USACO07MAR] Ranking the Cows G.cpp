//
//
////https://www.luogu.com.cn/problem/P2881
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring> 
//#include<queue>
//#include<unordered_map>
//#include<climits>
//#include<bitset>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1010;
//
//bitset<MAXN>g[MAXN];
//
//void solve() {
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//
//		g[u][v] = 1;
//	}
//
//	for (int k = 1; k <= n; ++k) {
//		for (int i = 1; i <= n; ++i) {
//			if (g[i][k])
//				g[i] |= g[k];
//		}
//	}
//
//	ll has = 0;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = i + 1; j <= n; ++j) {
//			if (g[i][j] || g[j][i])
//				has++;
//		}
//	}
//
//	ll total = 1LL * n * (n - 1) / 2;
//	ll ans = total - has;
//
//	cout << ans << "\n";
//	
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	solve();
//
//	return 0;
//}