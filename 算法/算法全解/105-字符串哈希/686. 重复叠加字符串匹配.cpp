//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//typedef unsigned long long ull;
//const int base = 499;
//const int MAXN = 4e4 + 10;
//vector<ull>hashs(MAXN);
//vector<ull>power(MAXN);
//
//class Solution {
//private:
//    string tmp;
//
//    void build(int n) {
//        power[0] = 1;
//        for (int i = 1; i < n; ++i)
//            power[i] = power[i - 1] * base;
//        hashs[0] = tmp[0] - 'a' + 1;
//        for (int i = 1; i < n; ++i)
//            hashs[i] = hashs[i - 1] * base + tmp[i] - 'a' + 1;
//    }
//
//    ull getHash(int l, int r) {
//        ull res = hashs[r];
//        if (l > 0)
//            res -= hashs[l - 1] * power[r - l + 1];
//        return res;
//    }
//
//
//public:
//    int repeatedStringMatch(string a, string b) {
//        int n = a.size();
//        int m = b.size();
//
//        int k = (m + n - 1) / n;
//        tmp = "";
//        for (int i = 0; i < k; ++i)
//            tmp += a;
//
//        int s = tmp.size();
//        build(s);
//
//        ull hash_b = b[0] - 'a' + 1;
//        for (int i = 1; i < m; ++i)
//            hash_b = hash_b * base + b[i] - 'a' + 1;
//
//        for (int l = 0, r = m - 1; r < s; ++l, ++r) {
//            if (getHash(l, r) == hash_b)
//                return k;
//        }
//
//        tmp += a;
//        s = tmp.size();
//
//        build(s);
//        for (int l = 0, r = m - 1; r < s; ++l, ++r) {
//            if (getHash(l, r) == hash_b)
//                return k + 1;
//        }
//
//        return -1;
//    }
//};