#define _CRT_SECURE_NO_WARNINGS 1
 
//int search(int arr[], const int target, int left, int right)
//{
//	if (right >= left)
//	{
//		int m = (right + left) / 2;
//		if (target == arr[m])
//			return m;
//		else if (target < arr[m])
//			return search(arr, target, left, m - 1);
//		else
//			return search(arr, target, m + 1, right);
//	}
//	else
//		return -1;
//}