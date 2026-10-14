//
////https://lightoj.com/problem/how-many-points
//
//#include<iostream>
//#include<cstdlib> 
//
//using namespace std;
//
//typedef long long ll;
//
///*
//格点：x,y都是整数的点
//给定两个格点 (x1,y1) (x2,y2)
//两点线段上包含两端，总格点数量 = gcd(dx, dy) + 1
//dx = |x1‑x2|， dy = |y1‑y2|
//原理：皮克定理相关 / 直线格点定理
//*/ 
//
//
//ll gcd(ll a, ll b) {
//    if (b != 0)
//        return gcd(b, a % b);
//    return a;
//}
//
//void solve(int i) {
//    ll x1, y1, x2, y2;
//    cin >> x1 >> y1 >> x2 >> y2;
//
//    ll dx = llabs(x1 - x2);
//    ll dy = llabs(y1 - y2);
//
//    ll ans = gcd(dx, dy) + 1;
//    cout << "Case " << i << ": " << ans << "\n";
//}
//
//int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int T;
//    cin >> T;
//
//    for (int i = 1; i <= T; ++i)
//        solve(i);
//
//    return 0;
//}
