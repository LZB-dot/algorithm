////连续阶乘逆元的线性递推
////实现组合公式 C(n, m) 的计算，最终结果对 1000000007 取模后返回。
////输入范围：0≤m≤n≤1000
//
//#include <iostream>
//using namespace std;
//
//#define ll long long
//
//const int mod = 1e9 + 7;
//const int MAXN = 1000;
//
//ll fac[MAXN + 1];
//ll inv[MAXN + 1];
//
//ll power(ll x, int n) {
//    ll ans = 1;
//    x %= mod;
//    while (n) {
//        if (n & 1)
//            ans = (ans * x) % mod;
//        x = (x * x) % mod;
//        n >>= 1;
//    }
//    return ans;
//}
//
//void build() {
//    //预处理阶乘
//    fac[0] = fac[1] = 1;
//    for (int i = 2; i <= MAXN; ++i)
//        fac[i] = 1LL * i * fac[i - 1] % mod;
//
//    //先求最大的，然后进行倒推
//    inv[MAXN] = power(fac[MAXN], mod - 2);
//    for (int i = MAXN - 1; i >= 0; --i)
//        inv[i] = 1LL * (i + 1) * inv[i + 1] % mod;
//}
//
////不计顺序，从n个元素里面取出m个有多少种不同解法
////n!/( m!*(n-m)! )
//int c(int n, int m) {
//    ll ans = fac[n];
//    ans = ans * inv[m] % mod;
//    ans = ans * (inv[n - m]) % mod;
//    return (int)ans;
//}
//
//int main() {
//    build();
//
//    cout << "C(5,2) = " << c(5, 2) << endl;
//
//    return 0;
//}