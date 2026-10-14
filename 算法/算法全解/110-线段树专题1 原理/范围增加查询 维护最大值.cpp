//// 线段树支持范围增加、范围查询
//// 维护最大值
//// 对数器验证
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 1e5 + 10;
//ll arr[MAXN];
//ll mx[MAXN << 2];
//ll increase[MAXN << 2];
//
//void up(int i) {
//	mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
//}
//
//void lazy(int i, ll v) {
//	mx[i] += v;
//	increase[i] += v;
//}
//
//void down(int i) {
//	if (increase[i]) {
//		lazy(i << 1, increase[i]);
//		lazy(i << 1 | 1, increase[i]);
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
//}
//
//void add(int jobl, int jobr, int jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		lazy(i, jobv);
//	else {
//		down(i);
//		int mid = l + ((r - l) >> 1);
//		if (jobl <= mid)
//			add(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			add(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//}
//
//ll query(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return mx[i];
//
//	down(i);
//	int mid = l + ((r - l) >> 1);
//
//	ll ans = LLONG_MIN;
//	if (jobl <= mid)
//		ans = max(ans, query(jobl, jobr, l, mid, i << 1));
//	if (jobr > mid)
//		ans = max(ans, query(jobl, jobr, mid + 1, r, i << 1 | 1));
//
//	return ans;
//}
//
//void getArray(int n, int v) {
//	for (int i = 1; i <= n; ++i)
//		arr[i] = rand() % v;
//}
//
//void checkAdd(ll check[], int jobl, int jobr, int jobv) {
//	for (int i = jobl; i <= jobr; ++i)
//		check[i] += jobv;
//}
//
//ll checkQuery(ll check[], int jobl, int jobr) {
//	ll ans = LLONG_MIN;
//	for (int i = jobl; i <= jobr; ++i) 
//		ans = max(ans, check[i]);
//	return ans;
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n = 1000;
//	int v = 5000;
//	int t = 50000;
//
//	getArray(n, v);
//	build(1, n, 1);
//
//	ll check[1005];
//	for (int i = 1; i <= n; ++i)
//		check[i] = arr[i];
//
//	while (t--) {
//		int op = rand() % 2;
//		int a = rand() % n + 1;
//		int b = rand() % n + 1;
//
//		int jobl = min(a, b);
//		int jobr = max(a, b);
//
//		if (op == 0) {
//			ll jobv = (rand() % (2 * v)) - v;
//			add(jobl, jobr, jobv, 1, n, 1);
//			checkAdd(check, jobl, jobr, jobv);
//		}
//		else {
//			ll ans1 = query(jobl, jobr, 1, n, 1);
//			ll ans2 = checkQuery(check, jobl, jobr);
//			if (ans1 != ans2) {
//				cout << "出错了！" << endl;
//				return 0;
//			}
//		}
//	}
//	cout << "你的代码完全正确\n";
//	return 0;
//}