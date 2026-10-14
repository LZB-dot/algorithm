//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//typedef long long ll;
//
//const int MOD = 1e9 + 7;
//const int N = 1010;
//string l, r;
//int dp[N][11][11][2];
//vector<int>num;
//int digit;
//
//int dfs(int pos, int pp, int p, int free) {
//	if (pos == digit)
//		return  p == 10 ? 0 : 1;
//
//	if (dp[pos][pp][p][free] != -1)
//		return dp[pos][pp][p][free];
//
//	ll res = 0;
//	int upper = free ? 9 : num[pos];
//	for (int i = 0; i <= upper; ++i) {
//		int new_free = free || (i < upper);
//		if (i == pp || i == p)
//			continue;
//
//		int new_p, new_pp;
//		if (p == 10) {
//			if (i != 0) {
//				new_pp = 10;
//				new_p = i;
//			}
//			else {
//				new_pp = 10;
//				new_p = 10;
//			}
//		}
//		else {
//			new_pp = p;
//			new_p = i;
//		}
//
//		res = (res + dfs(pos + 1, new_pp, new_p, new_free)) % MOD;
//	}
//	return dp[pos][pp][p][free] = res;
//}
//
//int count(const string& n) {
//	num.clear();
//	for (char c : n) {
//		num.push_back(c - '0');
//	}
//	digit = num.size();
//	memset(dp, -1, sizeof(dp));
//	return dfs(0, 10, 10, 0);
//}
//
//int total(const string& s) {
//	ll res = 0;
//	for (char c : s) {
//		res = (res * 10 + (c - '0')) % MOD;
//	}
//	return (int)(res + 1) % MOD;
//}
//
//bool check(const string& s) {
//	int len = s.size();
//	if (len < 2) 
//		return false;
//
//	for (int i = 1; i < len; ++i) {
//		if (s[i] == s[i - 1]) 
//			return true;
//	}
//	for (int i = 2; i < len; ++i) {
//		if (s[i] == s[i - 2]) 
//			return true;
//	}
//	return false;
//}
//
//int main() {
//	cin >> l >> r;
//	int c1 = (total(l) - count(l) + MOD) % MOD;
//	int c2 = (total(r) - count(r) + MOD) % MOD;
//	int border = check(l) ? 1 : 0;
//	cout << (c2 - c1 + border + MOD)% MOD << endl;
//	return 0;
//}
//
//

