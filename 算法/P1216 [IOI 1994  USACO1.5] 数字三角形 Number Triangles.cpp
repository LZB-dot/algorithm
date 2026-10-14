//
////#include<iostream>
////#include<vector>
////using namespace std;
////
////
////
////int main() {
////
////	int r;
////	cin >> r;
////	vector<vector<int>>dp(r + 1, vector<int>(r + 1, 0));
////	vector<vector<int>>mp(r, vector<int>(r, 0));
////
////	for (int i = 0; i < r; ++i) {
////		for (int j = 0; j <= i; ++j)
////			cin >> mp[i][j];
////	}
////
////	for (int j = 0; j < r; ++j)
////		dp[r - 1][j] = mp[r - 1][j];
////
////	for (int i = r - 2; i >= 0; --i) {
////		for (int j = 0; j <= i; ++j) {
////			dp[i][j] = mp[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
////		}
////	}
////	cout << dp[0][0] << endl;
////	return 0;
////}
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//
//int main() {
//
//	int r;
//	cin >> r;
//	vector<int>dp(r + 1, 0);
//	vector<vector<int>>mp(r, vector<int>(r, 0));
//
//	for (int i = 0; i < r; ++i) {
//		for (int j = 0; j <= i; ++j)
//			cin >> mp[i][j];
//	}
//
//	for (int j = 0; j < r; ++j)
//		dp[j] = mp[r - 1][j];
//
//	for (int i = r - 2; i >= 0; --i) {
//		for (int j = 0; j <= i; ++j) {
//			dp[j] = mp[i][j] + max(dp[j], dp[j + 1]);
//		}
//	}
//	cout << dp[0] << endl;
//	return 0;
//}
//
