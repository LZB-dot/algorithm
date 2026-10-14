//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//#define ll long long
//
//const int MAXN = 1e5;
//const int mod = 1e9 + 7;
//
//int n;
//int cnts[MAXN + 1];
//ll pow2[MAXN + 1];//2的i次方
//ll dp[MAXN + 1];//gcd为i的非空子集数量
//
//void build() {
//	pow2[0] = 1;
//	for (int i = 1; i <= MAXN; ++i) {
//		pow2[i] = (pow2[i - 1] * 2) % mod;
//	}
//}
//
//ll solve() {
//	for (int i = MAXN; i >= 1; --i) {
//		ll counts = 0;
//		for (int j = i; j <= MAXN; j += i)
//			counts += cnts[j];
//		dp[i] = (pow2[counts] - 1 + mod) % mod;
//	
//		for (int j = i + i; j <= MAXN; j += i) {
//			dp[i] = (dp[i] - dp[j] + mod) % mod;
//		}
//	}
//
//	return dp[1];
//}
//
//int main() {
//	cin >> n;
//	int x;
//	for (int i = 0; i < n; ++i) {
//		cin >> x;
//		cnts[x]++;
//	}
//
//	build();
//	cout << solve() << endl;
//
//	return 0;
//}
