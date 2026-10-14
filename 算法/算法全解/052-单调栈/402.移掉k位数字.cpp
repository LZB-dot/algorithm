//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//    string removeKdigits(string num, int k) {
//        string ans;
//        int n = num.size();
//        vector<char>stack;
//        int cnt = 0;
//        bool flag = 1;
//
//        if (k >= n) {
//            return "0";
//        }
//
//        for (char c : num) {
//            while (flag && !stack.empty() && c < stack.back()) {
//                cnt++;
//                stack.pop_back();
//                if (cnt == k) {
//                    flag = 0;
//                    break;
//                }
//            }
//            stack.push_back(c);
//        }
//
//        int remain = k - cnt;
//        if (remain > 0) {
//            stack.erase(stack.end() - remain, stack.end());
//        }
//
//        int l = 0, m = stack.size();
//        while (l < m&& stack[l] == '0') {
//            ++l;
//        }
//
//        if (l == m) {
//            ans = "0";
//        }
//        else{
//            for (int i = l; i < m; ++i) {
//                ans += stack[i];
//            }
//
//        }
//        return ans;
//    }
//};