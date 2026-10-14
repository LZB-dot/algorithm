////#include<iostream>
////#include<vector>
////#include<stack>
////using namespace std;
////
//////class Solution {
//////public:
//////    vector<int> dailyTemperatures(vector<int>& temperatures) {
//////        int n = temperatures.size();
//////        vector<int>ans(n, 0);
//////        stack<int>stk;
//////        for (int i = 0; i < n; ++i) {
//////            while (!stk.empty()
//////                && temperatures[i] > temperatures[stk.top()]) {
//////                int tmp = stk.top();
//////                stk.pop();
//////                ans[tmp] = i - tmp;
//////            }
//////            stk.push(i);
//////        }
//////        return ans;
//////    }
//////};
////
////class Solution {
////public:
////    vector<int> dailyTemperatures(vector<int>& temperatures) {
////        int n = temperatures.size();
////        vector<int>ans(n, 0);
////        vector<int>stk;
////        for (int i = 0; i < n; ++i) {
////            while (!stk.empty()
////                && temperatures[i] > temperatures[stk.back()]) {
////                int tmp = stk.back();
////                stk.pop_back();
////                ans[tmp] = i - tmp;
////            }
////            stk.push_back(i);
////        }
////        return ans;
////    }
////};
//
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int MAXN = 1e5 + 10;
//int st[MAXN];
//
//class Solution {
//public:
//    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        int n = temperatures.size();
//        vector<int>ans(n, 0);
//        int r = 0;
//
//        for (int i = 0; i < n; ++i) {
//            while (r != 0 && temperatures[st[r - 1]] < temperatures[i]) {
//                int top = st[--r];
//                ans[top] = i;
//            }
//
//            st[r++] = i;
//        }
//
//
//        for (int i = 0; i < n; ++i) {
//            if (ans[i] != 0)
//                ans[i] -= i;
//        }
//
//        return ans;
//    }
//};