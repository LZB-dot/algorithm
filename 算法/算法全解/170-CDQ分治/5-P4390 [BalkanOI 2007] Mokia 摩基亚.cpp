//
//
////https://www.luogu.com.cn/problem/P4390
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXM = 5e5 + 10;
//const int MAXN = 1e4 + 10;
//const int MAX = 2e6 + 10;
//
//struct Node {
//	int x, y;
//	int val;
//	int d;
//	int op;
//	int pos;
//};
//
//int n;
//Node arr[MAXM];
//int ans[MAXN];
//int cnt = 1;
//int tree[MAX];
//
//inline int lowbit(int i) {
//	return i & -i;
//}
//
//inline void add(int i, int x) {
//	while (i < MAX) {
//		tree[i] += x;
//		i += lowbit(i);
//	}
//}
//
//inline int query(int i) {
//	int ans = 0;
//	while (i >= 1) {
//		ans += tree[i];
//		i -= lowbit(i);
//	}
//	return ans;
//}
//
//void addQ(int a, int b, int i, int d) {
//	arr[cnt].x = a;
//	arr[cnt].y = b;
//	arr[cnt].pos = i;
//	arr[cnt].op = 2;
//	arr[cnt].val = 0;
//	arr[cnt++].d = d;
//}
//
//void merge(int l, int mid, int r) {
//	int i = l, j = mid + 1;
//
//	for (; j <= r; ++j) {
//		while (i <= mid && arr[i].x <= arr[j].x) {
//			if (arr[i].op == 1) 
//				add(arr[i].y, arr[i].val);
//			
//			++i;
//		}
//
//		if (arr[j].op == 2)
//			ans[arr[j].pos] += query(arr[j].y) * arr[j].d;
//	}
//
//	for (int k = l; k < i; ++k) {
//		if (arr[k].op == 1)
//			add(arr[k].y, -arr[k].val);
//	}
//
//	inplace_merge(arr + l, arr + mid + 1, arr + r + 1, [](const Node& a, const Node& b) {
//		if (a.x != b.x)
//			return a.x < b.x;
//		return a.op < b.op;
//	});
//}
//
//void cdq(int l, int r) {
//	if (l >= r)
//		return;
//
//	int mid = l + ((r - l) >> 1);
//	cdq(l, mid);
//	cdq(mid + 1, r);
//	merge(l, mid, r);
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int op, a, b, c, d;
//	cin >> op;
//
//	int t = 1;
//
//	while (op != 3) {
//		if (op == 0)
//			cin >> n;
//		else if (op == 1) {
//			cin >> a >> b >> c;
//			arr[cnt].x = a;
//			arr[cnt].y = b;
//			arr[cnt].val = c;
//			arr[cnt++].op = 1;
//		}
//		else if (op == 2) {
//			cin >> a >> b >> c >> d;
//			addQ(c, d, t, 1);
//			addQ(a - 1, b - 1, t, 1);
//			addQ(a - 1, d, t, -1);
//			addQ(c, b - 1, t, -1);
//			++t;
//		}
//		else
//			break;
//
//		cin >> op;
//	}
//
//	if (cnt > 1)
//		cdq(1, cnt - 1);
//
//	for (int i = 1; i < t; ++i)
//		cout << ans[i] << "\n";
//
//	return 0;
//}