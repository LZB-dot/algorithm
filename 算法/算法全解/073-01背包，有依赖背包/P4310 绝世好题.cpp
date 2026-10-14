//#include<iostream>
//#include<vector>
//
//
//using namespace std;
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	vector<int>nums(n+1);
//	for (int i = 1; i <= n; ++i)
//		cin >> nums[i];
//
//	//相邻两个数&！=0 即相邻两个数至少有一位都为1
//	//来到i位时，寻找i-1位是否有同一位为1
//	//状态压缩为：dp[i-1的二进制位为1]+1
//
//	vector<int>dp(32, 0);
//
//	for (int i = 1; i <= n; ++i) {
//		if (nums[i] == 0)
//			continue;
//
//		//先计算以x为末尾的最大值
//		int tmp = nums[i];
//		int wei = 0;
//		int mx = 0;
//		while (tmp) {
//			if (tmp & 1)
//				mx = max(mx, dp[wei]);
//			
//			++wei;
//			tmp >>= 1;
//		}
//		mx += 1;
//
//		//遍历更新以x为结尾的所有可能
//		tmp = nums[i];
//		wei = 0;
//		while (tmp) {
//			if (tmp & 1)
//				dp[wei] = max(dp[wei], mx);
//			++wei;
//			tmp >>= 1;
//		}
//	}
//
//	int ans = 0;
//	for (int i : dp) 
//		ans = max(i, ans);
//	
//
//	cout << ans << "\n";
//
//	return 0;
//}