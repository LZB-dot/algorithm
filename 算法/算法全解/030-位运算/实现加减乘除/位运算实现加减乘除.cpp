//#include<iostream>
//using namespace std;
//
//int add(int a, int b) {
//	int ans = a;
//	while (b != 0) {
//		ans = a ^ b;
//		b = (a & b) << 1;
//		a = ans;
//	}
//	return ans;
//}
//
//int minu(int a, int b) {
//	return add(a, neg(b));
//}
//
//int neg(int n) {
//	return add(~n, 1);
//}
//
//int multiply(int a, int b) {
//	int ans = 0;
//	while (b != 0) {
//		if ((b & 1) == 1) {
//			ans = add(ans, a);
//		}
//		a <<= 1;
//		b >>= 1;
//	}
//	return ans;
//}
//
////a和b不能是最小整数
//int divide(int a, int b) {
//	int x = a < 0 ? neg(a) : a;
//	int y = b < 0 ? neg(b) : b;
//
//	int ans = 0;
//	for (int i = 30; i >= 0; i = minu(i, 1)) {
//		if ((x >> i) >= y) {
//			ans |= (1 << i);
//			x = minu(x, y << i);
//		}
//	}
//	return a < 0 ^ b < 0 ? neg(x) : ans;
//}
