//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 1e4 + 10;
//
//int stjump[MAXN][15];
//int log_[MAXN];
//
//void precal(int n) {
//	log_[1] = 0;
//	for (int i = 2; i <= n; ++i)
//		log_[i] = log_[i >> 1] + 1;
//
//}
//
//int gcd(int x, int y) {
//	while (y != 0) {
//		int tmp = y;
//		y = x % y;
//		x = tmp;
//	}
//	return x;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, q;
//	cin >> n >> q;
//
//	precal(n);
//
//	vector<int>a(n + 1);
//	for (int i = 1; i <= n; ++i)
//		cin >> a[i];
//
//	for (int i = 1; i <= n; ++i) 
//		stjump[i][0] = a[i];
//
//	for (int p = 1; p < 15; ++p) {
//		for (int i = 1; i + (1 << p - 1) <= n; ++i)
//			stjump[i][p] = gcd(stjump[i][p - 1], stjump[i + (1 << p - 1)][p - 1]);
//	}
//
//	while (q--) {
//		int l, r;
//		cin >> l >> r;
//
//		int p = log_[r - l + 1];
//		int ans = gcd(stjump[l][p], stjump[r - (1 << p) + 1][p]);
//
//		cout << ans << "\n";
//	}
//
//	return 0;
//}