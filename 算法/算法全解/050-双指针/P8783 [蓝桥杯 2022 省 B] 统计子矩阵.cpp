//#include<iostream>
//#include<unordered_map>
//#include<climits>
//#include<vector>
//
//using namespace std;
//
//#define ll long long
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<vector<int>>grid(n + 1, vector<int>(m + 1));
//
//
//	for (int i = 1; i <= n; ++i)
//		for (int j = 1; j <= m; ++j) 
//			cin >> grid[i][j];
//			
//	ll ans = 0;
//	//上边界
//	for (int top = 1; top <= n; ++top) {
//		vector<ll>col(m + 1, 0);
//		//下边界
//		for (int bottom = top; bottom <= n; ++bottom) {
//			
//			for (int i = 1; i <= m; ++i)
//				col[i] += grid[bottom][i];
//
//			ll cur = 0;
//			int left = 1;
//			for (int right = 1; right <= m; ++right) {
//				cur += col[right];
//
//				while (cur > k && left <= right) {
//					cur -= col[left];
//					++left;
//				}
//
//				ans += right - left + 1;
//			}
//
//		}
//	}
//
//	cout << ans << "\n";
//
//	return 0;
//}