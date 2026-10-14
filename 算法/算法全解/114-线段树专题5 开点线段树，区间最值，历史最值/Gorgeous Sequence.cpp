//#include<iostream>
//#include<vector>
//#include <climits>
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 1e6 + 10;
//const int LIMIT = INT_MIN;
//
//int arr[MAXN];
//ll sum[MAXN << 2];
//int mx[MAXN << 2], sem[MAXN << 2];
//int cnt[MAXN << 2];
//
//
//void up(int i) {
//	int l = i << 1;
//	int r = i << 1 | 1;
//
//	sum[i] = sum[l] + sum[r];
//	mx[i] = max(mx[l], mx[r]);
//
//	if (mx[l] > mx[r]) {
//		cnt[i] = cnt[l];
//		sem[i] = max(sem[l], mx[r]);
//	}
//	else if (mx[l] == mx[r]) {
//		cnt[i] = cnt[l] + cnt[r];
//		sem[i] = max(sem[l], sem[r]);
//	}
//	else {
//		cnt[i] = cnt[r];
//		sem[i] = max(mx[l], sem[r]);
//	}
//}
//
//void lazy(int i, int v) {
//	if (v < mx[i]) {
//		sum[i] -= 1LL * cnt[i] * (mx[i] - v);
//		mx[i] = v;
//	}
//}
//
//void down(int i) {
//	lazy(i << 1, mx[i]);
//	lazy(i << 1 | 1, mx[i]);
//}
//
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = arr[l];
//		mx[i] = arr[l];
//		sem[i] = LIMIT;
//		cnt[i] = 1;
//	}
//	else {
//		int mid = l + ((r - l) >> 1);
//		build(l, mid, i << 1);
//		build(mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//}
//
//void setMin(int jobl, int jobr, int jobv, int l, int r, int i) {
//	if (jobv >= mx[i])
//		return;
//
//	if (jobl <= l && r <= jobr && sem[i] < jobv)
//		lazy(i, jobv);
//	else {
//		down(i);
//		int mid = l + ((r - l) >> 1);
//		if (jobl <= mid)
//			setMin(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			setMin(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//
//		up(i);
//	}
//}
//
//int queryMax(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return mx[i];
//
//	down(i);
//	int mid = l + ((r - l) >> 1);
//	int ans = INT_MIN;
//
//	if (jobl <= mid)
//		ans = max(ans, queryMax(jobl, jobr, l, mid, i << 1));
//	if (jobr > mid)
//		ans = max(ans, queryMax(jobl, jobr, mid + 1, r, i << 1 | 1));
//
//	return ans;
//}
//
//ll querySum(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return sum[i];
//	down(i);
//	int mid = (l + r) >> 1;
//	long long ans = 0;
//	if (jobl <= mid) {
//		ans += querySum(jobl, jobr, l, mid, i << 1);
//	}
//	if (jobr > mid) {
//		ans += querySum(jobl, jobr, mid + 1, r, i << 1 | 1);
//	}
//	return ans;
//}
//
//inline int read() {
//	int num = 0;
//	char c;
//
//	while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
//
//	bool flag = 0;
//	if (c == '-')
//		flag = 1;
//	else
//		num = c - '0';
//
//	while (isdigit(c = getchar()))
//		num = num * 10 + c - '0';
//
//	return flag ? -num : num;
//}
//
//int main() {
//	int T = read();
//	while (T--) {
//		int n = read(), m = read();
//		for (int i = 1; i <= n; ++i) arr[i] = read();
//		build(1, n, 1);
//
//		while (m--) {
//			int op = read();
//			int x = read(), y = read();
//			if (op == 0) {
//				int t = read();
//				setMin(x, y, t, 1, n, 1);
//			}
//			else if (op == 1) {
//				cout << queryMax(x, y, 1, n, 1) << "\n";
//			}
//			else {
//				cout << querySum(x, y, 1, n, 1) << '\n';
//			}
//		}
//	}
//	return 0;
//}