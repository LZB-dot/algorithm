//
////https://www.luogu.com.cn/problem/P2146
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
//int head[MAXN], to[MAXN], nxt[MAXN];
//int cnt = 1;
//
//int n;
//
//int fa[MAXN], dep[MAXN], sz[MAXN];
//int son[MAXN];
//int top[MAXN];
//
//int dfn[MAXN], seg[MAXN];
//int cntd = 0;
//
//
//int sum[MAXN << 2];
//int change[MAXN << 2];
//bool lazyFlag[MAXN << 2];
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
//		if (v != fa[u] && v != son[u])
//			dfs2(v, v);
//	}
//}
//
//
//void lazy(int i, int v, int m) {
//	sum[i] = v * m;
//	change[i] = v;
//	lazyFlag[i] = true;
//}
//
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//
//void down(int i, int ln, int rn) {
//	if (lazyFlag[i]) {
//		lazy(i << 1, change[i], ln);
//		lazy(i << 1 | 1, change[i], rn);
//		lazyFlag[i] = false;
//	}
//}
//
//void update(int jobl, int jobr, int jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazy(i, jobv, r - l + 1);
//	else {
//		int mid = l + (r - l >> 1);
//
//		down(i, mid - l + 1, r - mid);
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
//
//ll query(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return sum[i];
//
//	int mid = l + (r - l >> 1);
//	down(i, mid - l + 1, r - mid);
//
//	ll ans = 0;
//	
//	if (jobl <= mid)
//		ans += query(jobl, jobr, l, mid, i << 1);
//	if (jobr > mid)
//		ans += query(jobl, jobr, mid + 1, r, i << 1 | 1);
//
//	return ans;
//}
//
//
//void pathUpdate(int x, int v) {
//	int y = 1;
//
//	while (top[x] != top[y]) {
//		if (dfn[top[x]] <= dfn[top[y]]) {
//			update(dfn[top[y]], dfn[y], v, 1, n, 1);
//			y = fa[top[y]];
//		}
//		else {
//			update(dfn[top[x]], dfn[x], v, 1, n, 1);
//			x = fa[top[x]];
//		}
//	}
//
//	update(min(dfn[x], dfn[y]), max(dfn[x], dfn[y]),v, 1, n, 1);
//}
//
//
//
//inline void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void solve() {
//	cin >> n;
//
//	for (int i = 2; i <= n; ++i) {
//		int u;
//		cin >> u;
//		++u;
//
//		add(u, i);
//	}
//
//	dfs1(1, 0);
//	dfs2(1, 1);
//
//	int q;
//	cin >> q;
//
//	while (q--) {
//		string op;
//		cin >> op;
//
//		int x;
//		cin >> x;
//		++x;
//
//		if (op == "install") {
//			int p1 = sum[1];
//			pathUpdate(x, 1);
//			int p2 = sum[1];
//			cout << abs(p1 - p2) << "\n";
//		}
//		else {
//			int p1 = sum[1];
//			update(dfn[x], dfn[x] + sz[x] - 1, 0, 1, n, 1);
//			int p2 = sum[1];
//			cout << abs(p1 - p2) << "\n";
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