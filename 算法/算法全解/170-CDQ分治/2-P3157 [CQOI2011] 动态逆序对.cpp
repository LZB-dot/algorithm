//
////https://www.luogu.com.cn/problem/P3157
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 1e5 + 10;
//const int MAXM = 5e4 + 10;
//
//// val: 数组的值
//// i: 元素在原始序列的位置pos
//// d: 修改量 +1添加 / -1删除
//// t: 时间戳，0代表永不删除，1~m代表第t次删除
//struct Node {
//	int val;
//	int i;
//	int d;
//	int t;
//};
//
//int n, m;
//int a[MAXN];     //原始位置pos上的值
//int pos[MAXN];   //值v所在的原始下标
//int del[MAXM];   //第k次删除的数字v
//int tree[MAXN];
//Node arr[MAXN + MAXM];
//
//int cnt = 0;
//ll ans[MAXM];    //记录第k次删除减少的逆序对数量
//
//bool cmp(Node x, Node y) {
//	return x.i < y.i;
//}
//
//inline int lowbit(int i) {
//	return i & -i;
//}
//
//inline void add(int i, int x) {
//	while (i <= n) {
//		tree[i] += x;
//		i += lowbit(i);
//	}
//}
//
//inline int sum(int i) {
//	int res = 0;
//	while (i > 0) {
//		res += tree[i];
//		i -= lowbit(i);
//	}
//	return res;
//}
//
//void prepare() {
//	cnt = 0;
//
//	for (int i = 1; i <= n; ++i) {
//		arr[++cnt].val = a[i];
//		arr[cnt].i = i;
//		arr[cnt].d = 1;
//		arr[cnt].t = 0;
//	}
//
//	for (int k = 1; k <= m; ++k) {
//		int v = del[k];
//		arr[++cnt].val = v;
//		arr[cnt].i = pos[v];
//		arr[cnt].d = -1;
//		arr[cnt].t = k;
//	}
//}
//
//
//void merge(int l, int mid, int r) {
//	int i = l;
//
//	for (int j = mid + 1; j <= r; ++j) {
//		while (i <= mid && arr[i].i < arr[j].i) {
//			add(arr[i].val, arr[i].d);
//			++i;
//		}
//
//		ans[arr[j].t] += 1LL * arr[j].d * (sum(n) - sum(arr[j].val));
//	}
//
//	for (int p = l; p < i; p++)
//		add(arr[p].val, -arr[p].d);
//
//
//	i = mid;
//
//	for (int j = r; j > mid; j--) {
//		while (i >= l && arr[i].i > arr[j].i) {
//			add(arr[i].val, arr[i].d);
//			--i;
//		}
//
//		ans[arr[j].t] += 1LL * arr[j].d * sum(arr[j].val - 1);
//	}
//
//	for (int p = mid; p > i; p--)
//		add(arr[p].val, -arr[p].d);
//
//
//	sort(arr + l, arr + r + 1, cmp);
//}
//
//void cdq(int l, int r) {
//	if (l == r)
//		return;
//	int mid = l + (r - l >> 1);
//	cdq(l, mid);
//	cdq(mid + 1, r);
//	merge(l, mid, r);
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m;
//
//
//	for (int i = 1; i <= n; ++i) {
//		cin >> a[i];
//		pos[a[i]] = i;
//	}
//
//	for (int i = 1; i <= m; ++i)
//		cin >> del[i];
//
//	prepare();
//	cdq(1, cnt);
//
//	ll total = ans[0];
//	for (int i = 1; i <= m; i++) {
//		cout << total << '\n';
//		total += ans[i];
//	}
//
//
//	return 0;
//}
//
//
//
