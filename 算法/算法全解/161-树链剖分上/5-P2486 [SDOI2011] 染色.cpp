//
////https://www.luogu.com.cn/problem/P2486
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
//int cnt = 1;
//
//int n, m;
//int arr[MAXN];
//
//int fa[MAXN], sz[MAXN], dep[MAXN];
//int son[MAXN];
//int top[MAXN];
//
//int dfn[MAXN];
//int seg[MAXN];
//int cntd;
//
//int sum[MAXN << 2];
//int lcolor[MAXN << 2], rcolor[MAXN << 2];
//int change[MAXN << 2];
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
//	seg[cntd] = u;
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
//
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//
//	if (rcolor[i << 1] == lcolor[i << 1 | 1])
//		sum[i]--;
//
//	lcolor[i] = lcolor[i << 1];
//	rcolor[i] = rcolor[i << 1 | 1];
//}
//
//void lazy(int i, int v) {
//	sum[i] = 1;
//	lcolor[i] = v;
//	rcolor[i] = v;
//	change[i] = v;
//}
//
//void down(int i) {
//	if (change[i] != 0) {
//		lazy(i << 1, change[i]);
//		lazy(i << 1 | 1, change[i]);
//		change[i] = 0;
//	}
//}
//
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = 1;
//		lcolor[i] = rcolor[i] = arr[seg[l]];
//	}
//	else {
//		int mid = l + (r - l >> 1);
//
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
//}
//
//void update(int jobl, int jobr, int jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazy(i, jobv);
//	else {
//		int mid = l + (r - l >> 1);
//
//		down(i);
//
//		if (jobl <= mid)
//			update(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			update(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
//}
//
//void pathUpdate(int x, int y, int v) {
//	while (top[x] != top[y]) {
//		if (dep[top[x]] <= dep[top[y]]) {
//			update(dfn[top[y]], dfn[y], v, 1, n, 1);
//			y = fa[top[y]];
//		}
//		else {
//			update(dfn[top[x]], dfn[x], v, 1, n, 1);
//			x = fa[top[x]];
//		}
//	}
//
//	update(min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), v, 1, n, 1);
//
//}
//
//int query(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return sum[i];
//
//	int mid = l + (r - l >> 1);
//	down(i);
//
//	if (jobr <= mid)
//		return query(jobl, jobr, l, mid, i << 1);
//	if (jobl > mid)
//		return query(jobl, jobr, mid + 1, r, i << 1 | 1);
//
//	int a = query(jobl, jobr, l, mid, i << 1);
//	int b = query(jobl, jobr, mid + 1, r, i << 1 | 1);
//
//	int cur = a + b;
//
//	if (rcolor[i << 1] == lcolor[i << 1 | 1])
//		--cur;
//
//	return cur;
//
//}
//
//int pointColor(int jobi, int l, int r, int i) {
//	if (l == r)
//		return lcolor[i];
//
//	down(i);
//
//	int mid = l + (r - l >> 1);
//
//	if (jobi <= mid)
//		return pointColor(jobi, l, mid, i << 1);
//
//	return pointColor(jobi, mid + 1, r, i << 1 | 1);
//}
//
//int pathQuery(int x, int y) {
//	int ans = 0;
//	int sonc, fac;
//
//	while (top[x] != top[y]) {
//		if (dep[top[x]] <= dep[top[y]]) {
//			ans += query(dfn[top[y]], dfn[y], 1, n, 1);
//			sonc = pointColor(dfn[top[y]], 1, n, 1);
//			fac = pointColor(dfn[fa[top[y]]], 1, n, 1);
//			y = fa[top[y]];
//		}
//		else {
//			ans += query(dfn[top[x]], dfn[x], 1, n, 1);
//			sonc = pointColor(dfn[top[x]], 1, n, 1);
//			fac = pointColor(dfn[fa[top[x]]], 1, n, 1);
//			x = fa[top[x]];
//		}
//
//		if (sonc == fac)
//			--ans;
//	}
//
//	ans += query(min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), 1, n, 1);
//
//	return ans;
//}
//
//void solve() {
//	cin >> n >> m;
//
//	for (int i = 1; i <= n; ++i)
//		cin >> arr[i];
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//
//		add(u, v);
//		add(v, u);
//	}
//
//	dfs1(1, 0);
//	dfs2(1, 1);
//
//	build(1, n, 1);
//
//
//	while (m--) {
//		string op;
//		cin >> op;
//
//		int a, b, c;
//
//		if (op == "C") {
//			cin >> a >> b >> c;
//			pathUpdate(a, b, c);
//		}
//		else {
//			cin >> a >> b;
//			cout << pathQuery(a, b) << "\n";
//		}
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