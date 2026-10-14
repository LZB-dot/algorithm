
//循环n-1轮，每次把最大值一直交换到末尾

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int arr[] = { 9,8,13,6,12,4,3,11,10,7,1,2,5 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//    for (int i = 0; i < size - 1; i++) //循环轮数
//    {
//        bool flag = false;  // 标记本轮是否有交换
//        for (int j = 0; j < size - i - 1; j++) 
//        {
//            if (arr[j] > arr[j + 1]) 
//            {
//                swap(arr[j], arr[j + 1]);
//                flag = true;
//            }
//        }
//        if (!flag) 
//            break;  
//    }
//	for (int i = 0; i < size; i++)
//		cout << arr[i] << "\t";
//	cout << endl;
//	return 0;
//}