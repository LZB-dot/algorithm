//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 5005;
//string s1, s2;
//int dp[MAXN][MAXN];
//int n, m, k;
//char ans[MAXN];
//
//void caldp() {
//
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			if (s1[i - 1] == s2[j - 1])
//				dp[i][j] = 1 + dp[i - 1][j - 1];
//			else
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//		}
//	}
//}
//
//void lcs() {
//	caldp();
//	k = dp[n][m];
//
//	if (k == 0)
//		return;
//
//	int len = k;
//	int i = n, j = m;
//	while (len > 0) {
//		if (s1[i - 1] == s2[j - 1]) {
//			ans[--len] = s1[i - 1];
//			i--; j--;
//		}
//		else {
//			if (dp[i - 1][j] > dp[i][j - 1])
//				i--;
//			else
//				j--;
//		}
//	}
//}
//
//int main() {
//	cin >> s1 >> s2;
//	n = s1.size();
//	m = s2.size();
//	lcs();
//	if (k == 0)
//		cout << -1 << endl;
//	else {
//		for (int i = 0; i < k; ++i)
//			cout << ans[i];
//		cout << endl;
//	}
//	return 0;
//}