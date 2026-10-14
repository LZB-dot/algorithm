////三堆石头拿取斐波那契数博弈
////有三堆石头，数量分别为a、b、c。
////两个人轮流拿，每次可以选择其中一堆石头，拿取斐波那契数的石头。
////拿到最后一颗石子的人获胜，根据a、b、c返回谁赢。三堆石头拿取斐波那契数博弈
////有三堆石头，数量分别为a、b、c。
////两个人轮流拿，每次可以选择其中一堆石头，拿取斐波那契数的石头。
////拿到最后一颗石子的人获胜，根据a、b、c返回谁赢。
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int a, b, c;
//vector<int>s;
//vector<bool>appear;
//
//int f[] = { 1,2,3,5,8,13,21,34,55,89 };
//
//string solve(int mx) {
//	for (int i = 1; i <= mx; ++i) {
//		fill(appear.begin(), appear.end(), false);
//
//		for (int j : f) {
//			if (i >= j) {
//				appear[s[i - j]] = true;
//			}
//		}
//
//		for (int k = 0; k <= mx; ++k) {
//			if (!appear[k]) {
//				s[i] = k;
//				break;
//			}
//		}
//	}
//
//	int tmp = s[a] ^ s[b] ^ s[c];
//	string ans = tmp != 0 ? "先手赢" : "后手赢";
//	return ans;
//}
//
//int main() {
//	cin >> a >> b >> c;
//	int mx = max(max(a, b), c);
//	s.resize(mx + 1, 0);
//	appear.resize(mx + 1);
//	cout << solve(mx) << endl;
//	return 0;
//}