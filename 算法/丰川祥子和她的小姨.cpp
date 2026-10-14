//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<climits>
//using namespace std;
//
//typedef long long ll;
//
//void work1(ll n) {
//	if (n == 1 || n == 2)
//		cout << n << " ";
//	ll x1 = 1, x2 = 1;
//	n -= 2;
//	ll ans = 2;
//	while (n--) {
//		ll tmp = x1 + x2;
//		x1 = x2;
//		x2 = tmp;
//		ans += tmp;
//	}
//	cout << ans << " ";
//	return;
//}
//
//void work2(ll x) {
//	if (x == 1 || x == 2)
//		cout << x << " ";
//	ll x1 = 1, x2 = 1;
//	ll ans = 2;
//	ll sum = 2;
//	while (sum < x) {
//		ll tmp = x1 + x2;
//		x1 = x2;
//		x2 = tmp;
//		ans++;
//		sum += tmp;
//	}
//	if (sum > x) {
//		ans--;
//	}
//	cout << ans << " ";
//}
//
//
//int main() {
//	ll n, x;
//	cin >> n >> x;
//	work1(n);
//	work2(x);
//	return 0;
//}