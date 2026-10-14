//
//
//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int n, m;
//vector<vector<int>>presum;//前i个偶像j乐队的人数
//vector<int>memo;
//vector<int>sum;//每个乐队总人数
//
//int main() {
//	cin >> n >> m;
//	presum.resize(n + 1, vector<int> (m, 0));
//	sum.resize(m, 0);
//	int a;
//	for (int i = 1; i <= n; ++i) {
//		cin >> a;
//		--a;
//		sum[a]++;
//		//逐行复制
//		for (int j = 0; j < m; ++j) {
//			presum[i][j] = presum[i - 1][j];
//		}
//		presum[i][a]++;
//	}
//
//	memo.resize(1 << m, INT_MAX);
//	memo[0] = 0;
//
//	for (int i = 1; i < (1 << m); ++i) {
//		int len = 0;
//		//计算当前状态i包含的乐队总人数
//		for (int j = 0; j < m; ++j) {
//			if (i & (1 << j))
//				len += sum[j];
//		}
//		//枚举最后可能加入的乐队
//		for (int j = 0; j < m; ++j) {
//			if (i & (1 << j)) {
//				int pre = i ^ (1 << j);//不加最后一个乐队j的状态
//				//计算不在正确位置的人数
//				//即j乐队总人数-在这个区间（len,len-sum[j]）内的j乐队偶像数
//				//在这区间的j乐队偶像数用前缀和求出
//				int out = sum[j] - (presum[len][j] - presum[len - sum[j]][j]);
//				memo[i] = min(memo[i], memo[pre] + out);
//			}
//		}
//	}
//	cout << memo[(1 << m) - 1] << endl;
//	return 0;
//}
