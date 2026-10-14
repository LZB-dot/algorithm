//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int>v(n, 0);
//	for (int i = 0; i < n; ++i) {
//		cin >> v[i];
//	}
//	sort(v.begin(), v.end(), greater<int>());
//	long long ans = 0;
//	int i = 0;
//	int cnt = 0;
//	while (i != n) {
//		if (v[i] - cnt <= 0) {
//			break;
//		}
//		ans += v[i++] - cnt;
//		cnt++;
//	}
//	cout << ans << endl;
//	return 0;
//}