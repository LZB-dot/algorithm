//#include<iostream>
//#include<vector>
//
//
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 2e5 + 10;
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//
//ll ans = 0;
//ll score[MAXN], sz[MAXN];
//int n;
//
//void add(int u, int v) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//void dfs(int u, int fa) {
//	score[u] = 0;
//	sz[u] = 1;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa) {
//			dfs(v, u);
//			sz[u] += sz[v];
//			score[u] += score[v];
//		}
//	}
//	score[u] += sz[u];
//}
//
//void dp(int u, int fa) {
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != fa) {
//			score[v] = score[u] - sz[v] + n - sz[v];
//			dp(v, u);
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n;
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//
//	dfs(1, 0);
//	dp(1, 0);
//
//	for (int i = 1; i <= n; i++)
//		ans = max(ans, score[i]);
//
//	cout << ans << "\n";
//
//	return 0;
//}