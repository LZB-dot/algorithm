//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int L, M;
//	cin >> L >> M;
//	vector<int>diff(L + 2, 0);
//	for (int i = 0; i < M; i++)
//	{
//		int l, r;
//		cin >> l >> r;
//		diff.at(l)++;
//		if (r + 1 <= L)
//			diff.at(r + 1)--;
//	}
//	int res = 0;
//	int cur = 0;
//	for (int i = 0; i <= L; i++)
//	{
//		cur += diff.at(i);
//		if (cur == 0)
//			res++;
//	}
//	cout << res << endl;
//	return 0;
//}