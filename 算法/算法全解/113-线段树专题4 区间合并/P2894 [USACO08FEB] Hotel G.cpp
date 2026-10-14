//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//
//const int MAXN = 1e5 + 10;
//
//int change[MAXN<<2];
//bool update[MAXN<<2];
//
//int pre[MAXN << 2], suf[MAXN << 2], len[MAXN << 2];
//
//void up(int i,int ln,int rn) {
//	int left = i << 1;
//	int right = i << 1 | 1;
//
//	len[i] = max(max(len[left], len[right]), suf[left] + pre[right]);
//	pre[i] = pre[left] == ln ? pre[left] + pre[right] : pre[left];
//	suf[i] = suf[right] == rn ? suf[right] + suf[left] : suf[right];
//}
//
//void lazy(int i,int v,int n) {
//	pre[i] = suf[i] = len[i] = v == 1 ? 0 : n;
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
//void build(int l,int r,int i) {
//	if (l == r)
//		pre[i] = suf[i] = len[i] = 1;
//	else {
//		int mid = l + ((r - l) >> 1);
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i, mid - l + 1, r - mid);
//	}
//	change[i] = 0;
//	update[i] = false;
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
//		up(i, mid - l + 1, r - mid);
//	}
//}
//
//int query(int jobx, int l, int r, int i) {
//	if (l == r)
//		return l;
//
//	int mid = l + ((r - l) >> 1);
//	down(i, mid - l + 1, r - mid);
//
//	if (len[i << 1] >= jobx)
//		return query(jobx, l, mid, i << 1);
//	
//	if (suf[i << 1] + pre[i << 1 | 1] >= jobx)
//		return mid - suf[i << 1] + 1;
//
//	return query(jobx, mid + 1, r, i << 1 | 1);
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
//	build(1, n, 1);
//
//	int op;
//	int x, y;
//	while (m--) {
//		cin >> op;
//		if (op == 1) {
//			cin >> x;
//			if (len[1] < x)
//				cout << "0\n";
//			else {
//				int left = query(x, 1, n, 1);
//				updateRange(left, left + x - 1, 1, 1, n, 1);
//				cout << left << "\n";
//			}
//		}
//		else {
//			cin >> x >> y;
//			updateRange(x, x+y-1, 0, 1, n, 1);
//		}
//	}
//
//	return 0;
//}