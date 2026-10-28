//
//
////https://www.luogu.com.cn/problem/P4306
//
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
//const int MAXN = 2010;
//
//bitset<MAXN> g[MAXN];
//
//void solve() {
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; ++i) {
//		string s;
//		cin >> s;
//
//		s = " " + s;
//		for (int j = 1; j <= n; ++j) {
//			int cur = s[j] - '0';
//			g[i][j] = cur;
//		}
//
//		g[i][i] = 1;
//
//	}
//
//	for (int bridge = 1; bridge <= n; ++bridge) {
//
//		for (int i = 1; i <= n; ++i) {
//			if (g[i][bridge])
//				g[i] |= g[bridge];
//		}
//	}
//
//	int ans = 0;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j)
//			if (g[i][j] == 1)
//				++ans;
//	}
//
//	cout << ans << "\n";
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