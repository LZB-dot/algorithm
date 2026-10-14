////尼姆博弈
////有 n 堆石子，每堆有若干颗；
////两名玩家轮流行动，每次可以从任意一堆中拿走任意数量的石子（至少拿 1 颗）；
////拿到最后一颗石子的玩家获胜；
////给定每堆石子的数量，判断先手是否能赢
//
////最终态是0 0 0 0 0....
////必胜态：若异或和 xor_sum ≠ 0 → 先手必胜
////必输态：若异或和 xor_sum = 0 → 此时先手无论拿多少，异或和一定不等于0
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		int n;
//		cin >> n;
//		int sum = 0, a;
//		for (int i = 0; i < n; ++i) {
//			cin >> a;
//			sum ^= a;
//		}
//		string s = (sum != 0) ? "Yes" : "No";
//		cout << s << endl;
//	}
//
//	return 0;
//}
//
