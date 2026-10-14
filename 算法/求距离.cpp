//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>v(n);
//	int mx = INT_MIN, mi = INT_MAX;
//	int rx = 0, ri = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//		if (mx < v[i])
//		{
//			rx = i;
//			mx = v[i];
//		}
//		if (mi > v[i])
//		{
//			ri = i;
//			mi = v[i];
//		}
//	}
//	int r1 = max(rx, ri);
//	int r2 = max(n - rx, n - ri) - 1;
//	int res = max(r1, r2);
//	cout << res << endl;
//	return 0;
//}