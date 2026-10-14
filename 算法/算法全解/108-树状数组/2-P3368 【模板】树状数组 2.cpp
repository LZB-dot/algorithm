////
//////树状数组范围增加、单点查询模版
////
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 5e5 + 10;
//int n, m;
//
//int tdiff[MAXN];
//
//inline int lowbit(int x) {
//	return x & -x;
//}
//
//inline void add(int i, int x) {
//	while (i <= n) {
//		tdiff[i] += x;
//		i += lowbit(i);
//	}
//}
//
//inline int sum(int i) {
//	int ans = 0;
//
//	while (i >= 1) {
//		ans += tdiff[i];
//		i -= lowbit(i);
//	}
//
//	return ans;
//}
//
//int main() {
//	cin >> n >> m;
//
//	int a;
//	for (int i = 1; i <= n; ++i) {
//		cin >> a;
//		add(i, a);
//		add(i + 1, -a);
//	}
//
//	while (m--) {
//		int op;
//		cin >> op;
//
//		if (op == 1) {
//			int x, y, k;
//			cin >> x >> y >> k;
//
//			add(x, k);
//			add(y + 1, -k);
//		}
//		else {
//			int x;
//			cin >> x;
//			cout << sum(x) << "\n";
//		}
//	}
//
//	return 0;
//}