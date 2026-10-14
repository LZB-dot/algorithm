//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 5e5 + 10;
//int tree[MAXN][26];
//int ed[MAXN];
//int vis[MAXN];
//int cnt = 1;
//
//
//void insert(const string& s) {
//	int cur = 1;
//	for (char c : s) {
//		int path = c - 'a';
//		if (tree[cur][path] == 0)
//			tree[cur][path] = ++cnt;
//		cur = tree[cur][path];
//	}
//	ed[cur] = 1;
//}
//
//int search(const string& s) {
//	int cur = 1;
//	for (char c : s) {
//		int path = c - 'a';
//		if (tree[cur][path] == 0)
//			return 0;
//		cur = tree[cur][path];
//	}
//
//	if (ed[cur] != 1)
//		return 0;
//
//	if (vis[cur] == 0) {
//		vis[cur]++;
//		return 1;
//	}
//	else {
//		return 2;
//	}
//
//}
//
//int main() {
//	int n;
//	cin >> n;
//
//	string s;
//	for (int i = 0; i < n; ++i) {
//		cin >> s;
//		insert(s);
//	}
//	int m;
//	cin >> m;
//	while (m--) {
//		cin >> s;
//		int flag = search(s);
//		if (flag == 0)
//			cout << "WRONG\n";
//		else if (flag == 1)
//			cout << "OK\n";
//		else
//			cout << "REPEAT\n";
//	}
//
//	return 0;
//}