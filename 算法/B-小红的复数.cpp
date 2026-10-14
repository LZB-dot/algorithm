//#include<iostream>
//using namespace std;
//
//const int M = 1000000007;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//
//    long long x, y;
//    cin >> x >> y;
//
//    for (int i = 1; i < n; ++i) {
//        long long a, b;
//        cin >> a >> b;
//
//        long long tmpx = x;
//        long long tmpy = y;
//
//        x = (tmpx * a % M - tmpy * b % M) % M;
//        y = (tmpx * b % M + tmpy * a % M) % M;
//
//        if (x < 0) 
//            x += M;
//        if (y < 0) 
//            y += M;
//    }
//
//    cout << x << " " << y << endl;
//    return 0;
//}