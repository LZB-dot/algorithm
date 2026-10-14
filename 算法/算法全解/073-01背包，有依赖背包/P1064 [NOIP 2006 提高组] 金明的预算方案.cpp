//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 33001;
//const int MAXM = 61;
//int cost[MAXM];
//int val[MAXM];
//bool isMain[MAXM];
//int attachCount[MAXM];
//int attach[MAXM][2];
//int dp[MAXN];
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= m; ++i) {
//		int v, p, q;
//		cin >> v >> p >> q;
//		cost[i] = v;
//		val[i] = v * p;
//		if (q == 0) {
//			isMain[i] = true;
//		}
//		else {
//			attach[q][attachCount[q]++] = i;
//		}
//	}
//
//	fill(dp, dp + n + 1, 0);
//
//	for (int i = 1; i <= m; ++i) {
//		if (isMain[i]) {
//			for (int j = n; j >= cost[i]; --j) {
//				dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
//
//				if (attachCount[i] >= 1 && j >= cost[attach[i][0]] + cost[i]) {
//					dp[j] = max(dp[j], 
//						dp[j - cost[i]- cost[attach[i][0]]] 
//						+ val[i] + val[attach[i][0]]);
//				}
//
//				if (attachCount[i] >= 2 && j >= cost[attach[i][1]] + cost[i]) {
//					dp[j] = max(dp[j],
//						dp[j - cost[i] - cost[attach[i][1]]]
//						+ val[i] + val[attach[i][1]]);
//				}
//
//				if (attachCount[i] == 2 && j >= cost[attach[i][0]]+ cost[attach[i][1]] + cost[i]) {
//					dp[j] = max(dp[j],
//						dp[j - cost[i] - cost[attach[i][0]] - cost[attach[i][1]]]
//						+ val[i] + val[attach[i][0]] + val[attach[i][1]]);
//				}
//			}
//		}
//	}
//	cout << dp[n] << endl;
//	return 0;
//}