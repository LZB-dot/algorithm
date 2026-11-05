////https://codeforces.com/problemset/problem/600/E
//
//
//
//
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
//const int MAXN = 2e5 + 10;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//
//int n;
//int arr[MAXN];
//
//int fa[MAXN], sz[MAXN];
//int son[MAXN];
//
//ll ans[MAXN];
//int colorCnt[MAXN];
//int mx[MAXN];
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
//void effect(int u,int root) {
//	colorCnt[arr[u]]++;
//
//	if (colorCnt[arr[u]] == mx[root])
//		ans[root] += arr[u];
//	else if(colorCnt[arr[u]]>mx[root]) {
//		mx[root] = colorCnt[arr[u]];
//		ans[root] = arr[u];
//	}
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != fa[u])
//			effect(v, root);
//	}
//}
//
//void cancel(int u) {
//	colorCnt[arr[u]]--;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != fa[u])
//			cancel(v);
//	}
//}
//
//void dfs2(int u, int keep) {
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != son[u] && v != fa[u])
//			dfs2(v, 0);
//	}
//
//	if (son[u] != 0)
//		dfs2(son[u], 1);
//
//	mx[u] = mx[son[u]];
//	ans[u] = ans[son[u]];
//
//	colorCnt[arr[u]]++;
//
//	if (colorCnt[arr[u]] == mx[u])
//		ans[u] += arr[u];
//	else if (colorCnt[arr[u]] > mx[u]) {
//		mx[u] = colorCnt[arr[u]];
//		ans[u] = arr[u];
//	}
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != fa[u] && v != son[u])
//			effect(v, u);
//	}
//
//	if (keep == 0)
//		cancel(u);
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
//		add(u, v);
//		add(v, u);
//	}
//
//	dfs1(1, 0);
//	dfs2(1, 0);
//
//	for (int i = 1; i <= n; i++) 
//		cout << ans[i] << " ";
//	
//	cout << "\n";
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