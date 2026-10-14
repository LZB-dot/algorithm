//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    string minWindow(string s, string t) {
//        if (s.empty() || t.empty())
//            return "";
//        string ans;
//
//        vector<int>demand(256, 0);
//        for (char c : t) {
//            demand[c]--;
//        }
//        int debt = t.size();
//        int n = s.size();
//        int len = INT_MAX;
//        int start;
//
//        //[l,r]
//        for (int l = 0, r = 0; r < n; ++r) {
//            if (++demand[s[r]] <= 0) {
//                debt--;
//            }
//
//            while (debt == 0) {
//                if (r - l + 1 < len) {
//                    len = r - l + 1;
//                    start = l;
//                }
//                if (--demand[s[l]] < 0) {
//                    debt++;
//                }
//                l++;
//            }
//        }
//        return len == INT_MAX ? "" : s.substr(start, len);
//    }
//};