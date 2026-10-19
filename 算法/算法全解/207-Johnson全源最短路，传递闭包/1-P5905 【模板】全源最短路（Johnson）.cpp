//
//
//// https://www.luogu.com.cn/problem/P5905
//
//
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//const int MAXN = 3010;  
//const int MAXM = 9010; 
//const int INF = 1e9;   
//typedef long long ll;
//
//int head[MAXN], to[MAXM], nxt[MAXM], weight[MAXM]; 
//int cnt;          
//
//int n, m;
//
//int h[MAXN];    
//bool in[MAXN];   
//int update[MAXN]; 
//
//int dist[MAXN];  
//bool vis[MAXN]; 
//
//void init() {
//	cnt = 1;
//
//	for (int i = 0; i <= n; ++i) 
//		head[i] = 0;
//	
//}
//
//inline void add(int u, int v, int w) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	weight[cnt] = w; 
//	head[u] = cnt++;
//
//}
//
//bool SPFA(int s) {
//
//	for (int i = 1; i <= n; ++i)
//		h[i] = INF;
//
//	queue<int> q;
//	q.push(s);
//
//	in[s] = true;
//	update[s] = 1;
//	h[s] = 0;   
//
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//
//		in[u] = false; 
//
//		for (int i = head[u]; i; i = nxt[i]) {
//			int v = to[i];
//			int w = weight[i];
//
//			if (h[v] > h[u] + w) {
//				h[v] = h[u] + w;
//
//				if (!in[v]) {
//
//					if (++update[v] > n)
//						return true;
//
//					q.push(v);
//					in[v] = true;
//				}
//			}
//		}
//	}
//
//	return false;
//}
//
//void dijkstra(int s) {
//
//	for (int i = 1; i <= n; ++i) {
//		dist[i] = INF;
//		vis[i] = false;
//	}
//
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
//	dist[s] = 0;
//	heap.push({ 0, s });
//
//	while (!heap.empty()) {
//
//		pair<int, int> cur = heap.top();
//		heap.pop();
//
//		int d = cur.first;
//		int u = cur.second;
//
//		if (vis[u]) 
//			continue; 
//
//		vis[u] = true;
//
//		for (int i = head[u]; i; i = nxt[i]) {
//			int v = to[i];
//			int w = weight[i];
//
//			if (!vis[v] && dist[v] > d + w) {
//
//				dist[v] = d + w;
//				heap.push({ dist[v], v });
//			}
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m;
//
//	init();
//
//	for (int i = 1; i <= n; ++i)
//		add(0, i, 0);
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v, w;
//		cin >> u >> v >> w;
//		add(u, v, w);
//	}
//
//	if (SPFA(0)) 
//		cout << "-1\n";
//	else {
//		//对原图边重赋权 w' = w + h[u] - h[v]
//		for (int u = 1; u <= n; ++u) {
//			for (int i = head[u]; i; i = nxt[i]) {
//				int v = to[i];
//				weight[i] += h[u] - h[v];
//			}
//		}
//
//		//枚举每一个起点i，求i到所有j的最短路
//		//实际距离为这条路径的距离和 - 起点的h + 终点的h
//		for (int i = 1; i <= n; ++i) {
//			dijkstra(i);
//
//			ll ans = 0;
//			for (int j = 1; j <= n; ++j) {
//				if (dist[j] == INF)
//					ans += 1LL * j * INF;
//				else
//					ans += 1LL * j * (dist[j] - h[i] + h[j]);
//			}
//			cout << ans << "\n";
//		}
//	}
//
//
//	return 0;
//}
