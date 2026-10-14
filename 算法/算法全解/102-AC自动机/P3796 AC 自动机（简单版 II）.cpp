//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 2e4;
//
//int T;
//
//int cnt;
//int tree[MAXN][26], ed[MAXN];
//
//int edge;
//int head[MAXN], to[MAXN], nxt[MAXN];
//
//int fail[MAXN], times[MAXN];
//int count_p[MAXN]; 
//
//void add(int u, int v) {
//	to[edge] = v;
//	nxt[edge] = head[u];
//	head[u] = edge++;
//}
//
//void insert(const string& s, int i) {
//	int cur = 0;
//	for (char c : s) {
//		int path = c - 'a';
//		if (!tree[cur][path])
//			tree[cur][path] = ++cnt;
//		cur = tree[cur][path];
//	}
//	ed[cur] = i; 
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
//				tree[u][i] = tree[fail[u]][i];
//			}
//		}
//	}
//}
//
//void dfs(int u) {
//	for (int i = head[u]; ~i; i = nxt[i]) {
//		int v = to[i];
//		dfs(v);
//		times[u] += times[v]; 
//		if (ed[v] != 0) {
//			count_p[ed[v]] = times[v];
//		}
//	}
//}
//
//
//void init() {
//	cnt = 0;
//	edge = 0;
//
//	memset(tree, 0, sizeof(tree));
//	memset(ed, 0, sizeof(ed));
//	memset(head, -1, sizeof(head));
//	memset(to, 0, sizeof(to));
//	memset(nxt, 0, sizeof(nxt));
//	memset(fail, 0, sizeof(fail));
//	memset(times, 0, sizeof(times));
//	memset(count_p, 0, sizeof(count_p)); 
//}
//
//void solve() {
//	init();
//
//	vector<string> patterns(T + 1);
//	for (int i = 1; i <= T; ++i) {
//		cin >> patterns[i];
//		insert(patterns[i], i);
//	}
//
//	string t;
//	cin >> t;
//	setFail();
//
//	int cur = 0;
//	for (char c : t) {
//		int path = c - 'a';
//		cur = tree[cur][path]; 
//		times[cur]++;
//	}
//
//	for (int i = 1; i <= cnt; ++i) {
//		add(fail[i], i);
//	}
//
//	dfs(0);
//
//	int mx = 0;
//	for (int i = 1; i <= T; ++i) {
//		mx = max(mx, count_p[i]);
//	}
//
//	cout << mx << "\n";
//	for (int i = 1; i <= T; ++i) {
//		if (count_p[i] == mx) {
//			cout << patterns[i] << "\n";
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	while (cin >> T && T != 0) {
//		solve();
//	}
//
//	return 0;
//}