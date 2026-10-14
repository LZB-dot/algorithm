////60 = 2 * 2 * 3 * 5
////24 = 2 * 2 * 2 * 3;
////gcd(60, 24) = 2 * 2 * 3 = 12;
////最大公约数等于公共素因子的乘积
//
////求素数的方法--埃拉托色尼筛算法
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//void Sieve(int n, vector<bool>& isPrime)
//{
//	isPrime[0] = isPrime[1] = false;
//	for (int i = 2; i * i <= n; i++)
//		if (isPrime[i])
//			for (int j = i * i; j <= n; j += i)
//				isPrime[j] = false;
//}
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	int n = min(a, b);
//	vector<bool>isPrime(n + 1, true);
//	Sieve(n, isPrime);
//	int gcd = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		if (isPrime[i])
//			while (a % i == 0 && b % i == 0)
//			{
//				gcd *= i;
//				a /= i;
//				b /= i;
//			}
//	}
//	cout << "最大公约数为：" << gcd << endl;
//	return 0;
//}