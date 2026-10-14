////加入差值绝对值直到长度固定
////给定一个非负数组 arr，重复执行以下操作：
////计算数组中任何两个数差值的绝对值。
////如果该差值在 arr 中不存在，就将其加入 arr（每个差值只加一次）。
////对新的 arr 重复上述过程，直到数组大小不再变化。
////返回最终数组 arr 的长度。
//
//
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//int gcd(int a, int b) {
//	while (b > 0) {
//		int tmp = b;
//		b = a % b;
//		a = tmp;
//	}
//	return a;
//}
//
//int way(vector<int>arr) {
//	int mx = 0;
//	int g = 0;
//	unordered_map<int, int>cnts;
//	for (int num : arr) {
//		cnts[num]++;
//		mx = max(mx, num);
//		if (num != 0) {
//			g = gcd(g, num);
//		}
//	}
//
//	if (g == 0)
//		return arr.size();
//
//	int ans = mx / g;
//	int zero = 0;
//	for (auto& it : cnts) {
//		if (it.first != 0) {
//			ans += it.second - 1;
//		}
//		zero = max(zero, it.second);
//	}
//
//	if (cnts.count(0)) {
//		ans += (zero > 1) ? cnts[0] : 0;
//	}
//
//	return ans;
//}