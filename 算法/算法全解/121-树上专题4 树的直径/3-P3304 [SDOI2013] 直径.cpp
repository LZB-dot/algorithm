//#include<iostream>
//#include<cstring> 
//#include<algorithm> 
//
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 2e5 + 10;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], weight[MAXN << 1];
//int cnt;
//
//ll dist[MAXN];   
//int pre[MAXN];        
//bool visD[MAXN];      // 标记直径上的点
//int start, ed;        // 直径的两个端点
//
//void init() {
//	memset(head, 0, sizeof(head));
//	memset(dist, 0, sizeof(dist));
//	memset(pre, 0, sizeof(pre));
//	memset(visD, false, sizeof(visD));
//	cnt = 1;
//	start = ed = 0;
//}
//
//
//void dfs(int u, int fa, int w) {
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
//void add(int u, int v, int w) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//
////标记直径上所有点
//void setD() {
//	for (int i = ed; i; i = pre[i])
//		visD[i] = 1;
//}
//
////不走直径上的点，求最大距离
//ll maxDistExceptD(int u, int fa, ll c) {
//	ll ans = c;
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		int w = weight[i];
//		if (v != fa && !visD[v])
//			ans = max(ans, maxDistExceptD(v, u, c + w));
//	}
//	return ans;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//	init();
//
//	for (int i = 1; i < n; ++i) {
//		int u, v, w;
//		cin >> u >> v >> w;
//		add(u, v, w);
//		add(v, u, w);
//	}
//
//	dfs(1, 0, 0);
//	ll diameter = 0;
//	for (int i = 1; i <= n; ++i) {
//		if (dist[i] > diameter) {
//			diameter = dist[i];
//			start = i;
//		}
//	}
//
//	// 第二次DFS：找直径终点 end + 最终直径长度
//	dfs(start, 0, 0);
//	diameter = 0;
//	for (int i = 1; i <= n; ++i) {
//		if (dist[i] > diameter) {
//			diameter = dist[i];
//			ed = i;  
//		}
//	}
//
//	cout << diameter << "\n";
//
//	setD();
//
//	// 收缩直径，求公共部分
//	int l = start, r = ed;
//	ll mx;
//	for (int i = pre[ed]; i != start; i = pre[i]) {
//		mx = maxDistExceptD(i, 0, 0);
//
//		// 收缩右端点
//		if (mx == diameter - dist[i])
//			r = i;
//
//		// 收缩左端点（只收缩一次）
//		if (mx == dist[i] && l == start)
//			l = i;
//	}
//
//	int ans = 0;
//	if (l != r) {
//		ans = 1;  
//		for (int i = pre[r]; i != l; i = pre[i])
//			ans++;
//	}
//	cout << ans << "\n";
//
//	return 0;
//}