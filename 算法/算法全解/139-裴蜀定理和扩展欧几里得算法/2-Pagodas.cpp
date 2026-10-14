//
//
////https://acm.hdu.edu.cn/showproblem.php?pid=5512
//
//
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
//void solve(int i) {
//	int n, a, b;
//	cin >> n >> a >> b;
//
//	cout << "Case #" << i << ": ";
//	int t = gcd(a, b);
//	int ans = n / t;
//
//	if (ans & 1)
//		cout << "Yuwgna\n";
//	else
//		cout << "Iaka\n";
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int T;
//	cin >> T;
//
//	for (int i = 1; i <= T; ++i) {
//		solve(i);
//	}
//
//
//	return 0;
//}