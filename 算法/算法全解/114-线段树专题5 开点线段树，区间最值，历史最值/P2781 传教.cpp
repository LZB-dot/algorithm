//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//
// //范围1 ~ 10^9，线段树高度差不多30
//	// 查询次数1000，每次查询都有左右两条边线
//	// 所以空间占用差不多1000 * 30 * 2 = 60000
//	// 适当调大即可
//const int MAXN = 1e5 + 10;
//int cnt;
//int left_[MAXN], right_[MAXN];
//ll sum[MAXN], add[MAXN];
//
//void up(int i, int l, int r) {
//	sum[i] = sum[l] + sum[r];
//}
//
//void lazy(int i, ll v, int n) {
//	add[i]+= v;
//	sum[i] += n * v;
//}
//
//void down(int i,int ln,int rn) {
//	if (add[i] != 0) {
//		if (left_[i] == 0)
//			left_[i] = ++cnt;
//		if (right_[i] == 0)
//			right_[i] = ++cnt;
//	
//		lazy(left_[i], add[i], ln);
//		lazy(right_[i], add[i], rn);
//	
//		add[i] = 0;
//	}
//}
//
//void addRange(int jobl, int jobr, ll jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazy(i, jobv, r - l + 1);
//	else {
//		int mid = l + ((r - l) >> 1);
//		down(i, mid - l + 1, r - mid);
//
//		if (jobl <= mid) {
//			if (left_[i] == 0)
//				left_[i] = ++cnt;
//			addRange(jobl, jobr, jobv, l, mid, left_[i]);
//		}
//
//		if (jobr > mid) {
//			if (right_[i] == 0)
//				right_[i] = ++cnt;
//			addRange(jobl, jobr, jobv, mid + 1, r, right_[i]);
//		}
//
//		up(i, left_[i], right_[i]);
//	}
//}
//
//ll query(int jobl, int jobr,  int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return sum[i];
//
//	int mid = l + ((r - l) >> 1);
//	down(i, mid - l + 1, r - mid);
//
//	ll ans = 0;
//	if (jobl <= mid && left_[i] != 0)
//		ans += query(jobl, jobr, l, mid, left_[i]);
//	if (jobr > mid && right_[i] != 0)
//		ans += query(jobl, jobr, mid + 1, r, right_[i]);
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
//	cnt = 1;
//	int op;
//	int l, r;
//	ll v;
//	while (m--) {
//		cin >> op;
//		if (op == 1) {
//			cin >> l >> r >> v;
//			addRange(l, r, v, 1, n, 1);
//		}
//		else {
//			cin >> l >> r;
//			cout << query(l, r, 1, n, 1) << "\n";
//		}
//	}
//
//
//	return 0;
//}