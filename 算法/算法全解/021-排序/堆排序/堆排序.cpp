//
//#include<iostream>
//using namespace std;
//
//#pragma GCC optimize(3)
//#define endl "\n"
//
//void HeapInsert(int arr[], int i)
//{
//	while (arr[i] > arr[(i - 1) / 2])
//	{
//		swap(arr[i], arr[(i - 1) / 2]);
//		i = (i - 1) / 2;
//	}
//}
//
//void Heapify(int arr[], int i, int size)
//{
//	int l = 2 * i + 1, r = 2 * i + 2;
//	while (l < size)
//	{
//		int large = (r < size && arr[l] < arr[r]) ? r : l;
//		if (arr[large] <= arr[i])
//			break;
//		swap(arr[large], arr[i]);
//		i = large;
//		l = 2 * i + 1;
//		r = 2 * i + 2;
//	}
//}
//
//void BigHeapSort(int arr[], int size)
//{
//	//普通：自顶向底建堆
//	//for (int i = 0; i < size; i++)
//	//	HeapInsert(arr, i);
//	//优化：自底向顶建堆（从非叶子节点开始）
//	for (int i = size / 2 - 1; i >= 0; i--)
//		Heapify(arr, i, size);
//	size--;
//	while (size >= 0)
//	{
//		swap(arr[0], arr[size]);
//		Heapify(arr, 0, --size);
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	int arr[] = { 9,8,13,6,12,4,3,11,10,7,1,2,5 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	BigHeapSort(arr, size);
//	for (int i : arr)
//		cout << i << " ";
//	cout << endl;
//	return 0;
//}