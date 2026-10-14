//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1000001;
//const int MOD = 100000007;
//
//ll fac[MAXN];
//ll inv[MAXN];
//
//ll qpow(ll a, ll b) {
//	a %= MOD;
//	ll ans = 1;
//
//	while (b) {
//		if (b & 1)
//			ans = (ans * a) % MOD;
//		a = (a * a) % MOD;
//		b >>= 1;
//	}
//	return ans;
//}
//
//void build(int n) {
//	fac[0] = inv[0] = 1;
//	fac[1] = 1;
//	for (int i = 2; i <= n; ++i)
//		fac[i] = (fac[i - 1] * i) % MOD;
//
//	inv[n] = qpow(fac[n], MOD - 2);
//	for (int i = n - 1; i >= 1; --i)
//		inv[i] = (inv[i + 1] * (i + 1)) % MOD;
//}
//
//ll C(int n, int k) {
//	return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
//}
//
//ll compute(int n) {
//	build(2 * n);
//	return (C(2 * n, n) - C(2 * n, n - 1) + MOD) % MOD;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//	cout << compute(n) << "\n";
//
//	return 0;
//}