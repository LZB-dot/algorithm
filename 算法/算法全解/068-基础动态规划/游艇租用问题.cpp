//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include<errno.h>
//#include<string.h>
//
//// 计算从出租站 1 到出租站 n 的最少租金
//int yachtRental(int** r, int n) 
//{
//    // 动态规划数组，dp[i] 表示从出租站 1 到出租站 i 的最少租金
//    int* dp = (int*)malloc((n + 1) * sizeof(int));
//    if (dp == NULL) 
//    {
//        printf("%s\n", strerror(errno));
//        return -1;
//    }
//    dp[1] = 0;
//    for (int i = 2; i <= n; i++) 
//    {
//        dp[i] = INT_MAX; 
//        for (int j = 1; j < i; j++)
//            if (dp[j] != INT_MAX && dp[j] + r[j - 1][i - 1] < dp[i])
//                dp[i] = dp[j] + r[j - 1][i - 1];
//    }
//    int result = dp[n];
//    free(dp);
//    return result;
//}
//
//int main()
//{
//    int n = 4;  // 出租站的数量
//    // 租金矩阵，r[i][j] 表示从出租站 i+1 到出租站 j+1 的租金
//    int r[3][4] = {
//        {0, 5, 15, 20},
//        {0, 0, 7, 10},
//        {0, 0, 0, 5}
//    };
//
//    // 将二维数组转换为指针数组
//    int** r_ptr = (int**)malloc(3 * sizeof(int*));
//    if (r_ptr == NULL) 
//    {
//        printf("%s\n",strerror(errno));
//        return 1;
//    }
//    for (int i = 0; i < 3; i++) 
//        r_ptr[i] = r[i];
//    // 计算最少租金
//    int minCost = yachtRental(r_ptr, n);
//    if (minCost != -1)
//        printf("从出租站 1 到出租站 %d 的最少租金为: %d\n", n, minCost);
//    free(r_ptr);
//    return 0;
//}