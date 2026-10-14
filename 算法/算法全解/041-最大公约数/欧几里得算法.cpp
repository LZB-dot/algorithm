//
//
////gcd(a,b)=gcd(b,a mod b)   b!=0
////		  =a   b==0
//
//#include<iostream>
//using namespace std;
//
//int gcd(int a, int b)
//{
//	if (b == 0)
//		return a;
//	else
//		return gcd(b, a % b);
//}
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	cout << "最大公约数为：" << gcd(a, b);
//	return 0;
//}