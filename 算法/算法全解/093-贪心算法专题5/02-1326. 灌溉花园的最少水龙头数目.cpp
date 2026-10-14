//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int minTaps(int n, vector<int>& ranges) {
//        vector<int>right(n + 1, 0);
//        for (int i = 0; i <= n; ++i) {
//            int left = max(0, i - ranges[i]);
//            int righ = min(n, i + ranges[i]);
//            right[left] = max(right[left], righ);
//        }
//
//        int ans = 0;
//        int cur = 0;
//        int next = 0;
//        for (int i = 0; i < n; ++i) {
//            next = max(next, right[i]);
//            if (cur == i) {
//                if (next <= i)
//                    return -1;
//                cur = next;
//                ans++;
//            }
//        }
//
//        return ans;
//    }
//};