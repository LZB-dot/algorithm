//#define _CRT_SECURE_NO_WARNINGS
//
//#include<iostream>
//#include<cstdio>
//#include<queue>
//using namespace std;
//
//struct index{
//	int x1, y1, x2, y2;
//};
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	index arr[10000];
//
//	for (int i = 0; i < n; ++i) {
//		int a, b, x, y;
//		scanf("%d%d%d%d", &a, &b, &x, &y);
//		arr[i].x1 = a;
//		arr[i].y1 = b;
//		arr[i].x2 = a + x;
//		arr[i].y2 = b + y;
//	}
//	int c, d;
//	scanf("%d %d", &c, &d);
//
//	bool flag = 1;
//	for (int i = n - 1; i >= 0; --i) {
//		if (c >= arr[i].x1 && c <= arr[i].x2
//			&& d >= arr[i].y1 && d <= arr[i].y2) {
//			cout << i + 1 << endl;
//			return 0;
//		}
//	}
//	return 0;
//}