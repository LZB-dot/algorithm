////
//////树状数组单点增加、范围查询模版
////
////#include<iostream>
////#include<vector>
////
////using namespace std;
////
////const int MAXN = 5e5 + 10;
////int tree[MAXN];
////int n, m;
////
//////返回只有i的末位1
////inline int lowbit(int i) {
////	return i & -i;
////}
////
//////有i的和都要加上v
//////向上扩展，每次都加上自己的末位1
//////假设n=16
//////3-----00011	3 + v
//////		00100	4 + v
//////		01000	8 + v
//////		10000	16+ v
////inline void add(int i, int v) {
////	while (i <= n) {
////		tree[i] += v;
////		i += lowbit(i);
////	}
////}
////
//////向下扩展，每次都减去自己的末位1
//////15----01111	15
//////		01110	14（01110-01101 13-14）
//////		01100	12（01100-01001 9 -12）
//////		01000	8 （01000-00001	8 - 1）
//////		00000	0
////inline int sum(int i) {
////	int ans = 0;
////	while (i > 0) {
////		ans += tree[i];
////		i -= lowbit(i);
////	}
////
////	return ans;
////}
////
////inline int range(int l, int r) {
////	return sum(r) - sum(l - 1);
////}
////
////int main() {
////	ios::sync_with_stdio(false);
////	cin.tie(nullptr);
////
////	cin >> n >> m;
////	int v = 0;
////	for (int i = 1; i <= n; ++i) {
////		cin >> v;
////		add(i, v);
////	}
////
////	int a, b, c;
////	for (int i = 1; i <= m; ++i) {
////		cin >> a >> b >> c;
////		if (a == 1)
////			add(b, c);
////		else
////			cout << range(b, c) << "\n";
////	}
////
////	return 0;
////}
////
////
//
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 5e5 + 10;
//
//int tree[MAXN];
//int n, m;
//
//inline int lowbit(ll x) {
//	return x & -x;
//}
//
//inline void add(ll i, ll x) {
//	while (i <= n) {
//		tree[i] += x;
//		i += lowbit(i);
//	}
//}
//
//inline ll sum(ll i) {
//	ll sum = 0;
//	while (i > 0) {
//		sum += tree[i];
//		i -= lowbit(i);
//	}
//
//	return sum;
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m;
//
//	for (int i = 1; i <= n; ++i) {
//		int x;
//		cin >> x;
//		add(i, x);
//	}
//
//	while (m--) {
//		int op, x, y;
//		cin >> op >> x >> y;
//
//		if (op == 1)
//			add(x, y);
//		else 
//			cout << sum(y) - sum(x - 1) << "\n";
//		
//	}
//
//
//	return 0;
//}