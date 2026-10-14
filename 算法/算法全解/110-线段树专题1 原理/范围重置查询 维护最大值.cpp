
// 线段树同时支持范围重置、范围查询
// 维护最大值

//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//
//int arr[MAXN];
//int mx[MAXN << 2];
//int change[MAXN << 2];
//bool update[MAXN << 2];
//
//
//void up(int i) {
//	mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
//}
//
//void lazy(int i, int v) {
//	mx[i] = v;
//	change[i] = v;
//	update[i] = true;
//}
//
//void down(int i) {
//	if (update[i]) {
//		lazy(i << 1, change[i]);
//		lazy(i << 1 | 1, change[i]);
//		update[i] = false;
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
//	change[i] = 0;
//	update[i] = false;
//}
//
//void updateRange(int jobl,int jobr,int jobv,int l,int r,int i){
//	if (jobl <= l && r <= jobr)
//		lazy(i, jobv);
//	else {
//		down(i);
//		int mid = l + ((r - l) >> 1);
//		if (jobl <= mid)
//			updateRange(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			updateRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//}
//
//int query(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return mx[i];
//	int ans = INT_MIN;
//	down(i);
//	int mid = l + ((r - l) >> 1);
//	if (jobl <= mid)
//		ans = max(ans, query(jobl, jobr, l, mid, i << 1));
//	if (jobr > mid)
//		ans = max(ans, query(jobl, jobr, mid + 1, r, i << 1 | 1));
//	
//	return ans;
//	
//}