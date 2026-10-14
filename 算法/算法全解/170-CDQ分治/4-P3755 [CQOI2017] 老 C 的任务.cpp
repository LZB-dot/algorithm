//
//
////https://www.luogu.com.cn/problem/P3755
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
//const int MAXN = 1e5 + 10;
//
//
//struct Node{
//	int x, y;
//	int op;
//	int val;
//	int pos;
//	int d;
//};
//
//int n, m;
//Node arr[MAXN * 5];
//int cnt = 1;
//ll ans[MAXN];
//
//void add(int x, int y,int d, int pos) {
//	arr[cnt].x = x;
//	arr[cnt].y = y;
//	arr[cnt].d = d;
//	arr[cnt].op = 2;
//	arr[cnt++].pos = pos;
//}
//
//void merge(int l, int mid, int r) {
//	int i = l, j = mid + 1;
//	ll sum = 0;
//
//	for (; j <= r; ++j) {
//		while (i <= mid && arr[i].y <= arr[j].y) {
//			sum += arr[i].val;
//			++i;
//		}
//		
//		if (arr[j].op == 2)
//			ans[arr[j].pos] += sum * arr[j].d;
//	}
//
//	inplace_merge(arr + l, arr + mid + 1, arr + r + 1, [&](const Node& a, const Node& b) {
//		return a.y < b.y;
//	});
//}
//
//void cdq(int l, int r) {
//	if (l == r)
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
//	cin >> n >> m;
//
//	for (int i = 1; i <= n; ++i) {
//		int x, y, v;
//		cin >> x >> y >> v;
//
//		arr[cnt].x = x;
//		arr[cnt].y = y;
//		arr[cnt].op = 1;
//		arr[cnt].d = 1;
//		arr[cnt].val = v;
//		arr[cnt++].pos = 1;
//	}
//
//	for (int i = 1; i <= m; ++i) {
//		int a, b, c, d;
//		cin >> a >> b >> c >> d;
//
//		add(c, d, 1, i);
//		add(a - 1, b - 1, 1, i);
//		add(a - 1, d, -1, i);
//		add(c, b-1, -1, i);
//	}
//
//	sort(arr + 1, arr + cnt + 1, [&](const Node& a, const Node& b) {
//		if (a.x != b.x)
//			return a.x < b.x;
//		return a.op < b.op;
//	});
//
//	cdq(1, cnt);
//
//	for (int i = 1; i <= m; ++i)
//		cout << ans[i] << "\n";
//
//	return 0;
//}
