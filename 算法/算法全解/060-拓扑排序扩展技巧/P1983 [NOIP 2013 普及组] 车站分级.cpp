//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 1005;
//const int MAXM = 2e6 + 10; 
//
//int head[MAXN], nxt[MAXM], to[MAXM];
//int cnt;
//int indegree[MAXN];
//int level[MAXN];
//
//void init(int n) {
//	memset(head, 0, sizeof(head));
//	memset(indegree, 0, sizeof(indegree));
//	memset(level, 0, sizeof(level));
//	cnt = 1;
//}
//
//void add(int u, int v) {
//	indegree[v]++;
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, m;
//	cin >> n >> m;
//	init(n);
//	vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false)); 
//
//	while (m--) {
//		int s;
//		cin >> s;
//		vector<int>stop(s);
//		vector<bool>is(n + 1, false);
//		int l = n, r = 1;
//		for (int i = 0; i < s; ++i) {
//			cin >> stop[i];
//			is[stop[i]] = true;
//			l = min(l, stop[i]);
//			r = max(r, stop[i]);
//		}
//
//		for (int u = l; u <= r; ++u) {
//			if (!is[u]) {
//				for (int v : stop) {
//					if (!vis[u][v]) {
//						add(u, v);
//						vis[u][v] = true;
//					}
//				}
//			}
//		}
//	}
//
//	queue<int>q;
//	for (int i = 1; i <= n; ++i)
//		if (indegree[i] == 0) {
//			q.push(i);
//			level[i] = 1;
//		}
//
//	int ans = 1;
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//
//		for (int i = head[u]; i != 0; i = nxt[i]) {
//			int v = to[i];
//			level[v] = max(level[v], level[u] + 1);
//			ans = max(ans, level[v]);
//
//			if (--indegree[v] == 0)
//				q.push(v);
//		}
//	}
//
//	cout << ans << "\n";
//	return 0;
//}