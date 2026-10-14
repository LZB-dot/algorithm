//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//
//// 该函数用于计算数字塔从顶部到底部的最大路径和
//int max_path_sum(int** tower, int n)
//{
//    // 动态分配一个二维数组 dp 来存储中间结果
//    int** dp = (int**)malloc(n * sizeof(int*));
//    if (dp == NULL) {
//        printf("内存分配失败: %s\n", strerror(errno));
//        exit(1);
//    }
//    // 为 dp 数组的每一行分配内存
//    for (int i = 0; i < n; i++) 
//    {
//        dp[i] = (int*)malloc(n * sizeof(int));
//        if (dp[i] == NULL) 
//        {
//            printf("内存分配失败: %s\n", strerror(errno));
//            exit(1);
//        }
//    }
//    // 初始化 dp 数组的最后一行，
//    // 因为从最后一行的每个元素到底部的最大路径和就是其本身
//    for (int j = 0; j < n; j++)
//        dp[n - 1][j] = tower[n - 1][j];
//    // 从倒数第二行开始向上逐层计算每个位置到底部的最大路径和
//    for (int i = n - 2; i >= 0; i--) {
//        for (int j = 0; j <= i; j++) {
//            // 状态转移方程：当前位置的最大路径和
//            // 等于当前位置的值加上下方或右下方位置的最大路径和中的较大值
//            dp[i][j] = tower[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
//        }
//    }
//    // 最终结果存储在 dp[0][0] 中，即从顶部到底部的最大路径和
//    int result = dp[0][0];
//    for (int i = 0; i < n; i++)
//        free(dp[i]);
//    free(dp);
//    return result;
//}
//
//int main()
//{
//    // 定义一个二维数组 tower 来表示数字塔
//    int tower[5][5] = {
//        {9},
//        {12, 15},
//        {10, 6, 8},
//        {2, 18, 9, 5},
//        {19, 7, 10, 4, 16}
//    };
//    // 计算数字塔的行数
//    int n = sizeof(tower) / sizeof(tower[0]);
//    // 动态分配一个二维数组 tower_ptr 来存储数字塔
//    int** tower_ptr = (int**)malloc(n * sizeof(int*));
//    if (tower_ptr == NULL) 
//    {
//        printf("%s\n", strerror(errno));
//        return 1;
//    }
//    // 为 tower_ptr 数组的每一行分配内存，因为列数不一样
//    for (int i = 0; i < n; i++) 
//    {
//        tower_ptr[i] = (int*)malloc((i + 1) * sizeof(int));
//        if (tower_ptr[i] == NULL)
//        {
//            printf("%s\n", strerror(errno));
//            return 1;
//        }
//        // 将 tower 数组中的元素复制到 tower_ptr 数组中
//        for (int j = 0; j <= i; j++)
//            tower_ptr[i][j] = tower[i][j];
//    }
//    // 调用 max_path_sum 函数计算数字塔从顶部到底部的最大路径和
//    int max_sum = max_path_sum(tower_ptr, n);
//    printf("最大路径和：%d\n", max_sum);
//    for (int i = 0; i < n; i++)
//        free(tower_ptr[i]);
//    free(tower_ptr);
//    return 0;
//}