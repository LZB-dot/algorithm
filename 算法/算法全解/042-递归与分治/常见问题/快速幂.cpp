//#define _CRT_SECURE_NO_WARNINGS 1
//
//
////递归
////a^ n	= 0, a == 0
////		= 1, a != 0 && n == 0
////		= (a ^ (n / 2)) ^ 2, a为偶数(a % 2 == 0)
////		= (a ^ (n / 2)) ^ 2 * a, a为奇数(a % 2 == 0)
//
////非递归
////n用二进制表达  如93--01011101
////93=1+4+8+16+64
//
//
//#include<iostream>
//using namespace std;
//
//////递归
////double fastPower(double a,int n)
////{
////	if (a == 0)
////		return 0;
////	else if (n == 0)
////		return 1;
////	else
////	{
////		double x = fastPower(a, n / 2);
////		if (n % 2 == 0)
////			return x * x;
////		else
////			return x * x * a;
////	}
////}
//
////非递归--更快一点
//double fastPower(double a, int n)
//{
//	double b = a;
//	int i = n;
//	double s = 1.0;
//	while (i > 0)
//	{
//		if (i % 2)
//			s *= b;
//		i >>= 1;
//		b *= b;
//	}
//	return s;
//}
//
//int main()
//{
//	double a;
//	int n;
//	cin >> a >> n;
//	cout << fastPower(a, n);
//	return 0;
//}