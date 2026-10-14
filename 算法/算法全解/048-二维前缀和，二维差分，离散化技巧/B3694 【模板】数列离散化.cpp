//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//#define ll long long
//
//vector<int>nums;
//vector<int>tmp;
//
//int get(int x) {
//	return lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin() + 1;
//}
//
//int main() {
//	int T;
//	cin >> T;
//
//	while (T--) {
//		int n;
//		cin >> n;
//		nums.resize(n, 0);
//		for (int i = 0; i < n; ++i)
//			cin >> nums[i];
//
//		tmp = nums;
//		sort(tmp.begin(), tmp.end());
//		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
//
//		for (int x : nums) 
//			cout << get(x) << " ";
//		cout << "\n";
//	}
//
//
//	return 0;
//}