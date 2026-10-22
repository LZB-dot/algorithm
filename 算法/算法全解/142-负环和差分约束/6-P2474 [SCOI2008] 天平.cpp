//
//
////https://www.luogu.com.cn/problem/P2474
//
//
//#include<iostream>
//#include<algorithm>
//#include<cstring> 
//#include<string>
//
//using namespace std;
//
//const int MAXN = 55;
//
//int n, a, b;
//int mi[MAXN][MAXN], mx[MAXN][MAXN];
//
//void Floyd() {
//
//	for (int bridge = 1; bridge <= n; ++bridge) {
//
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= n; ++j) {
//				mi[i][j] = max(mi[i][j], mi[i][bridge] + mi[bridge][j]);
//				mx[i][j] = min(mx[i][j], mx[i][bridge] + mx[bridge][j]);
//			}
//		}
//	}
//}
//
//void solve() {
//	cin >> n >> a >> b;
//
//	for (int i = 1; i <= n; ++i) {
//		string s;
//		cin >> s;
//
//		for (int j = 1; j <= n; ++j) {
//
//			char c = s[j - 1];
//
//			if (c == '+') {
//				mi[i][j] = 1;
//				mx[i][j] = 2;
//			}
//			else if (c == '-') {
//				mi[i][j] = -2;
//				mx[i][j] = -1;
//			}
//			else if (c == '=') {
//				mi[i][j] = 0;
//				mx[i][j] = 0;
//			}
//			else { // '?'
//				mi[i][j] = -2;
//				mx[i][j] = 2;
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		mi[i][i] = 0;
//		mx[i][i] = 0;
//	}
//
//	Floyd();
//
//	int a1 = 0, a2 = 0, a3 = 0;
//
//	for (int i = 1; i <= n; ++i) {
//		for (int j = i + 1; j <= n; ++j) {
//
//			if (i == a || i == b || j == a || j == b)
//				continue;
//
//			if (mi[a][i] > mx[j][b] || mi[a][j] > mx[i][b])
//				++a1;
//
//			if (mx[a][i] < mi[j][b] || mx[a][j] < mi[i][b])
//				++a3;
//			
//			if (mi[a][i] == mx[a][i] && mi[j][b] == mx[j][b] && mi[a][i] == mi[j][b])
//				++a2;
//			else if (mi[a][j] == mx[a][j] && mi[i][b] == mx[i][b] && mi[a][j] == mi[i][b])
//				++a2;
//		}
//	}
//
//	cout << a1 << " " << a2 << " " << a3 << "\n";
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
