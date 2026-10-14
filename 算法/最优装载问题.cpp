//#include<stdio.h>
//#include<stdlib.h>
//
//int compare(const void* a, const void* b)
//{
//	return (*(int*)a - *(int*)b);
//}
//
//int optimal_loading(int w[], int n, int c)
//{
//	qsort(w, n, sizeof(int), compare);
//	int count = 0;
//	int current_weight = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (current_weight + w[i] <= c)
//		{
//			count++;
//			current_weight += w[i];
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	//集装箱重量
//	int w[] = { 20,30,10,40,50 };
//	int c = 100;//轮船载重量
//	int n = sizeof(w) / sizeof(w[0]);
//	int result = optimal_loading(w, n, c);
//	printf("能装载的最多集装箱数量为: %d\n", result);
//	return 0;
//}