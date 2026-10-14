//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<int> arr{ 9,5,8,2,7,12,4,3,1,11 ,10 };
//vector<int> result(arr.size()); // 辅助数组
//
//// 合并[left, mid]和[mid+1, right]两个有序区间
//void Merge(int left, int right, int mid)
//{
//    int i = left;  // 辅助数组的起始索引（对应原数组的left位置）
//    int x = left;  // 左子数组的当前索引
//    int y = mid + 1;  // 右子数组的当前索引
//
//    // 合并两个有序子数组到辅助数组
//    while (x <= mid && y <= right)
//    {
//        if (arr[x] <= arr[y])  // 取较小的元素放入辅助数组
//            result[i++] = arr[x++];
//        else
//            result[i++] = arr[y++];
//    }
//
//    // 处理左子数组剩余元素
//    while (x <= mid)
//        result[i++] = arr[x++];
//
//    // 处理右子数组剩余元素
//    while (y <= right)
//        result[i++] = arr[y++];
//
//    // 将辅助数组中[left, right]区间的元素拷贝回原数组
//    for (i = left; i <= right; i++)
//        arr[i] = result[i];
//}
//
//// 归并排序主函数，排序区间[left, right]
//void MergeSort(int left, int right)
//{
//    if (left < right)
//    {
//        int mid = (left + right) / 2;
//        MergeSort(left, mid);  // 排序左半部分
//        MergeSort(mid + 1, right);  // 排序右半部分
//        Merge(left, right, mid);  // 合并左右两部分
//    }
//}
//
//int main()
//{
//    cout << "排序前: ";
//    for (auto it : arr)
//        cout << it << "\t";
//    cout << endl;
//
//    MergeSort(0, arr.size() - 1);
//
//    cout << "排序后: ";
//    for (auto it : arr)
//        cout << it << "\t";
//    cout << endl;
//
//    return 0;
//}
