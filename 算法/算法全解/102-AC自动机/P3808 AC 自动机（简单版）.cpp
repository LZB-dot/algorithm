//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring> 
//
//using namespace std;
//
//const int MAXN = 1e6 + 10;
//
//int cnt = 0;
//int tree[MAXN][26], ed[MAXN];
//
//int fail[MAXN], times[MAXN];
//
//int edge = 0;
//int head[MAXN], to[MAXN], nxt[MAXN];
//
//void add(int u, int v) {
//	nxt[edge] = head[u];
//	to[edge] = v;
//	head[u] = edge++;
//}
//
//void insert(int i, const string& s) {
//	int n = s.size();
//	int u = 0;
//	for (char c : s) {
//		int path = c - 'a';
//		if (!tree[u][path])
//			tree[u][path] = ++cnt;
//		u = tree[u][path];
//	}
//	ed[i] = u;
//}
//
//void setFail() {
//	queue<int>q;
//
//	for (int i = 0; i < 26; ++i) {
//		if (tree[0][i]) {
//			fail[tree[0][i]] = 0;
//			q.push(tree[0][i]);
//		}
//	}
//
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//
//		for (int i = 0; i < 26; ++i) {
//			if (tree[u][i]) {
//				fail[tree[u][i]] = tree[fail[u]][i];
//				q.push(tree[u][i]);
//			}
//			else {
//				
//				tree[u][i] = tree[fail[u]][i];
//			}
//		}
//	}
//}
//
//void dfs(int u) {
//	for (int i = head[u]; ~i; i = nxt[i]) { 
//		dfs(to[i]);
//		times[u] += times[to[i]];
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	memset(head, -1, sizeof(head));
//
//	int n;
//	cin >> n;
//	string s;
//	for (int i = 1; i <= n; ++i) {
//		cin >> s;
//		insert(i, s);
//	}
//	setFail();
//	string t;
//	cin >> t;
//	int u = 0;
//	for (char c : t) {
//		u = tree[u][c - 'a'];
//		times[u]++;
//	}
//
//	for (int i = 1; i <= cnt; ++i)
//		add(fail[i], i);
//
//	dfs(0);
//
//	int ans = 0;
//	for (int i = 1; i <= n; ++i) {
//		if (times[ed[i]] > 0) {
//			ans++;
//		}
//	}
//	cout << ans << "\n";
//
//	return 0;
//}