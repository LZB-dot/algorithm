//
////https://www.luogu.com.cn/problem/P2163
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 5e5 * 5 + 10;
//
//struct Node {
//	int x, y;
//	int op;
//	int d;
//	int p;
//};
//
//int n, m;
//Node arr[MAXN];
//int cnt = 0;
//int ans[MAXN];
//
//void addQ(int x, int y, int d, int i) {
//	arr[++cnt].x = x;
//	arr[cnt].y = y;
//	arr[cnt].d = d;
//	arr[cnt].p = i;
//	arr[cnt].op = 2;
//}
//
//void merge(int l, int mid, int r) {
//
//	int i = l, j = mid + 1;
//	int tree = 0;
//
//	for (; j <= r; ++j) {
//		while (i <= mid && arr[i].y <= arr[j].y) {
//			if(arr[i].op==1)
//				++tree;
//			++i;
//		}
//
//		if (arr[j].op == 2)
//			ans[arr[j].p] += tree * arr[j].d;
//	}
//
//	//原本两个数组已经有序 合并成一个数组
//	inplace_merge(arr + l, arr + mid + 1, arr + r + 1, [](const Node& tx, const Node& ty) {
//		return tx.y < ty.y;
//	});
//}
//
//void cdq(int l, int r) {
//	if (l == r)
//		return;
//
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
//	for (int i = 1; i <= n; ++i) {
//		int x, y;
//		cin >> x >> y;
//
//		arr[++cnt].x = x;
//		arr[cnt].y = y;
//		arr[cnt].op = 1;
//	}
//
//	for (int i = 1; i <= m; ++i) {
//		int a, b, c, d;
//		cin >> a >> b >> c >> d;
//		addQ(c, d, 1, i);
//		addQ(a - 1, b - 1, 1, i);
//		addQ(a - 1, d, -1, i);
//		addQ(c, b - 1, -1, i);
//	}
//
//	sort(arr + 1, arr + cnt + 1, [&](Node& tx, Node& ty) {
//		if (tx.x != ty.x)
//			return tx.x < ty.x;
//
//		return tx.op < ty.op;
//	});
//
//
//	cdq(1, cnt);
//
//	for (int i = 1; i <= m; ++i)
//		cout << ans[i] << "\n";
//
//	return 0;
//}