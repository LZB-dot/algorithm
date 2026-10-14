//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int T;
//	cin >> T;
//	while (T--)
//	{
//		int n, q;
//		cin >> n >> q;
//		vector<vector<int>>a(n, vector<int>(n, 0));
//		while (q--)
//		{
//			int op, k, v;
//			cin >> op >> k >> v;
//			if (op == 1)
//				for (int i = 0; i < n; ++i)
//					a[k-1][i] = v;
//			else if (op == 2)
//				for (int i = 0; i < n; ++i)
//					a[i][k-1] = v;
//		}
//		for (vector<int>& x : a)
//		{
//			for (int y : x)
//				cout << y << " ";
//			cout << endl;
//		}
//	}
//	return 0;
//}