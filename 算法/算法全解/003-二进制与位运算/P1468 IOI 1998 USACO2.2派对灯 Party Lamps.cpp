//#include<iostream>
//#include<vector>
//#include<set>
//using namespace std;
//
//int n, c;
//vector<int>open, close;
//set<string>ans;
//
//bool check1(int sum) {
//	if (c == 0)
//		return sum == 0;
//	//保证奇偶性相同，多的次数一定是偶数可以忽略
//	return sum <= c && (sum % 2 == c % 2);
//}
//
//string cal(int i, int j, int k, int l) {
//	string s(n, '1');
//	for (int a = 1; a <= n; ++a) {
//		int cnt = 0;
//		if (i)
//			cnt++;
//		if (j && (a % 2))
//			cnt++;
//		if (k && !(a % 2))
//			cnt++;
//		if (l && (a % 3 == 1))
//			cnt++;
//		if (cnt % 2 == 1)
//			s[a - 1] = '0';
//	}
//	return s;
//}
//
//bool check2(string s) {
//	for (int i : open) {
//		if (s[i - 1] != '1')
//			return false;
//	}
//	for (int i : close) {
//		if (s[i - 1] != '0')
//			return false;
//	}
//
//	return true;
//}
//
//void solve() {
//	for (int i = 0; i <= 1; ++i) 
//		for (int j = 0; j <= 1; ++j)
//			for (int k = 0; k <= 1; ++k)
//				for (int l = 0; l <= 1; ++l) {
//					if (!check1(i + j + k + l)) 
//						continue;
//					string tmp = cal(i, j, k, l);
//					if (check2(tmp))
//						ans.insert(tmp);
//				}
//	if (ans.empty())
//		cout << "IMPOSSIBLE" << endl;
//	else {
//		for (const string& s : ans)
//			cout << s << endl;
//	}
//}
//
//int main() {
//	cin >> n >> c;
//	int a;
//	cin >> a;
//	while (a != -1) {
//		open.push_back(a);
//		cin >> a;
//	}
//	cin >> a;
//	while (a != -1) {
//		close.push_back(a);
//		cin >> a;
//	}
//	solve();
//	return 0;
//}