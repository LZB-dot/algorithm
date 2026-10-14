//#include<stdio.h>
//#include<stdlib.h>
//
//int compare(const void* a, const void* b)
//{
//	return(*(int*)b - *(int*)a);
//}
//
//int greedyMinTime(int jobs[], int n, int m)
//{
//	if (m >= n)
//	{
//		int maxTime = jobs[0];
//		for (int i = 1; i < n; i++)
//			if (jobs[i] > maxTime)
//				maxTime = jobs[i];
//		return maxTime;
//	}
//	int* machineTime = (int*)malloc(sizeof(int) * m);
//	for (int i = 0; i < m; i++)
//		machineTime[i] = 0;
//	qsort(jobs, n, sizeof(int), compare);
//	for (int i = 0; i < n; i++)
//	{
//		int minIndex = 0;
//		for (int j = 1; j < m; j++)
//		{
//			if (machineTime[j] < machineTime[minIndex])
//				minIndex = j;
//		}
//		machineTime[minIndex] += jobs[i];
//	}
//	int maxTime = machineTime[0];
//	for (int i = 1; i < m; i++)
//	{
//		if (machineTime[i] > maxTime)
//			maxTime = machineTime[i];
//	}
//	free(machineTime);
//	return maxTime;
//
//}
//int main()
//{
//	int jobs[] = { 5,4,2,7,8,3 };
//	int n = sizeof(jobs) / sizeof(jobs[0]);
//	int m = 3;
//	int result = greedyMinTime(jobs, n, m);
//	printf("最短完成时间：%d\n", result);
//	return 0;
//}