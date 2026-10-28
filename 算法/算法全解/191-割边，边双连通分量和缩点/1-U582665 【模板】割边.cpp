//
////https://www.luogu.com.cn/problem/U582665
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
//const int MAXN = 5e5 + 10;
//const int MAXM = 2e6 + 10;
//
//int n, m;
//
//int head[MAXN], to[MAXM << 1], nxt[MAXM << 1];
//int cnt;
//
//int dfn[MAXN], low[MAXN];
//int cntd;
//
//bool vis[MAXM];
//
//inline void add(int u, int v) {
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
//		dfn[i] = 0;
//		low[i] = 0;
//	}
//
//	memset(vis, 0, sizeof(vis));
//}
//
//void tarjan(int u, int pre) {
//	dfn[u] = low[u] = ++cntd;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if ((i ^ 1) == pre)
//			continue;
//
//		if (dfn[v] == 0) {
//			tarjan(v, i);
//			low[u] = min(low[u], low[v]);
//
//			if (low[v] > dfn[u])
//				vis[i >> 1] = true;
//		}
//		else
//			low[u] = min(low[u], dfn[v]);
//	}
//}
//
//void solve() {
//	cin >> n >> m;
//	init();
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//		
//		add(u, v);
//		add(v, u);
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		if (dfn[i] == 0)
//			tarjan(i, 0);
//	}
//
//	int ans = 0;
//
//	for (int i = 1; i <= m; ++i) {
//		if (vis[i])
//			++ans;
//	}
//
//	cout << ans << "\n";
//
//	for (int i = 1; i <= m; ++i)
//		if (vis[i])
//			cout << i << " ";
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
//
//
