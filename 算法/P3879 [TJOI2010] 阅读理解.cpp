//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAX = 1e6;
//const int N = 26;
//int n, m;
//int total;
//int trie[MAX][N];
//vector<int>cnt[MAX];
//
//void Init() {
//	total = 1;
//	for (int i = 0; i < MAX; ++i) 
//		for (int j = 0; j < N; ++j)
//			trie[i][j] = 0;
//}
//
//void Insert(const string& s,int idx) {
//	int cur = 1;
//	for (char c : s) {
//		int path = c - 'a';
//		if (trie[cur][path] == 0)
//			trie[cur][path] = ++total;
//		cur = trie[cur][path];
//	}
//	if (cnt[cur].empty() || cnt[cur].back() != idx) {
//		cnt[cur].push_back(idx);
//	}
//}
//
//void Query(const string& s) {
//	int cur = 1;
//	for (char c : s) {
//		int path = c - 'a';
//		if (trie[cur][path] == 0) {
//			cout << endl;
//			return;
//		}
//		cur = trie[cur][path];
//	}
//	for (int i : cnt[cur]) {
//		cout << i << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	Init();
//	cin >> n;
//	for (int i = 1; i <= n; ++i) {
//		int s;
//		cin >> s;
//		for (int j = 1; j <= s; ++j) {
//			string str;
//			cin >> str;
//			Insert(str, i);
//		}
//	}
//
//	cin >> m;
//	while (m--) {
//		string s;
//		cin >> s;
//		Query(s);
//	}
//
//	return 0;
//}