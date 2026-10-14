//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<deque>
//using namespace std;
//
//const int MAXN = 3e5 + 10;
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], weight[MAXN << 1];
//int cnt = 1;
//
//int dist[MAXN], pre[MAXN];
//bool visD[MAXN];
//int maxDist[MAXN];
//int n, s;
//int start, ed, diameter;
//
//void add(int u, int v, int w) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//
//void dfs(int u, int fa, int w) {
//	pre[u] = fa;       
//	dist[u] = dist[fa] + w; 
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa)      
//			dfs(v, u, weight[i]);
//	}
//}
//
//int maxDistUnDiameter(int u, int fa, int cost) {
//	int ans = cost;
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (!visD[v] && v != fa)
//			ans = max(ans, maxDistUnDiameter(v, u, cost + weight[i]));
//	}
//	return maxDist[u] = ans;
//}
//
//int compute() {
//	//l-edµÄ¾àÀë
//	//r-edµÄ¾àÀë
//	int suml = 0, sumr = 0;
//	deque<int> dq;
//	int ans = 1e9;
//
//	//l×ó²à£¬rÓÒ²à
//	for (int l = ed, r = ed; r; r = pre[r]) {
//
//		while (l && suml - sumr + dist[l] - dist[pre[l]] <= s) {
//			while (!dq.empty() && maxDist[l] >= maxDist[dq.back()])
//				dq.pop_back();
//
//			dq.push_back(l);
//			suml += dist[l] - dist[pre[l]];
//			l = pre[l];
//		}
//
//		int cur = max({ sumr, maxDist[dq.front()], diameter - suml });
//		ans = min(ans, cur);
//
//		if (!dq.empty() && dq.front() == r)
//			dq.pop_front();
//
//		sumr += dist[r] - dist[pre[r]];
//	}
//	return ans;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	cin >> n >> s;
//
//	for (int i = 1; i <= n - 1; ++i) {
//		int u, v, w;
//		cin >> u >> v >> w;
//		add(u, v, w);
//		add(v, u, w);
//	}
//
//	diameter = 0;
//	dfs(1, 0, 0);
//	for (int i = 1; i <= n; ++i) {
//		if (dist[i] > diameter) {
//			diameter = dist[i];
//			start = i;
//		}
//	}
//
//	diameter = 0;
//	dfs(start, 0, 0);
//	for (int i = 1; i <= n; ++i) {
//		if (dist[i] > diameter) {
//			diameter = dist[i];
//			ed = i;
//		}
//	}
//
//	for (int i = ed; i; i = pre[i])
//		visD[i] = true;
//
//	for (int i = ed; i; i = pre[i])
//		maxDistUnDiameter(i, 0, 0);
//
//	cout << compute() << endl;
//
//	return 0;
//}