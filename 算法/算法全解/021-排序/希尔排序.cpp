
////通过增量d，分成d组进行插入排序，然后d/=2继续直到d不为1停止

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int arr[] = { 9,8,13,6,12,4,3,11,10,7,1,2,5 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//
//	int d = size / 2;
//	while (d != 0)
//	{
//		for (int i = d; i < size; i++)
//		{
//			int temp = arr[i];
//			int j = i - d;
//			while (j >= 0 && arr[j] > temp)
//			{
//				arr[j + d] = arr[j];
//				j -= d;
//			}
//			arr[j + d] = temp;
//		}
//		d /= 2;
//	}
//
//	for (int i = 0; i < size; i++)
//		cout << arr[i] << "\t";
//    cout << endl;
//	return 0;
//}