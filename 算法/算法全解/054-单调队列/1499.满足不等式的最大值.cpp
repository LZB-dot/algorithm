//#include<iostream>
//#include<vector>
//#include<deque>
//#include<climits>  // 用于INT_MIN
//using namespace std;
//
//class Solution {
//public:
//    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
//        deque<pair<int, int>> dq;  // 存储(x_j, y_j - x_j)，维护y_j - x_j递减
//        int n = points.size();
//        int ans = INT_MIN;  // 初始化为最小值，避免负数结果错误
//
//        for (int i = 0; i < n; ++i) {
//            int x_i = points[i][0];
//            int y_i = points[i][1];
//
//            // 移除窗口外的点（x_i - x_j > k，不满足条件）
//            while (!dq.empty() && x_i - dq.front().first > k) {
//                dq.pop_front();
//            }
//
//            // 计算当前i与窗口内最优j的方程值
//            if (!dq.empty()) {
//                // 方程：(y_i - y_j) + (x_i + x_j) = (y_i + x_i) + (y_j - x_j)
//                int current = (y_i + x_i) + dq.front().second;
//                ans = max(ans, current);
//            }
//
//            // 维护队列：确保y_j - x_j递减，移除小于等于当前值的元素
//            while (!dq.empty() && dq.back().second <= (y_i - x_i)) {
//                dq.pop_back();
//            }
//            dq.push_back({ x_i, y_i - x_i });
//        }
//
//        return ans;
//    }
//};