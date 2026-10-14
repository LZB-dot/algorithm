//#include<iostream>
//#include<unordered_map>
//using namespace std;
//
//#define ll long long
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, c;
//	cin >> n >> c;
//	unordered_map<ll, ll>mp;
//	int x;
//	for (int i = 0; i < n; ++i) {
//		cin >> x;
//		mp[x]++;
//	}
//
//	ll ans = 0;
//	for (auto it : mp) {
//		int a = it.first;
//		if (mp.count(a - c))
//			ans += mp[a - c] * it.second;
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}