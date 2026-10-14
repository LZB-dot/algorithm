//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<vector<int>>mp(n + 1);
//	int u, v;
//	for (int i = 0; i < n - 1; ++i) {
//		cin >> u >> v;
//		mp[u].push_back(v);
//		mp[v].push_back(u);
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		if (mp[i].size() == (n - 1)) {
//			cout << i << endl;
//			break;
//		}
//	}
//
//	return 0;
//}