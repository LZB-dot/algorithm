//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 1e4 + 10;
//const int MAXM = 5e4 + 10;
//const int INF = 1e9;
//
//int n, m;
//int head[MAXN], to[MAXM], nxt[MAXM], weight[MAXM];
//int cnt = 1;
//
//int fa[MAXN];
//
//int root;
//int stjump[MAXN][15], depth[MAXN];
//int stmin[MAXN][15];
//
//struct Edge {
//	int u, v, w;
//
//	bool operator<(const Edge& other) {
//		return w > other.w;
//	}
//}Edges[MAXM];
//
//void add(int u, int v, int w) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//
//int find(int x) {
//	if (fa[x] != x)
//		fa[x] = find(fa[x]);
//
//	return fa[x];
//}
//
//void dfs(int u, int fa, int w) {
//	depth[u] = depth[fa] + 1;
//	stjump[u][0] = fa;
//	stmin[u][0] = w;
//
//	for (int p = 1; p < 15; ++p) {
//		stjump[u][p] = stjump[stjump[u][p - 1]][p - 1];
//		stmin[u][p] = min(stmin[u][p - 1], stmin[stjump[u][p - 1]][p - 1]);
//	}
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa)
//			dfs(v, u, weight[i]);
//	}
//}
//
//int query(int x, int y) {
//	if (find(x) != find(y))
//		return -1;
//
//	int res = INF;
//
//	if (depth[x] < depth[y])
//		swap(x, y);
//
//	for (int p = 14; p >= 0; --p) {
//		if (depth[stjump[x][p]] >= depth[y]) {
//			res = min(res, stmin[x][p]);
//			x = stjump[x][p];
//		}
//	}
//
//	if (x == y)
//		return res;
//
//	for (int p = 14; p >= 0; --p) {
//		if (stjump[x][p] != stjump[y][p]) {
//			res = min(res, min(stmin[x][p], stmin[y][p]));
//			x = stjump[x][p];
//			y = stjump[y][p];
//		}
//	}
//
//	res = min(res, min(stmin[x][0], stmin[y][0]));
//	return res;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m;
//
//	for (int i = 1; i <= n; ++i)
//		fa[i] = i;
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v, w;
//		cin >> u >> v >> w;
//		Edges[i] = { u,v,w };
//	}
//
//	sort(Edges + 1, Edges + m + 1);
//
//	for (int i = 1; i <= m; ++i) {
//		int u = Edges[i].u, v = Edges[i].v, w = Edges[i].w;
//
//		int fu = find(u);
//		int fv = find(v);
//		if (fu != fv) {
//			fa[fu] = fv;
//			add(u, v, w);
//			add(v, u, w);
//		}
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		if (depth[i] == 0)
//			dfs(i, 0, INF);
//	}
//
//	int q;
//	cin >> q;
//	while (q--) {
//		int x, y;
//		cin >> x >> y;
//		cout << query(x, y) << "\n";
//	}
//
//	return 0;
//}