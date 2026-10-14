//#include<stdio.h>
//#include<float.h>
//#include<math.h>
//
//typedef  struct{
//	double x,y;
//}Point;
//
//double distance(Point p1, Point p2)
//{
//	return sqrt((p1.x-p2.x)*(p1.x-p2.x)
//		+ (p1.y - p2.y) * (p1.y - p2.y));
//}
//
//double trianglePerimeter(Point p1, Point p2, Point p3) 
//{
//	return distance(p1, p2) + distance(p2, p3) + distance(p3, p1);
//}
//
//double optimalTriangulation(Point polygon[], int n)
//{
//	//t[i][j] 表示从顶点 vi 到顶点 vj 构成的子多边形的最优三角剖分的权值
//	double t[100][100];
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			t[i][j] = 0;
//	//枚举子多边形长度
//	for (int len = 3; len <= n; len++)
//	{
//		//确保子多边形长度不超过n
//		for (int i = 0; i <= n - len; i++)
//		{
//			//子多边形结束顶点j
//			int j = i + len - 1;
//			t[i][j] = DBL_MAX;
//			for (int k = i + 1; k < j; k++)
//			{
//				double cost=t[i][k]+t[k][j]+ trianglePerimeter(polygon[i], polygon[k], polygon[j]);
//				if (cost < t[i][j])
//					t[i][j] = cost;
//			}
//		}
//	}
//	return t[0][n - 1];
//}
//int main()
//{
//	Point polygon[] = { {0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 1} };
//	int n = sizeof(polygon) / sizeof(polygon[0]);
//	double result = optimalTriangulation(polygon, n);
//	printf("凸多边形的最优三角剖分权值即周长之和为%.2f\n", result);
//	return 0;
//}