//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>  
//using namespace std;
//
//class Solution {
//public:
//    string largestPalindromic(string num) {
//        int cnt[10] = { 0 };
//
//        for (char c : num)
//            cnt[c - '0']++;
//
//        string left;
//        char mid = 0; 
//        for (int i = 9; i >= 1; --i) {
//            if (mid == 0 && cnt[i] % 2 == 1) 
//                mid = i + '0';
//
//            for (int j = 0; j < cnt[i] / 2; ++j) {
//                left.push_back(i + '0');
//            }
//        }
//
//        if (left.empty()) {
//            if (mid == 0)
//                return "0";
//            else
//                return string(1, mid);
//        }
//        else {
//            if (mid == 0 && cnt[0] % 2 == 1) {
//                mid = '0';
//            }
//            for (int i = 0; i < cnt[0] / 2; ++i)
//                left.push_back('0');
//        }
//
//        string s = left;
//        string right = left;
//        reverse(right.begin(), right.end());
//        if (mid != 0)
//            s += mid;
//        s += right;
//        return s;
//    }
//};
