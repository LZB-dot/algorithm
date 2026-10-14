//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//int st[MAXN];
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//	vector<int>high(n + 1);
//	for (int i = 1; i <= n; ++i)
//		cin >> high[i];
//
//
//	int r = 0;
//	vector<int>ans(n + 1, 0);
//	for (int i = 1; i <= n; ++i) {
//		
//		while (r > 0 && high[i] > high[st[r - 1]]) {
//			ans[st[--r]] = i;
//		}
//
//		st[r++] = i;
//	}
//
//	for (int i = 1; i <= n; ++i)
//		cout << ans[i] << "\n";
//
//	return 0;
//}