//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//int n, k;
//vector<int>nums;
//int ans = 0;
//
//bool check(int n) {
//	if (n < 2)
//		return false;
//	for (int i = 2; i * i <= n; ++i) {
//		if (n % i == 0)
//			return false;
//	}
//	return true;
//}
//
//void dfs(int i, int sum,int cnt) {
//
//	if (cnt == k)
//		if (check(sum)) {
//			ans++;
//			return;
//		}
//
//	if (i >= n || cnt + (n - i + 1) < k)
//		return;
//
//
//
//	dfs(i + 1, sum, cnt);
//	dfs(i + 1, sum + nums[i], cnt + 1);
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> k;
//	nums.resize(n);
//	for (int i = 0; i < n; ++i)
//		cin >> nums[i];
//
//	dfs(0, 0, 0);
//	cout << ans << endl;
//	
//
//	return 0;
//}