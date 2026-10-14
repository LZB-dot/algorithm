//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<climits>
//using namespace std;
//
//
//int main() {
//	
//	int n, m;
//	cin >> n >> m;
//
//	vector<int>teacher(n + 1);
//
//	for (int i = 1; i <= n; ++i)
//		cin >> teacher[i];
//	
//	int left = 0;
//	int sum = 0;
//	int x, y;
//	int ans = INT_MAX;
//	vector<int>freq(m + 1, 0);
//	for (int right = 1; right <= n; ++right) {
//		if (freq[teacher[right]] == 0)
//			++sum;
//		freq[teacher[right]]++;
//
//		while (sum == m) {
//			int len = right - left + 1;
//			if (ans > len) {
//				ans = len;
//				x = left;
//				y = right;
//			}
//
//			if (--freq[teacher[left]] == 0)
//				--sum;
//
//			++left;
//		}
//	}
//
//	cout << x << " " << y << "\n";
//
//	return 0;
//}