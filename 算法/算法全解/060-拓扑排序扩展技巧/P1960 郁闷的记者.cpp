//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 5e3 + 5;
//const int MAXM = 1e5 + 5;
//
//int head[MAXN], nxt[MAXM], to[MAXM];
//int indegree[MAXN];
//int cnt;
//
//void init() {
//	cnt = 1;
//	memset(head, 0, sizeof(head));
//	memset(indegree, 0, sizeof(indegree));
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
//	int n;
//	cin >> n;
//	int m;
//	cin >> m;
//	init();
//	int u, v;
//	for (int i = 0; i < m; ++i) {
//		cin >> u >> v;
//		add(u, v);
//	}
//
//	bool flag = false;
//	queue<int>q;
//	vector<int>ans;
//	for (int i = 1; i <= n; ++i)
//		if (indegree[i] == 0) {
//			q.push(i);
//			ans.push_back(i);
//		}
//		
//	if (ans.size() > 1)
//		flag = 1;
//
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//
//		for (int i = head[u]; i != 0; i = nxt[i]) {
//			int v = to[i];
//			if (--indegree[v] == 0) {
//				q.push(v);
//				ans.push_back(v);
//			}
//		}
//
//		if (q.size() > 1)
//			flag = 1;
//	}
//
//	for (int i : ans)
//		cout << i << "\n";
//	if (flag)
//		cout << "1\n";
//	else
//		cout << "0\n";
//	
//
//	return 0;
//}