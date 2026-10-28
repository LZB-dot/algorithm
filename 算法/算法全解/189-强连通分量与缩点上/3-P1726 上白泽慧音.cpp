//
////https://www.luogu.com.cn/problem/P1726
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
//const int MAXN = 5010;
//const int MAXM = 1e6 + 10;
//
//int head[MAXN], to[MAXM], nxt[MAXM];
//int cnt;
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
//int scccnt;
//int belong[MAXN];
//int idx;
//int scc[MAXN];
//int sccl[MAXN], sccr[MAXN];
//
//bool vis[MAXN];
//
//inline void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//
//void init() {
//	cnt = 1;
//	scccnt = 0;
//	cntd = 0;
//	top = 0;
//	idx = 0;
//
//	for (int i = 0; i <= n; ++i) {
//		head[i] = 0;
//		dfn[i] = 0;
//		low[i] = 0;
//		belong[i] = 0;
//		vis[i] = 0;
//	}
//}
//
//void tarjan(int u) {
//	dfn[u] = low[u] = ++cntd;
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
//				low[u] = min(low[u],dfn[v]);
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
//}
//
//void solve() {
//	cin >> n >> m;
//
//	init();
//
//	for (int i = 1; i <= m; ++i) {
//		int u, v, t;
//		cin >> u >> v >> t;
//
//		add(u, v);
//		if (t == 2)
//			add(v, u);
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		if (dfn[i] == 0)
//			tarjan(i);
//	}
//
//	int x = 1;
//	int ans = 0;
//	ans = sccr[x] - sccl[x] + 1;
//
//	for (int i = 2; i <= scccnt; ++i) {
//		int cur = sccr[i] - sccl[i] + 1;
//
//		if (cur > ans) {
//			ans = cur;
//			x = i;
//		}
//		else if (cur == ans) {
//			int mi1 = 1e9, mi2 = 1e9;
//
//			for (int p = sccl[x]; p <= sccr[x]; ++p)
//				mi1 = min(mi1, scc[p]);
//	
//			for (int p = sccl[i]; p <= sccr[i]; ++p)
//				mi2 = min(mi2, scc[p]);
//		
//			if (mi2 < mi1)
//				x = i;
//		}
//	}
//
//	vector<int>path;
//
//	for (int p = sccl[x]; p <= sccr[x]; ++p)
//		path.push_back(scc[p]);
//
//	sort(path.begin(), path.end());
//	cout << ans << "\n";
//	for (int i : path)
//		cout << i << " ";
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