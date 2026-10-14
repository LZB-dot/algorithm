//
////t=min(a,b)
////gcd(a,b)=t	a%t==0&&b%t==0
////		  =t-1  a%t!=0||b%t!=0
//
//#include<iostream>
//using namespace std;
//
//int gcd(int a, int b)
//{
//	int x = min(a, b);
//	for (int i = x; i >= 1; i--)
//	{
//		if (a % i == 0 && b % i == 0)
//			return i;
//	}
//}
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	cout << "最大公约数为：" << gcd(a, b) << endl;
//	return 0;
//}