//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<climits>
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//	int n;
//	ll p;
//	cin >> n >> p;
//	vector<ll>a(n), b(n);
//	int x;
//	for (int i = 0; i < n; ++i) {
//		cin >> x;
//		a[i] = x % p;
//	}
//	for (int i = 0; i < n; ++i) {
//		cin >> x;
//		b[i] = x % p;
//	}
//	int ans = 0;
//	for (int i = 0; i < n; ++i) {
//		int tmp = a[i] * b[i] % p;
//		ans = (ans + tmp) % p;
//	}
//	cout << ans << endl;
//	return 0;
//}