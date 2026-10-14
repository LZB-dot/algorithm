//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 5e4 + 10;
//
//int stmax[MAXN][20], stmin[MAXN][20];
//int n, q;
//int h[MAXN];
//int log_[MAXN];
//
//void precal() {
//	log_[1] = 0;
//	for (int i = 2; i <= n; ++i)
//		log_[i] = log_[i >> 1] + 1;
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> q;
//
//	for (int i = 1; i <= n; ++i)
//		cin >> h[i];
//
//	for (int i = 1; i <= n; ++i) {
//		stmax[i][0] = h[i];
//		stmin[i][0] = h[i];
//	}
//
//	for (int p = 1; p < 20; ++p)
//		for (int i = 1; i + (1 << (p - 1)) <= n; ++i) {
//			stmax[i][p] = max(stmax[i][p - 1], stmax[i + (1 << (p - 1))][p - 1]);
//			stmin[i][p] = min(stmin[i][p - 1], stmin[i + (1 << (p - 1))][p - 1]);
//		}
//
//	precal();
//
//	while (q--) {
//		int a, b;
//		cin >> a >> b;
//
//		int p = log_[b - a + 1];
//		int mx = max(stmax[a][p], stmax[b - (1 << p) + 1][p]);
//		int mi = min(stmin[a][p], stmin[b - (1 << p) + 1][p]);
//
//		cout << mx - mi << "\n";
//	}
//
//	return 0;
//}