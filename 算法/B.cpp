//#include<iostream>
//#include<vector>
//using namespace std;
//
//int gcd(int a, int b)
//{
//	while (b != 0)
//	{
//		int temp = b;
//		a = a % b;
//		a = temp;
//	}
//	return a;
//}
//
//int work(vector<int>& arr)
//{
//	if (arr.empty())
//		return 0;
//	int ans = arr[0];
//	for (int i : arr)
//	{
//		ans = gcd(ans, i);
//		if (ans == 1)
//			break;
//	}
//	return ans;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>a(n, 0);
//	vector<int>b(n - 1, 0);
//	for (int i = 0; i < n; ++i)
//		cin >> a[i];
//	for (int i = 0; i < n - 1; ++i)
//		b[i] = b[i] ^ b[i + 1];
//	cout << work(b) << endl;
//	return 0;
//}