//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int countNumbersWithUniqueDigits(int n) {
//        if (n == 0) {
//            return 1;
//        }
//
//        int ans = 10;
//        int cur = 9;
//        int available = 9;
//        for (int k = 2; k <= n; ++k) {
//            cur *= available;
//            ans += cur;
//            available--;
//        }
//
//        return ans;
//
//    }
//};