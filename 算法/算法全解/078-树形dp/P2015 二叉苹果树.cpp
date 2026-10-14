//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//#define ll long long
//
//const int MAXN = 105;
//const int MAXM = 210;
//
//int cnt;
//int head[MAXN], to[MAXM], nxt[MAXM], weight[MAXM];
////以i为根的子树 保留k个树枝的最大苹果数量
//vector<vector<ll>>dp(MAXN, vector<ll>(MAXN, 0));
//int n, q;
//
//void init() {
//	cnt = 1;
//	memset(head, 0, sizeof(head));
//}
//
//void add(int u, int v, int w) {
//	weight[cnt] = w;
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//
//void dfs(int u, int father) {
//
//	for (int i = head[u]; i != 0; i = nxt[i]) {
//		int v = to[i];
//		int w = weight[i];
//
//		if (v == father)
//			continue;
//
//		dfs(v, u);
//
//		//遍历父节点u的保留树枝数
//		for (int k = q; k >= 1; --k) {
//			//遍历给子节点v分配的树枝数
//			for (int j = 0; j < k; ++j) {
//				dp[u][k] = max(dp[u][k], dp[u][k - j - 1] + dp[v][j] + w);
//			}
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> q;
//
//	init();
//	int u, v, w;
//	for (int i = 0; i < n - 1; ++i) {
//		cin >> u >> v >> w;
//		add(u, v, w);
//		add(v, u, w);
//	}
//	dfs(1, -1);
//	cout << dp[1][q] << "\n";
//	return 0;
//}
//
//
//
