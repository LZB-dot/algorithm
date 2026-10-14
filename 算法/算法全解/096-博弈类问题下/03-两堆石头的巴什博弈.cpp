////两堆石头的巴什博弈”，规则为：
////有两堆石头，数量分别为 a、b；
////两人轮流操作，每次只能选择其中一堆石头，取 1~m 颗；
////拿到最后一颗石子的人获胜；
////需要根据 a、b、m 判断谁（先手 / 后手）能赢。
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//vector<int>s;
//vector<bool>appear;
//
//int a, b, m;
//
//string solve(int c) {
//	for (int i = 1; i <= c; ++i) {
//
//		fill(appear.begin(), appear.end(), false);
//
//		for (int j = 1; j <= m && j <= i; ++j)
//			appear[s[i - j]] = true;
//
//		for (int k = 0; k <= m; ++k) {
//			if (!appear[k]) {
//				s[i] = k;
//				break;
//			}
//		}
//	}
//
//	for (int i = 0; i <= c; ++i) {
//		for (int j = 0; j <= c; ++j) {
//			cout << i << "\t" << j << "\t" << (s[i] ^ s[j]) << endl;
//		}
//	}
//
//	string ans = (s[a] ^ s[b] != 0) ? "先手赢" : "后手赢";
//	return ans;
//}
//
//string way2() {
//	string ans = ((a % (m + 1)) ^ (b % (m + 1)) != 0) ? "先手赢" : "后手赢";
//	return ans;
//}
//
//int main() {
//	cin >> a >> b >> m;
//	int c = max(a, b);
//	s.resize(c + 1, 0);
//	appear.resize(m + 1);
//	cout << solve(c) << endl;
//	cout << way2() << endl;
//	return 0;
//}