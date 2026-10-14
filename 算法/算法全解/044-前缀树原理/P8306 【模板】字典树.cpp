//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 3e6 + 10;
//
//int tree[MAXN][63];
//int ed[MAXN], pass[MAXN];
//int cnt;
//
//int idx(char c) {
//	if (islower(c))
//		return c - 'a';
//	else if (isupper(c))
//		return 26 + c - 'A';
//	else if (isdigit(c))
//		return 52 + c - '0';
//	return -1;
//}
//
//void init() {
//
//	for (int i = 0; i <= cnt; ++i) {
//		ed[i] = 0;
//		pass[i] = 0;
//		fill(tree[i], tree[i] + 65, 0);
//	}
//	cnt = 1;
//}
//
//void insert(const string& word) {
//	int cur = 1;
//	pass[cur]++;
//	for (char c : word) {
//		int path = idx(c);
//		if (tree[cur][path] == 0)
//			tree[cur][path] = ++cnt;
//		cur = tree[cur][path];
//		pass[cur]++;
//	}
//	ed[cur]++;
//}
//
//int prefix(const string& pre) {
//	int cur = 1;
//	for (char c : pre) {
//		int path = idx(c);
//		if (tree[cur][path] == 0)
//			return 0;
//		cur = tree[cur][path];
//	}
//	return pass[cur];
//}
//
//int search(const string& word) {
//	int cur = 1;
//	for (char c : word) {
//		int path = idx(c);
//		if (tree[cur][path] == 0)
//			return 0;
//		cur = tree[cur][path];
//	}
//	return ed[cur];
//}
//
//void remove(const string& word) {
//	if (search(word) == 0)
//		return;
//	int cur = 1;
//	for (char c : word) {
//		int path = idx(c);
//		if (--pass[tree[cur][path]] == 0) {
//			tree[cur][path] = 0;
//			return;
//		}
//		cur = tree[cur][path];
//	}
//	--ed[cur];
//	return;
//}
//
//void solve() {
//	init();
//	int n, q;
//	cin >> n >> q;
//	string s;
//	for (int i = 0; i < n; ++i) {
//		cin >> s;
//		insert(s);
//	}
//
//	while (q--) {
//		cin >> s;
//		cout << prefix(s) << "\n";
//	}
//
//	return;
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
//
//	return 0;
//}