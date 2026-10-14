//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//#define ll long long
//
////除了11，所有偶数位回文数都能被11整除
//
//bool isPrime(ll x) {
//    if (x < 2)
//        return false;
//    if (x == 2)
//        return true;
//
//    if (x % 2 == 0)
//        return false;
//
//    for (int i = 3; i * i <= x; i += 2) {
//        if (x % i == 0)
//            return false;
//    }
//    return true;
//}
//
//void solve(ll a, ll b) {
//    //1位
//    for (int d1 = 5; d1 <= 9; d1 += 2) {
//        if (d1 >= a && d1 <= b && isPrime(d1))
//            cout << d1 << "\n";
//    }
//
//    //2位
//    if (a <= 11 && b >= 11)
//        cout << "11\n";
//
//    //3位
//    for (int d1 = 1; d1 <= 9; d1 += 2) {
//        for (int d2 = 0; d2 <= 9; ++d2) {
//            ll sum = d1 * 100 + d2 * 10 + d1;
//            if (sum > b)
//                return;
//            if (sum >= a && isPrime(sum))
//                cout << sum << "\n";
//
//        }
//    }
//
//    //5位
//    for (int d1 = 1; d1 <= 9; d1 += 2) {
//        for (int d2 = 0; d2 <= 9; ++d2) {
//            for (int d3 = 0; d3 <= 9; ++d3) {
//                ll sum = d1 * 10000 + d2 * 1000 + d3 * 100 + d2 * 10 + d1;
//                if (sum > b)
//                    return;
//                if (sum >= a && isPrime(sum))
//                    cout << sum << "\n";
//            }
//        }
//    }
//
//    //7位
//    for (int d1 = 1; d1 <= 9; d1 += 2) {
//        for (int d2 = 0; d2 <= 9; ++d2) {
//            for (int d3 = 0; d3 <= 9; ++d3) {
//                for (int d4 = 0; d4 <= 9; ++d4) {
//                    ll sum = d1 * 1000000 + d2 * 100000 + d3 * 10000
//                        + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
//                    if (sum > b)
//                        return;
//                    if (sum >= a && isPrime(sum))
//                        cout << sum << "\n";
//                }
//
//            }
//        }
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    ll a, b;
//    cin >> a >> b;
//
//    solve(a, b);
//
//    return 0;
//}