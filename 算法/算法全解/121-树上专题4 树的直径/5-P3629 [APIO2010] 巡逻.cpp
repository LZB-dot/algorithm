//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//
//int dist[MAXN], pre[MAXN];
//bool visD[MAXN];
//int ans[MAXN];
//
//void add(int u, int v) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//void dfs(int u, int fa, int w) {
//	dist[u] = dist[fa] + w;
//	pre[u] = fa;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa)
//			dfs(v, u, 1);
//	}
//}
//
//void dp(int u, int fa) {
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa)
//			dp(v, u);
//
//	}
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa) {
//			int ad = ((visD[v] && visD[u]) ? -1 : 1);
//			ans[u] = max(ans[u], dist[u] + dist[v] + ad);
//			dist[u] = max(dist[u], dist[v] + ad);
//		}
//	}
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, k;
//	cin >> n >> k;
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//
//	dfs(1, 0, 0);
//
//	int start = 0;
//	int diameter = 0;
//	for (int i = 1; i <= n; ++i) {
//		if (dist[i] > diameter) {
//			diameter = dist[i];
//			start = i;
//		}
//	}
//
//	int ed = 0;
//	diameter = 0;
//	dfs(start, 0, 0);
//	for (int i = 1; i <= n; ++i) {
//		if (dist[i] > diameter) {
//			diameter = dist[i];
//			ed = i;
//		}
//	}
//
//	if (k == 1) {
//		cout << 2 * (n - 1) - diameter + 1 << "\n";
//		return 0;
//	}
//
//	for (int i = ed; i; i = pre[i])
//		visD[i] = 1;
//
//	memset(dist, 0, (n + 5) * sizeof(int));
//	dp(1, 0);
//
//	int diameter2 = 0;
//	for (int i = 1; i <= n; ++i)
//		diameter2 = max(diameter2, ans[i]);
//
//	cout << 2 * (n - 1) - diameter - diameter2 + 2 << "\n";
//
//	return 0;
//}