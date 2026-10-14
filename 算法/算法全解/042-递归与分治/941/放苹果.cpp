//#include<iostream>
//using namespace std;
//
//int work(int m, int n) {
//	if (m == 0)
//		return 1;
//	if (n == 0)
//		return 0;
//	if (m < n) {
//		return work(m, m);
//	}
//	//至少有一个空盘子+至少有一个盘子放1个苹果
//	else {
//		return work(m, n - 1) + work(m - n, n);
//	}
//}
//
//int main() {
//
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; ++i) {
//		int m, n;
//		cin >> m >> n;
//		cout << work(m, n) << endl;
//
//	}
//	return 0;
//}