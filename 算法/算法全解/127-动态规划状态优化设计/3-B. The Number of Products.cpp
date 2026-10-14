////https://codeforces.com/problemset/problem/1215/B
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1e5 + 10;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	ll neg = 0, pos = 0;
//	ll cnt0 = 1, cnt1 = 0; // pre[0]=0，偶数，初始cnt0=1
//	int cur = 0;
//
//	// cur：1奇数，0偶数
//	for (int i = 1; i <= n; ++i) {
//		ll x;
//		cin >> x;
//
//		cur ^= (x > 0 ? 0 : 1);
//
//		if (cur == 0) {
//			pos += cnt0;
//			neg += cnt1;
//			cnt0++;
//		}
//		else {
//			pos += cnt1;
//			neg += cnt0;
//			cnt1++;
//		}
//	}
//
//	cout << neg << " " << pos << "\n";
//	return 0;
//}
