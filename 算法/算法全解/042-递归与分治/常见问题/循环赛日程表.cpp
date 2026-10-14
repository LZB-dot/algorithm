//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#define N 16
//
//// 复制子矩阵的函数
//void copy(int arr[N][N], int x1, int y1, int x2, int y2, int n) 
//{
//    for (int i = 0; i < n; i++) 
//        for (int j = 0; j < n; j++) 
//            arr[x2 + i][y2 + j] = arr[x1 + i][y1 + j];
//}
//
//// 生成循环赛日程表的函数
//void table(int arr[N][N], int i, int j, int n) 
//{
//    if (n == 1) 
//        // 当 n 为 1 时，初始化该位置的值为当前子矩阵左上角对应的运动员编号
//        arr[i][j] = i + 1;
//    else 
//    {
//        int s = n >> 1;
//        // 递归生成左上角子表
//        table(arr, i, j, s);
//        // 递归生成左下角子表
//        table(arr, i + s, j, s);
//        // 把左上角复制到右下角
//        copy(arr, i, j, i + s, j + s, s);
//        // 把左下角复制到右上角
//        copy(arr, i + s, j, i, j + s, s);
//    }
//}
//
//// 打印日程表的函数
//void pri_table(int arr[N][N]) 
//{
//    for (int i = 0; i < N; i++) 
//    {
//        for (int j = 0; j < N; j++)
//            printf("%4d", arr[i][j]);
//        printf("\n");
//    }
//}
//int main() 
//{
//    int arr[N][N];
//    // 生成循环赛日程表
//    table(arr, 0, 0, N);
//    // 打印日程表
//    pri_table(arr);
//    return 0;
//}