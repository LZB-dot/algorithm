//
////需要反复删除，并且删除完还要根据之前的继续进行匹配
////可以用栈来
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<climits>
//using namespace std;
//
//const int MAXN = 1e6;
//int st1[MAXN];
//int st2[MAXN];
//
//vector<int>getNxt(const string& s) {
//	int m = s.size();
//
//	if (m == 1)
//		return{ -1 };
//
//	vector<int>nxt(m,-1);
//	nxt[0] = -1;
//	nxt[1] = 0;
//
//	int i = 2, cn = 0;
//	while (i < m) {
//		if (s[i - 1] == s[cn])
//			nxt[i++] = ++cn;
//		else if (cn > 0)
//			cn = nxt[cn];
//		else
//			nxt[i++] = 0;
//	}
//
//	return nxt;
//}
//
//void solve(const string& s1, const string& s2) {
//
//	int n = s1.size();
//	int m = s2.size();
//
//	vector<int>nxt = getNxt(s2);
//	int x = 0, y = 0;
//
//	int size_ = 0;
//
//	while (x < n) {
//		if (s1[x] == s2[y]) {
//			st1[size_] = x;
//			st2[size_] = y;
//			++x; 
//			++y;
//			++size_;
//		}
//		else if (y == 0) {
//			st1[size_] = x;
//			st2[size_] = -1;
//			++x;
//			++size_;
//		}
//		else {
//			y = nxt[y];
//		}
//
//		if (y == m) {
//			size_ -= m;
//			y = size_ > 0 ? (st2[size_ - 1] + 1) : 0;
//		}
//	}
//
//	for (int i = 0; i < size_; ++i)
//		cout << s1[st1[i]];
//	cout << "\n";
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	string s, t;
//	cin >> s;
//	cin	>> t;
//
//	solve(s, t);
//
//	return 0;
//}
//
//
