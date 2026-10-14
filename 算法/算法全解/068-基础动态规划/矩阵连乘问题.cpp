#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<limits.h>
//
//void matriChainOrder(int p[], int n, int m[][100], int s[][100])
//{
//	//对角线为0，单个矩阵不需要相乘
//	for (int i = 1; i <= n; i++)
//		m[i][i] = 0;
//	//遍历不同规模的矩阵链，从2开始
//	for (int L = 2; L <= n; L++)
//	{
//		//从开头开始遍历长度为L的矩阵链
//		for (int i = 1; i <= n - L + 1; i++)
//		{
//			int j = i + L - 1;//计算当前矩阵链结束位置
//			m[i][j] = INT_MAX;//初始化为最大值便于更新
//			//尝试在不同位置k断开
//			for (int k = i; k < j ; k++)
//			{
//				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
//				if (q < m[i][j])
//				{
//					m[i][j] = q;
//					s[i][j] = k;//记录断开点
//				}
//			}
//		}
//	}
//}
//void priOptimalParens(int s[][100], int i, int j)
//{
//	if (i == j)
//		printf("A%d", i);
//	else
//	{
//		printf("(");
//		priOptimalParens(s, i, s[i][j]);//递归打印最优分割点左边
//		priOptimalParens(s, s[i][j] + 1, j);//递归打印最优分割点右边
//		printf(")");
//	}
//}
//int main()
//{
//	int p[] = { 30,35,15,5,10,20,25 };
//	int n = sizeof(p) / sizeof(p[0]) - 1;
//	//n是矩阵个数
//	int m[100][100], s[100][100];
//	//m数组用于存储矩阵链Ai...Aj的最少乘法次数
//	//s数组用于记录矩阵链Ai...Aj的最优分割点
//	matriChainOrder(p, n, m, s);
//	printf("最少乘法次数：%d\n", m[1][n]);
//	printf("最优计算顺序：");
//	priOptimalParens(s, 1, n);
//	printf("\n");
//	return 0;
//}