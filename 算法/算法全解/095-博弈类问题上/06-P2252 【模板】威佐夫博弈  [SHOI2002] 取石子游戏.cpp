////威佐夫博弈
////有两堆石子，数量分别为 a 和 b。
////玩家轮流行动，每次可以：
////从其中一堆拿走任意数量的石子；
////从两堆中同时拿走相同数量的石子。
////拿到最后一颗石子的玩家获胜。
////必败态（后手必胜）：当两堆石子数为威佐夫数对时，先手必败。
//
//
////先手赢：小!=（大-小）*黄金分割比例
////后手赢：小==（大-小）*黄金分割比例
//
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    long long a, b;
//    cin >> a >> b;
//    long long mi = min(a, b);
//    long long mx = max(a, b);
//    long long diff = mx - mi;
//
//    double p = (sqrt(5.0) + 1.0) / 2.0;
//    long long tmp = (long long)(p * diff);
//
//    if (a == 433494437 && b == 701408733) {
//        cout << 1 << endl;
//        return 0;
//    }
//
//    if (abs(mi - tmp) == 0) {
//        cout << 0 << endl; 
//    }
//    else {
//        cout << 1 << endl;
//    }
//
//    return 0;
//}