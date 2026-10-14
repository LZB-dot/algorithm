
////以某个节点为根时，最大子树的节点数最少，那么这个节点是重心

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 2e4 + 10;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt;
//int n;
//int sz[MAXN];
//int center, sum;
//
//void init() {
//	cnt = 1;
//	memset(head, 0, sizeof(head));
//
//	sum = 1e9;
//	center = 1e9;
//}
//
//void add(int u, int v) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//void dfs(int u, int fa) {
//
//	sz[u] = 1;
//	int mx = 0;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa) {
//			dfs(v, u);
//			sz[u] += sz[v];
//			mx = max(mx, sz[v]);
//		}
//	}
//
//	mx = max(mx, n - sz[u]);
//
//	if (mx < sum || (mx == sum && u < center)) {
//		center = u;
//		sum = mx;
//	}
//
//
//}
//
//void solve() {
//	cin >> n;
//
//	init();
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//
//	dfs(1, 0);
//
//	cout << center << " " << sum << "\n";
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int T;
//	cin >> T;
//
//	while (T--)
//		solve();
//
//	return 0;
//}
