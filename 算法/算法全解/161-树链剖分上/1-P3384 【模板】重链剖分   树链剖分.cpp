//
//
//
////https://www.luogu.com.cn/problem/P3384
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
//int n, m;
//int root;
//int MOD;
//
//int arr[MAXN];
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 0;
//
//int fa[MAXN], dep[MAXN], sz[MAXN];
//int son[MAXN];//重儿子
//int top[MAXN];//重链的顶端节点
//int dfn[MAXN];
//int seg[MAXN];//seg[dfn[u]]=u
//int cntd;//dfn时间戳
//
//ll sum[MAXN << 2];
//ll addF[MAXN << 2];
//
//inline void addE(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void init() {
//	cnt = 2;
//	cntd = 0;
//
//	for (int i = 0; i <= n; ++i) {
//		head[i] = 0;
//		fa[i] = i;
//		top[i] = 0;
//		son[i] = 0;
//	}
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
//	sum[i] = (sum[i << 1] + sum[i << 1 | 1]) % MOD;
//}
//
//void lazy(int i, ll v, int n) {
//	sum[i] = (sum[i] + v * n) % MOD;
//	addF[i] = (addF[i] + v) % MOD;
//}
//
//void down(int i, int ln, int rn) {
//	if (addF[i] != 0) {
//		lazy(i << 1, addF[i], ln);
//		lazy(i << 1 | 1, addF[i], rn);
//		addF[i] = 0;
//	}
//}
//
//void build(int l, int r, int i) {
//	if (l == r)
//		sum[i] = arr[seg[l]] % MOD;
//	else {
//		int mid = l + (r - l >> 1);
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//
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
//			add(jobl, jobr,jobv, l, mid, i << 1);
//		if (jobr > mid)
//			add(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
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
//		ans = (ans + query(jobl, jobr, l, mid, i << 1)) % MOD;
//	
//	if (jobr > mid)
//		ans = (ans + query(jobl, jobr, mid + 1, r, i << 1 | 1)) % MOD;
//
//
//	return ans;
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
//void subtreeAdd(int x, int v) {
//	add(dfn[x], dfn[x] + sz[x] - 1, v, 1, n, 1);
//}
//
//ll pathSum(int x, int y) {
//	ll ans = 0;
//
//	while (top[x] != top[y]) {
//		if (dep[top[x]] <= dep[top[y]]) {
//			ans = (ans + query(dfn[top[y]], dfn[y], 1, n, 1)) % MOD;
//			y = fa[top[y]];
//		}
//		else {
//			ans = (ans + query(dfn[top[x]], dfn[x], 1, n, 1)) % MOD;
//			x = fa[top[x]];
//		}
//	}
//
//	ans = (ans + query(min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), 1, n, 1)) % MOD;
//	return ans;
//}
//
//ll subtreeSum(int x) {
//	return query(dfn[x], dfn[x] + sz[x] - 1, 1, n, 1);
//}
//
//void solve() {
//	cin >> n >> m >> root >> MOD;
//
//	init();
//
//	for (int i = 1; i <= n; ++i)
//		cin >> arr[i];
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		addE(u, v);
//		addE(v, u);
//	}
//
//	dfs1(root, 0);
//	dfs2(root, root);
//
//	build(1, n, 1);
//
//	for (int i = 1; i <= m; ++i) {
//		int op;
//		cin >> op;
//
//		int x, y, v;
//		if (op == 1) {
//			cin >> x >> y >> v;
//			pathAdd(x, y, v);
//		}
//		else if (op == 2) {
//			cin >> x >> y;
//			cout << pathSum(x, y) << "\n";
//		}
//		else if (op == 3) {
//			cin >> x >> v;
//			subtreeAdd(x, v);
//		}
//		else {
//			cin >> x;
//			cout << subtreeSum(x) << "\n";
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