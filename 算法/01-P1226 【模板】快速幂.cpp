//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define ll long long
//
//ll power(ll x, ll n, ll mod) {
//	ll ans = 1;
//	x %= mod;
//	while (n > 0) {
//		if (n & 1)
//			ans = (ans * x) % mod;
//		x = (x * x) % mod;
//		n >>= 1;
//	}
//	return ans;
//}
//
//int main() {
//	ll a, b, p;
//	cin >> a >> b >> p;
//	printf("%lld^%lld mod %lld=%lld", a, b, p, power(a, b, p));
//	return 0;
//}