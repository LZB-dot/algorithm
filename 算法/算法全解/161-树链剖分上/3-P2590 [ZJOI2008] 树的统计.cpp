//
//// https://www.luogu.com.cn/problem/P2590
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
//const int MAXN = 3e4 + 10;
//const int INF = 1e9;
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
//int cntd = 0;
//
//int mx[MAXN << 2];
//int sum[MAXN << 2];
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
//
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
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//	mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
//}
//
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = arr[seg[l]];
//		mx[i] = arr[seg[l]];
//	}
//	else {
//		int mid = l + (r - l >> 1);
//
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
//
//}
//
//void update(int jobi, int jobv, int l, int r, int i) {
//	if (l == r) {
//		sum[i] = jobv;
//		mx[i] = jobv;
//	}
//	else {
//		int mid = l + (r - l >> 1);
//
//		if (jobi <= mid)
//			update(jobi, jobv, l, mid, i << 1);
//		else
//			update(jobi, jobv, mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
//}
//
//int queryMax(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return mx[i];
//
//	int mid = l + (r - l >> 1);
//	int ans = -INF;
//
//	if (jobl <= mid)
//		ans = max(ans, queryMax(jobl, jobr, l, mid, i << 1));
//	if (jobr > mid)
//		ans = max(ans, queryMax(jobl, jobr, mid + 1, r, i << 1 | 1));
//
//	return ans;
//}
//
//int querySum(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return sum[i];
//
//	int mid = l + (r - l >> 1);
//	int ans = 0;
//
//	if (jobl <= mid)
//		ans += querySum(jobl, jobr, l, mid, i << 1);
//	if (jobr > mid)
//		ans += querySum(jobl, jobr, mid + 1, r, i << 1 | 1);
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
//	ans = max(ans, queryMax(min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), 1, n, 1));
//
//	return ans;
//}
//
//int pathSum(int x, int y) {
//	int ans = 0;
//
//	while (top[x] != top[y]) {
//		if (dep[top[x]] <= dep[top[y]]) {
//			ans += querySum(dfn[top[y]], dfn[y], 1, n, 1);
//			y = fa[top[y]];
//		}
//		else {
//			ans += querySum(dfn[top[x]], dfn[x], 1, n, 1);
//			x = fa[top[x]];
//		}
//	}
//
//	ans += querySum(min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), 1, n, 1);
//
//	return ans;
//}
//
//
//void solve() {
//	cin >> n;
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
//	dfs1(1, 0);
//	dfs2(1, 1);
//
//	build(1, n, 1);
//
//	int q;
//	cin >> q;
//
//	while (q--) {
//		string op;
//		cin >> op;
//
//		int u, v;
//		cin >> u >> v;
//
//		if (op == "CHANGE")
//			update(dfn[u], v, 1, n, 1);
//		else if (op == "QMAX")
//			cout << pathMax(u, v) << "\n";
//		else
//			cout << pathSum(u, v) << "\n";
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