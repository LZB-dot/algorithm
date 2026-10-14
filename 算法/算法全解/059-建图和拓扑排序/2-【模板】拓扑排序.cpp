//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//const int MAXN = 2e5 + 10;
//
//int head[MAXN], to[MAXN], nxt[MAXN];
//int cnt = 1;
//
//int indegree[MAXN];
//
//void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		indegree[v]++;
//	}
//
//	queue<int>q;
//	for (int i = 1; i <= n; ++i)
//		if (indegree[i] == 0)
//			q.push(i);
//
//	vector<int>ans;
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//
//		ans.push_back(u);
//
//		for (int i = head[u]; i; i = nxt[i]) {
//			int v = to[i];
//			if (--indegree[v] == 0)
//				q.push(v);
//		}
//	}
//
//	if (ans.size() != n)
//		cout << "-1\n";
//	else {
//		for (int i = 0; i < n - 1; ++i)
//			cout << ans[i] << " ";
//		cout << ans[n - 1] << "\n";
//	}
//
//	return 0;
//}

