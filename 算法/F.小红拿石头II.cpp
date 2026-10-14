//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//void work() {
//	int n;
//	cin >> n;
//	vector<int>v(n, 0);
//	for (int i = 0; i < n; ++i) {
//		cin >> v[i];
//	}
//	sort(v.begin(), v.end());
//
//	int i = 0;
//	long long cnt = 0;
//	for (int i = 0; i < n; ++i) {
//		if (v[i] >= (i + 1)) {
//			cnt = i + 1;
//		}
//		else {
//			break;
//		}
//	}
//}
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		work();
//	}
//	return 0;
//}