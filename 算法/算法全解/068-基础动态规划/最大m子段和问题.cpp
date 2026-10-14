//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// 函数用于求解最大 m 子段和
//int maxMSubSum(int* arr, int n, int m) 
//{
//    if (n < m || m < 1)
//        return 0;
//
//    // 动态分配二维数组 dp 用于存储中间结果
//    // dp[i][j] 表示将前 j 个元素划分成 i 个不相交子段所能得到的最大和
//    int** dp = (int**)malloc((m + 1) * sizeof(int*));
//    for (int i = 0; i <= m; i++) 
//    {
//        dp[i] = (int*)malloc((n + 1) * sizeof(int));
//    }
//
//    // 初始化 dp 数组
//    for (int i = 0; i <= m; i++) 
//    {
//        for (int j = 0; j <= n; j++) 
//        {
//            if (i == 0 || j == 0)
//                dp[i][j] = 0;
//            else if (i > j)
//                // 子段数多于元素数，无法划分，设为负无穷（这里用 0 表示不可能情况）
//                dp[i][j] = 0;
//        }
//    }
//
//    // 动态规划填充 dp 数组
//    //控制子段的数量
//    for (int i = 1; i <= m; i++) 
//        //用于控制考虑的元素数量
//        for (int j = i; j <= n; j++) 
//        {
//            int max_val = dp[i][j - 1] + arr[j - 1];
//            for (int k = i - 1; k < j; k++) 
//                if (dp[i - 1][k] + arr[j - 1] > max_val) 
//                    max_val = dp[i - 1][k] + arr[j - 1];
//            dp[i][j] = max_val;
//        }
//
//    int result = dp[m][m];
//    for (int j = m; j <= n; j++) 
//        if (dp[m][j] > result) 
//            result = dp[m][j];
//
//    for (int i = 0; i <= m; i++)
//        free(dp[i]);
//    free(dp);
//
//    return result;
//}
//
//int main() {
//    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4, 20 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    int m = 4;
//    int result = maxMSubSum(arr, n, m);
//    printf("最大 %d 子段和为：%d\n", m, result);
//    return 0;
//}