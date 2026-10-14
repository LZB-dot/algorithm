//#include<stdio.h>
//#include<limits.h>
//#include<stdlib.h>
////求一维数组最大子段和
//int maxSubArray(int* nums, int n)
//{
//    int max_sum = INT_MIN;
//    int current_sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//// 如果当前子段和加上当前元素大于当前元素本身
//// 意味着继续累加当前元素到当前子段可以得到更大的和
//        if (current_sum + nums[i] > nums[i])
//            current_sum += nums[i];
////如果是负数，对后续子段和有负面影响，不进行相加
//        else
//            current_sum = nums[i];
//        if (current_sum > max_sum)
//            max_sum = current_sum;
//    }
//    return max_sum;
//}
//int maxSubmatrixSum(int** matrix, int rows, int cols)
//{
//    //矩阵为空则直接返回
//    if (rows == 0 || cols == 0)
//        return 0;
//    int max_sum = INT_MIN;
//    // 用于存储从第 i 行到当前行每列元素的累加和
//    int* temp = (int*)malloc(sizeof(int) * cols);
//    //枚举矩阵上边界
//    for (int i = 0; i < rows; i++)
//    {
//        for (int k = 0; k < cols; k++)
//            temp[k] = 0;
//        //枚举矩阵下边界
//        for (int j = i; j < rows; j++)
//        {
//            // 累加当前行（第 j 行）的元素到 temp 数组中
//            for (int k = 0; k < cols; k++)
//                // 将第 j 行第 k 列的元素累加到 temp[k] 中
//                temp[k] += matrix[j][k];
//        }
//        // 计算当前 temp 数组（代表从第 i 行到第 j 行每列元素累加和）的最大子段和
//        int current_sum = maxSubArray(temp, cols);
//        if (current_sum > max_sum)
//            max_sum = current_sum;
//    }
//    return max_sum;
//    free(temp);
//}
//int main()
//{
//    int matrix[3][3] = {
//       {1, -2, -3},
//       {-4, 5, -6},
//       {7, 8, -9}
//    };
//    int rows = 3;
//    int cols = 3;
//    int** matrixPtr = (int**)malloc(rows * sizeof(int*));
//    for (int i = 0; i < rows; i++)
//// 让 matrixPtr[i] 指向矩阵的第 i 行
//        matrixPtr[i] = matrix[i];
//    int result = maxSubmatrixSum(matrixPtr, rows, cols);
//    printf("最大子矩阵和为：%d", result);
//    free(matrixPtr);
//    return 0;
//}