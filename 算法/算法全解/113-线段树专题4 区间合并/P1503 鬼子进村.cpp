//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//int st[MAXN];
//int pre[MAXN << 2], suf[MAXN << 2];
//int n, m;
//
//void up(int i, int ln, int rn) {
//	int l = i << 1;
//	int r = i << 1 | 1;
//	pre[i] = pre[l] == ln ? pre[l] + pre[r] : pre[l];
//	suf[i] = suf[r] == rn ? suf[r] + suf[l] : suf[r];
//}
//
//void build(int l, int r, int i) {
//	if (l == r)
//		pre[i] = suf[i] = 1;
//	else {
//		int mid = l + ((r - l) >> 1);
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i, mid - l + 1, r - mid);
//	}
//}
//
//void update(int jobi, int jobv, int l, int r, int i) {
//	if (l == r)
//		pre[i] = suf[i] = jobv;
//	else {
//		int mid = l + ((r - l) >> 1);
//		if (jobi <= mid)
//			update(jobi, jobv, l, mid, i << 1);
//		else
//			update(jobi, jobv, mid + 1, r, i << 1 | 1);
//		up(i, mid - l + 1, r - mid);
//	}
//}
//
//int query(int jobi, int l, int r, int i) {
//	if (l == r)
//		return pre[i];
//
//	int mid = l + ((r - l) >> 1);
//	int left = i << 1;
//	int right = i << 1 | 1;
//
//	if (jobi <= mid) {
//		if (jobi > mid - suf[left])
//			return suf[left] + pre[right];
//		else
//			return query(jobi, l, mid, left);
//	}
//	else {
//		if (mid + pre[right] >= jobi)
//			return suf[left] + pre[right];
//		else
//			return query(jobi, mid + 1, r, right);
//	}
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	cin >> n >> m;
//	build(1, n, 1);
//	int top = 0;
//
//	while (m--) {
//		char op[2];
//		cin >> op;
//
//		if (op[0] == 'D') {
//			int x;
//			cin >> x;
//			update(x, 0, 1, n, 1);
//			st[top++] = x;
//		}
//		else if (op[0] == 'R') {
//			int x = st[--top];
//			update(x, 1, 1, n, 1);
//		}
//		else if (op[0] == 'Q') {
//			int x;
//			cin >> x;
//			cout << query(x, 1, n, 1) << '\n';
//		}
//	}
//
//	return 0;
//}