//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//#pragma GCC optimize(3)
//
//struct Team {
//	int a, b, c;
//};
//
//vector<Team>help;
//
//void Merge(vector<Team>& v, int l, int r, int mid)
//{
//	int i = l, x = l, y = mid + 1;
//	while (x <= mid && y <= r)
//	{
//		if (v[x].a < v[x].b)
//			help[i++].a = v[x++].a;
//		else
//			help[i++].a = v[y++].a;
//	}
//	while (x <= mid)
//		help[i++].a = v[x++].a;
//	while (y <= r)
//		help[i++].a = v[y++].a;
//	for (int k = l; k <= r; ++k)
//		v[k] = help[k];
//}
//
//void Sort(vector<Team>& v, int l, int r)
//{
//	if (l >= r)
//		return;
//	int mid = (l + r) / 2;
//	Sort(v, l, mid);
//	Sort(v, mid + 1, r);
//	Merge(v, l, r, mid);
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<Team>v(n);
//
//	for (int i = 0; i < n; ++i)
//		cin >> v[i].a >> v[i].b >> v[i].c;
//
//	help.resize(n);
//	Sort(v, 0, n - 1);
//	long long count = 0;
//	vector<pair<int, int>>bc;
//
//	for (int i = 0; i < n; i++)
//	{
//		int b = v[i].b;
//		int c = v[i].c;
//		//在bc查找第一个大于当前b的
//		auto it = upper_bound(bc.begin(), bc.end(), make_pair(b, 0));
//		for (auto j = it; j != bc.end(); ++j)
//			if (j->second > c)//继续查找所有大于当前c的
//				++count;
//		bc.insert(upper_bound(bc.begin(), bc.end(), make_pair(b, c)), make_pair(b, c));
//	}
//
//	long long sum= (long long)n * (n - 1) / 2;
//	long long ans = sum - 2 * count;
//	cout << ans << endl;
//	return 0;
//}