//
////https://www.luogu.com.cn/problem/P1347
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring> 
//#include<queue>
//#include<unordered_map>
//#include<climits>
//#include<bitset>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 30;
//
//int n, m;
//
//bitset<MAXN>g[MAXN];
//int indegree[MAXN];
//
//void floyd() {
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			if (g[j][i])
//				g[j] |= g[i];
//		}
//	}
//}
//
//int check() {
//	int ans = 0;
//
//	for (int i = 1; i <= n; ++i)
//		if (g[i][i])
//			return 2;
//
//	for (int i = 1; i <= n; ++i) {
//		for (int j = i + 1; j <= n; ++j) {
//			if (g[i][j] == 0 && g[j][i] == 0)
//				return 3;
//		}
//	}
//
//	return 1;
//}
//
//void prin(int t) {
//	vector<int>order;
//
//
//}
//
//void solve() {
//	cin >> n >> m;
//
//	bool f = 0;
//
//	for (int i = 1; i <= m; ++i) {
//		string s;
//		cin >> s;
//
//		if (f)
//			continue;
//
//		int u = s[0] - 'A' + 1;
//		int v = s[2] - 'A' + 1;
//		indegree[v]++;
//		g[u][v] = 1;
//
//		floyd();
//
//		int c = check();
//
//		if (c == 2) {
//			cout << "Inconsistency found after" << i << " relations.\n";
//			f = 1;
//		}
//		else if (c == 1) {
//			cout << "Sorted sequence determined after " << i << " relations: ";
//			vector<int>order;
//
//			for (int p = 1; p <= n; ++p)
//				order[n - g[p].count()] = 'A' + p - 1;
//
//			for (int i = 1; i <= n; ++i)
//				cout << order[i];
//
//			cout << ".\n";
//			f = 1;
//		}
//		
//	}
//
//	if (!f)
//		cout << "Sorted sequence cannot be determined.\n";
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	solve();
//
//	return 0;
//}