//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//
//ll px, py;
//ll x, y;
//ll d;
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
//int main() {
//
//	ll a, b;
//
//	cin >> a >> b;
//	exgcd(a, b);
//
//	ll ans = ((x % b) + b) % b;
//	cout << ans << "\n";
//
//	return 0;
//}