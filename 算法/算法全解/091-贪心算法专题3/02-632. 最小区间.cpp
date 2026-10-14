//#include<iostream>
//#include<vector>
//#include<set>
//#include<climits> 
//using namespace std;
//
//class Solution {
//private:
//    struct Node {
//        int val;  // 数值
//        int arr;  // 所属数组的索引
//        int idx;  // 在所属数组中的位置
//
//        // 构造函数（保持不变）
//        Node(int a, int b, int c) : val(a), arr(b), idx(c) {}
//    };
//
//    struct CompareNode {
//        bool operator()(const Node& a, const Node& b) const {
//            if (a.val != b.val) {
//                return a.val < b.val; // 优先按数值升序
//            }
//            // 修正：值相等时按数组索引排序（更稳妥，避免去重）
//            return a.arr < b.arr;
//        }
//    };
//public:
//    vector<int> smallestRange(vector<vector<int>>& nums) {
//        int n = nums.size(); 
//        set<Node, CompareNode> s;
//
//        for (int i = 0; i < n; ++i) {
//            s.insert(Node(nums[i][0], i, 0));
//        }
//
//        int left = -1, right = -1;
//        int ans = INT_MAX;
//
//        while (s.size() == n) {
//            Node l = *s.begin();       // 最小值节点
//            Node r = *s.rbegin();      // 最大值节点
//            // 更新最小区间
//            if (r.val - l.val < ans) {
//                ans = r.val - l.val;
//                left = l.val;
//                right = r.val;
//            }
//
//            // 移除当前最小值节点
//            s.erase(s.begin());
//
//            //计算下一个元素的位置，并判断是否越界
//            int next_idx = l.idx + 1; 
//            int next_arr = l.arr;      // 所属数组的索引
//            // 只有下一个位置不越界时，才插入新节点
//            if (next_idx < nums[next_arr].size()) {
//                s.insert(Node(nums[next_arr][next_idx], next_arr, next_idx));
//            }
//        }
//
//        return { left, right };
//    }
//};
