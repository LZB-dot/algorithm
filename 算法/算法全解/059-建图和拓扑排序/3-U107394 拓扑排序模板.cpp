//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//
//int head[MAXN], to[MAXN << 1], nxt[MAXN << 1];
//int cnt = 1;
//
//int indegree[MAXN] = { 0 };
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
//
//		add(u, v);
//		indegree[v]++;
//	}
//
//	priority_queue<int,vector<int>,greater<int> >min_heap;
//	vector<int>ans;
//
//	for (int i = 1; i <= n; ++i) {
//		if (indegree[i] == 0)
//			min_heap.push(i);
//	}
//
//	while (!min_heap.empty()) {
//		int u = min_heap.top();
//		min_heap.pop();
//
//		ans.push_back(u);
//
//		for (int i = head[u]; i; i = nxt[i]) {
//			int v = to[i];
//
//			if (--indegree[v] == 0)
//				min_heap.push(v);
//		}
//	}
//
//	for (int i : ans)
//		cout << i << " ";
//	cout << "\n";
//
//
//	return 0;
//}
//
