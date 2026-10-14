//#include<iostream>
//#include<ctime>
//#include<vector>
//using namespace std;
//
//#pragma GCC optimize(3)
//#define endl "\n"
//
//int first, last;
//
//// 将数组分区，小于x的放左边，等于x的放中间，大于x的放右边
//void partition(vector<int>& arr, int l, int r, int x)
//{
//    int less = l - 1;
//    int more = r + 1;
//    int cur = l;
//    while (cur < more)
//    {
//        if (arr[cur] < x)
//            swap(arr[cur++], arr[++less]);
//        else if (arr[cur] > x)
//            swap(arr[cur], arr[--more]);
//        else
//            cur++;
//    }
//    first = less + 1;  // 等于x区域的起始索引
//    last = more - 1;   // 等于x区域的结束索引
//}
//
//// 查找数组中第target小的元素（1-based索引）
//int work(vector<int>& arr, int target)
//{
//    // 转换为0-based索引并检查有效性
//    target--;
//    if (arr.empty() || target < 0 || target >= arr.size())
//        return -1;  // 处理无效输入
//
//    int l = 0, r = arr.size() - 1;
//    while (true)  // 使用无限循环，直到找到目标
//    {
//        // 随机选择一个元素作为基准
//        int i = l + rand() % (r - l + 1);
//        int x = arr[i];
//
//        partition(arr, l, r, x);
//
//        // 根据目标位置与分区的关系调整查找范围
//        if (target < first)
//            r = first - 1;
//        else if (target > last)
//            l = last + 1;
//        else
//            return x;  // 找到目标元素
//    }
//}
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    srand((unsigned int)time(nullptr));
//    int n, target;
//    cin >> n >> target;
//    vector<int> arr(n);
//    for (int i = 0; i < n; i++)
//        cin >> arr[i];
//
//    cout << work(arr, target) << endl;
//    return 0;
//}
