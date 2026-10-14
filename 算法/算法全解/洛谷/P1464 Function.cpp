//#include<iostream>
//#include<cstring>
//using namespace std;
//
//#define ll long long
//
//const ll N = 21;
//
//ll dp[N][N][N];  
//
//ll work(ll a, ll b, ll c) {
//
//    if (a <= 0 || b <= 0 || c <= 0) {
//        return 1;
//    }
//    
//    if (a > 20 || b > 20 || c > 20) {
//        return work(20, 20, 20);
//    }
//
//    if (dp[a][b][c] != -1) {
//        return dp[a][b][c];
//    }
//
//    ll res;
//    
//    if (a < b && b < c) {
//        res = work(a, b, c - 1) + work(a, b - 1, c - 1) - work(a, b - 1, c);
//    }
//    
//    else {
//        res = work(a - 1, b, c) + work(a - 1, b - 1, c)
//            - work(a - 1, b - 1, c - 1) + work(a - 1, b, c - 1);
//    }
//
//    dp[a][b][c] = res;  
//    return res;
//}
//
//int main() {
//    ll a, b, c;
//    
//    memset(dp, -1, sizeof(dp));
//
//    while (cin >> a >> b >> c) {
//        if (a == -1 && b == -1 && c == -1)
//            break; 
//
//        ll ans = work(a, b, c);
//        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, ans);  
//    }
//    return 0;
//}