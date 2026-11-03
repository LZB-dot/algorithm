//
////https://www.luogu.com.cn/problem/P10641
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
//
//int head[MAXN], to[MAXN<<1], nxt[MAXN<<1];
//int cnt = 1;
//
//int n, k;
//int arr[MAXN];
//
//int fa[MAXN];
//int son[MAXN], top[MAXN];
//
//int dfn[MAXN];
//ll sum[MAXN];
//int cntd = 0;
//
//inline void add(int u, int v) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//void dfs1(int u, int f) {
//	fa[u] = f;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != f) {
//			dfs1(v, u);
//
//			if (son[u] == 0 || sum[son[u]] < sum[v])
//				son[u] = v;
//		}
//	}
//
//	sum[u] = arr[u] + sum[son[u]];
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
//void solve() {
//	cin >> n >> k;
//
//	for (int i = 1; i <= n; ++i)
//		cin >> arr[i];
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//
//	dfs1(1, 0);
//	dfs2(1, 1);
//
//	vector<ll>ans;
//
//	for (int i = 1; i <= n; ++i) {
//		if (top[i] == i)
//			ans.push_back(sum[i]);
//	}
//
//	sort(ans.begin(), ans.end(), greater<ll>());
//
//	ll res = 0;
//	for (int i = 0; i < min((int)ans.size(), k); ++i)
//		res += ans[i];
//
//	cout << res << "\n";
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	solve();
//
//	return 0;
//}