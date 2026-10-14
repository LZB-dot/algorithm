//#include <iostream>
//#include <vector>
//#include <deque>
//using namespace std;
//
//class Solution {
//public:
//    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
//        int n = nums.size();
//        // 使用 deque 来维护窗口内最小值和最大值的索引
//        deque<int> minDeque, maxDeque;
//        long long result = 0;
//        int left = 0;
//
//        for (int right = 0; right < n; ++right) {
//            int current = nums[right];
//
//            // 如果当前元素超出 [minK, maxK] 范围，则窗口需要重置
//            if (current < minK || current > maxK) {
//                left = right + 1;
//                minDeque.clear();
//                maxDeque.clear();
//                continue;
//            }
//
//            // 维护 minDeque：确保队列是单调递增的
//            while (!minDeque.empty() && nums[minDeque.back()] >= current) {
//                minDeque.pop_back();
//            }
//            minDeque.push_back(right);
//
//            // 维护 maxDeque：确保队列是单调递减的
//            while (!maxDeque.empty() && nums[maxDeque.back()] <= current) {
//                maxDeque.pop_back();
//            }
//            maxDeque.push_back(right);
//
//
//            while (nums[minDeque.front()] < minK) {
//                left = minDeque.front() + 1;
//                minDeque.pop_front();
//            }
//            while (nums[maxDeque.front()] > maxK) {
//                left = maxDeque.front() + 1;
//                maxDeque.pop_front();
//            }
//
//
//            if (nums[minDeque.front()] == minK && nums[maxDeque.front()] == maxK) {
//                int r = min(minDeque.front(), maxDeque.front());
//                result += (r - left + 1);
//            }
//        }
//
//        return result;
//    }
//};
//
