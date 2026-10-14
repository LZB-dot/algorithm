//
//
////https://www.luogu.com.cn/problem/P4549
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int gcd(int a, int b) {
//	if (b != 0)
//		return gcd(b, a % b);
//
//	return a;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	int ans = 0;
//	for (int i = 1; i <= n; ++i) {
//		int x;
//		cin >> x;
//		ans = gcd(abs(x),ans);
//	}
//
//	cout << ans << "\n";
//	return 0;
//}