//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//pair<int,int> manacher(const string& s) {
//	string ss;
//	for (char c : s) {
//		ss += '#';
//		ss += c;
//	}
//	ss += '#';
//
//	int n = ss.size();
//	vector<int>p(n, 0);
//	int r = 0, c = 0;
//	int mx = 0, mc = 0;
//
//	for (int i = 0; i < n; ++i) {
//		int len = r > i ? min(p[2 * c - i], r - i) : 1;
//
//		while (i + len < n && i - len >= 0 && ss[i + len] == ss[i - len])
//			++len;
//
//		if (i + len > r) {
//			r = i + len;
//			c = i;
//		}
//
//		p[i] = len;
//		if (len > mx) {
//			mx = len;
//			mc = i;
//		}
//	}
//	
//	mx -= 1;
//	int start = (mc - mx) >> 1;
//	return { start,mx };
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	string s;
//	string letter;
//	vector<int>pos;
//
//	char c;
//	while (cin.get(c) ) {
//		s += c;
//		if (isalpha(c)) { 
//			letter += tolower(c);
//			pos.push_back(s.size() - 1);  
//		}
//	}
//
//	auto ans = manacher(letter);
//
//	int l = pos[ans.first];
//	int r = pos[ans.first + ans.second - 1];
//
//	cout << ans.second << "\n";
//	for (int i = l; i <= r; ++i)
//		cout << s[i];
//	cout << "\n";
//
//	return 0;
//}