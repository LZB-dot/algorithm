//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//const int MAXN = 2e5 + 5;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//	while (n--) {
//		int s;
//		cin >> s;
//		vector<int>a(s);
//		for (int i = 0; i < s; ++i) {
//			cin >> a[i];
//		}
//		int ans = INT_MIN;
//		for (int i = 0; i + 1 < s; ++i) {
//			int x1 = a[i], x2 = a[i + 1];
//			int mex = 0;
//			if (x1 == 0 || x2 == 0) {
//				mex++;
//				if (x1 == 1 || x2 == 1)
//					mex++;
//			}
//			int tmp = max(x1, x2);
//			ans = max(ans, tmp - mex);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}