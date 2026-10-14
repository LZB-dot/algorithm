//
//
////https://www.luogu.com.cn/problem/P1516
//
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//
//ll x, y, px, py, d;
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
//
//void solve() {
//	ll x1, x2, m, n, l;
//	cin >> x1 >> x2 >> m >> n >> l;
//
//	ll a, b, c;
//	if (x1 < x2) {
//		a = m - n;
//		c = x2 - x1;
//	}
//	else {
//		a = n - m;
//		c = x1 - x2;
//	}
//
//	if (a < 0) {
//		a = -a;
//		c = l - c;
//	}
//	
//	b = l;
//	exgcd(a, b);
//
//	if (c % d != 0)
//		cout << "Impossible\n";
//	else {
//		x *= (c / d);
//		ll addx = b / d;
//
//		if (x < 0) {
//			ll cnt = (1 - x + addx - 1) / addx;
//			x += cnt * addx;
//		}
//		else {
//			ll cnt = (x - 1) / addx;
//			x -= cnt * addx;
//		}
//
//		cout << x << "\n";
//	}
//	
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	//int T;
//	//cin >> T;
//
//	//while (T--)
//		solve();
//
//	return 0;
//}