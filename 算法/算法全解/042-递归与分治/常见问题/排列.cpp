//#include<iostream>
//
//using namespace std;
//
//const int MAXN = 1e5 + 1;
//int a[MAXN], b[MAXN], p[MAXN], ans[MAXN];
//
//bool check(int n, int k) {
//	int saved = p[1];
//	for (int i = 2; i <= n; ++i) {
//		if (a[p[i]] >= a[saved] && b[p[i]] >= b[saved])
//			saved = p[i];
//	}
//	if (saved == k)
//		return 1;
//	return 0;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d %d", &a[i], &b[i]);
//	}
//
//
//}