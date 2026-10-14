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
//int dist[MAXN], pre[MAXN];
//
//void init() {
//	cnt=1;
//  memset(head, 0, sizeof(head));
//	memset(dist, 0, sizeof(dist));
//	memset(pre, 0, sizeof(pre));
//}
//
//void add(int u, int v, int w) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//
//void dfs(int u, int fa,int w) {
//	pre[u] = fa;
//	dist[u] = dist[fa] + w;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		int we = weight[i];
//		if (v != fa)
//			dfs(v, u, we);
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
//	dfs(1, 0, 0);
//
//	int tmp = 0;
//	int start = 0;
//	for (int i = 1; i <= n; ++i) {
//		if (tmp < dist[i]) {
//			tmp = dist[i];
//			start = i;
//		}
//	}
//
//	dfs(start, 0, 0);
//	tmp = 0;
//	for (int i = 1; i <= n; ++i) {
//		if (tmp < dist[i]) 
//			tmp = dist[i];
//	}
//
//	cout << tmp << "\n";
//
//
//	return 0;
//}