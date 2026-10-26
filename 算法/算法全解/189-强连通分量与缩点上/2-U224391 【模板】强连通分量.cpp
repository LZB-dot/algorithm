//
////https://www.luogu.com.cn/problem/U224391
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 5e4 + 10;
//const int MAXM = 1e5 + 10;
//
//int head[MAXN], to[MAXM], nxt[MAXM];
//int cnt;
//
//inline void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//int n, m;
//
//int dfn[MAXN];
//int low[MAXN];
//int cntd;
//
//int sta[MAXN];
//int top;
//
//int belong[MAXN];
//int scc[MAXN];
//int sccl[MAXN], sccr[MAXN];
//int idx;
//int scccnt;
//
//bool vis[MAXN];
//
//void init() {
//	cnt = 1;
//	cntd = 0;
//	top = 0;
//	idx = 0;
//	scccnt = 0;
//
//	memset(head, 0, sizeof(head));
//	memset(dfn, 0, sizeof(dfn));
//	memset(low, 0, sizeof(low));
//	memset(belong, 0, sizeof(belong));
//	memset(vis, 0, sizeof(vis));
//}
//
//void tarjan(int u) {
//	dfn[u] = low[u] = ++cntd;
//
//	sta[top++] = u;
//
//	for (int i = head[u]; i; i = nxt[i]) {
//		int v = to[i];
//
//		if (dfn[v] == 0) {
//			tarjan(v);
//			low[u] = min(low[u], low[v]);
//		}
//		else {
//			if (belong[v] == 0)
//				low[u] = min(low[u], dfn[v]);
//		}
//	}
//
//	if (dfn[u] == low[u]) {
//		scccnt++;
//		sccl[scccnt] = idx + 1;
//
//		int pop;
//
//		do {
//			pop = sta[--top];
//			belong[pop] = scccnt;
//			scc[++idx] = pop;
//		} while (pop != u);
//
//		sccr[scccnt] = idx;
//	}
//
//}
//
//
//
//void solve() {
//	init();
//
//	cin >> n >> m;
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		if (dfn[i] == 0)
//			tarjan(i);
//	}
//
//	cout << scccnt << "\n";
//
//	for (int i = 1; i <= scccnt; ++i)
//		sort(scc + sccl[i], scc + sccr[i] + 1);
//
//	for (int i = 1; i <= n; ++i) {
//		int tmp = belong[i];
//
//		if (!vis[tmp]) {
//			vis[tmp] = 1;
//
//			int sz = sccr[tmp] - sccl[tmp] + 1;
//			cout << sz << " ";
//
//			for (int j = sccl[tmp]; j <= sccr[tmp]; ++j)
//				cout << scc[j] << " ";
//
//			cout << "\n";
//		}
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