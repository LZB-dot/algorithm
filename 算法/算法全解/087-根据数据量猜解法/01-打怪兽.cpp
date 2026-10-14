////
////
//////能力的范围大，金钱范围小
////
////#include<iostream>
////#include<vector>
////#include<climits>
////using namespace std;
////
////int n, m = 0;
////vector<vector<int>>dp;
////vector<int>ability, money;
////
//////dp：i个怪兽，花费金钱j的能力
////int compute(){
////	dp.resize(n + 1, vector<int>(m + 1, INT_MIN));
////	dp[0][0] = 0;
////	for (int i = 1; i <= n; ++i) {
////		for (int j = 0; j <= m; ++j) {
////			if (dp[i - 1][j] != INT_MIN && dp[i - 1][j] >= ability[i - 1]) {
////				dp[i][j] = dp[i - 1][j];
////			}
////			if (j >= money[i - 1] && dp[i - 1][j - money[i - 1]] != INT_MIN) {
////				dp[i][j] = max(dp[i][j], dp[i - 1][j - money[i - 1]] + ability[i - 1]);
////			}
////		}
////	}
////
////	int ans = -1;
////	for (int j = 0; j <= m; ++j) {
////		if (dp[n][j] != INT_MIN) {
////			ans = j;
////			break;
////		}
////	}
////
////	return ans;
////}
////
////int main() {
////	cin >> n;
////	ability.resize(n, 0);
////	money.resize(n, 0);
////	for (int i = 0; i < n; ++i){
////		cin >> ability[i] >> money[i];
////		m += money[i];
////	}
////	cout << compute() << endl;
////	return 0;
////}
//
//
//
//
////能力的范围大，金钱范围小
//
//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int n, m = 0;
//vector<int>dp;
//vector<int>ability, money;
//
////dp：i个怪兽，花费金钱j的能力
//int compute() {
//	dp.resize(m + 1, INT_MIN);
//	dp[0] = 0;
//	for (int i = 0; i < n; ++i) {
//		for (int j = m; j >= 0; --j) {
//			int cur = INT_MIN;
//			if (dp[j] != INT_MIN && dp[j] >= ability[i])
//				cur = dp[j];
//			if (j >= money[i] && dp[j - money[i]] != INT_MIN)
//				cur = max(cur, dp[j - money[i]] + ability[i]);
//			dp[j] = cur;
//		}
//	}
//
//	int ans = -1;
//	for (int j = 0; j <= m; ++j) {
//		if (dp[j] != INT_MIN) {
//			ans = j;
//			break;
//		}
//	}
//
//	return ans;
//}
//
//int main() {
//	cin >> n;
//	ability.resize(n, 0);
//	money.resize(n, 0);
//	for (int i = 0; i < n; ++i) {
//		cin >> ability[i] >> money[i];
//		m += money[i];
//	}
//	cout << compute() << endl;
//	return 0;
//}