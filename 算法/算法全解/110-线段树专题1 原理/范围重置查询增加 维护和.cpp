//#include<iostream>
//#include<vector>
//#include<climits>  
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//
//const int maxn = 1e5 + 10;
//
//int arr[maxn];
//ll sum[maxn << 2];
//ll change[maxn << 2], add[maxn << 2];
//bool updatetag[maxn << 2];  
//
//
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//
//void lazyupdate(int i, ll v, int n) {
//	sum[i] = v * n;
//	change[i] = v;
//	updatetag[i] = true;
//	add[i] = 0;  
//}
//
//void lazyadd(int i, ll v, int n) {
//	sum[i] += v * n;
//	add[i] += v;
//}
//
//void down(int i, int ln, int rn) {
//	if (updatetag[i]) {
//		lazyupdate(i << 1, change[i], ln);
//		lazyupdate(i << 1 | 1, change[i], rn);
//		updatetag[i] = false;
//	}
//	if (add[i] != 0) {
//		lazyadd(i << 1, add[i], ln);
//		lazyadd(i << 1 | 1, add[i], rn);
//		add[i] = 0;
//	}
//}
//
//void build(int l, int r, int i) {
//	if (l == r)
//		sum[i] = arr[l];
//	else {
//		int mid = l + ((r - l) >> 1);
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//	change[i] = 0;
//	updatetag[i] = false;
//	add[i] = 0;
//}
//
//void updaterange(int jobl, int jobr, int jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazyupdate(i, jobv, r - l + 1);
//	else {
//		int mid = l + ((r - l) >> 1);
//		down(i, mid - l + 1, r - mid);
//
//		if (jobl <= mid)
//			updaterange(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			updaterange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//}
//
//void addrange(int jobl, int jobr, ll jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr) {
//		lazyadd(i, jobv, r - l + 1);
//	}
//	else {
//		int mid = (l + r) >> 1;
//		down(i, mid - l + 1, r - mid);
//		if (jobl <= mid)
//			addrange(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			addrange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
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
//
//	if (jobl <= mid)
//		ans += query(jobl, jobr, l, mid, i << 1); 
//	if (jobr > mid)
//		ans += query(jobl, jobr, mid + 1, r, i << 1 | 1); 
//
//	return ans;
//}