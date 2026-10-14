//#include<iostream>
//#include<vector>
//using namespace std;
//
//#define ll long long
//const int N = 100009;
//ll f[N] = { 1ll };
//int main() {
//	int c[4], d[4], n, k, now, s, tmp;
//	ll ans;
//	for (int j = 0; j < 4; ++j)
//		cin >> c[j];
//	cin >> n;
//	for (int j = 0; j < 4; ++j)
//		for (int i = c[j]; i < N; ++i)
//			f[i] += f[i - c[j]];//完全背包预处理
//	while (n--) {
//		for (int j = 0; j < 4; ++j)
//			cin >> d[j];
//		cin >> s;
//		ans = f[s];
//		for (int status = 1; status <= 15; ++status) {//二进制数枚举集合
//			now = s;
//			for (int tmp = status, j = k = 0; tmp; tmp >>= 1, ++j)
//				if (tmp & 1) {
//					k ^= 1;
//					now -= (d[j] + 1) * c[j];
//				} 
//			if (now >= 0)
//				k ? ans -= f[now] : ans += f[now];
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}
