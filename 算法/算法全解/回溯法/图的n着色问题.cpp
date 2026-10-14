#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//#define MAX 100
//
//int n;//顶点
//int m;//颜色种类数
//int a[MAX][MAX];//邻接矩阵
//int x[MAX];//解向量，表示第i个顶点颜色
//int sum = 0;//记录可行解数量
//
//// 检查当前顶点的颜色是否与相邻顶点冲突
//int ok(int k)
//{
//	for (int j = 1; j < k; j++)
//	{
//		if (a[k][j] && x[j] == x[k])
//			return 0;
//	}
//	return 1;
//}
//
//void backtrack(int t)
//{
//	if (t > n)
//		sum++;
//	else
//	{
//		for (int i = 1; i <= m; i++)
//		{
//			x[t] = i;
//			if (ok(t))
//				backtrack(t + 1);
//		}
//	}
//}
//
//int main() 
//{
//	printf("请输入图的顶点数n: ");
//	scanf("%d", &n);
//	printf("请输入颜色数m: ");
//	scanf("%d", &m);
//
//	// 输入邻接矩阵
//	printf("请输入邻接矩阵（1表示相连，0表示不相连）:\n");
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			scanf("%d", &a[i][j]);
//		}
//	}
//
//	backtrack(1);  // 从第一个顶点开始回溯搜索
//	printf("图的m着色问题的可行解数量为: %d\n", sum);
//
//	return 0;
//}



