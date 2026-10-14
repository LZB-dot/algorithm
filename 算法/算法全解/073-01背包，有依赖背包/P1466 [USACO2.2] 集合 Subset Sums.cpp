//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//
//
//	ll sum = (ll)n * (n + 1) / 2;
//
//	if (sum % 2 != 0) {
//		cout << 0 << "\n";
//		return 0;
//	}
//
//	int total = sum >> 1;
//
//	vector<ll>dp(total + 1);
//	dp[0] = 1;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = total; j >= i; --j) {
//			dp[j] += dp[j - i];
//		}
//	}
//
//	cout << (dp[total] >> 1) << "\n";
//	return 0;
//}