//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//
//int n;
//int sum = 0; //统计当前符号三角形中 “ - ”（代码中用 1 表示）的个数。
//int half;
//int p[100][100];//存储符号三角形
//
//void backtrack(int t)
//{
//	//如果+或-的个数超过一半则回溯
//	if ((sum > half) || (t * (t - 1) / 2 - sum > half))
//		return;
//	if (t > n)//已经生成完整的符号三角形
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n - i + 1; j++)
//			{
//				if (p[i][j] == 0)
//					printf("+ ");
//				else
//					printf("- ");
//			}
//			printf("\n");
//		}
//		printf("\n");
//	}
//	else
//	{
//		for (int i = 0; i < 2; i++)
//		{
//			p[1][t] = i;
//			sum += i;
//			for (int j = 2; j <= t; j++)
//			{
//				p[j][t - j + 1] = p[j - 1][t - j + 1] ^ p[j - 1][t - j + 2];
//				sum += p[j][t - j + 1];
//			}
//			backtrack(t + 1);
//			for (int j = 2; j <= t; j++)
//				sum -= p[j][t - j + 1];
//			sum -= i;
//		}
//	}
//}
//
//int main()
//{
//	printf("请输入符号三角形第一行的元素个数n: ");
//	scanf("%d", &n);
//	half = n * (n + 1) / 4;
//	if (n * (n + 1) / 2 % 2 != 0)
//	{
//		printf("无解\n");
//		return 0;
//	}
//	//“ + ”（用 0 表示）和 “ - ”（用 1 表示）
//	backtrack(1);
//	return 0;
//	return 0;
//}