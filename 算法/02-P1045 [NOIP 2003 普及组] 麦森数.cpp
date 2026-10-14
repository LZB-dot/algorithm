////一个正整数 N 的十进制位数 = log10​(N)+ 1
//
//#include<iostream>
//#include<cmath>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//const int N = 500;
//vector<int> res(N), x(N);
//
//vector<int>mul(const vector<int>& a, const vector<int>& b) {
//	vector<int>tmp(N << 1);
//	for (int i = 0; i < N; ++i) {
//		for (int j = 0; j < N; ++j) {
//			tmp[i + j] += a[i] * b[j];
//			tmp[i + j + 1] += tmp[i + j] / 10;
//			tmp[i + j] %= 10;
//		}
//	}
//
//	vector<int>ans(N);
//	for (int i = 0; i < N; ++i)
//		ans[i] = tmp[i];
//	return ans;
//}
//
//void quickpow(int p) {
//	x[0] = 2;
//	res[0] = 1;
//	while (p) {
//		if (p & 1)
//			res = mul(res, x);
//		x = mul(x, x);
//		p >>= 1;
//	}
//	res[0]--;
//}
//
//
//
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int p;
//	cin >> p;
//
//	int wei = static_cast<int>(p * log10(2.0)) + 1;
//	cout << wei << endl;
//
//	quickpow(p);
//	reverse(res.begin(), res.end());
//	for (int i = 0; i < 10; ++i) {
//		for (int j = 0; j < 50; ++j) {
//			cout << res[i * 50 + j];
//		}
//		cout << endl;
//	}
//	return 0;
//}