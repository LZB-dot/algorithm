//
////https://www.luogu.com.cn/problem/P8436
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
//const int MAXN = 5e5 + 10;
//const int MAXM = 2e6 + 10;
//
//int head[MAXN], to[MAXM << 1], nxt[MAXM << 1];
//int cnt;
//
//int dfn[MAXN], low[MAXN];
//int cntd;
//
//int n, m;
//
//int sta[MAXN];
//int top;
//
//int ebccSz[MAXN];
//int ebcc[MAXN];
//int idx;
//
//int ebccl[MAXN], ebccr[MAXN];
//int ebccCnt;
//
//inline void add(int u, int v) {
//	nxt[cnt] = head[u];
//	to[cnt] = v;
//	head[u] = cnt++;
//}
//
//void init() {
//	cnt = 2;
//	cntd = 0;
//	idx = 0;
//	ebccCnt = 0;
//	top = 0;
//
//	for (int i = 0; i <= n; ++i) {
//		head[i] = 0;
//		dfn[i] = 0;
//		low[i] = 0;
//		
//	}
//}
//
//
//void tarjan(int u, int pre) {
//	dfn[u] = low[u] = ++cntd;
//	sta[top++] = u;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if ((i ^ 1) == pre)
//			continue;
//
//		if (dfn[v] == 0) {
//			tarjan(v, i);
//			low[u] = min(low[u], low[v]);
//		}
//		else
//			low[u] = min(low[u], dfn[v]);
//	}
//
//	if (dfn[u] == low[u]) {
//		ebccCnt++;
//		ebccSz[ebccCnt] = 0;
//
//		ebccl[ebccCnt] = idx + 1;
//
//		int pop;
//		do {
//			pop = sta[--top];
//			ebccSz[ebccCnt]++;
//			ebcc[++idx] = pop;
//		} while (pop != u);
//
//		ebccr[ebccCnt] = idx;
//	}
//
//}
//
//void solve() {
//	cin >> n >> m;
//
//	init();
//	
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//
//		add(u, v);
//		add(v, u);
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		if (dfn[i] == 0)
//			tarjan(i, 0);
//	}
//
//	cout << ebccCnt << "\n";
//	for (int i = 1; i <= ebccCnt; ++i) {
//		cout << ebccSz[i] << "\n";
//
//		for (int j = ebccl[i]; j <= ebccr[i]; ++j)
//			cout << ebcc[j] << " ";
//
//		cout << "\n";
//	}
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