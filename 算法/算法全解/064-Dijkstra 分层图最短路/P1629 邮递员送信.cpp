//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//using namespace std;
//
//
//const int MAXN = 1005;
//const int MAXM = 2e5 + 5;
//const int INF = 0x3f3f3f3f;
//
//int cntG, cntR;
//int headG[MAXN], nxtG[MAXM], toG[MAXM], weightG[MAXM];
//int headR[MAXN], nxtR[MAXM], toR[MAXM], weightR[MAXM];
//
////从所有节点回到 1 的最短路：如果直接 Dijkstra 会很麻烦。
////巧妙方法：把图反向，把所有边方向颠倒，然后从 1 出发 Dijkstra。
////反向图求出来的从 1 到其他节点的距离 = 原图中每个节点到 1 的最短距离。
//
//void init() {
//	cntG = 1;
//	cntR = 1;
//	memset(headG, 0, sizeof(headG));
//	memset(headR, 0, sizeof(headR));
//
//}
//
//void addG(int u, int v, int w) {
//	nxtG[cntG] = headG[u];
//	toG[cntG] = v;
//	weightG[cntG] = w;
//	headG[u] = cntG++;
//}
//void addR(int u, int v, int w) {
//	nxtR[cntR] = headR[u];
//	toR[cntR] = v;
//	weightR[cntR] = w;
//	headR[u] = cntR++;
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, m;
//	cin >> n >> m;
//
//	init();
//
//	int u, v, w;
//	for (int i = 0; i < m; ++i) {
//		cin >> u >> v >> w;
//		addG(u, v, w);
//		addR(v, u, w);
//	}
//
//	auto dijkstra = [&](int start, int head[], int nxt[], int to[], int weight[], int n) {
//		vector<int> dis(n + 1, INF);
//		vector<bool> vis(n + 1, false);
//		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
//
//		dis[start] = 0;
//		min_heap.push({ 0,start });
//
//		while (!min_heap.empty()) {
//			auto it = min_heap.top();
//			min_heap.pop();
//			int u = it.second;
//
//			if (vis[u])
//				continue;
//
//			vis[u] = true;
//
//			for (int i = head[u]; i != 0; i = nxt[i]) {
//				int v = to[i];
//				int w = weight[i];
//				if (dis[v] > dis[u] + w) {
//					dis[v] = dis[u] + w;
//					min_heap.push({ dis[v],v });
//				}
//			}
//		}
//		return dis;
//		};
//
//	auto d1 = dijkstra(1, headG, nxtG, toG, weightG, n);
//	auto d2 = dijkstra(1, headR, nxtR, toR, weightR, n);
//
//	long long ans = 0;
//	for (int i = 2; i <= n; ++i)
//		ans += d1[i] + d2[i];
//
//	cout << ans << "\n";
//
//	return 0;
//}
//
