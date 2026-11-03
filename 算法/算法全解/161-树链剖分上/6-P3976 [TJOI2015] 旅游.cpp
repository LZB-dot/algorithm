//
////https://www.luogu.com.cn/problem/P3976
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
//
//int fa[MAXN], sz[MAXN], dep[MAXN];
//int son[MAXN];
//int top[MAXN];
//
//int dfn[MAXN];
//int seg[MAXN];
//int cntd;
//
//ll mx[MAXN << 2], mi[MAXN << 2];
//ll lprofit[MAXN << 2], rprofit[MAXN << 2];
//ll addF[MAXN << 2];
//
//inline void addE(int u, int v) {
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
//	int l = i << 1;
//	int r = i << 1 | 1;
//
//	mi[i] = min(mi[l], mi[r]);
//	mx[i] = max(mx[l], mx[r]);
//	lprofit[i] = max({ lprofit[l],lprofit[r],mx[r] - mi[l] });
//	rprofit[i] = max({ rprofit[l],rprofit[r], mx[l] - mi[r] });
//
//}
//
//void lazy(int i, ll v) {
//	addF[i] += v;
//	mi[i] += v;
//	mx[i] += v;
//}
//
//void down(int i) {
//	if (addF[i] != 0) {
//		lazy(i << 1, addF[i]);
//		lazy(i << 1 | 1, addF[i]);
//		addF[i] = 0;
//	}
//}
//
//void build(int l, int r, int i) {
//	if (l == r) 
//		mx[i] = mi[i] = arr[seg[l]];
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
//void add(int jobl, int jobr, ll jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazy(i, jobv);
//	else {
//		int mid = l + (r - l >> 1);
//
//		down(i);
//
//		if (jobl <= mid)
//			add(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			add(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
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
//	add(min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), v, 1, n, 1);
//}
//
//
////a是左边一段，与右边合并
//void merge(ll a[],ll rmax, ll rmin, ll rlpro, ll rrpro) {
//	ll lmax = a[0];
//	ll lmin = a[1];
//	ll llpro = a[2];
//	ll lrpro = a[3];
//
//	a[0] = max(lmax, rmax);
//	a[1] = min(lmin, rmin);
//	a[2] = max({ llpro, rlpro, rmax - lmin });
//	a[3] = max({ lrpro, rrpro, lmax - rmin });
//}
//
//void init(ll a[]) {
//	a[0] = -INF;
//	a[1] = INF;
//	a[2] = 0;
//	a[3] = 0;
//}
//
//void query(ll a[],int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr) 
//		merge(a,mx[i], mi[i], lprofit[i], rprofit[i]);
//	else {
//		int mid = l + (r - l >> 1);
//
//		down(i);
//
//		if (jobl <= mid)
//			query(a,jobl, jobr, l, mid, i << 1);
//		if (jobr > mid)
//			query(a,jobl, jobr, mid + 1, r, i << 1 | 1);
//	}
//}
//
//
//ll pathQuery(int x, int y) {
//
//	ll xpath[4];
//	ll ypath[4];
//	ll cur[4];
//
//	init(xpath);
//	init(ypath);
//
//	while (top[x] != top[y]) {
//		if (dep[top[x]] <= dep[top[y]]) {
//			init(cur);
//			query(cur,dfn[top[y]],dfn[y], 1, n, 1);
//			merge(cur, ypath[0], ypath[1], ypath[2], ypath[3]);
//
//			for (int i = 0; i < 4; ++i)
//				ypath[i] = cur[i];
//
//			y = fa[top[y]];
//		}
//		else {
//			init(cur);
//			query(cur, dfn[top[x]], dfn[x], 1, n, 1);
//			merge(cur, xpath[0], xpath[1], xpath[2], xpath[3]);
//
//			for (int i = 0; i < 4; ++i)
//				xpath[i] = cur[i];
//
//			x = fa[top[x]];
//
//		}
//	}
//
//	if (dep[x] <= dep[y]) {
//		init(cur);
//		query(cur, dfn[x], dfn[y], 1, n, 1);
//		merge(cur, ypath[0], ypath[1], ypath[2], ypath[3]);
//
//		for (int i = 0; i < 4; ++i)
//			ypath[i] = cur[i];
//	}
//	else {
//		init(cur);
//		query(cur, dfn[y], dfn[x], 1, n, 1);
//		merge(cur, xpath[0], xpath[1], xpath[2], xpath[3]);
//
//		for (int i = 0; i < 4; ++i)
//			xpath[i] = cur[i];
//	}
//
//	ll ans = max({ xpath[3], ypath[2], ypath[0] - xpath[1], 0LL });
//	
//	return ans;
//}
//
//void solve() {
//	cin >> n;
//
//	for (int i = 1; i <= n; ++i)
//		cin >> arr[i];
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//
//		addE(u, v);
//		addE(v, u);
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
//		int a, b, c;
//		cin >> a >> b >> c;
//
//		cout << pathQuery(a, b) << "\n";
//		pathAdd(a, b, c);
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