////在 mod 为质数时成立，时间复杂度 O(n)，可以快速求出 1~n 所有数的逆元。
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define ll long long 
//
//int n, mod;
//vector<ll>inv;
//
//void build() {
//    inv.resize(n + 1);
//	inv[1] = 1;//1的逆元为1
//	for (int i = 2; i <= n; ++i)
//        //inv[i]=(mod-mod/i)*inv[mod%i]%mod;
//		inv[i] = (mod - 1LL * (mod / i) * inv[mod % i] % mod) % mod;
//}
//
//int main() {
//    scanf("%d%d", &n, &mod);
//    inv.reserve(n + 1);
//    build();
//
//    for (int i = 1; i <= n; i++) {
//        printf("%lld\n", inv[i]); 
//    }
//
//    return 0;
//}