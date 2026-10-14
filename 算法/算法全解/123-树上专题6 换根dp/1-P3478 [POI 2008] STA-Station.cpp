//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1e6 + 10;
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//int n;
//
//int sz[MAXN];
//ll sum[MAXN], dp[MAXN];
//
//void add(int u, int v) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//void dfs1(int u, int fa) {
//	sum[u] = 0;
//	sz[u] = 1;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa) {
//			dfs1(v, u);
//			sz[u] += sz[v];
//			sum[u] += sum[v] + sz[v];
//		}
//	}
//}
//
//void dfs2(int u, int fa) {
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa) {
//			//v的子树深度-1，其余点深度+1
//			dp[v] = dp[u] - sz[v] + n - sz[v];
//			dfs2(v, u);
//		}
//	}
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n;
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//
//	dfs1(1, 0);
//	dp[1] = sum[1];
//	dfs2(1, 0);
//
//	ll mx = -1;
//	int ans = 0;
//	for (int i = 1; i <= n; ++i) {
//		if (dp[i] > mx) {
//			mx = dp[i];
//			ans = i;
//		}
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}