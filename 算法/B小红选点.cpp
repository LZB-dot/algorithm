//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<pair<int, int>>v(n);
//	for (int i = 0; i < n; ++i) {
//		cin >> v[i].first >> v[i].second;
//	}
//
//	if (n == 1) {
//		// 只有一个点时，输出该点两次
//		cout << v[0].first << " " << v[0].second << " "
//			<< v[0].first << " " << v[0].second << endl;
//		return 0;
//	}
//	int x1, y1, x2, y2;
//	int ans = 0;
//	for (int i = 0; i < n; ++i) {
//		for (int j = i; j < n; ++j) {
//			int dx = v[i].first - v[j].first;
//			int dy = v[i].second - v[j].second;
//			long long tmp = dx * dx + dy * dy;
//			if (tmp > ans) {
//				ans = tmp;
//				x1 = v[i].first;
//				x2 = v[j].first;
//				y1 = v[i].second;
//				y2 = v[j].second;
//			}
//
//		}
//	}
//
//	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
//	return 0;
//}