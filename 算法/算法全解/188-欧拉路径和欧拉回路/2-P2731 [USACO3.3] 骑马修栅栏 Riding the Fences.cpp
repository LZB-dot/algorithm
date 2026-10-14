//
//
////https://www.luogu.com.cn/problem/P2731
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//struct Edge {
//	int u, v, id;
//};
//
//bool cmp(Edge e1, Edge e2) {
//	if (e1.u == e2.u)
//		return e1.v < e2.v;
//
//	return e1.u < e2.u;
//}
//
//
//const int MAXN = 510;
//const int MAXM = 2010;
//
//int n = 500, m, k;
//
//Edge e[MAXM << 1];
//
//int head[MAXN], to[MAXM << 1], nxt[MAXM << 1], eid[MAXM << 1];
//int cnt = 1;
//
//int cur[MAXN];
//int deg[MAXN];
//bool vis[MAXM];
//
//int path[MAXM];
//int cntp;
//
//void add(int u, int v, int id) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	eid[cnt] = id;
//	head[u] = cnt++;
//}
//
//void connect() {
//	sort(e + 1, e + k + 1, cmp);
//
//	for (int i = 1; i <= k; ) {
//		int j = i + 1;
//		while (j <= k && e[i].u == e[j].u)
//			++j;
//
//		for (int p = j - 1; p >= i; --p) {
//			deg[e[p].u]++;
//			add(e[p].u, e[p].v, e[p].id);
//		}
//
//		i = j;
//	}
//
//	for (int i = 1; i <= n; ++i)
//		cur[i] = head[i];
//}
//
//
//int undirectedStart() {
//	int odd = 0;
//
//	for (int i = 1; i <= n; ++i) {
//		if ((deg[i] & 1) == 1)
//			++odd;
//	}
//
//	if (odd != 0 && odd != 2)
//		return -1;
//
//	for (int i = 1; i <= n; ++i) {
//		if (odd == 0 && deg[i] > 0)
//			return i;
//
//		if (odd == 2 && (deg[i] & 1) == 1)
//			return i;
//	}
//
//	return -1;
//}
//
//int st[MAXM];
//int top;
//
//void euler(int start) {
//	top = 0;
//	st[top] = start;
//	++top;
//
//	while (top != 0) {
//		int u = st[top - 1];
//
//		if (cur[u] > 0) {
//			int e = cur[u];
//			cur[u] = nxt[e];
//
//			if (!vis[eid[e]]) {
//				vis[eid[e]] = 1;
//				st[top] = to[e];
//				top++;
//			}
//		}
//		else {
//			--top;
//			path[++cntp] = u;
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> m;
//
//	k = 0;
//	for (int i = 1; i <= m; ++i) {
//		int u, v;
//		cin >> u >> v;
//
//		e[++k] = { u,v,i };
//		e[++k] = { v,u,i };
//	}
//
//	connect();
//
//	int start = undirectedStart();
//
//	if (start == -1)
//		cout << "No\n";
//	else {
//		euler(start);
//
//		if (cntp != m + 1)
//			cout << "No\n";
//		else {
//			for (int i = cntp; i >= 1; --i)
//				cout << path[i] << "\n";
//			cout << "\n";
//		}
//
//	}
//
//	return 0;
//}