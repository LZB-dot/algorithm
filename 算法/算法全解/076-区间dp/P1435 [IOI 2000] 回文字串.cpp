//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//vector<vector<int>>dp(1005, vector<int>(1005, -1));
//
//int solve(string s, int left, int right) {
//	if (left == right)
//		return 0;
//	if (left + 1 == right)
//		return (s[left] == s[right]) ? 0 : 1;
//
//	if (dp[left][right] != -1)
//		return dp[left][right];
//
//	if (s[left] == s[right])
//		return dp[left][right] = solve(s, left + 1, right - 1);
//
//	int p1 = solve(s, left , right - 1) + 1;
//	int p2 = solve(s, left + 1, right) + 1;
//
//	return dp[left][right] = min(p1, p2);
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	string s;
//	cin >> s;
//	cout << solve(s, 0, s.size() - 1) << "\n";;
//
//	return 0;
//}
//
//
//
