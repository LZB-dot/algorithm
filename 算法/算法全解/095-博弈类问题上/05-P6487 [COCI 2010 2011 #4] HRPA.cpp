////如果是斐波那契数列，那么先手一定要全取完才能必胜
////1 1 2 3 5 8 13 21 34....
//// 1 2 3，都是先手必败态
//
//// 13可以拆分为5 8 
//// 如果取大于等于5，那么后手可以直接取8，所以先手败
//// 如果取小于5，那么后手可以把剩余5的取完，然后继续面临8
//// 8=3+5
//// 如果取大于等于3，后手可以取完，先手败
//// 如果取小于3，那么后手可以把剩余3的取完，然后继续面临5
//// 5=2+3
//// 如果取大于等于2，后手可以取完，先手败
//// 如果取小于2，那么后手可以把剩余2的取完，然后继续面临3
//// 3除非先手全取完，那么先手必败
//
//#include<iostream>
//using namespace std;
//
//#define ll long long
//
//const ll N = 1e15 + 10;
//ll f[101];
//int s = 2;
//
//
//void build() {
//    f[0] = 1LL;
//    f[1] = 2LL;
//    ll cur = 0;
//    while (1) {
//        cur = f[s - 2] + f[s - 1];
//        if (cur > N) break;
//        f[s++] = cur;
//    }
//}
//
//ll bs(ll n) {
//    int l = 0, r = s - 1;
//    ll res = 0;
//    while (l <= r) {
//        int mid = l + ((r - l) >> 1);
//        if (f[mid] <= n) {
//            res = f[mid];
//            l = mid + 1;
//        }
//        else {
//            r = mid - 1;
//        }
//    }
//    return res;
//}
//
//ll compute(ll n) {
//    ll ans = -1;
//    ll find;
//    while (n != 1 && n != 2) {
//        find = bs(n);
//        if (n == find) { 
//            ans = find;
//            break;
//        }
//        else { 
//            n -= find;
//        }
//    }
//    if (ans != -1) {
//        return ans; 
//    }
//    else {
//        return n;  
//    }
//}
//
//
//int main() {
//    build();
//
//    ll n;
//    cin >> n;
//    ll ans = compute(n);
//    cout << ans << endl;
//
//    return 0;
//}