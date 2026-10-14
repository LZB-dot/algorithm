//#include<iostream>
//#include<vector>
//using namespace std;
//
//typedef long long ll;
//
//class Solution {
//private:
//    ll count(ll num, int d) {
//        ll ans = 0;
//        ll right = 1;
//        for (ll tmp = num; tmp > 0; tmp /= 10) {
//            ll left = tmp / 10;//左边数
//            ll cur = tmp % 10;//当前位数字
//            ll rt = num % right;
//            if (d == 0) {
//                if (left > 0)
//                    left--;
//            }
//
//            ans += left * right;
//
//            if (cur > d)
//                ans += right;
//            else if (cur == d)
//                ans += rt + 1;
//
//            right *= 10;
//        }
//
//        return ans;
//    }
//public:
//    int countDigitOne(int n) {
//        return (int)count((ll)n, 1);
//    }
//};