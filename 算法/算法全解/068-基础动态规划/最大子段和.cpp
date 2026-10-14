#define _CRT_SECURE_NO_WARNINGS 1

//穷举法

//#include<stdio.h>
//int mss(const int arr[],const int n)
//{
//	int maxSum = arr[0];
//	for (int i = 0; i < n; i++)
//	{
//		int currentSum = 0;
//		for (int j = i; j < n; j++)
//		{
//			currentSum += arr[j];
//			if (currentSum > maxSum)
//				maxSum = currentSum;
//		}
//	}
//	return maxSum;
//}
//int main()
//{
//	int arr[] = { -1,1,-3,4,-1,2,1,-5,4 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int max_sum = mss(arr, n);
//	printf("最大子段和：%d\n", max_sum);
//	return 0;
//}

//递归与分治

//#include<iostream>
//using namespace std;
//int maxCrossSum(int arr[], int low, int mid, int high)
//{
//	// 计算包含中间元素向左扩展的最大和
//	int sum = 0; int leftSum = -999999;
//	for (int i = mid; i >= low; i--)
//	{
//		sum += arr[i];
//		if (sum > leftSum)
//			leftSum = sum;
//	}
//	// 计算包含中间元素向右扩展的最大和
//	sum = 0; int rightSum = -999999;
//	for (int i = mid + 1; i <= high; i++)
//	{
//		sum += arr[i];
//		if (sum > rightSum)
//			rightSum = sum;
//	}
//	return leftSum + rightSum;
//}
//int maxSubSum(int arr[], int low, int high)
//{
//	if (low == high)
//		return arr[low];
//	int mid = (low + high) / 2;
//	int lm = maxSubSum(arr, low, mid);
//	int rm = maxSubSum(arr, mid + 1, high);
//	int cm = maxCrossSum(arr, low, mid, high);
//	if (lm >= rm && lm >= cm)
//		return lm;
//	else if (rm >= lm && rm >= cm)
//		return rm;
//	else
//		return cm;
//}
//int main()
//{
//	int arr[] = { -2,1,-3,4,-1,2,1,-5,4,20 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int maxSum = maxSubSum(arr, 0, n - 1);
//	cout << "最大子段和为：" << maxSum << endl;
//	system("pause");
//	return 0;
//}

//动态规划法

//#include<stdio.h>
//int mss(const int arr[],const int n)
//{
//	int maxSum = arr[0];
//	int maxCurrentSum = arr[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (maxCurrentSum + arr[i] > arr[i])
//			maxCurrentSum += arr[i];
//		else
//			maxCurrentSum = arr[i];
//		if (maxSum < maxCurrentSum)
//			maxSum = maxCurrentSum;
//	}
//	return maxSum;
//}
//int main()
//{
//	int arr[] = { -1,1,-3,4,-1,2,1,-5,4 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int max_sum = mss(arr, n);
//	printf("最大子段和：%d\n", max_sum);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int maxSubSum(int arr[], int n, int& maxbegin, int& maxend)
//{
//	int s = 1, b = 0;
//	//s用于记录当前子段的起始位置
//	//b用于记录当前子段的和
//	int sum = 0;
//	//sum用于记录到目前为止的最大子段和
//	for (int i = 0; i <= n; i++)
//	{
//		if (b > 0)
//			b += arr[i];
//		else
//		{
//			b = arr[i];
//			s = i;
//		}
//		if (b > sum)
//		{
//			sum = b;
//			maxbegin = s;
//			maxend = i;
//		}
//	}
//	return sum;
//}
//int main()
//{
//	int arr[] = { -2,1,-3,4,-1,2,1,-5,4,20 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int begin = 0, end = 0;
//	int maxSum = maxSubSum(arr, n-1, begin,end);
//	cout << "最大子段和为：" << maxSum << endl;
//	for (int i = begin; i <= end; i++)
//		cout << arr[i] << ' ';
//	system("pause");
//	return 0;
//}