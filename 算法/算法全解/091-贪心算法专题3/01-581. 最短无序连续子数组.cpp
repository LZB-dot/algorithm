//#include<iostream>
//#include<vector>
//#include<climits>  // 补充缺失的头文件，用于INT_MIN/INT_MAX
//using namespace std;
//
//class Solution {
//public:
//    int findUnsortedSubarray(vector<int>& nums) {
//        int n = nums.size();
//        if (n <= 1) 
//            return 0; 
//
//        //从左到右找需要排序的最右边界p1
//        int mx = nums[0];  // 初始化最大值为数组第一个元素
//        int p1 = -1;       // 记录最右的无序位置
//        for (int i = 1; i < n; ++i) {
//            if (nums[i] >= mx) {  // 当前元素是最大值，更新最大值
//                mx = nums[i];
//            }
//            else {              // 当前元素小于最大值，说明无序，更新右边界
//                p1 = i;
//            }
//        }
//
//        // 如果p1=-1，说明数组完全有序，直接返回0
//        if (p1 == -1) return 0;
//
//        //从右到左找需要排序的最左边界p2
//        int mi = nums[n - 1];  // 初始化最小值为数组最后一个元素
//        int p2 = n;          // 记录最左的无序位置
//        for (int i = n - 2; i >= 0; --i) {
//            if (nums[i] <= mi) {  // 当前元素是最小值，更新最小值
//                mi = nums[i];
//            }
//            else {              //当前元素大于最小值，说明无序，更新左边界
//                p2 = i;
//            }
//        }
//
//        return p1 - p2 + 1;
//    }
//};
