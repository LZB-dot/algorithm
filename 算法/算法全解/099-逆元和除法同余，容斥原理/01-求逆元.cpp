//
//
//#include <iostream>
//using namespace std;
//
//#define ll long long
//
//ll power(ll b, int n, int mod) {
//	ll ans = 1;
//	b %= mod;
//	while (n) {
//		if (n & 1)
//			ans = ans * b % mod;
//		b = b * b % mod;
//		n >>= 1;
//	}
//	return ans;
//}
//
////a/b
////b的逆元即为1/b，即为b的mod-2次方
//int compute(ll a, ll b, int mod) {
//	ll inv = power(b, mod - 2, mod);
//	return (a % mod) * inv % mod;
//}
//
