//
//// 二维数组上单点增加、范围查询，使用树状数组的模版
//
////给你一个二维矩阵 matrix，请你设计并实现一个数据结构，支持以下两种操作：
////
////1. update(row, col, val)：更新 matrix[row][col] 的值为 val。
////2. sumRegion(row1, col1, row2, col2)：返回子矩阵中元素的总和，子矩阵的左上角为(row1, col1) ，右下角为(row2, col2)。
////
////实现 NumMatrix 类：
////- NumMatrix(int[][] matrix) 用整数矩阵 matrix 初始化对象。
////- void update(int row, int col, int val) 更新 matrix[row][col] 的值到 val。
////- int sumRegion(int row1, int col1, int row2, int col2) 返回左上角(row1, col1)、右下角(row2, col2) 的子矩阵的元素和。
////下标从0开始
//
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 1e4 + 10;
//int tree[MAXN][MAXN];
//int nums[MAXN][MAXN];
//int n, m;
//
//inline int lowbit(int x) {
//	return x & -x;
//}
//
//inline void add(int x, int y, int v) {
//	for (int i = x; i <= n; i += lowbit(i)) {
//		for (int j = y; j <= m; j += lowbit(j))
//			tree[i][j] += v;
//	}
//}
//
//inline int sum(int x, int y) {
//	int ans = 0;
//	for (int i = x; i >= 1; i -= lowbit(i)) {
//		for (int j = y; j >= 1; j -= lowbit(j))
//			ans += tree[i][j];
//	}
//
//	return ans;
//}
//
//void update(int x, int y, int v) {
//	add(x + 1, y + 1, v - nums[x + 1][y + 1]);
//	nums[x + 1][y + 1] = v;
//}
//
//int sumRegion(int a, int b, int c, int d) {
//	return sum(c + 1, d + 1) - sum(a, d + 1) - sum(c + 1, b) + sum(a, b);
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//
//
//
//	return 0;
//}