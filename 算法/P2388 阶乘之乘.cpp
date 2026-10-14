//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//#define ll long long
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	ll n;
//	cin >> n;
//	//统计5的个数
//	ll ans = 0;
//	ll s = 0;//记录可以被整除的阶乘数
//	//5-9：1
//	//10-14：2
//	//...
//	for (int i = 1; i <= n; ++i) {
//		ll tmp = i;
//		while (tmp % 5 == 0) {
//			++s;
//			tmp /= 5;
//		}
//		ans += s;
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}