//
////https://www.luogu.com.cn/problem/P3379
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
//const int MAXN = 5e5 + 10;
//
//int n, m, root;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//
//int fa[MAXN], dep[MAXN], sz[MAXN];
//int son[MAXN];
//int top[MAXN];
//
//inline void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void dfs1(int u, int f) {
//	fa[u] = f;
//	dep[u] = dep[f] + 1;
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
//
//void dfs2(int u, int t) {
//	top[u] = t;
//
//	if (son[u] == 0)
//		return;
//
//	dfs2(son[u], t);
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != fa[u] && v != son[u])
//			dfs2(v, v);
//	}
//}
//
//int LCA(int a, int b) {
//	while (top[a] != top[b]) {
//		if (dep[top[a]] <= dep[top[b]])
//			b = fa[top[b]];
//		else
//			a = fa[top[a]];
//	}
//
//	return dep[a] <= dep[b] ? a : b;
//}
//
//void solve() {
//	cin >> n >> m >> root;
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//
//	dfs1(root, 0);
//	dfs2(root, root);
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//
//		cout << LCA(u, v) << "\n";
//	}
//
//	return;
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