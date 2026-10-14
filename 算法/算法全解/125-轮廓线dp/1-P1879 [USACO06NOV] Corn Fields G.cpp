////
////////ÆÕÍ¨×´Ñ¹dp
////
//////#include<iostream>
//////#include<cstring>
//////using namespace std;
//////
//////const int MAXN = 15;    
//////const int MOD = 100000000;
//////int n, m;
//////int a[MAXN][MAXN];     
//////int memo[MAXN][1 << MAXN]; 
//////
//////int get(int s, int j) {
//////	return (s >> j) & 1;
//////}
//////
//////int set(int s, int j, int v) {
//////	if (v == 0)
//////		return s & (~(1 << j));
//////	else
//////		return s | (1 << j);
//////}
//////
//////int f(int i, int pre);
//////
//////int dfs(int i, int j, int pre, int cur) {
//////	if (j == m + 1) 
//////		return f(i + 1, cur);
//////
//////	int ans = dfs(i, j + 1, pre, cur);
//////
//////	if (a[i][j] == 1          
//////		&& get(pre, j) == 0     
//////		&& get(cur, j - 1) == 0
//////		) 
//////		ans = (ans + dfs(i, j + 1, pre, set(cur, j, 1))) % MOD;
//////	
//////
//////	return ans;
//////}
//////
////////µÚ i ÐÐ£¬ÉÏÒ»ÐÐ×´Ì¬ pre
//////int f(int i, int pre) {
//////	if (i == n + 1) 
//////		return 1;
//////
//////	if (memo[i][pre] != -1) 
//////		return memo[i][pre];
//////	
//////	memo[i][pre] = dfs(i, 1, pre, 0);
//////	return memo[i][pre];
//////}
//////
//////int main() {
//////	ios::sync_with_stdio(false);
//////	cin.tie(0);
//////
//////	cin >> n >> m;
//////	for (int i = 1; i <= n; ++i)
//////		for (int j = 1; j <= m; ++j)
//////			cin >> a[i][j];
//////
//////	memset(memo, -1, sizeof(memo));
//////
//////	cout << f(1, 0) << endl;
//////
//////	return 0;
//////}
////
////
//////ÂÖÀªÏßdp
////
////#include<iostream>
////#include<cstring>
////using namespace std;
////
////const int MAXN = 15;
////const int MOD = 100000000;
////int n, m;
////int a[MAXN][MAXN];
////int memo[MAXN][MAXN][1 << MAXN];
////
////int get(int s, int j) {
////	return (s >> j) & 1;
////}
////
////int set(int s, int j, int v) {
////	if (v == 0)
////		return s & (~(1 << j));
////	else
////		return s | (1 << j);
////}
////
////
////int dfs(int i, int j, int s) {
////	if (i == n + 1)
////		return 1;
////
////	if (j == m + 1)
////		return dfs(i + 1, 1, s);
////
////	if (memo[i][j][s] != -1)
////		return memo[i][j][s];
////
////	int ans = dfs(i, j + 1, set(s, j, 0));
////
////	if (a[i][j] == 1
////		&& get(s, j) == 0
////		&& get(s, j - 1) == 0
////		)
////		ans = (ans + dfs(i, j + 1,set(s, j, 1))) % MOD;
////
////
////	return memo[i][j][s] = ans;
////}
////
////
////int main() {
////	ios::sync_with_stdio(false);
////	cin.tie(0);
////
////	cin >> n >> m;
////	for (int i = 1; i <= n; ++i)
////		for (int j = 1; j <= m; ++j)
////			cin >> a[i][j];
////
////	memset(memo, -1, sizeof(memo));
////
////	cout << dfs(1, 1, 0) << endl;
////
////	return 0;
////}
//
//
//
////ÂÖÀªÏßdp×´Ì¬Ñ¹Ëõ
//
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//const int MAXM = 12;   
//const int MOD = 100000000;
//
//int n, m, maxs;
//int a[15][15];             
//int dp[MAXM + 1][1 << MAXM]; 
//int prepare[1 << MAXM];  
//
//int get(int s, int j) {
//    return (s >> j) & 1;
//}
//
//int set(int s, int j, int v) {
//    if (v == 0)
//        return s & (~(1 << j));
//    else
//        return s | (1 << j);
//}
//
//int compute() {
//    maxs = 1 << m;
//    fill(prepare, prepare + maxs, 1);
//
//    for (int i = n; i >= 1; --i) {
//        for (int s = 0; s < maxs; ++s) {
//            dp[m][s] = prepare[s];
//        }
//
//        for (int j = m - 1; j >= 0; --j) {
//            for (int s = 0; s < maxs; ++s) {
//                int ans = dp[j + 1][set(s, j, 0)];
//
//                if (a[i][j + 1] == 1         
//                    && get(s, j) == 0          
//                    && (j == 0 || get(s, j - 1) == 0)) 
//                    ans = (ans + dp[j + 1][set(s, j, 1)]) % MOD;
//                
//                dp[j][s] = ans;
//            }
//        }
//
//        for (int s = 0; s < maxs; ++s) 
//            prepare[s] = dp[0][s];
//        
//    }
//
//    return prepare[0];
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
//    cin >> n >> m;
//    for (int i = 1; i <= n; ++i)
//        for (int j = 1; j <= m; ++j)
//            cin >> a[i][j];
//
//    memset(dp, -1, sizeof(dp));
//    cout << compute() << endl;
//
//    return 0;
//}