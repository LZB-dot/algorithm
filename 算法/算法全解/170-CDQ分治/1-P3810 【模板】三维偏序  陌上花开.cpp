////https://www.luogu.com.cn/problem/P3810
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//struct Node {
//	int i, a, b, c;
//};
//
//bool cmp(Node x, Node y) {
//	if (x.a != y.a)
//		return x.a < y.a;
//
//	if (x.b != y.b)
//		return x.b < y.b;
//
//	return x.c < y.c;
//}
//
//
//const int MAXN = 1e5 + 10;
//const int MAXM = 2e5 + 10;
//
//int n, k;
//Node arr[MAXN];
//int tree[MAXM]; 
//int f[MAXN], ans[MAXN];
//
//inline int lowbit(int i) {
//	return i & -i;
//}
//
//inline void add(int i, int x) {
//	while (i <= k) { 
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
//void merge(int l, int m, int r) {
//	int i = l;
//
//	for (int j = m + 1; j <= r; ++j) {
//		while (i <= m && arr[i].b <= arr[j].b) {
//			add(arr[i].c, 1);
//			++i;
//		}
//		f[arr[j].i] += sum(arr[j].c);
//	}
//
//
//	for (int p = l; p < i; ++p)
//		add(arr[p].c, -1);
//
//	sort(arr + l, arr + r + 1, [](const Node& x, const Node& y) {
//		return x.b < y.b;
//	});
//}
//
//void cdq(int l, int r) {
//	if (l == r)
//		return;
//
//	int mid = l + ((r - l) >> 1);
//
//	cdq(l, mid);
//	cdq(mid + 1, r);
//	merge(l, mid, r);
//}
//
//void prepare() {
//	sort(arr + 1, arr + 1 + n, cmp);
//	int r;
//	for (int l = 1; l <= n; l = r + 1) { 
//		r = l;
//		while (r + 1 <= n && arr[l].a == arr[r + 1].a && arr[l].b == arr[r + 1].b && arr[l].c == arr[r + 1].c) 
//			r++;
//		
//
//		for (int i = l; i <= r; i++) 
//			f[arr[i].i] = r - i;
//		
//	}
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> k;
//
//	for (int idx = 1; idx <= n; idx++) {
//		cin >> arr[idx].a >> arr[idx].b >> arr[idx].c;
//		arr[idx].i = idx; 
//	}
//
//	prepare();
//	cdq(1, n);
//
//	for (int i = 1; i <= n; i++) 
//		ans[f[i]]++;
//	
//
//	for (int d = 0; d < n; d++) 
//		cout << ans[d] << '\n';
//	
//	return 0;
//}
