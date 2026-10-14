//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int partition(int arr[], int s, int t)
//{
//	int l = s, r = t;
//	int target = arr[s];
//	while (l < r)
//	{
//		while (l < r && arr[r] > target)
//			r--;
//		if (l < r)
//			arr[l++] = arr[r];
//		while (l < r && arr[l] < target)
//			l++;
//		if (l < r)
//			arr[r--] = arr[l];
//	}
//	arr[r] = target;
//	return r;
//}
//
//int quick_select(int arr[], int s, int t, int k)
//{
//	if (s == t)
//		return arr[s];
//	int index = partition(arr, s, t);
//	if (index == k)
//		return arr[index];
//	else if (index > k)
//		return quick_select(arr, s, index - 1, k);
//	else
//		return quick_select(arr, index + 1, t, k);
//}
//
//int main()
//{
//	int arr[] = { 3,1,4,1,5,9,2,6,5,3,5 };
//	int s = sizeof(arr) / sizeof(arr[0]);
//	int k = 5;
//	int result = quick_select(arr, 0, s - 1, k-1);
//	printf("第%d小的元素为%d", k, result);
//	return 0;
//}