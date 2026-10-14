//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//
//ll x, y, px, py, d;
//vector<int>m, r;
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
//ll mul(ll a, ll b, ll mod) {
//	ll ans = 0;
//	while (b) {
//		if (b & 1)
//			ans = (ans + a) % mod;
//
//		b >>= 1;
//		a = (a + a) % mod;
//	}
//
//	return ans;
//}
//
//ll crt(int n) {
//	ll lcm = 1;
//	for (int i = 1; i <= n; ++i)
//		lcm *= m[i];
//
//	ll ans = 0;
//	for (int i = 1; i <= n; ++i) {
//		ll ai = lcm / m[i];
//
//		exgcd(ai, m[i]);
//		ll inv = (x % m[i] + m[i]) % m[i];
//
//		ll ti = mul(ai, inv, lcm);
//		ll ci = mul(ti, r[i], lcm);
//
//		ans = (ans + ci) % lcm;
//
//	}
//
//
//	return ans;
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	m.resize(n + 1, 0);
//	r.resize(n + 1, 0);
//
//	for (int i = 1; i <= n; ++i)
//		cin >> m[i] >> r[i];
//
//	cout << crt(n) << '\n';
//
//	return 0;
//}