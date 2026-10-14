//#include<iostream>
//using namespace std;
//
//typedef long long ll;
//
//// 快速幂
//ll mypow(ll a, ll b, ll MOD) {
//    ll sum = 1;
//    a %= MOD; //先取模避免溢出
//    while (b > 0) { 
//        if (b & 1)
//            sum = sum * a % MOD;
//        a = a * a % MOD;
//        b >>= 1;
//    }
//    return sum % MOD;
//}
//
//int main() {
//    ll k, L, p, s, w;
//    cin >> k >> L >> p >> s >> w;
//
//    //p=1时答案必为0
//    if (p == 1) {
//        cout << 0 << endl;
//        return 0;
//    }
//
//    if (s == 0) {
//        if (L == 1) {
//            cout << k % p << endl;
//        }
//        else if (L == 2) {
//            cout << (k % p) * ((k - 1) % p) % p << endl;
//        }
//        else {
//            //k*(k-1)*(k-2)^(L-2) mod p
//            ll part1 = k % p;
//            ll part2 = (k - 1) % p;
//            ll part3 = mypow((k - 2) % p, L - 2, p);
//            ll res = part1 * part2 % p;
//            res = res * part3 % p;
//            cout << res << endl;
//        }
//    }
//    else {
//        if (L == 1) {
//            cout << 1 % p << endl;
//        }
//        //(k-1)*(k-2)^(L-2) mod p
//        else {
//            ll part1 = (k - 1) % p;
//            ll part2 = mypow((k - 2) % p, L - 2, p);
//            ll res = part1 * part2 % p;
//            cout << res << endl;
//        }
//    }
//
//    return 0;
//}