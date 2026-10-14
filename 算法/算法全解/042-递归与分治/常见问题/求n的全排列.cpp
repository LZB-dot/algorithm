//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<errno.h>
//#include<string.h>
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void permute(int* arr, int start, int end)
//{
//	if (start == end) 
//	{
//		for (int i = 0; i <= end; i++)
//			printf("%d ", arr[i]);
//		printf("\n");
//	}
//	else 
//	{
//		for (int i = start; i <= end; i++)
//		{
//			swap(&arr[start], &arr[i]);
//			permute(arr, start + 1, end);
//			swap(&arr[start], &arr[i]);
//		}
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int* arr = (int*)malloc(sizeof(int) * n);
//	if (arr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	for (int i = 0; i < n; i++)
//		arr[i] = i + 1;
//	permute(arr, 0, n - 1);
//	free(arr);
//	return 0;
//}
