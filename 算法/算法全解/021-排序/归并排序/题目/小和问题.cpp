//#include<iostream>
//#include<vector>h
//using namespace std;
//
//vector<int>arr;
//vector<int>help;
//
//long long merge(int l, int m, int r)
//{
//	long long ans = 0;
//	for (int j = m + 1, i = l, sum = 0; j <= r; j++)
//	{
//		while (i <= m && arr[i] <= arr[j])
//			sum += arr[i++];
//		ans += sum;
//	}
//	int start = l, a = l, b = m + 1;
//	while (a <= m && b <= r)
//		help[start++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
//	while (a <= m)
//		help[start++] = arr[a++];
//	while (b <= r)
//		help[start++] = arr[b++];
//	for (int i = l; i <= r; i++)
//		arr[i] = help[i];
//	return ans;
//}
//
//long long smallSum(int l, int r)
//{
//	if (l == r)
//		return 0;
//	int m = (l + r) / 2;
//	return smallSum(l, m) + smallSum(m + 1, r) + merge(l, m, r);
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	
//	int n;
//	cin >> n;
//	arr.resize(n);
//	help.resize(n);
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//	long long res = smallSum(0, n - 1);
//	cout << res << endl;
//	return 0;
//}