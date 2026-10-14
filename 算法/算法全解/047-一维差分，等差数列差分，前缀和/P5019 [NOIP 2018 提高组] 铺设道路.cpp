//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//int main() {
//
//	int n;
//	cin >> n;
//	vector<int>nums(n);
//	for (int i = 0; i < n; ++i)
//		cin >> nums[i];
//
//	int ans = nums[0];
//	for (int i = 1; i < n; ++i) {
//		if (nums[i] > nums[i - 1])
//			ans += (nums[i] - nums[i - 1]);
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}