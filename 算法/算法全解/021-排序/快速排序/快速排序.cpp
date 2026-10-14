//#include<iostream>
//#include<ctime>  // 包含time函数所需头文件
//using namespace std;
//
//int first, last;
//
//// 三向切分：将数组分为 <x、==x、>x 三部分
//void partition(int arr[], int l, int r, int x)
//{
//    int less = l - 1;    // 小于区右边界（初始为空）
//    int more = r + 1;    // 大于区左边界（初始为空）
//    int cur = l;         // 当前遍历指针
//
//    while (cur < more)  // 注意：循环条件应为cur < more（避免进入大于区）
//    {
//        if (arr[cur] < x)
//            swap(arr[++less], arr[cur++]);  // 加入小于区，移动当前指针
//        else if (arr[cur] > x)
//            swap(arr[--more], arr[cur]);    // 加入大于区，当前指针不动（需重新检查交换来的元素）
//        else
//            cur++;  // 等于区，直接移动指针
//    }
//
//    // 修正边界赋值：等于区范围是 [less+1, more-1]
//    first = less + 1;
//    last = more - 1;  // more+1 → 改为 more-1
//}
//
//void QuickSort(int arr[], int l, int r)
//{
//    if (l >= r)
//        return;
//
//    // 随机选择基准值（优化：避免最坏情况）
//    int i = l + rand() % (r - l + 1);  // 生成[l, r]范围内的随机索引
//    int x = arr[i];
//
//    // 切分并获取等于区边界
//    partition(arr, l, r, x);
//
//    // 递归排序小于区和大于区（等于区已有序，无需处理）
//    QuickSort(arr, l, first - 1);
//    QuickSort(arr, last + 1, r);
//}
//
//int main()
//{
//    srand((unsigned int)time(nullptr));  // 随机种子只初始化一次
//    int arr[] = { 9,8,13,6,12,4,3,11,10,7,1,2,5 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//
//    QuickSort(arr, 0, size - 1);
//
//    for (int i = 0; i < size; i++)
//        cout << arr[i] << " ";
//    cout << endl;
//
//    return 0;
//}
