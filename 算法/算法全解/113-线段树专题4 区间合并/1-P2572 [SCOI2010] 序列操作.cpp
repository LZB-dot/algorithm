//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//
//int arr[MAXN];
//int sum[MAXN << 2], change[MAXN << 2];
//int len0[MAXN << 2], len1[MAXN << 2];
//int pre0[MAXN << 2], pre1[MAXN << 2];
//int suf0[MAXN << 2], suf1[MAXN << 2];
//bool update[MAXN << 2], rev[MAXN << 2];
//
//void up(int i, int ln, int rn) {
//	int l = i << 1;
//	int r = i << 1 | 1;
//	sum[i] = sum[l] + sum[r];
//
//	len0[i] = max(max(len0[l], len0[r]), suf0[l] + pre0[r]);
//	pre0[i] = pre0[l] == ln ? pre0[l] + pre0[r] : pre0[l];
//	suf0[i] = suf0[r] == rn ? suf0[r] + suf0[l] : suf0[r];
//
//	len1[i] = max(max(len1[l], len1[r]), suf1[l] + pre1[r]);
//	pre1[i] = pre1[l] == ln ? pre1[l] + pre1[r] : pre1[l];
//	suf1[i] = suf1[r] == rn ? suf1[r] + suf1[l] : suf1[r];
//}
//
//void lazyUpdate(int i, int n, int v) {
//	sum[i] = n * v;
//	update[i] = true;
//	rev[i] = false;
//	change[i] = v;
//	len0[i] = pre0[i] = suf0[i] = (v == 0) ? n : 0;
//	len1[i] = pre1[i] = suf1[i] = (v == 1) ? n : 0;
//}
//
//void lazyReverse(int i, int n) {
//	sum[i] = n - sum[i];
//	rev[i] = !rev[i];
//	swap(len0[i], len1[i]);
//	swap(pre0[i], pre1[i]);
//	swap(suf0[i], suf1[i]);
//}
//
//void down(int i, int ln, int rn) {
//	if (update[i]) {
//		lazyUpdate(i << 1, ln, change[i]);
//		lazyUpdate(i << 1 | 1, rn, change[i]);
//		update[i] = false;
//	}
//	if (rev[i]) {
//		lazyReverse(i << 1, ln);
//		lazyReverse(i << 1 | 1, rn);
//		rev[i] = false;
//	}
//}
//
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = arr[l];
//		len0[i] = pre0[i] = suf0[i] = (arr[l] == 0 ? 1 : 0);
//		len1[i] = pre1[i] = suf1[i] = (arr[l] == 1 ? 1 : 0);
//	}
//	else {
//		int mid = l + ((r - l) >> 1);
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i, mid - l + 1, r - mid);
//	}
//
//	rev[i] = false;
//	update[i] = false;
//	change[i] = -1;
//}
//
//void updateRange(int jobl, int jobr, int jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazyUpdate(i, r - l + 1, jobv);
//	else {
//		int mid = l + ((r - l) >> 1);
//		down(i, mid - l + 1, r - mid);
//		if (jobl <= mid)
//			updateRange(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			updateRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//		up(i, mid - l + 1, r - mid);
//	}
//}
//
//void reverses(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazyReverse(i, r - l + 1);
//	else {
//		int mid = l + ((r - l) >> 1);
//		down(i, mid - l + 1, r - mid);
//		if (jobl <= mid)
//			reverses(jobl, jobr, l, mid, i << 1);
//		if (jobr > mid)
//			reverses(jobl, jobr, mid + 1, r, i << 1 | 1);
//		up(i, mid - l + 1, r - mid);
//	}
//}
//
//int querySum(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return sum[i];
//
//	int ans = 0;
//	int mid = l + ((r - l) >> 1);
//	down(i, mid - l + 1, r - mid);
//	if (jobl <= mid)
//		ans += querySum(jobl, jobr, l, mid, i << 1);
//	if (jobr > mid)
//		ans += querySum(jobl, jobr, mid + 1, r, i << 1 | 1);
//
//	return ans;
//}
//
//vector<int> queryOne(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return { len1[i],pre1[i],suf1[i] };
//
//	int mid = l + ((r - l) >> 1);
//	int ln = mid - l + 1;
//	int rn = r - mid;
//	down(i, ln, rn);
//
//	if (jobr <= mid)
//		return queryOne(jobl, jobr, l, mid, i << 1);
//
//	if (jobl > mid)
//		return queryOne(jobl, jobr, mid + 1, r, i << 1 | 1);
//
//	vector<int>left = queryOne(jobl, jobr, l, mid, i << 1);
//	vector<int>right = queryOne(jobl, jobr, mid + 1, r, i << 1 | 1);
//
//	int len = max(max(left[0], right[0]), left[2] + right[1]);
//	int pre = (left[0] >= mid - max(jobl, l) + 1) ? (left[1] + right[1]) : left[1];
//	int suf = (right[0] >= min(r, jobr) - mid) ? (right[2] + left[2]) : right[2];
//
//	return { len,pre,suf };
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 1; i <= n; ++i)
//		cin >> arr[i];
//
//	build(1, n, 1);
//
//	int op, l, r;
//
//	while (m--) {
//
//		cin >> op >> l >> r;
//
//		++l;
//		++r;
//		if (op == 0)
//			updateRange(l, r, 0, 1, n, 1);
//		else if (op == 1)
//			updateRange(l, r, 1, 1, n, 1);
//		else if (op == 2)
//			reverses(l, r, 1, n, 1);
//		else if (op == 3)
//			cout << querySum(l, r, 1, n, 1) << "\n";
//		else {
//			auto ans = queryOne(l, r, 1, n, 1);
//			cout << ans[0] << "\n";
//		}
//
//	}
//	return 0;
//}
//
//
//
//
//
//
