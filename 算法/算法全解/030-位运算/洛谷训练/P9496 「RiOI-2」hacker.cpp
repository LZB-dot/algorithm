//#include<iostream>
//using namespace std;
//
//typedef long long ll;
//
//int work(ll n, ll m) {
//	if (n == m)
//		return 0;
//	ll accept = m & (~n);
//	ll both = n & (~m);
//	if (accept && both)
//		return 2;
//	else
//		return 1;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int T;
//	cin >> T;
//	ll n, m;
//	while (T--) {
//		cin >> n >> m;
//		cout << work(n, m) << endl;
//	}
//}