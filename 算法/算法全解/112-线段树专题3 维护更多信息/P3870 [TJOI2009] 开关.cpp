//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 1e5 + 10;
////1 ´ò¿ª	0 ¹Ø±Õ
//int sum[MAXN << 2];
//bool reverses[MAXN << 2];
//
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//
//void lazy(int i,int n) {
//	sum[i] = n - sum[i];
//	reverses[i] = !reverses[i];
//}
//
//void down(int i, int ln, int rn) {
//	if (reverses[i]) {
//		lazy(i << 1,ln);
//		lazy(i << 1 | 1,rn);
//		reverses[i] = false;
//	}
//}
//
////void build(int l, int r, int i) {
////	if (l == r)
////		sum[i] = 0;
////	else {
////		int mid = l + ((r - l) >> 1);
////		build(l, mid, i << 1);
////		build(mid + 1, r, i << 1 | 1);
////		up(i);
////	}
////	reverses[i] = false;
////}
//
//void alter(int jobl, int jobr,  int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazy(i, r - l + 1);
//	else {
//		int mid = l + ((r - l) >> 1);
//		down(i, mid - l + 1, r - mid);
//
//		if (jobl <= mid)
//			alter(jobl, jobr, l, mid, i << 1);
//		if (jobr > mid)
//			alter(jobl, jobr, mid + 1, r, i << 1 | 1);
//	}
//	up(i);
//
//}
//
//int query(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return sum[i];
//
//	int ans = 0;
//	int mid = l + ((r - l) >> 1);
//	down(i, mid - l + 1, r - mid);
//
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
//	int op, l, r;
//	while (m--) {
//		cin >> op >> l >> r;
//		if (op == 0)
//			alter(l, r, 1, n, 1);
//		else
//			cout << query(l, r, 1, n, 1) << "\n";
//	}
//
//	return 0;
//}