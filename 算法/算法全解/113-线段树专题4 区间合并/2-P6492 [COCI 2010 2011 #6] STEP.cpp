//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//const int MAXN = 2e5 + 10;
//
////0-L	1-R
//int arr[MAXN];
//int len[MAXN << 2], pre[MAXN << 2], suf[MAXN << 2];
//
//void up(int l, int r, int i) {
//
//	int mid = l + ((r - l) >> 1);
//	int ln = mid - l + 1, rn = r - mid;
//
//	len[i] = max(len[i << 1], len[i << 1 | 1]);
//	pre[i] = pre[i << 1];
//	suf[i] = suf[i << 1 | 1];
//
//	if (arr[mid] != arr[mid + 1]) {
//		len[i] = max(len[i], suf[i << 1] + pre[i << 1 | 1]);
//		pre[i] = len[i << 1] == ln ? pre[i << 1] + pre[i << 1 | 1] : pre[i << 1];
//		suf[i] = suf[i << 1 | 1] == rn ? suf[i << 1 | 1] + suf[i << 1] : suf[i << 1 | 1];
//	}
//}
//
//void build(int l, int r, int i) {
//	if (l == r)
//		len[i] = pre[i] = suf[i] = 1;
//	else {
//		int mid = l + ((r - l) >> 1);
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(l, r, i);
//	}
//}
//
//void rever(int jobi, int l, int r, int i) {
//	if (l == r) {
//		arr[jobi] ^= 1;
//		return;
//	}
//
//	int mid = l + ((r - l) >> 1);
//	if (jobi <= mid)
//		rever(jobi, l, mid, i << 1);
//	else
//		rever(jobi, mid + 1, r, i << 1 | 1);
//
//	up(l, r, i);
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
//	int x;
//	while (m--) {
//		cin >> x;
//		rever(x, 1, n, 1);
//		cout << len[1] << "\n";
//	}
//
//	return 0;
//}


//https://www.luogu.com.cn/problem/P6492
