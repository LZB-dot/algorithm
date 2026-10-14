//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 6010;
//
//int head[MAXN];
//int to[MAXN];
//int next_[MAXN];
//int cnt;
//int dp[MAXN][2];
//int happy[MAXN];
//bool isRoot[MAXN];
//
//void addEdge(int u, int v) {
//	to[cnt] = v;
//	next_[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void dfs(int u) {
//	dp[u][1] = happy[u];
//	dp[u][0] = 0;
//
//	for (int i = head[u]; i != -1; i = next_[i]) {
//		int v = to[i];
//		dfs(v);
//		dp[u][0] += max(dp[v][0], dp[v][1]);
//		dp[u][1] += dp[v][0];
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; ++i) {
//		cin >> happy[i];
//	}
//
//	fill(head, head + n + 1, -1);
//	fill(isRoot + 1, isRoot + n + 1, true);
//
//	int u, v;
//	for (int i = 1; i < n; ++i) {
//		cin >> u >> v;
//		addEdge(v, u);
//		isRoot[u] = false;
//	}
//
//	int root = 1;
//
//	while (!isRoot[root]) {
//		++root;
//	}
//
//	dfs(root);
//	cout << max(dp[root][0], dp[root][1]);
//	return 0;
//}
