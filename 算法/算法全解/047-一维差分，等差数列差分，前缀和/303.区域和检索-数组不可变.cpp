//#include<iostream>
//#include<vector>
//using namespace std;
//
//class NumArray {
//private:
//    vector<int>pre;
//public:
//    NumArray(vector<int>& nums) {
//        int n = nums.size();
//        pre.resize(n + 1, 0);
//        for (int i = 0; i < n; ++i) {
//            pre[i + 1] = pre[i] + nums[i];
//        }
//    }
//
//    int sumRange(int left, int right) {
//        return pre[right + 1] - pre[left];
//    }
//};