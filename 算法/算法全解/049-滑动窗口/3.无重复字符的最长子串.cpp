//#include<iostream>
//#include<vector>
//using namespace std;
//
////class Solution {
////public:
////    int lengthOfLongestSubstring(string s) {
////        if (s.empty())
////            return 0;
////        bool bitset[256] = { false };
////        int l = 0, r = 0, n = s.size();
////        int res = 0;
////        //[l,r)
////        while (l < n) {
////            if (r < n && bitset[s[r]] == 0) {
////                bitset[s[r++]] = 1;
////            }
////            else {
////                bitset[s[l++]] = 0;
////            }
////            res = max(res, r - l);
////        }
////        return res;
////    }
////
////};
//
//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        if (s.empty())
//            return 0;
//        int n = s.size();
//        vector<int>last(256, -1);
//        int ans = 0;
//        for (int l = 0, r = 0; r < n; ++r) {
//            l = max(l, last[s[r]] + 1);
//            ans = max(ans, r - l + 1);
//            last[s[r]] = r;
//        }
//        return ans;
//    }
//};