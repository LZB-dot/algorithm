//#include<iostream>
//#include<vector>
//using namespace std;
//
//int ans = 0;
//
//void work(int n,int m,int last, vector<int>&path) {
//	if (m == 0) {
//		cout << n << "=" << path[0];
//		for (int i = 1; i < path.size(); ++i) {
//			cout << "+" << path[i];
//		}
//		cout << endl;
//		ans++;
//		return;
//	}
//	for (int i = last; i <= m && i < n; ++i) {
//		path.push_back(i);
//		work(n, m - i, i, path);
//		path.pop_back();
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
//	vector<int>path;
//	work(n, n, 1, path);
//	cout << "total=" << ans << endl;
//	return 0;
//}