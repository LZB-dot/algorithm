//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1e6 + 10;
//ll arr[MAXN];
//ll mx[MAXN << 2] , increase[MAXN << 2];
//ll change[MAXN << 2];
//bool update[MAXN << 2];
//
//
//void up(int i) {
//	mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
//}
//
////重置的同时把增量标0
//void updateLazy(int i, ll v) {
//	mx[i] = v;
//	increase[i] = 0;
//	change[i] = v;
//	update[i] = true;
//}
//
//void addLazy(int i,ll v) {
//	mx[i] += v;
//	increase[i] += v;
//}
//
//void down(int i) {
//	if (update[i]) {
//		updateLazy(i << 1, change[i]);
//		updateLazy(i << 1 | 1, change[i]);
//		update[i] = false;
//	}
//	if (increase[i] != 0) {
//		addLazy(i << 1 , increase[i]);
//		addLazy(i << 1 | 1, increase[i]);
//		increase[i] = 0;
//	}
//}
//
//void build(int l, int r, int i) {
//	if (l == r)
//		mx[i] = arr[l];
//	else {
//		int mid = l + ((r - l) >> 1);
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	increase[i] = 0;
//	change[i] = 0;
//	update[i] = false;
//}
//
//void updateRange(int jobl,int jobr,int jobv,int l,int r,int i){
//	if (jobl <= l && r <= jobr) 
//		updateLazy(i, jobv);
//	else {
//		down(i);
//		int mid = l + ((r - l) >> 1);
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
//void addRange(int jobl, int jobr, int jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		addLazy(i, jobv);
//	else {
//		down(i);
//		int mid = l + ((r - l) >> 1);
//		if (jobl <= mid)
//			addRange(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			addRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//}
//
//ll query(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return mx[i];
//	
//	ll ans = LLONG_MIN;
//	down(i);
//	int mid = l + ((r - l) >> 1);
//	if (jobl <= mid)
//		ans = max(ans, query(jobl, jobr, l, mid, i << 1));
//	if (jobr > mid)
//		ans = max(ans, query(jobl, jobr, mid + 1, r, i << 1 | 1));
//	
//	return ans;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, q;
//	cin >> n >> q;
//
//	for (int i = 1; i <= n; ++i)
//		cin >> arr[i];
//	build(1, n, 1);
//	int op;
//	int v, l, r;
//	while (q--) {
//		cin >> op;
//		cin >> l >> r;
//		if (op == 1) {
//			cin >> v;
//			updateRange(l, r, v, 1, n, 1);
//		}
//		else if (op == 2) {
//			cin >> v;
//			addRange(l, r, v, 1, n, 1);
//		}
//		else {
//			cout << query(l, r, 1, n, 1) << "\n";
//		}
//
//	}
//
//	return 0;
//}