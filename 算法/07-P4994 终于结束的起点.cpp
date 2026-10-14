//#include<iostream>
//using namespace std;
//
//#define ll long long
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int M;
//    cin >> M;
//    ll a = 0, b = 1;
//    int ans = 0; 
//
//    while (true) {
//        ll c = (a + b) % M;
//        a = b; 
//        b = c;
//        ans++; 
//
//        if (a == 0 && b == 1) {
//            cout << ans << endl;
//            break;
//        }
//    }
//
//    return 0;
//}