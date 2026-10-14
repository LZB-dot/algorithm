//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define ll long long
//
//
//class Solution {
//private:
//    vector<vector<ll>> cal(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
//        ll n = a.size();
//        ll m = b[0].size();
//        ll t = b.size();
//        vector<vector<ll>>res(n, vector<ll>(m, 0));
//        for (ll i = 0; i < n; ++i)
//            for (ll j = 0; j < m; ++j)
//                for (ll k = 0; k < t; ++k)
//                    res[i][j] += a[i][k] * b[k][j];
//
//        return res;
//    }
//
//    vector<vector<ll>>power(vector<vector<ll>> a, ll p) {
//        ll n = a.size();
//        vector<vector<ll>>res(n, vector<ll>(n, 0));
//        //初始化为单位矩阵
//        for (ll i = 0; i < n; ++i)
//            res[i][i] = 1;
//
//        while (p) {
//            if (p & 1) {
//                res = cal(res, a);
//            }
//            p >>= 1;
//            a = cal(a, a);
//        }
//
//        return res;
//    }
//public:
//    int tribonacci(int n) {
//        if (n == 0)
//            return 0;
//        if (n <= 2)
//            return 1;
//        vector<vector<ll>>start = { {1,1,0} };
//        vector<vector<ll>>base = {
//            {1, 1, 0},
//            {1, 0, 1},
//            {1, 0, 0}
//        };
//
//        vector<vector<ll>>res = cal(start, power(base, n - 2));
//        return (int)res[0][0];
//    }
//};
//
