//#include<iostream>
//#include<vector>
//
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1e5 + 10;
//
//ll arr[MAXN];
//ll sum[MAXN<<2], change[MAXN<<2];
//ll mx[MAXN<<2];
//bool update[MAXN<<2];
//
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//	mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
//}
//
//void lazy(int i, ll v, int n) {
//	sum[i] = n * v;
//	mx[i] = v;
//	change[i] = v;
//	update[i] = true;
//}
//
//void down(int i, int ln, int rn) {
//	if (update[i]) {
//		lazy(i << 1, change[i], ln);
//		lazy(i << 1 | 1, change[i], rn);
//		update[i] = false;
//	}
//}
//
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = arr[l];
//		mx[i] = arr[l];
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
//void getMod(int jobl, int jobr, int x, int l, int r, int i) {
//	if (mx[i] < x)
//		return;
//
//	if (l == r) {
//		sum[i] %= x;
//		mx[i] %= x;
//		return;
//	}
//
//	int mid = l + ((r - l) >> 1);
//	down(i, mid - l + 1, r - mid);
//
//	if (jobl <= mid)
//		getMod(jobl, jobr, x, l, mid, i << 1);
//	if (jobr > mid)
//		getMod(jobl, jobr, x, mid + 1, r, i << 1 | 1);
//
//	up(i);
//}
//
//void updateRange(int jobl, int jobr, int jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazy(i, jobv, r - l + 1);
//	else {
//		int mid = l + ((r - l) >> 1);
//		down(i, mid - l + 1, r - mid);
//
//		if (jobl <= mid)
//			updateRange(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			updateRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; ++i)
//		cin >> arr[i];
//
//	build(1, n, 1);
//	int op;
//	int l, r, v;
//	while (m--) {
//		cin >> op;
//		if (op == 1) {
//			cin >> l >> r;
//			cout << query(l, r, 1, n, 1) << "\n";
//		}
//		else if (op == 2) {
//			cin >> l >> r >> v;
//			getMod(l, r, v, 1, n, 1);
//		}
//		else {
//			cin >> l >> v;
//			updateRange(l, l, v, 1, n, 1);
//		}
//	}
//
//	return 0;
//}