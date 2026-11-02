//
////https://www.luogu.com.cn/problem/U41492
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
//const int MAXN = 1e5 + 10;
//
//int n, m;
//int arr[MAXN];
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//
//int fa[MAXN], sz[MAXN];
//int son[MAXN];
//
//int colorCnt[MAXN];
//int ans[MAXN];
//int diff = 0;
//
//inline void add(int u, int v) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//void dfs1(int u, int f) {
//	fa[u] = f;
//	sz[u] = 1;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != f) {
//			dfs1(v, u);
//
//			sz[u] += sz[v];
//
//			if (son[u] == 0 || sz[son[u]] < sz[v])
//				son[u] = v;
//		}
//	}
//}
//
//void effect(int u) {
//	if (++colorCnt[arr[u]] == 1)
//		++diff;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa[u])
//			effect(v);
//	}
//}
//
////void cancel(int u) {
////	colorCnt[arr[u]] = 0;
////
////	for (int i = head[u]; i; i = nxt[i]) {
////		int v = to[i];
////		if (v != fa[u])
////			cancel(v);
////	}
////}
////
////void dfs2(int u, int keep) {
////	for (int i = head[u]; i; i = nxt[i]) {
////		int v = to[i];
////
////		if (v != fa[u] && v != son[u])
////			dfs2(v, 0);
////	}
////
////	if (son[u] != 0)
////		dfs2(son[u], 1);
////
////	if (++colorCnt[arr[u]] == 1)
////		diff++;
////
////	for (int i = head[u]; i; i = nxt[i]) {
////		int v = to[i];
////
////		if (v != fa[u])
////			effect(v);
////	}
////
////	ans[u] = diff;
////
////	if (keep == 0) {
////		diff = 0;
////		cancel(u);
////	}
////}
//
//
//void cancel(int u) {
//	if (--colorCnt[arr[u]] == 0)
//		--diff;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa[u])
//			cancel(v);
//	}
//}
//
//void dfs2(int u, int keep) {
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != fa[u] && v != son[u])
//			dfs2(v, 0);
//	}
//
//	if (son[u] != 0)
//		dfs2(son[u], 1);
//
//	if (++colorCnt[arr[u]] == 1)
//		diff++;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != fa[u] && v != son[u])
//			effect(v);
//	}
//
//	ans[u] = diff;
//
//	if (keep == 0) 
//		cancel(u);
//	
//}
//
//void solve() {
//	cin >> n;
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//
//	for (int i = 1; i <= n; ++i)
//		cin >> arr[i];
//
//	dfs1(1, 0);
//	dfs2(1, 0);
//
//	cin >> m;
//
//	for (int i = 1; i <= m; ++i) {
//		int u;
//		cin >> u;
//		cout << ans[u] << "\n";
//	}
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