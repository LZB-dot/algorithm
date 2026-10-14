//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<int>getNxt(int n,const string& s) {
//	if (n == 1)
//		return{ -1 };
//
//	vector<int>nxt(n + 1);
//	nxt[0] = -1;
//	nxt[1] = 0;
//
//	int i = 2, cn = 0;
//	while (i <= n) {
//		if (s[i - 1] == s[cn])
//			nxt[i++] = ++cn;
//		else if (cn > 0)
//			cn = nxt[cn];
//		else
//			nxt[i++] = cn;
//	}
//
//	return nxt;
//}
//
// //求最大循环节：等于用数组长度减去最大前后缀长度
//
//int main() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	vector<int>nxt = getNxt(n, s);
//	cout << n - nxt[n] << "\n";
//
//	return 0;
//}
