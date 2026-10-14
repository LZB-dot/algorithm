//#include<iostream>
//#include<vector>
//
//
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 2e5 + 10;
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], weight[MAXN << 1];
//int cnt = 1;
//
//ll ans = 1e9;
//ll counts[MAXN], sz[MAXN];
//int n;
//
//void add(int u, int v, int w) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//
//void dfs(int u, int fa) {
//	counts[u] = 0;
//	sz[u] = 1;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa) {
//			dfs(v, u);
//			counts[u] += counts[v];
//			if (weight[i] != 1)
//				counts[u] += 1;
//		}
//	}
//}
//
//void dp(int u, int fa) {
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != fa) {
//			if (weight[i] == 1)
//				counts[v] = counts[u] + 1;
//			else
//				counts[v] = counts[u] - 1;
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
//		add(u, v, 1);
//		add(v, u, 0);
//	}
//
//	dfs(1, 0);
//	dp(1, 0);
//
//	for (int i = 1; i <= n; ++i)
//		ans = min(ans, counts[i]);
//
//	cout << ans << "\n";
//
//	for (int i = 1; i <= n; ++i)
//		if (counts[i] == ans)
//			cout << i << " ";
//	cout << "\n";
//
//	return 0;
//}