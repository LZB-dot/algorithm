//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 3e4 + 10;
//
//int tree[MAXN][2], ed[MAXN];
//int cnt = 0;
//
//int fail[MAXN];
//bool vis[MAXN];
//bool in[MAXN];
//
//void insert(const string& s) {
//	int u = 0;
//	for (char c : s) {
//		int path = c - '0';
//		if (!tree[u][path])
//			tree[u][path] = ++cnt;
//		u = tree[u][path];
//	}
//	ed[u] = 1;
//}
//
//void setFail() {
//	queue<int>q;
//	for (int i = 0; i < 2; ++i) {
//		if (tree[0][i]) {
//			q.push(tree[0][i]);
//			fail[tree[0][i]] = 0;
//		}
//	}
//
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//
//		ed[u] |= ed[fail[u]];
//
//		for (int i = 0; i < 2; ++i) {
//			if (tree[u][i]) {
//				q.push(tree[u][i]);
//				fail[tree[u][i]] = tree[fail[u]][i];
//			}
//			else
//				tree[u][i] = tree[fail[u]][i];
//		}
//	}
//}
//
//bool dfs(int u) {
//	if (ed[u])
//		return false;
//	if (in[u])
//		return true;
//	if (vis[u])
//		return false;
//
//	vis[u] = 1;
//	in[u] = 1;
//
//	for (int i = 0; i < 2; ++i) {
//		int v = tree[u][i];
//		if (dfs(v))
//			return true;
//	}
//
//	in[u] = false;
//	return false;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//	string s;
//	for (int i = 0; i < n; ++i) {
//		cin >> s;
//		insert(s);
//	}
//	setFail();
//
//	if (dfs(0))
//		cout << "TAK\n";
//	else
//		cout << "NIE\n";
//
//	return 0;
//}