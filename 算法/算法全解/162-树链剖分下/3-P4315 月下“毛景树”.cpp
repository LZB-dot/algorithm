//
//
////https://www.luogu.com.cn/problem/P4315
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
//const int INF = 1e9;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], weight[MAXN << 1];
//int cnt = 1;
//
//int n;
//int arr[MAXN];
//
//int fa[MAXN], dep[MAXN], sz[MAXN];
//int son[MAXN], top[MAXN];
//
//int dfn[MAXN], seg[MAXN];
//int cntd = 0;
//
//int mx[MAXN << 2];
//int change[MAXN << 2];
//int add[MAXN << 2];
//
//inline void addEdge(int u, int v, int w) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	weight[cnt] = w;
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
//		int w = weight[i];
//
//		if (v != f) {
//			arr[v] = w;
//
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
//		if (v != son[u] && v != fa[u])
//			dfs2(v, v);
//	}
//}
//
//
//void up(int i) {
//	mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
//}
//
//void lazyChange(int i, int v) {
//	mx[i] = v;
//	change[i] = v;
//	add[i] = 0;
//}
//
//void lazyAdd(int i, int v) {
//
//	if (change[i] != -1) {
//		change[i] += v;
//		mx[i] += v;
//	}
//	else {
//		mx[i] += v;
//		add[i] += v;
//	}
//
//}
//
//void down(int i) {
//	if (change[i] != -1) {
//		lazyChange(i << 1, change[i]);
//		lazyChange(i << 1 | 1, change[i]);
//		change[i] = -1;
//	}
//
//	if (add[i]) {
//		lazyAdd(i << 1, add[i]);
//		lazyAdd(i << 1 | 1, add[i]);
//		add[i] = 0;
//	}
//}
//
//void build(int l, int r, int i) {
//	change[i] = -1;
//
//	if (l == r)
//		mx[i] = arr[seg[l]];
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
//void changeRange(int jobl, int jobr, int jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazyChange(i, jobv);
//	else {
//		int mid = l + (r - l >> 1);
//		down(i);
//
//		if (jobl <= mid)
//			changeRange(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			changeRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
//}
//
//void pathChange(int x, int y, int v) {
//	if (x == y)
//		return;
//
//	while (top[x] != top[y]) {
//		if (dep[top[x]] <= dep[top[y]]) {
//			changeRange(dfn[top[y]], dfn[y], v, 1, n, 1);
//			y = fa[top[y]];
//		}
//		else {
//			changeRange(dfn[top[x]], dfn[x], v, 1, n, 1);
//			x = fa[top[x]];
//		}
//	}
//
//	changeRange(min(dfn[x], dfn[y]) + 1, max(dfn[x], dfn[y]), v, 1, n, 1);
//
//}
//
//
//void addRange(int jobl, int jobr, int jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazyAdd(i, jobv);
//	else {
//		int mid = l + (r - l >> 1);
//		down(i);
//
//		if (jobl <= mid)
//			addRange(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			addRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
//}
//
//void pathAdd(int x, int y, int v) {
//	if (x == y)
//		return;
//
//	while (top[x] != top[y]) {
//		if (dep[top[x]] <= dep[top[y]]) {
//			addRange(dfn[top[y]], dfn[y], v, 1, n, 1);
//			y = fa[top[y]];
//		}
//		else {
//			addRange(dfn[top[x]], dfn[x], v, 1, n, 1);
//			x = fa[top[x]];
//		}
//	}
//
//	addRange(min(dfn[x], dfn[y]) + 1, max(dfn[x], dfn[y]), v, 1, n, 1);
//}
//
//int queryMax(int jobl, int jobr, int l, int r, int i) {
//
//	if (jobl <= l && r <= jobr)
//		return mx[i];
//
//	int mid = l + (r - l >> 1);
//	down(i);
//	int ans = -INF;
//
//
//	if (jobl <= mid)
//		ans = max(ans, queryMax(jobl, jobr, l, mid, i << 1));
//	if (jobr > mid)
//		ans = max(ans, queryMax(jobl, jobr, mid + 1, r, i << 1 | 1));
//
//	return ans;
//}
//
//int pathMax(int x, int y) {
//	int ans = -INF;
//
//	while (top[x] != top[y]) {
//		if (dep[top[x]] <= dep[top[y]]) {
//			ans = max(ans, queryMax(dfn[top[y]], dfn[y], 1, n, 1));
//			y = fa[top[y]];
//		}
//		else {
//			ans = max(ans, queryMax(dfn[top[x]], dfn[x], 1, n, 1));
//			x = fa[top[x]];
//		}
//	}
//
//	ans = max(ans, queryMax(min(dfn[x], dfn[y]) + 1, max(dfn[x], dfn[y]), 1, n, 1));
//
//	return ans;
//}
//
//
//void solve() {
//	cin >> n;
//
//	vector<pair<int, int>>Edge(n);
//
//	for (int i = 1; i < n; ++i) {
//		int u, v, w;
//		cin >> u >> v >> w;
//
//		addEdge(u, v, w);
//		addEdge(v, u, w);
//
//		Edge[i] = { u,v };
//	}
//
//	dfs1(1, 0);
//	dfs2(1, 1);
//
//	build(1, n, 1);
//
//	string op;
//	cin >> op;
//
//	while (op != "Stop") {
//		if (op == "Change") {
//			int k, w;
//			cin >> k >> w;
//
//			int u;
//
//			if (dep[Edge[k].first] < dep[Edge[k].second])
//				u = Edge[k].second;
//			else
//				u = Edge[k].first;
//
//			changeRange(dfn[u], dfn[u], w, 1, n, 1);
//		}
//		else if (op == "Cover") {
//			int u, v, w;
//			cin >> u >> v >> w;
//
//			pathChange(u, v, w);
//		}
//		else if (op == "Add") {
//			int u, v, w;
//			cin >> u >> v >> w;
//
//			pathAdd(u, v, w);
//		}
//		else {
//			int x, y;
//			cin >> x >> y;
//
//			if (x == y)
//				cout << "0\n";
//			else
//				cout << pathMax(x, y) << "\n";
//		}
//
//		cin >> op;
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