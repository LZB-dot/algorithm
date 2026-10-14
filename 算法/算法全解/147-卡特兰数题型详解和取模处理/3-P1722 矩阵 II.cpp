//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MOD = 100;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	vector<int>f(n + 1, 0);
//	f[0] = f[1] = 1;
//	for (int i = 2; i <= n; ++i) {
//		for (int l = 0, r = i - 1; l < i; ++l, --r)
//			f[i] = (f[i] + f[l] * f[r]) % MOD;
//
//	}
//
//	cout << f[n] << "\n";
//
//	return 0;
//}