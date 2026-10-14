//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 3e5 + 10;
//
//int n, m;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], weight[MAXN << 1];
//int cnt = 1;
//
//int headQ[MAXN], toQ[MAXN << 1], nxtQ[MAXN << 1], idxQ[MAXN << 1];
//int cntQ = 1;
//
//int lca[MAXN];
//int queryu[MAXN], queryv[MAXN];
//
//int father[MAXN];
//bool vis[MAXN];
//
//int cost[MAXN], dist[MAXN];
//int mx = 0;
//
//int diff[MAXN];
//
//void add(int u, int v, int w) {
//	nxt[cnt] = head[u];
//	weight[cnt] = w;
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//void addQ(int u, int v, int i) {
//	nxtQ[cntQ] = headQ[u];
//	idxQ[cntQ] = i;
//	toQ[cntQ] = v;
//	headQ[u] = cntQ++;
//}
//
//int find(int u) {
//	if (father[u] != u)
//		father[u] = find(father[u]);
//	return father[u];
//}
//
//void tarjan(int u, int fa, int w) {
//	vis[u] = true;
//	dist[u] = dist[fa] + w;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (v != fa)
//			tarjan(v, u, weight[i]);
//	}
//
//	for (int i = headQ[u]; i; i = nxtQ[i]) {
//		int v = toQ[i];
//		if (vis[v]) {
//			int id = idxQ[i];
//			lca[id] = find(v);
//			cost[id] = dist[u] + dist[v] - 2 * dist[lca[id]];
//			mx = max(mx, cost[id]);
//		}
//	}
//
//	father[u] = fa;
//}
//
//bool dfs(int u, int fa, int w, int need, int num) {
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//		if (v == fa)
//			continue;
//
//		if (dfs(v, u, weight[i], need, num))
//			return true;
//
//		diff[u] += diff[v];
//	}
//
//	if (diff[u] == num && w >= need)
//		return true;
//
//	return false;
//}
//
//bool check(int target) {
//	memset(diff, 0, sizeof(diff));
//
//	int need = mx - target;
//	int num = 0;
//	for (int i = 1; i <= m; ++i) {
//		if (cost[i] > target) {
//			diff[queryu[i]]++;
//			diff[queryv[i]]++;
//			diff[lca[i]] -= 2;
//			++num;
//		}
//	}
//
//	if (num == 0)
//		return true;
//
//	return dfs(1, 0, 0, need, num);
//
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m;
//
//	for (int i = 1; i < n; ++i) {
//		int u, v, w;
//		cin >> u >> v >> w;
//		add(u, v, w);
//		add(v, u, w);
//	}
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//		queryu[i] = u;
//		queryv[i] = v;
//		addQ(u, v, i);
//		addQ(v, u, i);
//	}
//
//	for (int i = 1; i <= n; ++i)
//		father[i] = i;
//
//	tarjan(1, 0, 0);
//	int l = 0, r = mx;
//	int ans;
//
//	while (l <= r) {
//		int mid = l + (r - l >> 1);
//
//		if (check(mid)) {
//			ans = mid;
//			r = mid - 1;
//		}
//		else
//			l = mid + 1;
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}