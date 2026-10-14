////Nim 游戏问题：
////有若干堆石子（每堆石子数不同），两人轮流取，
////每次可以从任意一堆中取任意数量的石子（至少 1 个），
////取走最后一个石子的人获胜。
////问 “先手” 还是 “后手” 能赢？
//
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//vector<int>s;
//vector<bool>appear;
//
//string solve(const vector<int>& nums) {
//	int n = nums.size();
//	int mx = INT_MIN;
//	for (int num : nums)
//		mx = max(mx, num);
//
//	s.resize(mx + 1, 0);
//	appear.resize(mx + 1);
//
//	for (int i = 1; i <= mx; ++i) {
//		fill(appear.begin(), appear.end(), false);
//		for (int j = 0; j < i; ++j)
//			appear[s[j]] = true;
//
//		for (int k = 0; k <= mx; ++k) {
//			if (!appear[k]) {
//				s[i] = k;
//				break;
//			}
//		}
//	}
//
//	for (int i = 0; i <= mx; ++i) {
//		cout << i << "\t" << s[i] << endl;
//	}
//
//	int res = 0;
//	for (int num : nums)
//		res ^= s[num];
//
//	return res != 0 ? "先手" : "后手";
//}
//
//int main() {
//
//	cout << solve({ 17,20,35 }) << endl;
//	return 0;
//}
