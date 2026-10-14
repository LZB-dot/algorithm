//
//// tarjanÀ„∑®
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 5e5 + 10;
//
//int n, m, s;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//
//int headQ[MAXN], toQ[MAXN << 1], nxtQ[MAXN << 1], idxQ[MAXN << 1];
//int cntQ = 1;
//
//bool vis[MAXN];
//int father[MAXN], ans[MAXN];
//
//void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void addQ(int u, int v, int idx) {
//	toQ[cntQ] = v;
//	nxtQ[cntQ] = headQ[u];
//	idxQ[cntQ] = idx;
//	headQ[u] = cntQ++;
//}
//
//int find(int x) {
//	if (father[x] != x)
//		father[x] = find(father[x]);
//	return father[x];
//}
//
//void tarjan(int u, int fa) {
//	vis[u] = 1;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v == fa)
//			continue;
//
//		tarjan(v, u);
//		father[v] = u;
//	}
//
//	for (int i = headQ[u]; i; i = nxtQ[i]) {
//		int v = toQ[i];
//		int idx = idxQ[i];
//		if (vis[v])
//			ans[idx] = find(v);
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m >> s;
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//		addQ(u, v, i);
//		addQ(v, u, i);
//	}
//
//	for (int i = 1; i <= n; ++i)
//		father[i] = i;
//
//
//	tarjan(s, 0);
//
//	for (int i = 1; i <= m; ++i)
//		cout << ans[i] << "\n";
//
//	return 0;
//}