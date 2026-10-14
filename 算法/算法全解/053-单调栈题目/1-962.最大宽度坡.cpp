

//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 50005;
//
//class Solution {
//private:
//    int st[MAXN];
//    int r = 0;
//public:
//    int maxWidthRamp(vector<int>& nums) {
//        int n = nums.size();
//
//        int ans = 0;
//        vector<int>L(n + 1, 0);
//        for (int i = 0; i < n; ++i) {
//            if (r == 0 || nums[st[r - 1]] >= nums[i]) 
//                st[r++] = i;
//
//        }
//
//        for (int i = n - 1; i >= 0; --i) {
//            while (r > 0 && nums[st[r - 1]] <= nums[i]) {
//                int tp = st[--r];
//                ans = max(ans, i - tp + 1);
//            }
//        }
//        return ans;
//    }
//};