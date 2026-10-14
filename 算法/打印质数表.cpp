//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<bool>isPrime(n + 1, true);
//	if (n < 2)
//		return 0;
//	for (int i = 2; i * i <= n; ++i)
//		if (isPrime[i])
//			for (int j = i * i; j < n; j += i)
//				isPrime[j] = false;
//	for (int i = 2; i <= n; i++)
//		if (isPrime[i])
//			cout << i << " ";
//	cout << endl;
//	return 0;
//}