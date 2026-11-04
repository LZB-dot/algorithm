//
////https://codeforces.com/problemset/problem/1009/F
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
//const int MAXN = 1e6 + 10;
//const int INF = 1e9;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//
//int n;
//
//int fa[MAXN], len[MAXN];
//int son[MAXN], top[MAXN];
//
//int dfn[MAXN];
//int cntd = 0;
//
//int dp[MAXN];
//int ans[MAXN];
//
//inline void addEdge(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void dfs1(int u, int f) {
//	fa[u] = f;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != f) {
//			dfs1(v, u);
//
//			if (son[u] == 0 || len[son[u]] < len[v])
//				son[u] = v;
//		}
//	}
//
//	len[u] = len[son[u]] + 1;
//}
//
//void dfs2(int u, int t) {
//	dfn[u] = ++cntd;
//
//	dp[dfn[u]] = 1;
//	ans[u] = 0;
//
//	if (son[u] == 0)
//		return;
//
//	dfs2(son[u], t);
//
//	ans[u] = ans[son[u]] + 1;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != son[u] && v != fa[u]) {
//			dfs2(v, v);
//
//			for (int j = 1; j <= len[v]; ++j) {
//				dp[dfn[u] + j] = dp[dfn[u] + j] + dp[dfn[v] + j - 1];
//
//				if (dp[dfn[u] + j] > dp[dfn[u] + ans[u]]
//					|| (dp[dfn[u] + j] == dp[dfn[u] + ans[u]] && j < ans[u]))
//					ans[u] = j;
//			}
//		}
//	}
//
//	if (dp[dfn[u] + ans[u]] == 1)
//		ans[u] = 0;
//
//}
//
//
//void solve() {
//	cin >> n;
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//
//		addEdge(u, v);
//		addEdge(v, u);
//	}
//
//	dfs1(1, 0);
//	dfs2(1, 1);
//
//	for (int i = 1; i <= n; i++)
//		cout << ans[i] << "\n";
//}
//
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	solve();
//
//	return 0;
//}