//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int arr[] = { 9,8,13,6,12,4,3,11,10,7,1,2,5 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//
//    for (int i = 1; i < size; i++)
//    {
//        //实现0-i范围内的有序
//        int temp = arr[i];
//        //二分查找插入位置
//        int r = i - 1, l = 0;
//        int mid;
//        while (l <= r)
//        {
//            mid = (l + r) / 2;
//            if (temp > arr[mid])
//                l = mid + 1;
//            else
//                r = mid - 1;
//        }
//        //从l到i-1的元素全部右移
//        for (int j = i; j > l; j--)
//            arr[j] = arr[j - 1];
//        //l的位置存放i位置的元素
//        arr[l] = temp;
//    }
//    for (int i = 0; i < size; i++)
//        cout << arr[i] << "\t";
//    cout << endl;
//    return 0;
//}