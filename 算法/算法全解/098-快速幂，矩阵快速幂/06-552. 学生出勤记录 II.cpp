//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define ll long long
//const int mod = 1e9 + 7;
//
//class Solution {
//private:
//    vector<vector<ll>>cal(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
//        int n = a.size();
//        int m = b[0].size();
//        int t = b.size();
//        vector<vector<ll>>res(n, vector<ll>(m, 0));
//        for (int i = 0; i < n; ++i)
//            for (int j = 0; j < m; ++j)
//                for (int k = 0; k < t; ++k)
//                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
//
//        return res;
//    }
//
//    vector<vector<ll>>power(vector<vector<ll>> a, int p) {
//        int n = a.size();
//        vector<vector<ll>>res(n, vector<ll>(n, 0));
//        for (int i = 0; i < n; ++i)
//            res[i][i] = 1;
//
//        while (p) {
//            if (p & 1)
//                res = cal(res, a);
//            a = cal(a, a);
//            p >>= 1;
//        }
//
//        return res;
//    }
//public:
//    int checkRecord(int n) {
//        if (n == 1)
//            return 3;
//
//        vector<vector<ll>>start = { {1,1,0,1,0,0} };
//        vector<vector<ll>>base = {
//            {1, 1, 0, 1, 0, 0},  
//        {1, 0, 1, 1, 0, 0}, 
//        {1, 0, 0, 1, 0, 0}, 
//        {0, 0, 0, 1, 1, 0}, 
//        {0, 0, 0, 1, 0, 1}, 
//        {0, 0, 0, 1, 0, 0}  
//        };
//        vector<vector<ll>>res = cal(start, power(base, n - 1));
//        ll total = 0;
//        for (int i = 0; i < 6; ++i) {
//            total = (res[0][i] + total) % mod;
//        }
//        return (int)total;
//    }
//};