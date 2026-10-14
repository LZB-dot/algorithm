////分成 k 份的最大乘积
////一个数字 n 一定要分成 k 份（每份为正整数），得到的乘积尽量大是多少？
////数字 n 和 k 可能非常大，达到 10 ^ 12 规模。
////结果可能更大，所以返回结果对 1000000007 取模。
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define ll long long
//
//const int MOD = 1000000007;
//
//
//vector<vector<ll>>dp;
//
//ll dfs(int n, int k) {
//	if (k == 1)
//		return n;
//	ll ans = 0;
//	for (int i = 1; i <= n - k + 1; ++i) {
//		ll cur = dfs(n - i, k - 1) * i;
//		ans = max(cur, ans);
//	}
//	return ans;
//}
//ll way1(int n,int k) {
//	dp.resize(n, vector<ll>(k, -1));
//	return dfs(n, k);
//}
//
//
//
//ll power(int x, int n) {
//	ll res = 1;
//	x %= MOD;
//	while (n > 0) {
//		if (n & 1) {
//			res = (res * x) % MOD;
//		}
//		x = (x * x) % MOD;
//		n >>= 1;
//	}
//	return res;
//}
//
//ll way2(int n, int k) {
//	int x = n / k;
//	int remain = n % k;
//	ll p1 = power(x, k - remain);
//	ll p2 = power(x + 1, remain);
//	return (p1 * p2) % MOD;
//}
//
//void test() {
//	srand(time(0));
//	int N = 30;
//	for (int i = 1; i <= 2000; ++i) {
//		ll n = rand() % N + 1;
//		int k = rand() % n + 1;
//		ll ans1 = way1(n, k);
//		ll ans2 = way2(n, k);
//		if (ans1 != ans2) {
//			cout << "出错了" << endl;
//		}
//		if (i % 100 == 0) {
//			cout << "第" << i << "组测试完成" << endl;
//		}
//	}
//}
//
//int main() {
//	test();
//	return 0;
//}