//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int manacher(const string& s) {
//	string ss;
//	for (char c : s) {
//		ss += '#';
//		ss += c;
//	}
//	ss += '#';
//
//	int n = ss.size();
//	//记录以i为中心的最大回文半径
//	vector<int>p(n, 0);
//	int mx = 0;
//	int c = 0, r = 0;//回文中心和最右边界（下一个要匹配位置）
//
//	for (int i = 0; i < n; ++i) {
//		//r>i，被r包住
//		//2*c-i是i关于c的对称位置
//		//完全包住那就是p[2*c-i]
//		//恰好到边界，那么就是r-i，但是往边界外需要继续判断
//		//如果<，没被包住，就从自己开始回文，刚开始本身为1
//		int len = (r > i) ? min(p[2 * c - i], r - i) : 1;
//
//		//向边界外扩展看看是否匹配
//		//左右两边都不能越界
//		while (i + len < n && i - len >= 0 && ss[i + len] == ss[i - len])
//			len++;
//
//		//如果变大更新
//		if (i + len > r) {
//			r = i + len;
//			c = i;
//		}
//
//		p[i] = len;
//		mx = max(mx, len);
//	}
//
//	return mx - 1;
//}
//
//int main() {
//	string s;
//	cin >> s;
//	cout << manacher(s) << "\n";
//	return 0;
//}