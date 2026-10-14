//#include<iostream>
//#include<vector>
//#include<iomanip>
//#include<cmath>
//using namespace std;
//
//const int MAXN = 105;
//const double eps = 1e-7;
//double mat[MAXN][MAXN];
//
//int gauss(int n) {
//	//遍历每一行
//	for (int i = 1; i <= n; ++i) {
//		//寻找主元 把最大的移过来
//		int mx = i;
//		//遍历下面每一行
//		for (int j = i + 1; j <= n; ++j) {
//			if (fabs(mat[j][i]) > fabs(mat[mx][i]))
//				mx = j;
//		}
//		//移到当前处理的行
//		swap(mat[i], mat[mx]);
//		//主元为0 说明这一列都是0 无唯一解
//		if (fabs(mat[i][i]) < eps)
//			return 0;
//
//		//对当前行进行归一化
//		double div = mat[i][i];
//		for (int j = i; j <= n + 1; ++j)
//			mat[i][j] /= div;
//
//		//消除其余行的第i列
//		//遍历除了当前行的每一行
//		for (int j = 1; j <= n; ++j) {
//			if (i != j && fabs(mat[j][i]) > eps) {
//				double rate = mat[j][i];
//
//				for (int k = i; k <= n + 1; ++k)
//					mat[j][k] -= rate * mat[i][k];
//			}
//		}
//	}
//
//	return 1;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; ++i)
//		for (int j = 1; j <= n + 1; ++j)
//			cin >> mat[i][j];
//
//
//	int ok = gauss(n);
//	if (!ok)
//		cout << "No Solution\n";
//	else {
//		cout << fixed << setprecision(2);
//		for (int i = 1; i <= n; ++i)
//			cout << mat[i][n + 1] << '\n';
//	}
//	return 0;
//}