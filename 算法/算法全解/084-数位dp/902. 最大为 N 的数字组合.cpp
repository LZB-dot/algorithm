//
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//
//class Solution {
//
//public:
//    int atMostNGivenDigitSet(vector<string>& digits, int n) {
//        int m = digits.size();
//        int tmp = n / 10;
//        int len = 1;
//        int offset = 1;
//        while (tmp) {
//            offset *= 10;
//            len++;
//            tmp /= 10;
//        }
//
//        vector<int>digit(m);
//        for (int i = 0; i < m; ++i) {
//            digit[i] = stoi(digits[i]);
//        }
//        return dfs(digit, n, offset, len, 0, 0);
//
//    }
//
//    //offset用来方便取数
//    //len剩余未确定的位数
//    //free标记是否已经无约束//1自由    0约束
//    //fix标记是否选过数字---1已选 0未选
//    int dfs(const vector<int>& digit, int target, int offset, int len, bool free, bool fix) {
//        if (len == 0) {
//            return fix == 1 ? 1 : 0;
//        }
//
//        int ans = 0;
//        int cur = target / offset % 10;
//
//        if (!fix) {
//            ans += dfs(digit, target, offset / 10, len - 1, 1, 0);
//        }
//
//        if (free) {
//            ans += digit.size() * dfs(digit, target, offset / 10, len - 1, 1, 1);
//        }
//        else {
//            for (int d : digit) {
//                if (d == cur) {
//                    ans += dfs(digit, target, offset / 10, len - 1, 0, 1);
//                }
//                else if (d < cur) {
//                    ans += dfs(digit, target, offset / 10, len - 1, 1, 1);
//                }
//                else {
//                    break;
//                }
//            }
//        }
//
//        return ans;
//    }
//};