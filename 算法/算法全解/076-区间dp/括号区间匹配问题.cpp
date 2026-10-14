//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//vector<vector<int>>dp;
//
//int f(const string& s, int l, int r) {
//	if (dp[l][r] != -1) {
//		return dp[l][r];
//	}
//	if (l == r) {
//		dp[l][r] = 1;
//		return 1;
//	}
//
//	if (l == r - 1) {
//		if ((s[l] == '(' && s[r] == ')') ||
//			(s[l] == '[' && s[r] == ']')) {
//			dp[l][r] = 0;
//			return 0;
//		}
//		else {
//			dp[l][r] = 2;
//			return 2;
//		}
//	}
//
//
//	int ans = INT_MAX;
//
//	if ((s[l] == '(' && s[r] == ')') ||
//		(s[l] == '[' && s[r] == ']')) {
//		ans = f(s, l + 1, r - 1);
//	}
//
//	for (int k = l; k < r; ++k) {
//		ans = min(ans, f(s, l, k) + f(s, k + 1, r));
//	}
//
//	dp[l][r] = ans;
//	return ans;
//}
//
//int main() {
//	string s;
//	cin >> s;
//	int n = s.size();
//	dp.resize(n + 1, vector<int>(n + 1, -1));
//	cout << f(s, 0, n - 1) << endl;
//	return 0;
//}