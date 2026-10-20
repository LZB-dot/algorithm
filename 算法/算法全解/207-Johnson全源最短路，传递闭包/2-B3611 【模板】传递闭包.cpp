//
//
//
////https://www.luogu.com.cn/problem/B3611
//
//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<bitset>
//using namespace std;
//
//const int MAXN = 110;
//
//int n;
//
////dp[i]是一个bitset<101>类型的变量
//bitset<MAXN>dp[MAXN];
//
//
//void Floyd() {
//	for (int bridge = 1; bridge <= n; ++bridge) {
//		for (int i = 1; i <= n; ++i) {
//			if (dp[i][bridge])
//				dp[i] |= dp[bridge];
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n;
//
//	int s;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			cin >> s;
//			dp[i][j] = s;
//		}
//	}
//
//	Floyd();
//
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			if (dp[i][j])
//				cout << "1 ";
//			else
//				cout << "0 ";
//		}
//
//		cout << "\n";
//	}
//
//
//	return 0;
//}
