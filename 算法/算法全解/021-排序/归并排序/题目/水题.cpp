//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<int>help;
//
//void merge(vector<int>& v, int l, int r, int mid)
//{
//	int x = l, y = mid + 1, i = l;
//	while (x <= mid && y <= r)
//	{
//		if (v[x] <= v[y])
//			help[i++] = v[x++];
//		else
//			help[i++] = v[y++];
//	}
//	while (x <= mid)
//		help[i++] = v[x++];
//	while (y <= r)
//		help[i++] = v[y++];
//	for (int k = l; k <= r; ++k)
//		v[k] = help[k];
//}
//
//void work(vector<int>& v, int l, int r)
//{
//	if (l >= r)
//		return;
//	int m = (l + r) / 2;
//	work(v, l, m);
//	work(v, m + 1, r);
//	merge(v, l, r, m);
//}
//
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	int n;
//	cin >> n;
//	vector<int>v(n);
//	help.resize(n, 0);
//	for (int i = 0; i < n; i++)
//		cin >> v[i];
//	work(v, 0, n - 1);
//	for (int i : v)
//		cout << i << " ";
//	cout << endl;
//	return 0;
//}