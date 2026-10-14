//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <limits.h>
//
//int hanoi4_dp(int n) 
//{
//    int* dp = (int*)malloc((n + 1) * sizeof(int));
//    dp[0] = 0, dp[1] = 1;
//    for (int i = 2; i <= n; i++) 
//    {
//        dp[i] = 2 * dp[i - 1] + 1;
//        for (int j = 2; j < i; j++) 
//        {
//            int moves = 2 * dp[i-j] + (int)pow(2,j) - 1;
//            if (moves < dp[i]) 
//            {
//                dp[i] = moves;
//            }
//        }
//    }
//    int result = dp[n];
//    free(dp);
//    return result;
//}
//
//int main() 
//{
//    int n = 3;  // 圆盘的数量
//    int result = hanoi4_dp(n);
//    printf("四柱汉诺塔移动次数最少为：%d\n", result);
//    return 0;
//}