//#include <iostream>
//#include <vector>
//#include <deque> 
//using namespace std;
////
////class Solution {
////public:
////    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
////        int n = nums.size();//数组长度
////        deque<int> dq;//双端队列，存储数组元素的索引，维护队列内元素值递减
////        vector<int> ans;//存储每个滑动窗口的最大值
////
////        // 预处理：先处理前 k-1 个元素，为第一个完整窗口做准备
////        for (int i = 0; i < k - 1; ++i) {
////            // 弹出队列尾部所有值 <= 当前元素的索引
////            // 原因：这些元素在当前元素右侧，且值更小，永远不可能成为窗口最大值
////            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
////                dq.pop_back();
////            }
////            dq.push_back(i);  // 将当前元素索引加入队列尾部
////        }
////
////        // 滑动窗口遍历：从第一个完整窗口（左边界0，右边界k-1）开始
////        // l：窗口左边界，r：窗口右边界，每次循环窗口整体右移一位
////        for (int l = 0, r = k - 1; r < n; ++l, ++r) {
////            // 步骤1：将当前右边界元素r加入队列，维护队列递减性
////            while (!dq.empty() && nums[dq.back()] <= nums[r]) {
////                dq.pop_back();  // 弹出所有小于等于当前元素的尾部索引
////            }
////            dq.push_back(r);    // 当前元素索引入队
////
////            // 步骤2：当前窗口的最大值是队首元素对应的数值
////            // 因为队列递减，队首始终是窗口内最大元素的索引
////            ans.push_back(nums[dq.front()]);
////
////            // 步骤3：若队首元素是窗口左边界l，说明它即将离开窗口，需从队列中移除
////            if (dq.front() == l) {
////                dq.pop_front();
////            }
////        }
////
////        return ans;  // 返回所有窗口的最大值
////    }
////};
//
//
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        int n = nums.size();
//
//        deque<int>dq;
//
//        for (int i = 0; i < k - 1; ++i) {
//            while (!dq.empty() && nums[dq.back()] <= nums[i])
//                dq.pop_back();
//
//            dq.push_back(i);
//        }
//
//        int l = 0;
//        vector<int>ans;
//        for (int i = k - 1; i < n; ++i) {
//
//            while (!dq.empty() && nums[dq.back()] <= nums[i])
//                dq.pop_back();
//
//            dq.push_back(i);
//
//            ans.push_back(nums[dq.front()]);
//
//            if (!dq.empty() && dq.front() <= l)
//                dq.pop_front();
//
//            ++l;
//        }
//
//        return ans;
//    }
//};