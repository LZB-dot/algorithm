//#include<iostream>
//#include<vector>
//using namespace std;
//typedef long long ll;
//
//ll x, y, px, py, d;
//vector<ll> m, r;  
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
//	a = (a % mod + mod) % mod;
//	b = (b % mod + mod) % mod;
//
//	ll ans = 0;
//
//	while (b) {
//		if (b & 1)
//			ans = (ans + a) % mod;
//		b >>= 1;
//		a = (a + a) % mod;
//	}
//	return ans;
//}
//
//ll excrt(int n) {
//	ll lcm = 1;
//	ll tail = 0;
//	ll tmp, b, c, x0;
//
//	// ans = lcm * k + tail
//	for (int i = 1; i <= n; ++i) {
//		// ans = m[i] * y + ri
//		// lcm * x + m[i] * y = ri - tail
//		// a = lcm
//		// b = m[i]
//		// c = ri - tail
//		b = m[i];
//		c = ((r[i] - tail) % b + b) % b;
//
//		exgcd(lcm, b);
//
//		if (c % d != 0)
//			return -1;
//
//		// ax + by = gcd(a,b)，特解是，x变量
//		// ax + by = c，特解是，x变量 * (c/d)
//		// ax + by = c，最小非负特解x0 = (x * (c/d)) % (b/d) 取非负余数
//		// 通解 = x0 + (b/d) * n
//		x0 = mul(x, c / d, b / d);
//
//		// ans = lcm * x + tail，带入通解
//		// ans = lcm * (x0 + (b/d) * n) + tail
//		// ans = lcm * (b/d) * n + lcm * x0 + tail
//		// tail' = tail' % lcm'
//		tmp = lcm * (b / d);
//		tail = (tail + mul(x0, lcm, tmp)) % tmp;
//		lcm = tmp;
//	}
//
//	return tail;
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
//	cout << excrt(n) << '\n';
//
//	return 0;
//}
