//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX 100
//
//int n;// 作业数量
//int jobs[MAX][2];// 存储每个作业在两台机器上的处理时间
//int best_sequence[MAX];// 存储最优作业顺序
//int current_sequence[MAX];// 存储当前正在尝试的作业顺序
//int best_time = INT_MAX;
//int current_time = 0;
//
//void calculate_time()
//{
//    int machine1_time = 0, machine2_time = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int job = current_sequence[i];
//        machine1_time += jobs[job][0];
//        if (machine1_time > machine2_time)
//            machine2_time = machine1_time;
//        machine2_time += jobs[job][1];
//    }
//    current_time = machine2_time;
//    if (current_time < best_time)
//    {
//        best_time = current_time;
//        for (int i = 0; i < n; i++)
//            best_sequence[i] = current_sequence[i];
//    }
//}
//
//void backtrack(int depth)
//{
//    if (depth == n)
//    {
//        calculate_time();
//        return;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        int used = 0;
//        for(int j=0;j<depth;j++)
//            if (current_sequence[j] == i)
//            {
//                used = 1;
//                break;
//            }
//        if (!used)
//        {
//            current_sequence[depth] = i;
//            backtrack(depth + 1);
//        }
//    }
//}
//
//int main()
//{
//	printf("请输入作业数量：");
//	scanf("%d", &n);
//    printf("请依次输入每个作业在两台机器上的处理时间:\n");
//    for (int i = 0; i < n; i++) 
//    {
//        printf("作业 %d 的处理时间 (机器1 机器2): ", i + 1);
//        scanf("%d %d", &jobs[i][0], &jobs[i][1]);
//    }
//    for (int i = 0; i < n; i++)
//        current_sequence[i] = -1;
//    backtrack(0);
//    printf("最优作业顺序：");
//    for (int i = 0; i < n; i++)
//        printf("%d ", best_sequence[i] + 1);
//    printf("\n最优处理时间：%d\n", best_time);
//    return 0;
//}