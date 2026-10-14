//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//
//int start[MAXN << 2];
//int ed[MAXN << 2];
//
//void up(int i) {
//	start[i] = start[i << 1] + start[i << 1 | 1];
//	ed[i] = ed[i << 1] + ed[i << 1 | 1];
//}
//
////t=1 开始端点		0 结束端点
//void add(int t,int jobi,int l, int r, int i) {
//	if (l == r) {
//		if (t == 1)
//			start[i]++;
//		else
//			ed[i]++;
//	}
//	else {
//		int mid = l + ((r - l) >> 1);
//		if (jobi <= mid)
//			add(t, jobi, l, mid, i << 1);
//		else
//			add(t, jobi, mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
//}
//
//int query(int t,int jobr, int l, int r, int i) {
//	if (r <= jobr) {
//		if (t == 1)
//			return start[i];
//		else
//			return ed[i];
//	}
//	int ans = 0;
//	int mid = l + ((r - l) >> 1);
//	if (jobr > mid)
//		ans = query(t, jobr, l, mid, i<<1) + query(t, jobr, mid + 1, r, i << 1 | 1);
//	else
//		ans = query(t, jobr, l, mid, i<<1);
//
//	return ans;
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, m;
//	cin >> n >> m;
//	int q, l, r;
//	while (m--) {
//		cin >> q >> l >> r;
//		if (q == 1) {
//			add(1, l, 1, n, 1);
//			add(0, r, 1, n, 1);
//		}
//		else {
//			int s = query(1, r, 1, n, 1);
//			int e = query(0, l - 1, 1, n, 1);
//			cout << s - e << "\n";
//		}
//			
//	}
//
//	
//	return 0;
//}
