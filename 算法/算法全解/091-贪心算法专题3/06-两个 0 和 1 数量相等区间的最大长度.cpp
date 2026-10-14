////两个 0 和 1 数量相等区间的最大长度
////给定一个长度为 n 的 01 串，请找到两个区间，满足以下条件：
////两个区间中，1 的个数相等，0 的个数也相等。
////两个区间可以相交，但不可以完全重叠（即两个区间的左右端点不能完全一样）。
////请找到满足条件的两个最长区间，并返回它们的总长度（或两个区间长度之和）。
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int way(vector<int>& arr) {
//	int n = arr.size();
//	int leftZero = -1;
//	// 找到最左边的 0
//	for (int i = 0; i < n; ++i) {
//		if (arr[i] == 0) {
//			leftZero = i;
//			break;
//		}
//	}
//	if (leftZero == -1) { // 全是 1
//		return 0;
//	}
//	int leftOne = -1;
//	// 找到最左边的 1
//	for (int i = 0; i < n; ++i) {
//		if (arr[i] == 1) {
//			leftOne = i;
//			break;
//		}
//	}
//	if (leftOne == -1) { // 全是 0
//		return 0;
//	}
//	int rightZero = -1;
//	// 找到最右边的 0
//	for (int i = n - 1; i >= 0; --i) {
//		if (arr[i] == 0) {
//			rightZero = i;
//			break;
//		}
//	}
//	int rightOne = -1;
//	// 找到最右边的 1
//	for (int i = n - 1; i >= 0; --i) {
//		if (arr[i] == 1) {
//			rightOne = i;
//			break;
//		}
//	}
//	int p1 = rightZero - leftZero;
//	int p2 = rightOne - leftOne;
//	return max(p1, p2);
//}
