//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1e5 + 10;
//
//int n;
//ll arr[MAXN];
//ll sum[MAXN << 2];
//ll mx[MAXN << 2];
//
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//	mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
//}
//
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = arr[r];
//		mx[i] = arr[r];
//	}
//	else {
//		int mid = l + ((r - l) >> 1);
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//}
//
//
//void alter(int jobl, int jobr, int l, int r, int i) {
//	if (mx[i] == 1)
//		return;
//
//	if (l == r) {
//		sum[i] = sqrt(sum[i]);
//		mx[i] = sum[i];
//		return;
//	}
//	int mid = l + ((r - l) >> 1);
//	if (jobl <= mid)
//		alter(jobl, jobr, l, mid, i << 1);
//	if (jobr > mid)
//		alter(jobl, jobr, mid + 1, r, i << 1 | 1);
//	up(i);
//
//}
//
//ll query(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return sum[i];
//	ll ans = 0;
//
//	int mid = l + ((r - l) >> 1);
//	if (jobl <= mid)
//		ans += query(jobl, jobr, l, mid, i << 1);
//	if (jobr > mid)
//		ans += query(jobl, jobr, mid + 1, r, i << 1 | 1);
//
//	return ans;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n;
//	for (int i = 1; i <= n; ++i)
//		cin >> arr[i];
//	build(1, n, 1);
//	int m;
//	cin >> m;
//	while (m--) {
//		int k, l, r;
//		cin >> k >> l >> r;
//		if (l > r)
//			swap(l, r);
//		if (k == 0)
//			alter(l, r, 1, n, 1);
//		else if (k == 1)
//			cout << query(l, r, 1, n, 1) << "\n";
//	}
//
//
//	return 0;
//}