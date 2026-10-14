//#include<iostream>
//#include<vector>
//#include<cstdio>
//
//using namespace std;
//
//
//const int MAXN = 1e5 + 10;
//
//double arr[MAXN];
//double sum[MAXN << 2];
//double ssum[MAXN << 2];
//double add[MAXN << 2];
//
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//	ssum[i] = ssum[i << 1] + ssum[i << 1 | 1];
//}
//
//void lazy(int i, int n, double v) {
//	ssum[i] += 2 * sum[i] * v + v * v * n;
//	sum[i] += n * v;
//	add[i] += v;
//}
//
//void down(int i, int ln, int rn) {
//	if (add[i]) {
//		lazy(i << 1, ln, add[i]);
//		lazy(i << 1 | 1, rn, add[i]);
//		add[i] = 0;
//	}
//}
//
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = arr[l];
//		ssum[i] = arr[l] * arr[l];
//	}
//	else {
//		int mid = l + ((r - l) >> 1);
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	add[i] = 0;
//}
//
//void addRange(int jobl, int jobr, double jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazy(i, r - l + 1, jobv);
//	else {
//		int mid = l + ((r - l) >> 1);
//		down(i, mid - l + 1, r - mid);
//		if (jobl <= mid)
//			addRange(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			addRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//}
//
////t=1 和		0 平方和
//double query(int t,int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr) {
//		if (t == 1)
//			return sum[i];
//		else
//			return ssum[i];
//	}
//	
//	double ans = 0;
//	int mid = l + ((r - l) >> 1);
//	down(i, mid - l + 1, r - mid);
//	if (jobl <= mid)
//		ans += query(t, jobl, jobr, l, mid, i << 1);
//	if (jobr > mid)
//		ans += query(t, jobl, jobr, mid + 1, r, i << 1 | 1);
//
//	return ans;
//}
//
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
//	build(1, n, 1);
//
//	int op;
//	int l, r;
//	double k;
//	while (m--) {
//		cin >> op >> l >>  r;
//		if (op == 1) {
//			cin >> k;
//			addRange(l, r, k, 1, n, 1);
//		}
//		else if (op == 2) {
//			double sum = query(1, l, r, 1, n, 1);
//			double ans = sum / (r - l + 1);
//			printf("%.4lf\n", ans);
//		}
//		else {
//			double s1 = query(1, l, r, 1, n, 1);
//			double p1 = s1 / (r - l + 1);
//			double s2 = query(0, l, r, 1, n, 1);
//			double ans = s2 - 2 * p1 * s1 + (r - l + 1) * p1 * p1;
//			ans /= (r - l + 1);
//			printf("%.4lf\n", ans);
//		}
//	}
//	return 0;
//}