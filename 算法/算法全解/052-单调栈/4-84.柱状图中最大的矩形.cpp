////#include<iostream>
////#include<vector>
////using namespace std;
////
////class Solution {
////public:
////    int largestRectangleArea(vector<int>& heights) {
////        int n = heights.size();
////        vector<int>stk;
////        int ans = 0;
////        for (int r = 0; r < n; ++r) {
////            //´óÑ¹Ð¡
////            while (!stk.empty() &&
////                heights[stk.back()] >= heights[r]) {
////                int cur = stk.back();
////                stk.pop_back();
////                int l = stk.empty() ? -1 : stk.back();
////                ans = max(ans, heights[cur] * (r - l - 1));
////            }
////            stk.push_back(r);
////        }
////        while (!stk.empty()) {
////            int cur = stk.back();
////            stk.pop_back();
////            int l = stk.empty() ? -1 : stk.back();
////            ans = max(ans, heights[cur] * (n - l - 1));
////        }
////
////        return ans;
////    }
////};
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//
//class Solution {
//private:
//    int st[MAXN];
//    int r = 0;
//public:
//    int largestRectangleArea(vector<int>& heights) {
//        int n = heights.size();
//        int ans = 0;
//        for (int i = 0; i < n; ++i) {
//            while (r > 0 && heights[st[r - 1]] >= st[i]) {
//                int top = st[--r];
//                int L = r -1> 0 ? st[r - 1] : 0;
//                int R = i;
//
//                ans = max(ans, (R - L - 1) * heights[top]);
//            }
//        }
//
//        while (r > 0) {
//            int top = st[--r];
//            int R = n;
//            int L = r - 1 > 0 ? st[r - 1] : -1;
//            ans = max(ans, (R - L - 1) * heights[top]);
//        }
//
//        return ans;
//    }
//};
