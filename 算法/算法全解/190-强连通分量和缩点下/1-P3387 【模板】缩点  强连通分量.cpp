//
////https://www.luogu.com.cn/problem/P3387
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
//const int MAXN = 1e4 + 10;
//const int MAXM = 1e5 + 10;
//
//int n, m;
//
//int arr[MAXN], a[MAXM], b[MAXM];
//
//int head[MAXN], to[MAXM], nxt[MAXM];
//int cnt;
//
//int sta[MAXN];
//int top;
//
//int dfn[MAXN], low[MAXN];
//int cntd;
//
//int belong[MAXN];
//int sum[MAXN];
//int sccCnt;
//
//int indegree[MAXN];
//int dp[MAXN];
//
//inline void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void init() {
//	cnt = 1;
//	top = 0;
//	cntd = 0;
//
//	memset(head, 0, sizeof(head));
//	memset(dfn, 0, sizeof(dfn));
//	memset(low, 0, sizeof(low));
//	memset(belong, 0, sizeof(belong));
//	memset(sum, 0, sizeof(sum));
//	memset(indegree, 0, sizeof(indegree));
//	memset(dp, 0, sizeof(dp));
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
//				low[u] = min(low[u], dfn[v]);
//		}
//	}
//
//	if (dfn[u] == low[u]) {
//		sccCnt++;
//
//		int pop;
//		do {
//			pop = sta[--top];
//			belong[pop] = sccCnt;
//			sum[sccCnt] += arr[pop];
//		} while (pop != u);
//	}
//}
//
//void condense() {
//	cnt = 1;
//	for (int i = 0; i <= sccCnt; ++i)
//		head[i] = 0;
//
//	for (int i = 1; i <= m; ++i) {
//		int scc1 = belong[a[i]];
//		int scc2 = belong[b[i]];
//
//		if (scc1 != scc2) {
//			indegree[scc2]++;
//			add(scc1, scc2);
//		}
//	}
//}
//
//int topo() {
//	queue<int>q;
//
//	for (int i = 1; i <= sccCnt; ++i) {
//		if (indegree[i] == 0) {
//			dp[i] = sum[i];
//			q.push(i);
//		}
//	}
//
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//
//		for (int i = head[u]; i; i = nxt[i]) {
//			int v = to[i];
//
//			dp[v] = max(dp[v], dp[u] + sum[v]);
//			if (--indegree[v] == 0)
//				q.push(v);
//		}
//	}
//
//	int ans = 0;
//	for (int i = 1; i <= sccCnt; ++i)
//		ans = max(ans, dp[i]);
//
//	return ans;
//}
//
//int dpOnDAG() {
//	for (int u = sccCnt; u > 0; --u) {
//		if (indegree[u] == 0)
//			dp[u] = sum[u];
//
//		for (int i = head[u]; i; i = nxt[i]) {
//			int v = to[i];
//			dp[v] = max(dp[v], dp[u] + sum[v]);
//		}
//	}
//
//	int ans = 0;
//	for (int i = 1; i <= sccCnt; ++i)
//		ans = max(ans, dp[i]);
//
//	return ans;
//}
//
//void solve() {
//	cin >> n >> m;
//
//	init();
//
//	for (int i = 1; i <= n; ++i)
//		cin >> arr[i];
//
//	for (int i = 1; i <= m; ++i) {
//		cin >> a[i] >> b[i];
//		add(a[i], b[i]);
//	}
//
//	for (int i = 1; i <= n; i++)
//		if (dfn[i] == 0) {
//			tarjan(i);
//		}
//
//	condense();
//	int ans = topo();
//	//int ans = dpOnDAG();
//
//	cout << ans << "\n";
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