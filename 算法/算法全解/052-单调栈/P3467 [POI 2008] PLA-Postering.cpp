//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 3e5;
//int st[MAXN];
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	int ans = 0;
//
//	int r = 0;
//
//	int w, h;
//	vector<int>nums(n + 1, 0);
//	for (int i = 0; i < n; ++i) {
//		cin >> w >> h;
//		nums[i] = h;
//	}
//
//	for (int i = 0; i <= n; ++i) {
//		while (r > 0 && nums[i] <= nums[st[r - 1]]) {
//			int top = st[--r];
//			if (nums[top] == nums[i])
//				continue;
//			ans++;
//		}
//
//		st[r++] = i;
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}