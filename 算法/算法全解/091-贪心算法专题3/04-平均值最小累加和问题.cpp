////平均值最小累加和
////
////给定一个数组 arr，长度为 n。
////再给定一个数字 k，表示一定要将 arr 划分成 k 个集合，
////每个数字只能进入一个集合。
////
////返回每个集合的平均值（向下取整）都累加起来的最小值。
////
////数据范围：
////1 <= n <= 10 ^ 5
////0 <= arr[i] <= 10 ^ 5
////1 <= k <= n
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//int way1(vector<int>& nums,int k) {
//	int n = nums.size();
//	sort(nums.begin(), nums.end());
//	int ans = 0;
//	for (int i = 0; i < k - 1; ++i) {
//		ans += nums[i];
//	}
//	int sum = 0;
//	for (int i = k - 1; i < n; ++i) {
//		sum += nums[i];
//	}
//	ans += sum / (n - k + 1);
//	return ans;
//}
//
//int main() {
//	return 0;
//}