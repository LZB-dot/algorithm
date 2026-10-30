//
//
////长链剖分
////https://www.luogu.com.cn/problem/P5903
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
//#define ui unsigned int
//typedef long long ll;
//
//const int MAXN = 5e5 + 10;
//const int MAXP = 20;
//
//int n, m;
//
//ui s;
//int root;
//
//int head[MAXN], to[MAXN], nxt[MAXN];
//int cnt = 1;
//
//int stjump[MAXN][MAXP];
//int dep[MAXN], len[MAXN];
//int son[MAXN], top[MAXN];
//int dfn[MAXN];
//int cntd = 0;
//
//int high[MAXN];
//int up[MAXN];
//int down[MAXN];
//
//ui get(ui x) {
//	x ^= x << 13;
//	x ^= x >> 17;
//	x ^= x << 5;
//
//	s = x;
//	return x;
//}
//
//
//void setUp(int u, int i, int v) {
//	up[dfn[u] + i] = v;
//}
//
//int getUp(int u, int i) {
//	return up[dfn[u] + i];
//}
//
//void setDown(int u, int i, int v) {
//	down[dfn[u] + i] = v;
//}
//
//int getDown(int u, int i) {
//	return down[dfn[u] + i];
//}
//
//inline void addEdge(int u, int v) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//
//void dfs1(int u, int f) {
//	stjump[u][0] = f;
//
//	for (int p = 1; p < MAXP; ++p)
//		stjump[u][p] = stjump[stjump[u][p - 1]][p - 1];
//
//	dep[u] = dep[f] + 1;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != f) {
//			dfs1(v, u);
//
//			if (son[u] == 0 || len[son[u]] < len[v])
//				son[u] = v;
//		}
//	}
//
//	len[u] = len[son[u]] + 1;
//}
//
//void dfs2(int u, int t) {
//	dfn[u] = ++cntd;
//	top[u] = t;
//
//	if (son[u] == 0)
//		return;
//
//	dfs2(son[u], t);
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != son[u] && v != stjump[u][0])
//			dfs2(v, v);
//	}
//}
//
//void prepare() {
//	dfs1(root, 0);
//	dfs2(root, root);
//
//	//预处理小于等于 i 的最大 2 的幂的指数
//	high[0] = -1;
//	for (int i = 1; i <= n; ++i)
//		high[i] = high[i / 2] + 1;
//
//	for (int u = 1; u <= n; ++u) {
//		if (top[u] == u) {
//			int a = u;
//			int b = u;
//
//			for (int i = 0; i < len[u]; ++i) {
//				setUp(u, i, a);
//				setDown(u, i, b);
//
//				a = stjump[a][0];
//				b = son[b];
//			}
//		}
//	}
//}
//
//int query(int x, int k) {
//	if (k == 0)
//		return x;
//
//	if (k == (1 << high[k]))
//		return stjump[x][high[k]];
//
//	x = stjump[x][high[k]];
//	k -= (1 << high[k]);
//	//dep[x] - dep[top[x]]到链顶还要往上走多少步
//	k -= dep[x] - dep[top[x]];
//	x = top[x];
//
//	if (k >= 0)
//		return getUp(x, k);
//
//	return getDown(x, -k);
//}
//
//void solve() {
//	cin >> n >> m >> s;
//
//	for (int i = 1; i <= n; ++i) {
//		int father;
//		cin >> father;
//
//		if (father == 0)
//			root = i;
//		else
//			addEdge(father, i);
//	}
//
//	prepare();
//
//	ll ans = 0;
//	int tmp = 0;
//
//	for (int i = 1; i <= m; i++) {
//		int x = (get(s) ^ tmp) % n + 1;
//		int k = (get(s) ^ tmp) % dep[x];
//
//		tmp = query(x, k);
//		ans ^= (ll)i * tmp;
//	}
//
//	cout << ans << '\n';
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