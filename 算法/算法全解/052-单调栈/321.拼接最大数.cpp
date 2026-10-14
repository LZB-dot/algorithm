//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//private:
//    vector<int> mxSub(const vector<int>& nums, int x) {
//        int n = nums.size();
//        if (x >= n) {
//            return nums;
//        }
//        if (x <= 0) {
//            return {};
//        }
//
//        vector<int>stack;
//        int cnt = n - x;
//        //栈是递减的
//        for (int i : nums) {
//            while (!stack.empty() && i > stack.back() && cnt != 0) {
//                stack.pop_back();
//                --cnt;
//            }
//            stack.push_back(i);
//        }
//        stack.resize(x);
//        return stack;
//    }
//    bool greater(const vector<int>& a,int i, const vector<int>& b,int j) {
//        int s1 = a.size(), s2 = b.size();
//        while (i < s1 && j < s2 && a[i] == b[j]) {
//            ++i; ++j;
//        }
//        return (j == s2) || (i<s1 && a[i]>b[j]);
//    
//    }
//    vector<int> merge(const vector<int>& a,const vector<int>& b) {
//        int s1 = a.size(), s2 = b.size();
//        vector<int>ans;
//        int i = 0, j = 0;
//        while (i < s1&&j < s2) {
//            if (greater(a, i, b, j)) {
//                ans.push_back(a[i++]);
//            }
//            else {
//                ans.push_back(b[j++]);
//            }
//        }
//        while (i < s1) {
//            ans.push_back(a[i++]);
//        }
//        while (j < s2) {
//            ans.push_back(b[j++]);
//        }
//        return ans;
//    }
//public:
//    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
//        int n = nums1.size(), m = nums2.size();
//        vector<int>ans;
//        //nums1: i      nums2: j
//        //left是i的最小值,
//        //k-m小于0说明可以全在nums2选，nums1可以为0
//        //大于0说明在nums1至少里面选k-m个
//        int left = max(0, k - m);
//        //i的最大值是n或k的最小值
//        int right = min(n, k);
//        
//        for (int i = left; i <= right; ++i) {
//            int j = k - i;
//            if (i<0 || j>m) {
//                continue;
//            }
//
//            vector<int>s1 = mxSub(nums1, i);
//            vector<int>s2 = mxSub(nums2, j);
//            vector<int>cnt = merge(s1, s2);
//
//            if (ans < cnt) {
//                ans = cnt;
//            }
//        }
//
//        return ans;
//    }
//};