//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define ll long long
//const int mod = 1e9 + 7;
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
//                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
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
//
//public:
//    int countVowelPermutation(int n) {
//
//        vector<vector<ll>>start = { {1,1,1,1,1} };
//        vector<vector<ll>>base = {
//              {0, 1, 0, 0, 0},
//            {1, 0, 1, 0, 0},
//             {1, 1, 0, 1, 1},
//            {0, 0, 1, 0, 1},
//            {1, 0, 0, 0, 0}
//        };
//        vector<vector<ll>>res = cal(start, power(base, n - 1));
//        ll total = 0;
//        for (int i = 0; i < 5; ++i) {
//            total = (total + res[0][i]) % mod;
//        }
//        return (int)(total % mod);
//    }
//};