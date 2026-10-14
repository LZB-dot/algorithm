//#include<iostream>
//
//using namespace std;
//
//typedef long long ll;
//
//ll x, y, px, py;
//ll d;
//
//ll mul(ll a, ll b, ll mod) {
//	ll ans = 0;
//
//	while (b) {
//		if (b & 1)
//			ans = (ans + a) % mod;
//		a = (a + a) % mod;
//		b >>= 1;
//	}
//
//	return ans;
//}
//
//
//ll qpow(ll a, ll b, ll mod) {
//	ll ans = 1;
//	while (b) {
//		if (b & 1)
//			ans = mul(ans, a,mod);
//		a = mul(a, a, mod);
//		b >>= 1;
//	}
//
//	return ans;
//}
//
//void exgcd(ll a, ll b) {
//	if (b == 0) {
//		d = a;
//		x = 1;
//		y = 0;
//	}
//	else {
//		exgcd(b, a % b);
//		px = x;
//		py = y;
//		x = py;
//		y = px - py * (a / b);
//	}
//}
//
//int main() {
//	ll n, m, l;
//	cin >> n >> m >> l;
//
//	ll mod = n + 1;
//	exgcd(qpow(2, m, mod), n + 1);
//	ll tmp = (x % mod + mod) % mod;
//
//	ll ans = mul(tmp, l, mod);
//	cout << ans << "\n";
//
//	return 0;
//}