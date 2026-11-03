//
////https://www.luogu.com.cn/problem/P1505
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
//const int MAXM = 4e5 + 10;
//const int INF = 1001;
//
//int head[MAXN], to[MAXM], nxt[MAXM], weight[MAXM];
//int cnt = 1;
//
//int n, m;
//int arr[MAXN];
//
//int fa[MAXN], sz[MAXN], dep[MAXN];
//int son[MAXN];
//int top[MAXN];
//
//int dfn[MAXN], seg[MAXN];
//int cntd = 0;
//
//int sum[MAXN << 2];
//int mx[MAXN << 2], mi[MAXN << 2];
//int change[MAXN << 2];
//int oppsite[MAXN << 2];
//
//inline void add(int u, int v, int w) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	weight[cnt] = w;
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
//		int w = weight[i];
//
//		if (v != f) {
//			arr[v] = w;
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
//	mi[i] = min(mi[i << 1], mi[i << 1 | 1]);
//}
//
//void build(int l, int r, int i) {
//	change[i] = -INF;
//
//	if (l == r) {
//		sum[i] = arr[seg[l]];
//		mx[i] = mi[i] = arr[seg[l]];
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
//void lazyChange(int i, int v) {
//	sum[i] = v;
//	mx[i] = v;
//	mi[i] = v;
//	change[i] = v;
//}
//
//void lazyOpp(int i) {
//	sum[i] = -sum[i];
//	int p1 = -mx[i];
//	int p2 = -mi[i];
//
//	mx[i] = max(p1, p2);
//	mi[i] = min(p1, p2);
//	oppsite[i] ^= 1;
//}
//
//void down(int i) {
//	if (change[i] != -INF) {
//		lazyChange(i << 1, change[i]);
//		lazyChange(i << 1 | 1, change[i]);
//		change[i] = -INF;
//		oppsite[i << 1] = 0;
//		oppsite[i << 1 | 1] = 0;
//	}
//
//	if (oppsite[i]) {
//		lazyOpp(i << 1);
//		lazyOpp(i << 1 | 1);
//		oppsite[i] = 0;
//	}
//
//}
//
//void changeC(int jobi, int jobv, int l, int r, int i) {
//	if (l == r)
//		lazyChange(i, jobv);
//	else {
//		int mid = l + (r - l >> 1);
//
//		down(i);
//
//		if (jobi <= mid)
//			changeC(jobi, jobv, l, mid, i << 1);
//		else
//			changeC(jobi, jobv, mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
//}
//
//void changeN(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazyOpp(i);
//	else {
//		int mid = l + (r - l >> 1);
//
//		down(i);
//
//		if (jobl <= mid)
//			changeN(jobl, jobr, l, mid, i << 1);
//		if (jobr > mid)
//			changeN(jobl, jobr, mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
//}
//
//void pathChangeN(int x, int y) {
//	while (top[x] != top[y]) {
//		if (dfn[top[x]] < dfn[top[y]]) {
//			changeN(dfn[top[y]], dfn[y], 1, n, 1);
//			y = fa[top[y]];
//		}
//		else {
//			changeN(dfn[top[x]], dfn[x], 1, n, 1);
//			x = fa[top[x]];
//		}
//	}
//
//	if (x != y)
//		//边权转化为点权，LCA点不用考虑
//		changeN(min(dfn[x], dfn[y]) + 1, max(dfn[x], dfn[y]), 1, n, 1);
//}
//
//int querySum(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return sum[i];
//
//	int ans = 0;
//	int mid = l + (r - l >> 1);
//	down(i);
//
//	if (jobl <= mid)
//		ans += querySum(jobl, jobr, l, mid, i << 1);
//	if (jobr > mid)
//		ans += querySum(jobl, jobr, mid + 1, r, i << 1 | 1);
//
//	return ans;
//}
//
//int pathSum(int x, int y) {
//	int ans = 0;
//
//	while (top[x] != top[y]) {
//		if (dfn[top[x]] < dfn[top[y]]) {
//			ans += querySum(dfn[top[y]], dfn[y], 1, n, 1);
//			y = fa[top[y]];
//		}
//		else {
//			ans += querySum(dfn[top[x]], dfn[x], 1, n, 1);
//			x = fa[top[x]];
//		}
//	}
//
//	if (x != y)
//		ans += querySum(min(dfn[x], dfn[y]) + 1, max(dfn[x], dfn[y]), 1, n, 1);
//
//	return ans;
//}
//
//
//int queryMax(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return mx[i];
//
//	int ans = INT_MIN;
//	int mid = l + (r - l >> 1);
//	down(i);
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
//	int ans = INT_MIN;
//
//	while (top[x] != top[y]) {
//		if (dfn[top[x]] < dfn[top[y]]) {
//			ans = max(ans, queryMax(dfn[top[y]], dfn[y], 1, n, 1));
//			y = fa[top[y]];
//		}
//		else {
//			ans = max(ans, queryMax(dfn[top[x]], dfn[x], 1, n, 1));
//			x = fa[top[x]];
//		}
//	}
//
//	if (x != y)
//		ans = max(ans, queryMax(min(dfn[x], dfn[y]) + 1, max(dfn[x], dfn[y]), 1, n, 1));
//
//	return ans;
//}
//
//int queryMin(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return mi[i];
//
//	int ans = INT_MAX;
//	int mid = l + (r - l >> 1);
//	down(i);
//
//	if (jobl <= mid)
//		ans = min(ans, queryMin(jobl, jobr, l, mid, i << 1));
//	if (jobr > mid)
//		ans = min(ans, queryMin(jobl, jobr, mid + 1, r, i << 1 | 1));
//
//	return ans;
//}
//
//int pathMin(int x, int y) {
//	int ans = INT_MAX;
//
//	while (top[x] != top[y]) {
//		if (dfn[top[x]] < dfn[top[y]]) {
//			ans = min(ans, queryMin(dfn[top[y]], dfn[y], 1, n, 1));
//			y = fa[top[y]];
//		}
//		else {
//			ans = min(ans, queryMin(dfn[top[x]], dfn[x], 1, n, 1));
//			x = fa[top[x]];
//		}
//	}
//
//	if (x != y)
//		ans = min(ans, queryMin(min(dfn[x], dfn[y]) + 1, max(dfn[x], dfn[y]), 1, n, 1));
//
//	return ans;
//}
//
//void solve() {
//	cin >> n;
//
//	vector<pair<int, int>>edge(n + 1);
//	for (int i = 1; i < n; ++i) {
//		int u, v, w;
//		cin >> u >> v >> w;
//
//		++u;
//		++v;
//
//		add(u, v, w);
//		add(v, u, w);
//
//		edge[i] = { u,v };
//	}
//
//	dfs1(1, 0);
//	dfs2(1, 1);
//
//	build(1, n, 1);
//
//	cin >> m;
//
//	while (m--) {
//		string op;
//		cin >> op;
//
//		if (op == "C") {
//			int i, w;
//			cin >> i >> w;
//
//			int u = edge[i].first;
//			int v = edge[i].second;
//
//			if (dep[u] < dep[v])
//				changeC(dfn[v], w, 1, n, 1);
//			else
//				changeC(dfn[u], w, 1, n, 1);
//		}
//		else if (op == "N") {
//			int u, v;
//			cin >> u >> v;
//			++u; ++v;
//
//			pathChangeN(u, v);
//		}
//		else if (op == "SUM") {
//			int u, v;
//			cin >> u >> v;
//			++u; ++v;
//
//			cout << pathSum(u, v) << "\n";
//		}
//		else if (op == "MAX") {
//			int u, v;
//			cin >> u >> v;
//			++u; ++v;
//
//			cout << pathMax(u, v) << "\n";
//		}
//		else {
//			int u, v;
//			cin >> u >> v;
//			++u; ++v;
//
//			cout << pathMin(u, v) << "\n";
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