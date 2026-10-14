//#include<iostream>
//#include<vector>
//#include<climits>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 2e5 + 10;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], weight[MAXN << 1];
//int cnt;
//
//int degree[MAXN];
//int flow[MAXN];//u流向自己子树的最大容量
//int dp[MAXN];
//
//void init(int n) {
//	cnt = 1;
//	memset(head, 0, sizeof(int) * (n + 5));
//	memset(degree, 0, sizeof(int) * (n + 5));
//	memset(flow, 0, sizeof(int) * (n + 5));
//	memset(dp, 0, sizeof(int) * (n + 5));
//}
//
//void add(int u, int v, int w) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//
//void dfs1(int u, int fa) {
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		int we = weight[i];
//
//		if (v != fa) {
//			dfs1(v, u);
//
//			if (degree[v] == 1)
//				flow[u] += we;
//			else
//				flow[u] += min(flow[v], we);
//		}
//	}
//}
//
//void dfs2(int u, int fa) {
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		int we = weight[i];
//
//		if (v != fa) {
//			if (degree[u] == 1)
//				dp[v] = flow[v] + we;
//			else {
//				int uexceptv = dp[u] - min(we, flow[v]);
//				dp[v] = flow[v] + min(we, uexceptv);
//			}
//			dfs2(v, u);
//		}
//	}
//}
//
//void solve() {
//	int n;
//	cin >> n;
//
//	init(n);
//
//	for (int i = 1; i < n; ++i) {
//		int u, v, w;
//		cin >> u >> v >> w;
//
//		add(u, v, w);
//		add(v, u, w);
//		degree[u]++;
//		degree[v]++;
//	}
//
//	dfs1(1, 0);
//	dp[1] = flow[1];
//	dfs2(1, 0);
//
//	int ans = 0;
//	for (int i = 1; i <= n; ++i)
//		ans = max(ans, dp[i]);
//
//	cout << ans << "\n";
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