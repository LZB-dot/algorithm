//
////https://www.luogu.com.cn/problem/P3388
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
//const int MAXN = 2e4 + 10;
//const int MAXM = 1e5 + 10;
//
//int n, m;
//
//int head[MAXN], to[MAXM << 1], nxt[MAXM << 1];
//int cnt;
//
//int dfn[MAXN], low[MAXN];
//int cntd;
//
//bool is[MAXN];
//
//inline void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void tarjan(int u, bool root) {
//	dfn[u] = low[u] = ++cntd;
//	int son = 0;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (dfn[v] == 0) {
//			++son;
//
//			tarjan(v, false);
//			low[u] = min(low[u], low[v]);
//		
//			if (low[v] >= dfn[u]) {
//				//u不是根，那么就是割点
//				//u是根，那么必须至少要有两个子树
//				if (!root || son >= 2)
//					is[u] = 1;
//			}
//		}
//		else 
//			low[u] = min(low[u], dfn[v]);
//
//	}
//}
//
//void solve() {
//	cin >> n >> m;
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		if (dfn[i] == 0)
//			tarjan(i, true);
//	}
//
//	int ans = 0;
//	for (int i = 1; i <= n; ++i)
//		if (is[i])
//			++ans;
//
//	cout << ans << "\n";
//	for (int i = 1; i <= n; ++i)
//		if (is[i])
//			cout << i << " ";
//
//	cout << "\n";
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