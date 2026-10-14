#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX 100
//
//int n;          // 图顶点数量
//int a[MAX][MAX];// 邻接矩阵表示图
//int x[MAX];     // 当前解，1表示顶点i在图中，0则相反
//int bestx[MAX]; // 最优解
//int bestn;      // 最大顶点数
//int cn;         // 当前顶点数
//
//void backtrack(int i) {
//    if (i > n) {
//        if (cn > bestn) {
//            bestn = cn;
//            // 修正：将判断条件改为 j <= n
//            for (int j = 1; j <= n; j++)
//                bestx[j] = x[j];
//        }
//        return;
//    }
//    int ok = 1;
//    for (int j = 1; j < i; j++) {
//        if (x[j] && !a[i][j]) {
//            ok = 0;
//            break;
//        }
//    }
//    if (ok) {
//        x[i] = 1;
//        cn++;
//        backtrack(i + 1);
//        cn--;
//    }
//    if (cn + n - i > bestn) {
//        x[i] = 0;
//        backtrack(i + 1);
//    }
//}
//
//int main() {
//    printf("请输入图的顶点数量: ");
//    scanf("%d", &n);
//
//    printf("请输入图的邻接矩阵（1表示相连，0表示不相连）:\n");
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            scanf("%d", &a[i][j]);
//        }
//    }
//
//    bestn = 0;
//    cn = 0;
//    // 初始化数组元素为 0
//    for (int i = 0; i < MAX; i++) {
//        x[i] = 0;
//        bestx[i] = 0;
//    }
//    backtrack(1);
//
//    printf("最大团的顶点数为: %d\n", bestn);
//    printf("最大团中的顶点为: ");
//    for (int i = 1; i <= n; i++) {
//        if (bestx[i]) {
//            printf("%d ", i);
//        }
//    }
//    printf("\n");
//    return 0;
//}