//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>v(n+1, 0);
//	for (int i = 1; i <= n; i++)
//		cin >> v[i];
//	for (int i = 1; i <= n; i++)
//	{
//		bool flag = 1;
//		for (int j = i + 1; j <= n; j++)
//			if (v[j] > v[i])
//			{
//				cout << j << " ";
//				flag = 0;
//				break;
//			}
//		if (flag)
//			cout << "0 ";
//	}
//	return 0;
//}