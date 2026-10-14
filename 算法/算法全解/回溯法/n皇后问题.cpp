#define _CRT_SECURE_NO_WARNINGS 1

//n叉树

//#include<stdio.h>
//#include<math.h>
//
//#define N 4//棋盘大小
//
//int x[N + 1];//存储每一行皇后所在列数，下标为行，值为列
//int sum = 0;//记录解的总数
//
//int Place(int k)
//{
//	for (int j = 1; j < k; j++)
//		if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
//			return 0;
//	return 1;
//}
//void Backtrack(int t)
//{
//    if (t > N)
//    {
//        sum++;
//        printf("第%d种解：", sum);
//        for (int i = 1; i <= N; i++)
//            printf("%d ", x[i]);
//        printf("\n");
//    }
//    else
//    {
//        for (int i = 1; i <= N; i++)
//        {
//            x[t] = i;
//            if (Place(t))
//                Backtrack(t + 1);
//        }
//    }
//}
//int main()
//{
//	Backtrack(1);
//	return 0;
//}

//排列树

//#include<stdio.h>
//#include<math.h>
//
//#define N 4
//
//int x[N + 1];
//int sum = 0;
//
//int Place(int k)
//{
//    for (int j = 1; j < k; j++)
//        // 检查是否在同一列或同一对角线上
//        if (x[j] == x[k] || abs(k - j) == abs(x[j] - x[k]))
//            return 0;
//    return 1;
//}
//
//void Backtrack(int t)
//{
//    if(t > N)
//    {
//        sum++;
//        printf("第%d种解：", sum);
//        for (int i = 1; i <= N; i++)
//            printf("%d ", x[i]);
//        printf("\n");
//    }
//    else
//    {
//        for (int i = t; i <= N; i++)
//        {
//            int temp = x[t];
//            x[t] = x[i];
//            x[i] = temp;
//            if (Place(t))
//                Backtrack(t + 1);
//            temp = x[t];
//            x[t] = x[i];
//            x[i] = temp;
//        }
//    }
//}
//
//int main() 
//{
//    // 初始化解向量，从 1 到 N
//    for (int i = 1; i <= N; i++)
//        x[i] = i;
//    // 从第一行开始回溯搜索
//    Backtrack(1);
//    printf("n 后问题（n = %d）的解的总数为: %d\n", N, sum);
//    return 0;
//}
//

