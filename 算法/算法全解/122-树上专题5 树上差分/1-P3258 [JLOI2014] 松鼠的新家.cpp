//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 3e5 + 10;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//
//int stjump[MAXN][20], depth[MAXN];
//
//int diff[MAXN];
//
//int ans[MAXN];
//
//void add(int u, int v) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//void build(int u, int fa) {
//	stjump[u][0] = fa;
//	depth[u] = depth[fa] + 1;
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
//
//	return stjump[u][0];
//}
//
//void dfs(int u, int fa) {
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v == fa)
//			continue;
//
//		dfs(v, u);
//		diff[u] += diff[v];
//	}
//
//	ans[u] = diff[u];
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; ++i)
//		cin >> a[i];
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//	build(1, 0);
//
//
//	for (int i = 1; i < n; ++i) {
//		int u = a[i];
//		int v = a[i + 1];
//		int father = LCA(u, v);
//		diff[u] += 1;
//		diff[v] += 1;
//		diff[father] -= 1;
//		diff[stjump[father][0]] -= 1;
//	}
//
//	dfs(1, 0);
//
//	for (int i = 2; i <= n; ++i) 
//		ans[a[i]]--;
//	
//
//	for (int i = 1; i <= n; ++i) 
//			cout << ans[i] << "\n";
//	
//
//
//	return 0;
//}