//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1e5 + 5;
//const int MOD = 1e9 + 7;
//
//
//ll fac[MAXN];//阶乘
//ll inv1[MAXN];//阶乘逆元
//ll inv2[MAXN];//连续数逆元
//
//ll qpow(ll x, ll b) {
//	ll ans = 1;
//	x %= MOD;
//
//	while (b) {
//		if (b & 1)
//			ans = (ans * x) % MOD;
//		x = (x * x) % MOD;
//		b >>= 1;
//	}
//
//	return ans;
//}
//
//void build1(int n) {
//	fac[0] = inv1[0] = 1;
//	fac[1] = 1;
//
//	for (int i = 2; i <= n; ++i)
//		fac[i] = (fac[i - 1] * i) % MOD;
//
//	inv1[n] = qpow(fac[n], MOD - 2);
//	for (int i = n - 1; i >= 1; --i)
//		inv1[i] = (inv1[i + 1] * (i + 1)) % MOD;
//
//}
//
//void build2(int n) {
//	inv2[1] = 1;
//	for (int i = 2; i <= n + 1; ++i)
//		inv2[i] = MOD - inv2[MOD % i] * (MOD / i) % MOD;
//}
//
//ll C(int n, int k) {
//	return (((fac[n] * inv1[k]) % MOD) * inv1[n - k]) % MOD;
//}
//
//ll compute1(int n) {
//	build1(2 * n);
//	return (C(2 * n, n) - C(2 * n, n - 1) + MOD) % MOD;
//}
//
//ll compute2(int n) {
//	build1(2 * n);
//	return C(2 * n, n) * qpow(n + 1, MOD - 2) % MOD;
//}
//
//ll compute3(int n) {
//	build2(n);
//	vector<ll>f(n + 1, 0);
//	f[0] = f[1] = 1;
//
//	for (int i = 2; i <= n; ++i)
//		f[i] = f[i - 1] * (4LL * i - 2) % MOD * inv2[i + 1] % MOD;
//
//	return f[n];
//}
//
//ll compute4(int n) {
//	vector<ll>f(n + 1, 0);
//	f[0] = f[1] = 1;
//
//	for (int i = 2; i <= n; ++i)
//		for (int l = 0, r = i - 1; l < i; ++l, --r) {
//			f[i] = (f[i] + f[l] * f[r] % MOD) % MOD;
//		}
//
//	return f[n];
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	cout << compute1(n) << "\n";
//	//cout << compute2(n) << "\n";
//	//cout << compute3(n) << "\n";
//	//cout << compute4(n) << "\n";
//
//	return 0;
//}