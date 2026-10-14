//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 5e5 + 10;
//
//int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], weight[MAXN << 1];
//int cnt;
//
//int dist[MAXN];//从u节点出发的最长距离
//int ans[MAXN];//包含u节点的最长距离
//
//void init() {
//	cnt = 1;
//	memset(head, 0, sizeof(head));
//	memset(dist, 0, sizeof(dist));
//	memset(ans, 0, sizeof(ans));
//}
//
//void add(int u, int v, int w) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//
//void dfs(int u, int fa) {
//	
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa) 
//			dfs(v, u);
//		
//	}
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa) {
//			ans[u] = max(ans[u], dist[u] + dist[v] + weight[i]);
//			dist[u] = max(dist[u], dist[v] + weight[i]);
//		}
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
//	init();
//
//	for (int i = 1; i <= n; ++i) {
//		int u, v, w;
//		cin >> u >> v >> w;
//		add(u, v, w);
//		add(v, u, w);
//	}
//
//	dfs(1, 0);
//	int diameter = INT_MIN;
//	for (int i = 1; i <= n; ++i)
//		diameter = max(diameter, ans[i]);
//
//	cout << diameter <<  "\n";
//
//	return 0;
//}