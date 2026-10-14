//#include<stdio.h>
//#include<stdlib.h>
//
//#define NoEdge -1
//
//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////i正在考虑城市编号，n城市总数，a邻接矩阵，表示i到j的距离
////x当前城市访问顺序，cc已经走过的总费用
//void Backtrack(int i, int n, int** a, int* x, int* bestx, int cc, int* bestc)
//{
//	if (i == n)
//	{
//		if (a[x[n - 1]][x[n]] != NoEdge &&
//			a[x[n]][1] != NoEdge &&
//			(cc + a[x[n - 1]][x[n]] + a[x[n]][1] < *bestc || *bestc == NoEdge))
//		{
//			for (int j = 1; j <= n; j++)
//				bestx[j] = x[j];
//			*bestc = cc + a[x[n - 1]][x[n]] + a[x[n]][1];
//		}
//	}
//	else
//	{
//		for (int j = i; j <= n; j++)
//		{
//			if (a[x[i - 1]][x[j]] != NoEdge &&
//				(cc + a[x[i - 1]][x[j]] < *bestc || *bestc == NoEdge))
//			{
//				Swap(x[i], x[j]);
//				cc += a[x[i - 1]][x[j]];
//				Backtrack(i + 1, n, a, x, bestx, cc, bestc);
//				cc -= a[x[i - 1]][x[j]];
//				Swap(x[i], x[j]);
//			}
//		}
//	}
//}
//
//int main() {
//    int n = 4; // 假设4个城市
//    int** graph = (int**)malloc((n + 1) * sizeof(int*));
//    for (int i = 0; i <= n; i++) {
//        graph[i] = (int*)malloc((n + 1) * sizeof(int));
//        for (int j = 0; j <= n; j++) {
//            graph[i][j] = NoEdge;
//        }
//    }
//    // 初始化邻接矩阵，这里简单设置一些值，你可以根据实际情况修改
//    graph[1][2] = 10;
//    graph[1][3] = 15;
//    graph[1][4] = 20;
//    graph[2][1] = 10;
//    graph[2][3] = 35;
//    graph[2][4] = 25;
//    graph[3][1] = 15;
//    graph[3][2] = 35;
//    graph[3][4] = 30;
//    graph[4][1] = 20;
//    graph[4][2] = 25;
//    graph[4][3] = 30;
//
//    int* x = (int*)malloc((n + 1) * sizeof(int));
//    int* bestx = (int*)malloc((n + 1) * sizeof(int));
//    for (int i = 1; i <= n; i++) {
//        x[i] = i;
//    }
//    int cc = 0;
//    int bestc = NoEdge;
//
//    Backtrack(2, n, graph, x, bestx, cc, &bestc);
//    printf("最短路径费用: %d\n", bestc);
//
//    for (int i = 0; i <= n; i++) {
//        free(graph[i]);
//    }
//    free(graph);
//    free(x);
//    free(bestx);
//
//    return 0;
//}