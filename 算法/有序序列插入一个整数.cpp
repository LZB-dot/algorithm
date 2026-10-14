//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    vector<int>nums(n + 1);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    int target;
//    cin >> target;
//
//    // 修复二分查找逻辑
//    int l = 0, r = n;  // 右边界设为n，处理插入到末尾的情况
//    while (l < r)
//    {
//        int mid = l + (r - l) / 2;  // 避免溢出
//        if (nums[mid] < target)
//            l = mid + 1;
//        else
//            r = mid;
//    }
//
//    // 元素后移
//    for (int i = n; i > l; --i)
//        nums[i] = nums[i - 1];
//    nums[l] = target;
//
//    // 输出结果
//    for (int num : nums)
//        cout << num << " ";
//    cout << endl;
//    return 0;
//}
