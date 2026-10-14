//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 5e5 + 10;
//
//int n, m, s;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//
//int depth[MAXN], stjump[MAXN][20];
//
//void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void dfs(int u, int fa) {
//	depth[u] = depth[fa] + 1;
//
//	stjump[u][0] = fa;
//	for (int p = 1; p < 20; ++p)
//		stjump[u][p] = stjump[stjump[u][p - 1]][p - 1];
//
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa)
//			dfs(v, u);
//	}
//}
//
//int mylog2(int x) {
//	int res = 0;
//	while ((1 << res) <= (x >> 1))
//		++res;
//	return res;
//}
//
//int lca(int u, int v) {
//	if (depth[u] < depth[v])
//		swap(u, v);
//
//
//	for (int p = 19; p >= 0; --p)
//		if (depth[stjump[u][p]] >= depth[v])
//			u = stjump[u][p];
//
//	if (u == v)
//		return u;
//
//	int power = mylog2(depth[u]);
//
//	for (int p = power; p >= 0; --p) {
//		if (stjump[u][p] != stjump[v][p]) {
//			u = stjump[u][p];
//			v = stjump[v][p];
//		}
//	}
//	return stjump[u][0];
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m >> s;
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//
//	dfs(s, 0);
//
//	while (m--) {
//		int u, v;
//		cin >> u >> v;
//		cout << lca(u, v) << "\n";
//	}
//
//	return 0;
//}