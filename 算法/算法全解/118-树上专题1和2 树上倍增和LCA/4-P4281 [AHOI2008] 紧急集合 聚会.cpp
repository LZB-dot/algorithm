//
//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 5e5 + 10;
//int head[MAXN], nxt[MAXN << 1], to[MAXN << 1];
//int cnt;
//
//int stjump[MAXN][20];
//int depth[MAXN];
//int power = 0;
//
//int togather;
//ll cost;
//
//int mylog2(int n) {
//	int ans = 0;
//	while ((1 << ans) <= (n >> 1))
//		++ans;
//	return ans;
//}
//
//void build(int n) {
//	power = mylog2(n);
//	cnt = 1;
//	memset(head + 1, 0, n * sizeof(int));
//}
//
//void add(int u, int v) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//void dfs(int u, int fa) {
//	depth[u] = depth[fa] + 1;
//	stjump[u][0] = fa;
//
//	for (int p = 1; p <= power; ++p)
//		stjump[u][p] = stjump[stjump[u][p - 1]][p - 1];
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa)
//			dfs(v, u);
//	}
//}
//
//int LCA(int u, int v) {
//	if (depth[u] < depth[v])
//		swap(u, v);
//
//	for (int p = power; p >= 0; --p)
//		if (depth[stjump[u][p]] >= depth[v])
//			u = stjump[u][p];
//
//	if (u == v)
//		return u;
//
//
//	for (int p = power; p >= 0; --p) {
//		if (stjump[u][p] != stjump[v][p]) {
//			u = stjump[u][p];
//			v = stjump[v][p];
//		}
//	}
//
//	return stjump[u][0];
//}
//
//void compute(int a, int b, int c) {
//	int h1 = LCA(a, b);
//	int h2 = LCA(a, c);
//	int h3 = LCA(c, b);
//
//	int high, low;
//	if (h1 != h2) {
//		high = depth[h1] > depth[h2] ? h2 : h1;
//		low = depth[h1] > depth[h2] ? h1 : h2;
//	}
//	else {
//		high = h1;
//		low = h3;
//	}
//
//	togather = low;
//	cost = (ll)depth[a] + depth[b] + depth[c] - 2LL * depth[high] - depth[low];
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, m;
//	cin >> n >> m;
//
//	build(n);
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//
//		add(u, v);
//		add(v, u);
//	}
//
//	dfs(1, 0);
//
//	for (int i = 1; i <= m; ++i) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		compute(a, b, c);
//		cout << togather << " " << cost << "\n";
//	}
//
//
//	return 0;
//}
//
//
//
//
