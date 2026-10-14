//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//
//int a, b;
//vector<int>num;
//vector<vector<vector<int>>>memo;
//int digit;
//
//int dfs(int n, int pos, int pre, int free) {
//	if (pos == digit) {
//		return pre == 10 ? 0 : 1;
//	}
//
//	if (memo[pos][pre][free] != -1)
//		return memo[pos][pre][free];
//
//	int res = 0;
//	int upper = free ? 9 : num[pos];
//
//	for (int i = 0; i <= upper; ++i) {
//		int new_free = free || (i < upper);
//		//สืฮป
//		if (pos == 0)
//		{
//			if (i == 0)
//				res += dfs(n, pos + 1, 10, new_free);
//			else
//				res += dfs(n, pos + 1, i, new_free);
//		}
//		else {
//			if (pre == 10)
//				if (i == 0) {
//					res += dfs(n, pos + 1, 10, new_free);
//				}
//				else {
//					res += dfs(n, pos + 1, i, new_free);
//				}
//			else {
//				if (abs(i - pre) >= 2)
//					res += dfs(n, pos + 1, i, new_free);
//			}
//		}
//	}
//	return memo[pos][pre][free] = res;
//}
//
//int count(int n) {
//	num.clear();
//	memo.clear();
//
//	if (n < 0) 
//		return 0; 
//	int tmp = n;
//
//	if (tmp == 0) {
//		num.push_back(0);
//	}
//	else {
//		while (tmp) {
//			num.push_back(tmp % 10);
//			tmp /= 10;
//		}
//		reverse(num.begin(), num.end());
//	}
//
//	digit = num.size();
//	memo.resize(digit, vector<vector<int>>(11, vector<int>(2, -1)));
//
//	return dfs(n, 0, 10, 0);
//}
//
//int main() {
//	cin >> a >> b;
//	int cnt1 = count(a - 1);
//	int cnt2 = count(b);
//	cout << cnt2 - cnt1 << endl;
//	return 0;
//}