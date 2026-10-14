////巴什博弈问题：
////有n个石子，两人轮流取，每次最少取 1 个、最多取m个，
////取走最后一个石子的人获胜。
////问 “先手” 还是 “后手” 能赢？
//
////sg!=0--必胜态
////sg==0--必败态
////sg[0]=0--必败态
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//vector<int>s;
//vector<bool>appear;
//
//string solve(int n, int m) {
//	s[0] = 0;
//	for (int i = 1; i <= n; ++i) {
//		fill(appear.begin(), appear.end(), false);
//		for (int j = 1; j <= m && j <= i; ++j) {
//			appear[s[i - j]] = true;
//		}
//
//		for (int k = 0; k <= m; ++k) {
//			if (!appear[k]){
//				s[i] = k;
//				break;
//			}
//		}
//	}
//
//	string ans = s[n] != 0 ? "先手" : "后手";
//	return ans;
//}
//
//int main() {
//	int n = 100;
//	int m = 4;
//	s.resize(n + 1, 0);
//	appear.resize(m + 1, 0);
//	cout << solve(n, m) << endl << endl;
//	for (int i = 0; i <= n; ++i) {
//		cout << i << "\t" << s[i] << endl;
//	}
//	return 0;
//}