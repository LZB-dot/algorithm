//#include<iostream>
//using namespace std;
//
//int gcd(int a, int b) {
//	if (b == 0)
//		return a;
//	return gcd(b, a % b);
//}
//
//int lcm(int a, int b) {
//	return a / gcd(a, b) * b;
//}
//
//int main() {
//	int x, y; 
//	cin >> x >> y;
//	//gcd(x, y) ¡Á lcm(x, y) = x ¡Á y
//	//¼´x*y=i*j
//	//¼´gcd£¨a£¬b£©=1£¬a*b=lcm/gcd;
//
//	if (y % x != 0) {
//		cout << "0\n";
//		return 0;
//	}
//	int ans = 0;
//	int k = y / x;
//	for (int a = 1; a * a <= k; ++a) {
//		if (k % a == 0 && gcd(a, k / a) == 1) {
//			if (a == k / a)
//				ans += 1;
//			else
//				ans += 2;
//		}
//			
//	}
//	cout << ans << "\n";
//
//	return 0;
//}