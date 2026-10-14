//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//#include<errno.h>
//
//// 定义活动结构体，增加一个成员来记录原始编号
//typedef struct {
//    int start;
//    int end;
//    int id;  // 新增成员，用于记录活动的原始编号
//} Act;
//
//// 比较函数，用于 qsort 按结束时间排序
//int compare(const void* a, const void* b) 
//{
//    Act* act1 = (Act*)a;
//    Act* act2 = (Act*)b;
//    return act1->end - act2->end;
//}
//
//// 活动安排函数
//void actSelection(Act activities[], int n) 
//{
//    qsort(activities, n, sizeof(Act), compare);
//    printf("选择的活动编号为：%d ", activities[0].id);
//    int last_finish_time = activities[0].end;
//    for (int i = 1; i < n; i++) {
//
//        if (activities[i].start >= last_finish_time) 
//        {
//            printf("%d ", activities[i].id);
//            last_finish_time = activities[i].end;
//        }
//    }
//    printf("\n");
//}
//
//int main() {
//    int start_times[] = { 1, 3, 0, 5, 8, 5 };
//    int end_times[] = { 2, 4, 6, 7, 9, 9 };
//    int n = sizeof(start_times) / sizeof(start_times[0]);
//    Act* activities = (Act*)malloc(n * sizeof(Act));
//    if (activities == NULL) 
//    {
//        printf("%s\n", strerror(errno));
//        return 1;
//    }
//    // 初始化活动信息并记录原始编号
//    for (int i = 0; i < n; i++) 
//    {
//        activities[i].start = start_times[i];
//        activities[i].end = end_times[i];
//        activities[i].id = i + 1;  // 记录活动的原始编号
//    }
//    actSelection(activities, n);
//    free(activities);
//    return 0;
//}