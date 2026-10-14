
//在0 - i-1的范围内有序，i元素插入到里面，比i大的元素后移

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
//        int temp = arr[i];
//        int j = i - 1;
//        while (j >= 0 && temp < arr[j])
//        {
//            arr[j + 1] = arr[j];
//            j--;
//        }
//        arr[j + 1] = temp;
//    }
//    for (int i = 0; i < size; i++)
//        cout << arr[i] << "\t";
//    cout << endl;
//    return 0;
//}