//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//
//	vector<int>a(n);
//	int c1 = 0, c2 = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a[i];
//		if (a[i] == 1)
//			c1++;
//		else
//			c2++;
//	}
//
//	int min = (n - 1);
//	int max = (n - 1) + c2 - 1;
//
//	if (k<min || k>max)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//
//	int cur = k - min;
//	vector<int>res;
//	res.push_back(2);
//	c2--;
//
//	for (int i = 0; i < cur && c2>0; ++i)
//	{
//		res.push_back(2);
//		c2--;
//	}
//
//	bool flag = 1;
//	while (c1 > 0 || c2 > 0)
//	{
//		if (flag && c1 > 0)
//		{
//			res.push_back(1);
//			c1--;
//		}
//		else if (c2 > 0)
//		{
//			res.push_back(2);
//			c2--;
//		}
//		flag = !flag;
//	}
//	for (int num : res)
//		cout << num << " ";
//	cout << endl;
//	return 0;
//}