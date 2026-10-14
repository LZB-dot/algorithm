//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//        int n1 = nums1.size();
//        int n2 = nums2.size();
//        vector<int>ans(n1, -1);
//        vector<int>stack;
//        unordered_map<int, int>next;//元素值及对应下一个比他大的值
//
//        //小压大，遇到大的出栈
//        for (int i = 0; i < n2; ++i) {
//            while (!stack.empty() && nums2[i] > stack.back()) {
//                int tmp = stack.back();
//                stack.pop_back();
//                next[tmp] = nums2[i];
//            }
//            stack.push_back(nums2[i]);
//        }
//
//        for (int i = 0; i < n1; ++i) {
//            if (next.find(nums1[i]) != next.end()) {
//                ans[i] = next[nums1[i]];
//            }
//        }
//
//        return ans;
//    }
//};