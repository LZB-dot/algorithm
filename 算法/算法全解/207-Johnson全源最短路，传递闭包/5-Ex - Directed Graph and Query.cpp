//
//
////https://atcoder.jp/contests/abc287/tasks/abc287_h
//
//
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
//const int MAXN = 2010;
//const int MAXM = 10010;
//
//int n, m, q;
//
//bitset<MAXN>g[MAXN];
//int s[MAXM], t[MAXM];
//int ans[MAXM];
//
//void floyd() {
//
//	for (int i = 1; i <= q; i++) 
//		ans[i] = -1;
//	
//	for (int bridge = 1; bridge <= n; ++bridge) {
//		
//		for (int i = 1; i <= n; ++i) {
//			if (g[i][bridge])
//				g[i] |= g[bridge];
//
//		}
//
//		for (int i = 1; i <= q; ++i) {
//			if (ans[i] == -1 && g[s[i]][t[i]]) 
//				ans[i] = max(bridge, max(s[i], t[i]));
//		}
//	}
//}
//
//void solve() {
//	cin >> n >> m;
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//
//		g[u][v] = 1;
//	}
//
//	cin >> q;
//	for (int i = 1; i <= q; ++i)
//		cin >> s[i] >> t[i];
//
//	floyd();
//
//	for (int i = 1; i <= q; ++i)
//		cout << ans[i] << '\n';
//
//	return;
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