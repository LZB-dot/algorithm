//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 2e6 + 5;
//bool open[MAXN];
//
//int main() {
//	int n;
//	cin >> n;
//
//	double a;
//	int t;
//	while (n--) {
//		cin >> a >> t;
//		while (t) {
//			int cur = (int)(a * t);
//			open[cur] = !open[cur];
//			--t;
//		}
//	}
//	for (int i = 1; i <= MAXN; ++i)
//		if (open[i]) {
//			cout << i << "\n";
//			return 0;
//		}
//
//	return 0;
//}