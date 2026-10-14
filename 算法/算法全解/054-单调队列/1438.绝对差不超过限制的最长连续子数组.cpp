//#include<iostream>
//#include<vector>
//#include<deque>
//using namespace std;
//
//
//class Solution {
//private:
//    //维护窗口最大值和最小值下标
//    deque<int>mx;
//    deque<int>mi;
//    vector<int>arr;
//
//public:
//    //判断加入该数窗口是否合法
//    bool ok(int limit, int num) {
//        int maxVal = 0, minVal = 0;//窗口最大值最小值
//        //非空的话，队首为最大值下标
//        if (!mx.empty()) {
//            maxVal = max(num, arr[mx.front()]);
//        }
//        else {
//            maxVal = num;
//        }
//
//        //非空的话，队首为最小值下标
//        if (!mi.empty()) {
//            minVal = min(num, arr[mi.front()]);
//        }
//        else {
//            minVal = num;
//        }
//
//        return (maxVal - minVal) <= limit;
//    }
//
//    //将该下标进队
//    void push(int r) {
//        //如果递增队列非空且该下标对应元素>队尾元素，队尾元素出队
//        while (!mx.empty() && arr[r] > arr[mx.back()]) {
//            mx.pop_back();
//        }
//        mx.push_back(r);
//
//        //如果递减队列非空且该下标对应元素<队尾元素，队尾元素出队
//        while (!mi.empty() && arr[r] < arr[mi.back()]) {
//            mi.pop_back();
//        }
//        mi.push_back(r);
//    }
//
//    //调整窗口大小
//    void pop(int l) {
//        //队首下标等于左边界，那么下次窗口就不在了，所以出队
//        if (!mx.empty() && mx.front() == l) {
//            mx.pop_front();
//        }
//        if (!mi.empty() && mi.front() == l) {
//            mi.pop_front();
//        }
//    }
//    int longestSubarray(vector<int>& nums, int limit) {
//        arr = nums;
//        int n = arr.size();
//        int ans = 0;
//        for (int l = 0, r = 0; l < n; ++l) {
//            while (r < n && ok(limit, arr[r])) {
//                push(r);
//                ++r;
//            }
//            ans = max(ans, r - l);
//            pop(l);
//        }
//        return ans;
//    }
//};