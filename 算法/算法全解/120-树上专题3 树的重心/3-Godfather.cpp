//
////以某个节点为根时，每颗子树的节点数不超过总节点数的一半，那么这个节点是重心
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 5e5 + 10;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt;
//int n;
//int sz[MAXN];
//int mxsum[MAXN];
//
//void init() {
//	cnt = 1;
//	memset(head, 0, sizeof(head));
//
//}
//
//void add(int u, int v) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//void dfs(int u, int fa) {
//
//	sz[u] = 1;
//	mxsum[u] = 0;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v != fa) {
//			dfs(v, u);
//			sz[u] += sz[v];
//			mxsum[u] = max(mxsum[u], sz[v]);
//		}
//	}
//
//	mxsum[u] = max(mxsum[u], n - sz[u]);
//}
//
//void solve() {
//	cin >> n;
//
//	init();
//
//	for (int i = 1; i < n; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//
//	dfs(1, 0);
//
//	vector<int>centers;
//	
//	for (int i = 1; i <= n; ++i) {
//		if (mxsum[i] <= n / 2)
//			centers.push_back(i);
//	}
//	
//	int m = centers.size();
//	if (m == 1)
//		cout << centers[0] << "\n";
//	else
//		cout << centers[0] << " " << centers[1] << "\n";
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	solve();
//
//	return 0;
//}
