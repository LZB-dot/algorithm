//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MOD = 19650827;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//	vector<int>nums(n + 1, 0);
//	for (int i = 1; i <= n; ++i) {
//		cin >> nums[i];
//	}
//
//	// dp[l][r][0]：区间[l,r]最后一个人是l的方法数
//	// dp[l][r][1]：区间[l,r]最后一个人是r的方法数
//	vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
//
//	// 初始化：长度为1的区间，只有一种方法
//	for (int i = 1; i < n; ++i) {
//		if (nums[i] < nums[i + 1]) {
//			dp[i][i+1][0] = dp[i][i+1][1] = 1;
//		}
//	}
//
//	// 枚举区间长度（从2到n）
//	for (int len = 2; len <= n; ++len) {
//		// 枚举左端点l，右端点r = l + len - 1
//		for (int l = 1; l + len - 1 <= n; ++l) {
//			int r = l + len - 1;
//
//			// 状态转移：dp[l][r][0]（最后一个人是l）
//			// 从 [l+1][r][0] 转移：l+1 是最后一个人，l 插入到左边，需满足 nums[l] < nums[l+1]
//			if (nums[l] < nums[l + 1]) {
//				dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][0]) % MOD;
//			}
//			// 从 [l+1][r][1] 转移：r 是最后一个人，l 插入到左边，需满足 nums[l] < nums[r]
//			if (nums[l] < nums[r]) {
//				dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][1]) % MOD;
//			}
//
//			// 状态转移：dp[l][r][1]（最后一个人是r）
//			// 从 [l][r-1][1] 转移：r-1 是最后一个人，r 插入到右边，需满足 nums[r] > nums[r-1]
//			if (nums[r] > nums[r - 1]) {
//				dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][1]) % MOD;
//			}
//			// 从 [l][r-1][0] 转移：l 是最后一个人，r 插入到右边，需满足 nums[r] > nums[l]
//			if (nums[r] > nums[l]) {
//				dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][0]) % MOD;
//			}
//		}
//	}
//
//	// 最终结果：区间[1,n]最后一个人是1或n的方法数之和
//	cout << (dp[1][n][0] + dp[1][n][1]) % MOD << endl;
//	return 0;
//}