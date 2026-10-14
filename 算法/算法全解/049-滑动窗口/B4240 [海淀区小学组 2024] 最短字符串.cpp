//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int main() {
//
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	string s;
//	cin >> s;
//
//	bool has[128] = { false };
//	int total = 0;
//	for (char c : s) {
//		if (!has[(int)c]) {
//			has[(int)c] = true;
//			total++;
//		}
//	}
//
//	int l = 0;
//	int freq[128] = { 0 };
//	int cnt = 0;
//	int ans = INT_MAX;
//	for (int r = 0; r < n; ++r) {
//		int t = (int)s[r];
//		if (freq[t] == 0)
//			cnt++;
//		freq[t]++;
//
//		while (total == cnt) {
//			ans = min(ans, r - l + 1);
//
//			int cur = (int)s[l];
//			if (--freq[cur] == 0)
//				cnt--;
//
//			++l;
//		}
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}