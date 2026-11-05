//
////https://www.luogu.com.cn/problem/P2245
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
//const int MAXN = 2e5 + 10;
//const int MAXM = 3e5 + 10;
//const int MAXP = 20;
//
//struct Edge {
//	int u, v, w;
//};
//
//bool cmp(Edge x, Edge y) {
//	return x.w < y.w;
//}
//int head[MAXN], to[MAXN], nxt[MAXN];
//int cnt = 1;
//
//int weight[MAXN];
//int cntu;
//
//int dep[MAXN];
//int stjump[MAXN][MAXP];
//
//int fa[MAXN];
//int n, m, q;
//Edge edge[MAXM];
//
//
//int find(int i) {
//	if (i != fa[i])
//		fa[i] = find(fa[i]);
//
//	return fa[i];
//}
//
//inline void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void kruskal() {
//	for (int i = 1; i <= n; ++i)
//		fa[i] = i;
//
//	sort(edge + 1, edge + m + 1, cmp);
//
//	cntu = n;
//
//	for (int i = 1; i <= m; ++i) {
//		int fx = find(edge[i].u);
//		int fy = find(edge[i].v);
//
//		if (fx != fy) {
//			cntu++;
//
//			fa[fx] = fa[fy] = cntu;
//			fa[cntu] = cntu;
//
//			weight[cntu] = edge[i].w;
//
//			add(cntu, fx);
//			add(cntu, fy);
//		}
//	}
//
//}
//
//void dfs(int u, int f) {
//	dep[u] = dep[f] + 1;
//	stjump[u][0] = f;
//
//	for (int p = 1; p < MAXP; ++p)
//		stjump[u][p] = stjump[stjump[u][p - 1]][p - 1];
//
//	for (int i = head[u]; i; i = nxt[i])
//		dfs(to[i], u);
//}
//
//int LCA(int a, int b) {
//	if (dep[a] < dep[b])
//		swap(a, b);
//
//	for (int p = MAXP - 1; p >= 0; --p) {
//		if (dep[stjump[a][p]] >= dep[b])
//			a = stjump[a][p];
//	}
//
//	if (a == b)
//		return a;
//
//	for (int p = MAXP - 1; p >= 0; --p) {
//		if (stjump[a][p] != stjump[b][p]) {
//			a = stjump[a][p];
//			b = stjump[b][p];
//		}
//	}
//
//
//	return stjump[a][0];
//}
//
//void solve() {
//	cin >> n >> m;
//
//	for (int i = 1; i <= m; ++i)
//		cin >> edge[i].u >> edge[i].v >> edge[i].w;
//
//	kruskal();
//
//	for (int i = 1; i <= cntu; ++i) {
//		if (i == fa[i])
//			dfs(i, 0);
//	}
//
//	cin >> q;
//
//	for (int i = 1; i <= q; i++) {
//		int x, y;
//		cin >> x >> y;
//
//		if (find(x) != find(y))
//			cout << "impossible\n";
//		else
//			cout << weight[LCA(x, y)] << "\n";
//
//	}
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