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
//	//只累加当前位置比前一个位置多的部分
//	int ans = nums[0];
//	for (int i = 1; i < n; ++i) 
//		ans += max(0, nums[i] - nums[i - 1]);
//	
//	cout << ans << "\n";
//	
//
//	return 0;
//}