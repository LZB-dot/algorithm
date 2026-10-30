//
//
////边权转化为点权模板
////https://www.luogu.com.cn/problem/P3038
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
//const int MAXN = 1e5 + 10;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt;
//
//int n, m;
//
//int fa[MAXN], sz[MAXN], dep[MAXN];
//int son[MAXN], top[MAXN];
//int dfn[MAXN];
//int cntd;
//
//int sum[MAXN << 2];
//int addF[MAXN << 2];
//
//void init() {
//	cnt = 2;
//	cntd = 0;
//
//	for (int i = 0; i <= n; ++i) {
//		head[i] = 0;
//		fa[i] = i;
//		sz[i] = 1;
//		dep[i] = 0;
//		dfn[i] = 0;
//		son[i] = 0;
//		top[i] = 0;
//	}
//
//}
//
//inline void addEdge(int u, int v) {
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
//			sz[u] += sz[v];
//
//			if (son[u] == 0 || sz[son[u]] < sz[v])
//				son[u] = v;
//		}
//	}
//}
//
//void dfs2(int u, int t) {
//	top[u] = t;
//	dfn[u] = ++cntd;
//
//	if (son[u] == 0)
//		return;
//
//	dfs2(son[u], t);
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != son[u] && v != fa[u])
//			dfs2(v, v);
//	}
//}
//
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//
//void lazy(int i, int v, int len) {
//	sum[i] += v * len;
//	addF[i] += v;
//}
//
//void down(int i, int ln, int rn) {
//	if (addF[i]) {
//		lazy(i << 1, addF[i], ln);
//		lazy(i << 1 | 1, addF[i], rn);
//		addF[i] = 0;
//	}
//}
//
//void add(int jobl, int jobr, int jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazy(i, jobv, r - l + 1);
//	else {
//		int mid = l + (r - l >> 1);
//		down(i, mid - l + 1, r - mid);
//
//		if (jobl <= mid)
//			add(jobl, jobr, jobv, l, mid, i << 1);
//
//		if (jobr > mid)
//			add(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
//}
//
//int query(int jobi, int l, int r, int i) {
//	if (l == r)
//		return sum[i];
//
//	int mid = l + (r - l >> 1);
//	down(i, mid - l + 1, r - mid);
//
//	if (jobi <= mid)
//		return query(jobi, l, mid, i << 1);
//	else
//		return query(jobi, mid + 1, r, i << 1 | 1);
//
//}
//
//void pathAdd(int x, int y, int v) {
//	while (top[x] != top[y]) {
//		if (dep[top[x]] <= dep[top[y]]) {
//			add(dfn[top[y]], dfn[y], v, 1, n, 1);
//			y = fa[top[y]];
//		}
//		else {
//			add(dfn[top[x]], dfn[x], v, 1, n, 1);
//			x = fa[top[x]];
//		}
//	}
//
//	add(min(dfn[x], dfn[y]) + 1, max(dfn[x], dfn[y]), v, 1, n, 1);
//}
//
//
//void solve() {
//	init();
//	cin >> n >> m;
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
//	char op;
//	for (int i = 1; i <= m; ++i) {
//		cin >> op;
//		int u, v;
//		cin >> u >> v;
//
//		if (op == 'P')
//			pathAdd(u, v, 1);
//		else {
//			int down = max(dfn[u], dfn[v]);
//			cout << query(down, 1, n, 1) << "\n";
//		}
//
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