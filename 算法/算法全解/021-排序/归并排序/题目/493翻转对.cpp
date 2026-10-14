//#include <vector>
//using namespace std;
//
//class Solution {
//private:
//    vector<int> help;
//
//    long long work(vector<int>& nums, int l, int r) 
//    {
//        if (l >= r) 
//            return 0;
//
//        int m = l + ((r - l) >> 1);  // 安全计算中点，避免溢出
//        return work(nums, l, m) + work(nums, m + 1, r) + merge(nums, l, m, r);
//    }
//
//    // 归并并计算跨区间的重要翻转对
//    long long merge(vector<int>& nums, int l, int m, int r) 
//    {
//        long long ans = 0;
//        int i = l, j = m + 1;
//
//        while (i <= m && j <= r) 
//        {
//            if ((long long)nums[i] > 2LL * nums[j]) 
//            {
//                // 左区间当前元素及右侧所有元素都满足条件
//                ans += (m - i + 1);
//                j++;  // 检查右区间下一个元素
//            }
//            else
//                i++;  // 左区间当前元素不满足，移动左指针
//        }
//
//        // 执行归并操作，使区间有序
//        i = l;
//        j = m + 1;
//        int k = l;
//
//        while (i <= m && j <= r)
//        {
//            if (nums[i] <= nums[j])
//                help[k++] = nums[i++];
//            else
//                help[k++] = nums[j++];
//        }
//
//        // 处理剩余元素
//        while (i <= m)
//            help[k++] = nums[i++];
//
//        while (j <= r)
//            help[k++] = nums[j++];
//
//        for (k = l; k <= r; k++)
//            nums[k] = help[k];
//
//        return ans;
//    }
//
//public:
//    int reversePairs(vector<int>& nums) {
//        if (nums.size() < 2)
//            return 0;  // 元素不足2个，无翻转对
//        help.resize(nums.size());
//        return (int)work(nums, 0, nums.size() - 1);
//    }
//};
