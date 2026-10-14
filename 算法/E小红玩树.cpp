//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//int bfs(int s, int t, int type, const vector<vector<int>>& mp, const vector<int>& graph) {
//	int n = mp.size() - 1;
//
//	queue<int>q;
//	q.push(s);
//	vector<bool>vis(n + 1, 0);
//	vis[s] = 1;
//	int dis = 0;
//
//	while (!q.empty()) {
//		int x = q.size();
//		for (int i = 0; i < x; ++i) {
//			int top = q.front();
//			q.pop();
//
//			if ((type == 0 && graph[top] == 1) || (type == 1 && top == t)) {
//				return dis;
//			}
//
//			for (int j : mp[top]) {
//				if (!vis[j]) {
//					vis[j] = 1;
//					q.push(j);
//				}
//			}
//		}
//		dis++;
//	}
//	return -1;
//}
//
//void work() {
//	int n;
//	cin >> n;
//	vector<vector<int>>mp(n + 1);
//	int r, p;
//	cin >> r >> p;
//	int u, v;
//	for (int i = 1; i < n; ++i) {
//		cin >> u >> v;
//		mp[u].push_back(v);
//		mp[v].push_back(u);
//	}
//	vector<int>graph(n + 1, 0);
//
//	for (int i = 1; i <= n; ++i) {
//		if (mp[i].size()==1) {
//			graph[i] = 1;
//			if (r == i) {
//				cout << "red" << endl;
//				return;
//			}
//			else if (p == i) {
//				cout << "purple" << endl;
//				return;
//			}
//		}
//	}
//
//	int dr = bfs(r, 0, 0, mp, graph);
//	int dp = bfs(p, r, 1, mp, graph);
//
//	if (dr <= dp) {
//		cout << "red" << endl;
//	}
//	else {
//		cout << "purple" << endl;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int T;
//	cin >> T;
//	while (T--) {
//		work();
//	}
//
//	return 0;
//}