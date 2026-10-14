//
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//	vector<int>indegree(n + 1, 0);
//	vector<vector<int>> adj(n + 1);
//
//	for (int u = 1; u <= n; ++u) {
//		int v;
//		while (cin >> v && v != 0) {
//			indegree[v]++;
//			adj[u].push_back(v);
//		}
//	}
//
//	queue<int>q;
//	vector<int>res;
//	for (int i = 1; i <= n; ++i)
//		if (indegree[i] == 0) 
//			q.push(i);
//		
//
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		res.push_back(u);
//
//		for (int i = 0; i < adj[u].size(); ++i) {
//			if (--indegree[adj[u][i]]==0)
//				q.push(adj[u][i]);
//		}
//	}
//
//	for (int i : res)
//		cout << i << " ";
//	cout << "\n";
//
//	return 0;
//}
//
//
