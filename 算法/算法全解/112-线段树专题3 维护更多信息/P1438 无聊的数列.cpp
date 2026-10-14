//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 1e5 + 10;
//int diff[MAXN];
//ll sum[MAXN << 2];
//ll add[MAXN << 2];
//
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//
//void lazy(int i, ll v,int n) {
//	sum[i] += n * v;
//	add[i] += v;
//}
//
//void down(int i, int ln, int rn) {
//	if (add[i]) {
//		lazy(i << 1, add[i], ln);
//		lazy(i << 1 | 1, add[i], rn);
//		add[i] = 0;
//	}
//}
//
//void build(int l, int r, int i) {
//	if (l == r)
//		sum[i] = diff[l];
//	else {
//		int mid = l + ((r - l) >> 1);
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	add[i] = 0;
//}
//
//void addRange(int jobl, int jobr, ll jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazy(i, jobv, r - l + 1);
//	else {
//		int mid = l + ((r - l) >> 1);
//		down(i, mid-l+1, r-mid);
//
//		if (jobl <= mid)
//			addRange(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			addRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
//}
//
//ll query(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return sum[i];
//
//	ll ans = 0;
//	int mid = l + ((r - l) >> 1);
//	down(i, mid - l + 1, r - mid);
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
//	int n, m;
//	cin >> n >> m;
//	vector<int>nums(n + 1);
//	for (int i = 1; i <= n; ++i) {
//		cin >> nums[i];
//		diff[i] = nums[i] - nums[i - 1];
//	}
//	build(1, n, 1);
//	int op;
//	int l, r, k, d;
//	while (m--) {
//		cin >> op;
//		if (op == 1) {
//			cin >> l >> r >> k >> d;
//			addRange(l, l, k, 1, n, 1);
//			if (l < n)
//				addRange(l + 1, r, d, 1, n, 1);
//			if (r < n)
//				addRange(r + 1, r + 1, -k - (r - l) * d, 1, n, 1);
//		}
//		else {
//			cin >> r;
//			cout << query(1, r, 1, n, 1) << "\n";
//		}
//	}
//	return 0;
//}