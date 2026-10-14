//// 范围重置 + 范围查询求和
//// 统一函数名、结构、写法
//// 对数器验证 100% 正确
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 100005;
//
//ll arr[MAXN];
//ll sum[MAXN << 2];
//ll change[MAXN << 2];
//bool update[MAXN << 2];
//
//// 统一函数名：up
//void up(int i) {
//	sum[i] = sum[i << 1] + sum[i << 1 | 1];
//}
//
//// 统一函数名：lazy（打重置标记）
//void lazy(int i, ll v, int n) {
//	sum[i] = v * n;
//	change[i] = v;
//	update[i] = true;
//}
//
//// 统一函数名：down
//void down(int i, int ln, int rn) {
//	if (update[i]) {
//		lazy(i << 1, change[i], ln);
//		lazy(i << 1 | 1, change[i], rn);
//		update[i] = false;
//	}
//}
//
//// 统一函数名：build
//void build(int l, int r, int i) {
//	if (l == r) {
//		sum[i] = arr[l];
//	}
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
//// 统一函数名：update（区间重置）
//// 函数名和区间加的 add 对应，结构完全一致
//void updateRange(int jobl, int jobr, ll jobv, int l, int r, int i) {
//	if (jobl <= l && r <= jobr) {
//		lazy(i, jobv, r - l + 1);
//	}
//	else {
//		int mid = l + ((r - l) >> 1);
//		down(i, mid - l + 1, r - mid);
//		if (jobl <= mid)
//			updateRange(jobl, jobr, jobv, l, mid, i << 1);
//		if (jobr > mid)
//			updateRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
//		up(i);
//	}
//}
//
//// 统一函数名：query
//ll query(int jobl, int jobr, int l, int r, int i) {
//	if (jobl <= l && r <= jobr)
//		return sum[i];
//
//	int mid = l + ((r - l) >> 1);
//	down(i, mid - l + 1, r - mid);
//	ll ans = 0;
//
//	if (jobl <= mid)
//		ans += query(jobl, jobr, l, mid, i << 1);
//	if (jobr > mid)
//		ans += query(jobl, jobr, mid + 1, r, i << 1 | 1);
//
//	return ans;
//}
//
//// ==================== 对数器 ====================
//void randomArray(int n, int v) {
//	for (int i = 1; i <= n; ++i)
//		arr[i] = rand() % v;
//}
//
//void checkUpdate(ll check[], int jobl, int jobr, ll jobv) {
//	for (int i = jobl; i <= jobr; ++i)
//		check[i] = jobv;
//}
//
//ll checkQuery(ll check[], int jobl, int jobr) {
//	ll ans = 0;
//	for (int i = jobl; i <= jobr; ++i)
//		ans += check[i];
//	return ans;
//}
//
//int main() {
//	srand(time(0));
//
//	int n = 1000;
//	int v = 2000;
//	int t = 500000;
//
//	randomArray(n, v);
//	build(1, n, 1);
//
//	ll check[1001];
//	for (int i = 1; i <= n; ++i)
//		check[i] = arr[i];
//
//	while (t--) {
//		int op = rand() % 2;
//		int a = rand() % n + 1;
//		int b = rand() % n + 1;
//		int jobl = min(a, b);
//		int jobr = max(a, b);
//
//		if (op == 0) {
//			ll jobv = rand() % (2 * v) - v;
//			updateRange(jobl, jobr, jobv, 1, n, 1);
//			checkUpdate(check, jobl, jobr, jobv);
//		}
//		else {
//			ll ans1 = query(jobl, jobr, 1, n, 1);
//			ll ans2 = checkQuery(check, jobl, jobr);
//			if (ans1 != ans2) {
//				cout << "出错了！\n";
//				return 0;
//			}
//		}
//	}
//
//	cout << "测试通过，代码完全正确！\n";
//	return 0;
//}