//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int N, M;
//	cin >> N >> M;
//	vector<int>v(M + 1, 0);
//	for (int i = 1; i <= N; i++)
//	{
//		int count;
//		cin >> count;
//		for (int j = 0; j < count; j++)
//		{
//			int x;
//			cin >> x;
//			v[x]++;
//		}
//	}
//	int res = 0;
//	for (int i = 1; i <= M; i++)
//		if (v[i] == N)
//			res++;
//	cout << res;
//	return 0;
//}