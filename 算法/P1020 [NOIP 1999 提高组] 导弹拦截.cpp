//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//const int N = 1e5 + 5;
//vector<int>nums;
//
////求最长不上升子序列
//int longIncrease(const vector<int>& nums) {
//	vector<int>ed;
//	for (int x : nums) {
//		//在降序空间查找第一个小于x的迭代器
//		auto it = upper_bound(ed.begin(), ed.end(), x, greater<int>());
//		if (it != ed.end()) {
//			*it = x;
//		}
//		else {
//			ed.push_back(x);
//		}
//	}
//	return ed.size();
//}
//
////求最长严格上升子序列
//int longStrictIncrease(const vector<int>& nums) {
//	vector<int>ed;
//	for (int x : nums) {
//		//在升序空间查找第一个大于等于x的迭代器
//		auto it = lower_bound(ed.begin(), ed.end(), x);
//		if (it == ed.end()) {
//			ed.push_back(x);
//		}
//		else {
//			*it = x;
//		}
//	}
//	return ed.size();
//}
//
//
//int main() {
//
//	int a;
//	while (cin >> a) {
//		nums.push_back(a);
//	}
//	cout << longIncrease(nums) << endl;
//	cout << longStrictIncrease(nums) << endl;
//
//	return 0;
//}
