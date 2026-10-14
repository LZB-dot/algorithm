////#include<iostream>
////#include<vector>
////using namespace std;
////
////const int MAXN = 1005;
////const int MAXT = 1e5 + 1;
////
////int cost[MAXT];
////int val[MAXN];
////int dp[MAXN][MAXT];
////
////int main() {
////	ios::sync_with_stdio(false);
////	cin.tie(NULL);
////
////	int n, t;
////	cin >> t >> n;
////
////	for (int i = 1; i <= n; ++i) {
////		cin >> cost[i] >> val[i];
////	}
////
////	for (int i = 1; i <= n; ++i) {
////		for (int j = 0; j <= t; ++j) {
////			dp[i][j] = dp[i - 1][j];
////			if (j >= cost[i]) {
////				dp[i][j] = max(dp[i][j], dp[i][j - cost[i]] + val[i]);
////			}
////		}
////	}
////
////	cout << dp[n][t] << endl;
////
////	return 0;
////}
//
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int MAXN = 10000 + 5;    
//const int MAXT = 10000000 + 5;  
//
//int cost[MAXN];               
//int val[MAXN];              
//long long dp[MAXT]; 
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int t, m;
//    cin >> t >> m;
//
//    for (int i = 1; i <= m; ++i) {
//        cin >> cost[i] >> val[i];
//    }
//
//
//    for (int i = 1; i <= m; ++i) {
//        for (int j = cost[i]; j <= t; ++j) {
//            dp[j] = max(dp[j], dp[j - cost[i]] + (long long)val[i]);
//        }
//    }
//
//    cout << dp[t] << '\n';
//    return 0;
//}