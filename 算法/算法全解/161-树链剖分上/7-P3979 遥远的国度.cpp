//
////https://www.luogu.com.cn/problem/P3979
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
//const ll INF = 1e18 + 10;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//
//int n, m;
//int arr[MAXN];
//int root;
//
//int fa[MAXN], sz[MAXN], dep[MAXN];
//int son[MAXN];
//int top[MAXN];
//
//int dfn[MAXN], seg[MAXN];
//int cntd = 0;
//
//int change[MAXN << 2];
//int mi[MAXN << 2];
//
//inline void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void dfs1(int u, int f) {
//	fa[u] = f;
//	sz[u] = 1;
//	dep[u] = dep[f] + 1;
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
//
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
//		if (v != son[u] && v != fa[u])
//			dfs2(v, v);
//	}
//}
//
//void up(int i) {
//	mi[i] = min(mi[i << 1], mi[i << 1 | 1]);
//}
//
//void build(int l, int r, int i) {
//
//	change[i] = -1;
//
//	if (l == r) 
//		mi[i] = arr[seg[l]];
//	else {
//		int mid = l + (r - l >> 1);
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//}
//
//void lazy(int i, int v) {
//	mi[i] = v;
//	change[i] = v;
//}
//
//void down(int i) {
//	if (change[i] != -1) {
//		lazy(i << 1, change[i]);
//		lazy(i << 1 | 1, change[i]);
//		change[i] = -1;
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
//
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
//}
//
//ll query(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return mi[i];
//
//	int mid = l + (r - l >> 1);
//	ll ans = INF;
//	down(i);
//
//	if (jobl <= mid)
//		ans = min(ans, query(jobl, jobr, l, mid, i << 1));
//	if (jobr > mid)
//		ans = min(ans, query(jobl, jobr, mid + 1, r, i << 1 | 1));
//
//	return ans;
//}
//
//
//int findSon(int rt, int u) {
//	while (top[rt] != top[u]) {
//		if (fa[top[rt]] == u)
//			return top[rt];
//		rt = fa[top[rt]];
//	}
//
//	return son[u];
//}
//
//ll treeQuery(int rt, int u) {
//	if (rt == u)
//		return query(1, n, 1, n, 1);
//
//	int dr = dfn[rt];
//	int du = dfn[u];
//
//	if (dr<du || dr>du + sz[u] - 1)
//		return query(dfn[u], dfn[u] + sz[u] - 1, 1, n, 1);
//
//	int uson = findSon(rt, u);
//	int l = dfn[uson];
//	int r = dfn[uson] + sz[uson] - 1;
//
//	ll ans = INF;
//
//	if (1 <= l - 1)
//		ans = min(ans, query(1, l - 1, 1, n, 1));
//
//	if (r + 1 <= n)
//		ans = min(ans, query(r + 1, n, 1, n, 1));
//
//	return ans;
//}
//
//void solve() {
//	cin >> n >> m;
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//
//		add(u, v);
//		add(v, u);
//	}
//
//	for (int i = 1; i <= n; ++i)
//		cin >> arr[i];
//
//	cin >> root;
//
//	dfs1(1, 0);
//	dfs2(1, 1);
//
//	build(1, n, 1);
//
//
//	while (m--) {
//		int op;
//		cin >> op;
//
//		if (op == 1) {
//			int id;
//			cin >> id;
//			root = id;
//		}
//		else if (op == 2) {
//			int x, y, v;
//			cin >> x >> y >> v;
//			pathUpdate(x, y, v);
//		}
//		else {
//			int x;
//			cin >> x;
//
//			cout << treeQuery(root,x) << "\n";
//		}
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