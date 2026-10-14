//#include<stdio.h>
//#include<limits.h>
//#include<stdlib.h>
//
//#define MAX_N 100
//
//int max(int a, int b)
//{
//	return a > b ? a : b;
//}
//
//int min(int a, int b)
//{
//	return a < b ? a : b;
//}
//
//void polygonGame(int values[], char ops[], int n, int* maxScore, int* minScore)
//{
//	/*m[i][j][0]：表示从第i个顶点开始，连续j个顶点组成的子多边形的最小得分。
//	m[i][j][1]：表示从第i个顶点开始，连续j个顶点组成的子多边形的最大得分。*/
//	int m[MAX_N][MAX_N][2];
//	for (int i = 0; i < n; i++)
//		m[i][1][0] = m[i][1][1] = values[i];
//	for (int j = 2; j <= n; j++)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			m[i][j][0] = INT_MAX;
//			m[i][j][1] = INT_MIN;
//			for (int k = 1; k < j; k++)
//			{
//				int opIndex = (i + k - 1) % n;
//				if (ops[opIndex] == '+')
//				{
//					int minVal = m[i][k][0] + m[(i + k) % n][j - k][0];
//					int maxVal = m[i][k][1] + m[(i + k) % n][j - k][1];
//					m[i][j][0] = min(m[i][j][0], minVal);
//					m[i][j][1] = max(m[i][j][1], maxVal);
//				}
//				else
//				{
//					int case1 = m[i][k][0] * m[(i + k) % n][j - k][0];
//					int case2 = m[i][k][0] * m[(i + k) % n][j - k][1];
//					int case3 = m[i][k][1] * m[(i + k) % n][j - k][0];
//					int case4 = m[i][k][1] * m[(i + k) % n][j - k][1];
//					m[i][j][0] = min(m[i][j][0], min(min(case1, case2), min(case3, case4)));
//					m[i][j][1] = max(m[i][j][1], max(max(case1, case2), max(case3, case4)));
//				}
//			}
//		}
//	}
//	*maxScore = INT_MIN;
//	*minScore = INT_MAX;
//	for (int i = 0; i < n; i++) 
//	{
//		*maxScore = max(*maxScore, m[i][n][1]);
//		*minScore = min(*minScore, m[i][n][0]);
//	}
//}
//
//int main()
//{
//	int values[] = { 3,4,5,7 };
//	char ops[] = { '+','*','+' };
//	int n = sizeof(values) / sizeof(values[0]);
//	int maxScore, minScore;
//	polygonGame(values, ops, n, &maxScore, &minScore);
//	printf("最大得分：%d\n", maxScore);
//	printf("最小得分：%d\n", minScore);
//	return 0;
//}