//#include<stdio.h>
//#include<math.h>
//
//void Swap(float& a, float& b)
//{
//	float x = a;
//	a = b;
//	b = a;
//}
//
//// 计算当前所选择圆的圆心横坐标
//float Center(int t, float* r, float* x, int n)
//{
//	float temp = 0;
//	for (int j = 1; j < t; j++)
//	{
//		float valuex = x[j] + 2.0 * sqrt(r[t] * r[j]);
//		if (valuex > temp)
//			temp = valuex;
//	}
//	return temp;
//}
//
//// 计算当前圆排列的长度
//void Compute(int n, float* r, float* x, float* min)
//{
//	float low = 0, high = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (x[i] - r[i] < low)
//			low = x[i] - r[i];
//		if (x[i] + r[i] > high)
//			high = x[i] + r[i];
//	}
//	if (high - low < *min)
//		*min = high - low;
//}
//
//void BackTrack(int t, int n, float* r, float* x, float* min)
//{
//	if (t > n)
//		Compute(n, r, x, min);
//	else
//	{
//		for (int j = t; j <= n; j++)
//		{
//			Swap(r[t], r[j]);
//			float centerx = Center(t, r, x, n);
//			if (centerx + r[t] + r[1] < *min)
//			{
//				x[t] = centerx;
//				BackTrack(t + 1, n, r, x, min);
//			}
//			Swap(r[t], r[j]);
//		}
//	}
//}
//
//int main()
//{
//	int n = 3; // 假设圆的数量为3
//	float r[4] = { 0, 1.0, 2.0, 3.0 }; // 半径数组，下标从1开始，0号元素不用
//	float x[4] = { 0 }; // 圆心横坐标数组，下标从1开始，0号元素不用
//	float min = 1e9; // 初始化最小长度为一个较大值
//	BackTrack(1, n, r, x, &min);
//	printf("最小排列长度: %f\n", min);
//	return 0;
//}