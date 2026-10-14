//#define _CRT_SECURE_NO_WARNINGS
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define ll long long
//
//int n, m;
//vector<ll>nums;
//
//void set(int l, int r, int s, int e, int d) {
//	nums[l] += s;
//	nums[l + 1] += d - s;
//	nums[r + 1] -= d + e;
//	nums[r + 2] += e;
//}
//
//void build() {
//	for (int i = 1; i <= n; ++i)
//		nums[i] += nums[i - 1];
//	for (int i = 1; i <= n; ++i)
//		nums[i] += nums[i - 1];
//}
//
//int main() {
//	scanf("%d %d", &n, &m);
//	nums.resize(n + 3, 0);
//
//	while (m--) {
//		int l, r, s, e;
//		scanf("%d %d %d %d", &l, &r, &s, &e);
//		int d = (e - s) / (r - l);
//		set(l, r, s, e, d);
//	}
//
//	build();
//	ll mx = nums[1];
//	ll sum = nums[1];
//	for (int i = 2; i <= n; ++i) {
//		sum ^= nums[i];
//		mx = max(nums[i], mx);
//	}
//
//	printf("%lld %lld", sum, mx);
//
//	return 0;
//}