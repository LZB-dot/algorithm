////https://www.luogu.com.cn/problem/P8775
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1e5 + 10;
//
//int n, x;
//ll h[MAXN];
//
//bool check(int k) {
//
//	for (int i = 1; i <= n - k; ++i) {
//		if (h[i + k - 1] - h[i - 1] < 2LL * x)
//			return false;
//	}
//	return true;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> x;
//
//	for (int i = 1; i <= n - 1; ++i) {
//		ll a;
//		cin >> a;
//		h[i] = h[i - 1] + a;
//	}
//
//	int ans = n;
//	int l = 1, r = n;
//	while (l <= r) {
//		int mid = l + ((r - l) >> 1);
//
//		if (check(mid)) {
//			ans = mid;
//			r = mid - 1; 
//		}
//		else 
//			l = mid + 1;
//		
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}