//#include<iostream>
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1e5 + 10;
//int n, m;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//
//int stjump[MAXN][20], depth[MAXN];
//int diff[MAXN];
//ll ans = 0;
//
//void add(int u, int v) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//void build(int u, int fa) {
//	depth[u] = depth[fa] + 1;
//	stjump[u][0] = fa;
//
//	for (int p = 1; p < 20; ++p)
//		stjump[u][p] = stjump[stjump[u][p - 1]][p - 1];
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa)
//			build(v, u);
//	}
//}
//
//int LCA(int u, int v) {
//	if (depth[u] < depth[v])
//		swap(u, v);
//
//	for (int p = 19; p >= 0; --p) {
//		if (depth[stjump[u][p]] >= depth[v])
//			u = stjump[u][p];
//	}
//
//	if (u == v)
//		return u;
//
//	for (int p = 19; p >= 0; --p) {
//		if (stjump[u][p] != stjump[v][p]) {
//			u = stjump[u][p];
//			v = stjump[v][p];
//		}
//	}
//	return stjump[u][0];
//}
//
//void dfs(int u, int fa) {
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa)
//			dfs(v, u);
//	}
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa) {
//			if (diff[v] == 0)
//				ans += m;
//			else if (diff[v] == 1)
//				ans += 1;
//
//			diff[u] += diff[v];
//		}
//	}
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m;
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//
//	build(1, 0); 
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//		int father = LCA(u, v);
//		diff[u]++;
//		diff[v]++;
//		diff[father] -= 2;
//	}
//
//	dfs(1, 0);
//
//	cout << ans << "\n";
//
//	return 0;
//}