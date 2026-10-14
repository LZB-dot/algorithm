//#include<iostream>
//#include<vector>
//using namespace std;
//
//
////class Solution {
////private:
////    int n = 0;
////    int len = 0;
////    int start;
////    void dfs(int l, int r, const string& s) {
////       if (l > r) {
////            return;
////       }
////
////       if (l == r) {
////           if (1 > len) {
////               len = 1;
////               start = l;
////           }
////           return;
////       }
////
////       if (s[l] == s[r])
////           if (r - l == 1 || check(l + 1, r - 1, s)) {
////               if (r - l + 1 > len) {
////                   len = r - l + 1;
////                   start = l;
////               }
////           }
////
////       dfs(l + 1, r, s);
////       dfs(l, r - 1, s);
////    }
////
////    bool check(int l, int r, const string& s) {
////        int st = l, ed = r;
////        while (st < ed) {
////            if (s[st] != s[ed]) {
////                return false;
////            }
////            st++; ed--;
////        }
////        return true;
////    }
////public:
////    string longestPalindrome(string s) {
////        n = s.size();
////        dfs(0, n - 1, s);
////        return s.substr(start, len);
////    }
////};
//
//
//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int n = s.size();
//        if (n <= 1) {
//            return s;
//        }
//        int ans = 0;
//        int start = 0;
//        for (int i = 0; i < n - 1; ++i) {
//            int len1 = expand(i, i, s, n);
//            int len2 = expand(i, i + 1, s, n);
//            int cur = max(len1, len2);
//            if (cur > ans) {
//                ans = cur;
//                start = i - ((cur - 1) >> 1);
//            }
//        }
//
//        return s.substr(start, ans);
//    }
//
//    int expand(int l, int r, const string& s, int n) {
//        while (l >= 0 && r < n && s[l] == s[r]) {
//            --l; ++r;
//        }
//        return r - l - 1;
//    }
//};