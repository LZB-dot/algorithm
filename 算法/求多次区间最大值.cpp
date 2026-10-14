//#include<iostream>
//#include<cmath>
//using namespace std;
//
//const int N = 10000;
////st[i][j] 表示从第i个数开始，长度为2的j次方的最大值
//int st[N][21];
//int arr[N];
//
//void st_pre(int n)
//{
//	for (int i = 1; i <= n; i++)
//		st[i][0] = arr[i];
//    //枚举区间长度，1<<j为2的j次方
//	for (int j = 1; (1 << j) <= n; j++)
//        //枚举起点
//		for (int i = 1; i + (1 << j) - 1 <= n; i++)
//			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
//}
//
//int st_find(int l, int r)
//{
//    //r - l + 1为长度，2的k次方小于等于长度
//	int k = (int)log2(r - l + 1);
//	return max(st[l][k], st[r - (1 << k) + 1][k]);
//}
//
//int main() 
//{
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//        cin >> arr[i];
//    st_pre(n);
//    while (m--) 
//    {
//        int l, r;
//        cin >> l >> r;
//        cout << st_find(l, r) << endl;
//    }
//    return 0;
//}