
////在i 到 n-1的范围内，找到最小值放在i位置，
//// 然后在i+1 - n-1范围内继续

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int arr[] = { 9,8,13,6,12,4,3,11,10,7,1,2,5 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < size; i++)
//	{
//		int min = i;
//		for (int j = i + 1; j < size; j++)
//		{
//			if (arr[min] > arr[j])
//				min = j;
//		}
//		swap(arr[i], arr[min]);
//	}
//	for (int i = 0; i < size; i++)
//		cout << arr[i] << "\t";
//	cout << endl;
//	return 0;
//}