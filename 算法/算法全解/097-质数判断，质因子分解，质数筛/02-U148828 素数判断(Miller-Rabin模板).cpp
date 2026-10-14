//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//#define ll long long
//
//ll p[] = { 2,3,5,7,11,13,17,19,23,29,31 ,37,39,41 };
//int s = sizeof(p) / sizeof(p[0]);
//
//ll power(ll x, ll n, ll mod) {
//	x %= mod;
//
//	ll ans = 1;
//	while (n) {
//		if (n & 1)
//			ans = (__int128)x * ans % mod;
//		x = (__int128)x * x % mod;
//		n >>= 1;
//	}
//
//	return ans;
//}
//
////单次测试，用底数a检验n是否为合数
//bool witness(ll a, ll n) {
//	ll u = n - 1;
//	int t = 0;
//	while ((u & 1) == 0) {
//		u >>= 1;
//		++t;
//	}
//
//	ll x1 = power(a, u, n);
//	for (int i = 1; i <= t; ++i) {
//		ll x2 = power(x1, 2, n);
//		if (x2 == 1 && x1 != 1 && x1 != n - 1)
//			return true;
//		x1 = x2;
//	}
//
//	// 费马小定理：如果 a^(n-1) ≠ 1 mod n → n 是合数
//	if (x1 != 1) {
//		return true;
//	}
//	return false;
//}
//
//bool millerRabin(ll n) {
//	if (n <= 1)
//		return false;
//	if (n <= 3)
//		return true;
//	if ((n & 1) == 0)
//		return false;
//
//	for (int i = 0; i < s && p[i] < n; ++i) {
//		if (witness(p[i], n))
//			return false;
//	}
//	return true;
//}
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		ll n;
//		cin >> n;
//		if (millerRabin(n))
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//
//
//
//	return 0;
//}