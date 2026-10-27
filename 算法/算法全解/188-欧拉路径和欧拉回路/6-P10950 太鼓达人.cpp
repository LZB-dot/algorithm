//
////https://www.luogu.com.cn/problem/P10950
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring> 
//#include<queue>
//#include<unordered_map>
//#include<climits>
//#include<bitset>
//
//using namespace std;
//
//typedef long long ll;
//
//
//const int MAXN = 2050;
//
//int n, k, m;
//
//int cur[MAXN];
//int path[MAXN];
//int cntp;
//
//int sta[MAXN][2];
//int top;
//
//void init() {
//	k = 2;
//	m = 1;
//	for (int i = 1; i <= n - 1; ++i)
//		m *= k;
//
//	cntp = 0;
//	top = 0;
//
//	for (int i = 1; i < MAXN; ++i)
//		cur[i] = 0;
//
//}
//
//void euler(int u, int e) {
//	while (cur[u] < k) {
//		int ce = cur[u]++;
//		int cu = (u * k + ce) % m;
//		euler(cu, ce);
//	}
//
//	path[++cntp] = e;
//}
//
//
//void solve() {
//	cin >> n;
//
//	init();
//	euler(0, -1);
//
//	cout << m * k << " ";
//
//	for (int i = 1; i <= n - 1; ++i)
//		cout << "0";
//
//	for (int i = cntp - 1; i >= 2; --i)
//		cout << path[i];
//
//	cout << "\n";
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	solve();
//
//	return 0;
//}