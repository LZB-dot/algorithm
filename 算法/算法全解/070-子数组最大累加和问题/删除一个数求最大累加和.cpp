////删掉1个数字后长度为k的子数组最大累加和
////给定一个数组nums，求必须删除一个数字后的新数组中
////长度为k的子数组最大累加和，删除哪个数字随意
//
//#include <iostream>
//#include <vector>
//#include <deque>
//#include <climits>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//    int maxSumAfterDelete(vector<int>& nums, int k) {
//        int n = nums.size();
//
//        // 题目要求删除一个元素后长度为k，所以原始数组长度必须至少为 k+1
//        if (n < k + 1) {
//            return 0;
//        }
//
//        deque<int> min_queue; // 单调队列，用于维护窗口内的最小值的索引
//        long long window_sum = 0;
//        int ans = INT_MIN;
//
//        for (int i = 0; i < n; ++i) {
//            // 1. 将当前元素加入窗口，并维护单调队列
//            // 队列保持单调递增，队首元素是当前窗口的最小值
//            while (!min_queue.empty() && nums[i] <= nums[min_queue.back()]) {
//                min_queue.pop_back();
//            }
//            min_queue.push_back(i);
//            window_sum += nums[i];
//
//            // 2. 当窗口大小达到 k+1 时，开始计算
//            if (i >= k) { // 因为窗口是 [i-k ... i]，大小为 k+1
//                // 当前窗口内删除一个元素后的最大值是 window_sum - 窗口内的最小值
//                int current_max = static_cast<int>(window_sum - nums[min_queue.front()]);
//                ans = max(ans, current_max);
//
//                // 3. 移动窗口，移除即将滑出窗口的元素
//                // 如果队首元素是即将滑出窗口的元素，则将其从队列中移除
//                if (min_queue.front() == i - k) {
//                    min_queue.pop_front();
//                }
//                window_sum -= nums[i - k];
//            }
//        }
//
//        return ans;
//    }
//};
