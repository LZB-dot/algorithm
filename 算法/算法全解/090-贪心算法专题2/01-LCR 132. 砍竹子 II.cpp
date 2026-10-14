//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define ll long long
//
//class Solution {
//private:
//    ll power(ll x, int n, int mod) {
//        ll sum = 1;
//        x %= mod;
//        while (n > 0) {
//            if (n & 1) {
//                sum = (x * sum) % mod;
//            }
//            n >>= 1;
//            x = (x * x) % mod;
//        }
//        return sum;
//    }
//public:
//    int cuttingBamboo(int bamboo_len) {
//        int mod = 1e9 + 7;
//        if (bamboo_len == 3)
//            return 2;
//        if (bamboo_len == 2)
//            return 1;
//        int p = bamboo_len % 3;
//        ll res = 0;
//        if (p == 0) {
//            res = power(3, bamboo_len / 3, mod);
//        }
//        else if (p == 1) {
//            res = power(3, (bamboo_len - 4) / 3, mod) * 4 % mod;
//        }
//        else {
//            res = power(3, (bamboo_len - 2) / 3, mod) * 2 % mod;
//        }
//        return (int)res;
//    }
//};