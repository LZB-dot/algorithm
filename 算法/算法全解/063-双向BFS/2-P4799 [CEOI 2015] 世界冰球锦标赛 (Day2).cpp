
////https://www.luogu.com.cn/problem/P4799

//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//
//int n;
//ll w;
//vector<ll>arr;
//
//void dfs(int l, int r,ll cur, vector<ll>& sum) {
//	if (cur > w)
//		return;
//	
//	if (l > r) {
//		sum.push_back(cur);
//		return;
//	}
//
//	dfs(l + 1, r, cur, sum);
//	dfs(l + 1, r, cur + arr[l], sum);
//}
//
//ll compute() {
//	int mid = n >> 1;
//	vector<ll>lsum, rsum;
//
//	dfs(0, mid, 0, lsum);
//	dfs(mid + 1, n - 1, 0, rsum);
//
//	sort(lsum.begin(), lsum.end());
//	sort(rsum.begin(), rsum.end());
//
//	ll ans = 0;
//	int j = rsum.size() - 1;
//
//	for (ll i : lsum) {
//		while (j >= 0 && rsum[j] + i > w)
//			--j;
//
//		ans += j + 1;
//	}
//
//	return ans;
//}
//
//int main() {
//	cin >> n >> w;
//	arr.resize(n);
//	for (int i = 0; i < n; ++i) 
//		cin >> arr[i];
//	
//	cout << compute() << "\n";
//	
//	return 0;
//}
//
//
