//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 1e6 + 10;
//vector<bool>prime(MAXN, true);
//vector<int>presum(MAXN, 0);
//
//void init(int m) {
//	prime[0] = prime[1] = false;
//	for (int i = 2; i * i <= m; ++i) {
//		if (prime[i]) {
//			for (int j = i * i; j <= m; j += i)
//				prime[j] = false;
//		}
//	}
//
//	presum[0] = 0;
//	for (int i = 1; i <= m; ++i)
//		presum[i] = presum[i - 1] + prime[i];
//}
//
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m;
//    cin >> n >> m;
//    init(m);
//    while (n--) {
//        int l, r;
//        cin >> l >> r;
//        if (l < 1 || r > m) 
//            cout << "Crossing the line\n";
//        else 
//            cout << presum[r] - presum[l - 1] << "\n";
//    }
//
//    return 0;
//}