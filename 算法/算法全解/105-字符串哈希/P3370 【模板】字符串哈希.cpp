//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 1e4 + 10;
//const int base = 499;
//ll nums[MAXN];
//
//ll toNum(char c) {
//	if (c >= '0' && c <= '9')
//		return c - '0' + 1;
//	else if (c >= 'a' && c <= 'z')
//		return c - 'a' + 11;
//	else
//		return c - 'A' + 37;
//}
//
//ll hashv(const string& s) {
//	ll ans = toNum(s[0]);
//	for (int i = 1; i < s.size(); ++i) 
//		ans = ans * base + toNum(s[i]);
//	
//	return ans;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; ++i) {
//		string s;
//		cin >> s;
//		nums[i] = hashv(s);
//	}
//
//	sort(nums, nums + n);
//	int ans = 1;
//	for (int i = 1; i < n; ++i) {
//		if (nums[i - 1] != nums[i])
//			++ans;
//	}
//
//	cout << ans << "\n";
//	return 0;
//}
//
//
//
//
