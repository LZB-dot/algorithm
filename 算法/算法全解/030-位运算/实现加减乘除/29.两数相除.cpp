//#include<iostream>
//using namespace std;
//
//
//class Solution {
//public:
//	int divide(int dividend, int divisor) {
//		if (dividend == INT_MIN && divisor == INT_MIN)
//			return 1;
//		if (dividend != INT_MIN && divisor != INT_MIN)
//			return divhelp(dividend, divisor);
//		if (divisor == INT_MIN)
//			return 0;
//		if (divisor == neg(1))
//			return INT_MAX;
//
//		dividend = add(dividend, divisor > 0 ? divisor : neg(divisor));
//		int ans = divhelp(dividend, divisor);
//		int offset = divisor > 0 ? neg(1) : 1;
//		return add(offset, ans);
//	}
//
//	int add(int a, int b) {
//		int ans = a;
//		while (b != 0) {
//			ans = a ^ b;
//			b = (a & b) << 1;
//			a = ans;
//		}
//		return ans;
//	}
//
//	int minu(int a, int b) {
//		return add(a, neg(b));
//	}
//
//	int neg(int n) {
//		return add(~n, 1);
//	}
//
//	//a和b不能是最小整数
//	int divhelp(int a, int b) {
//		int x = a < 0 ? neg(a) : a;  // 取a的绝对值
//		int y = b < 0 ? neg(b) : b;  // 取b的绝对值
//
//		int ans = 0;
//		for (int i = 30; i >= 0; i = minu(i, 1)) {
//			// 检查y * 2^i是否小于等于x
//			if ((x >> i) >= y) {
//				ans |= (1 << i);  // 将商的第i位置1
//				x = minu(x, y << i);  // 减去y * 2^i
//			}
//		}
//		return a < 0 ^ b < 0 ? neg(ans) : ans;
//	}
//};
