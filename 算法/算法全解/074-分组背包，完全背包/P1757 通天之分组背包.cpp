//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//const int MAXM = 1e4 + 10;
//int dp[MAXM];
//
//struct object{
//	int weight;
//	int value;
//	int group;
//};
//
//int main() {
//	int m, n;
//	cin >> m >> n;
//	vector<object>ob(n + 1);
//	for (int i = 1; i <= n; ++i) {
//		cin >> ob[i].weight >> ob[i].value >> ob[i].group;
//	}
//	sort(ob.begin(), ob.end(),
//		[](const object& a, const object& b) {
//			return a.group < b.group;
//		});
//
//	int start = 1;
//	while (start <= n) {
//		int end = start;
//		while (end + 1 <= n && ob[start].group == ob[end + 1].group) {
//			end++;
//		}
//		int tmp[MAXM];
//		memcpy(tmp, dp, sizeof(dp));
//		for (int j = m; j >= 0; --j) {
//			for (int i = start; i <= end; ++i) {
//				if (j >= ob[i].weight) {
//					dp[j] = max(dp[j], tmp[j - ob[i].weight] + ob[i].value);
//				}
//			}
//		}
//		start = end + 1;
//	}
//	cout << dp[m] << endl;
//	return 0;
//}