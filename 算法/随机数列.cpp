//#include<iostream>
//#include<string>
//#include<climits>
//using namespace std;
//
//const int N = 1e5 + 1;
//
//int main()
//{
//	int T;
//	cin >> T;
//	while (T--)
//	{
//		int a[N];
//		int n;
//		cin >> n;
//		int mx = INT_MIN, mi = INT_MAX;
//		double av = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//			mx = max(mx, a[i]);
//			mi = min(mi, a[i]);
//			av += a[i];
//		}
//		av /= n;
//		double t = 0.0;
//		for (int i = 0; i < n; i++)
//			t += (a[i] - av) * (a[i] - av);
//		t /= n;
//		cout << (mx - mi) << " ";
//		printf("%.3lf\n", t);
//	}
//	return 0;
//}