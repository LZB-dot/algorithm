//#include<stdio.h>
//// 全局变量，用于记录最优装载重量
//int bestWeight = 0;
//
//void backtrack(int* w, int n, int capacity, int currentWeight, int index)
//{
//	if (currentWeight > bestWeight && currentWeight <= capacity)
//		bestWeight = currentWeight;
//	if (index == n)
//		return;
//	if (currentWeight + w[index] <= capacity)
//		backtrack(w, n, capacity, currentWeight + w[index], index + 1);
//	backtrack(w, n, capacity, currentWeight, index + 1);
//}
//
//int loadingProblem(int w[], int n, int capacity)
//{
//	backtrack(w, n, capacity, 0, 0);
//	return bestWeight;
//}
//
//int main()
//{
//	int w[] = { 20,30,60,30 };
//	int n = sizeof(w) / sizeof(w[0]);
//	int capacity = 100;
//	int result = loadingProblem(w, n, capacity);
//	printf("最大装载重量为：%d", result);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int c = 10;  // 载重限制
//int w[] = { 2, 2, 6, 5, 4 };  // 每个物品重量
//int n = sizeof(w) / sizeof(w[0]);  // 物品数量
//int* x, * bestx;
//int current_w = 0, best_w = 0;
//int r = 0;  // 剩余物品重量
//
//void backtrack(int i) {
//    if (i >= n) {
//        if (current_w > best_w) {
//            for (int j = 0; j < n; j++)
//                bestx[j] = x[j];
//            best_w = current_w;
//        }
//        return;
//    }
//    r -= w[i];
//    if (current_w + w[i] <= c) {
//        x[i] = 1;
//        current_w += w[i];
//        backtrack(i + 1);
//        current_w -= w[i];
//    }
//    x[i] = 0;
//    backtrack(i + 1);
//    r += w[i];
//}
//
//int main() {
//    // 动态分配内存
//    x = (int*)malloc(sizeof(int) * n);
//    bestx = (int*)malloc(sizeof(int) * n);
//    if (x == NULL || bestx == NULL) {
//        printf("Memory allocation failed!\n");
//        return 1;
//    }
//    // 计算初始物品总重量
//    for (int i = 0; i < n; i++)
//        r += w[i];
//    backtrack(0);
//    printf("最优装载方案:");
//    for (int i = 0; i < n; i++)
//        printf("%d ", bestx[i]);
//    printf("\n最大装载重量：%d\n", best_w);
//    // 释放动态分配的内存
//    free(x);
//    free(bestx);
//    return 0;
//}