////https://www.luogu.com.cn/problem/P7771
////有向图的欧拉路径
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//struct Edge {
//	int u, v;
//};
//
//bool cmp(Edge e1, Edge e2) {
//	if (e1.u != e2.u)
//		return e1.u < e2.u;
//	return e1.v < e2.v;
//}
//
//const int MAXN = 1e5 + 10;
//const int MAXM = 2e5 + 10;
//
//int n, m;
//Edge e[MAXM];
//
//int head[MAXN], to[MAXM], nxt[MAXM];
//int cnt = 1;
//
//int cur[MAXN];
//
//int out[MAXN], in[MAXN];
//
//int path[MAXM]; 
//int cntp = 0;
//
//void add(int u, int v) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	head[u] = cnt++;
//}
//
//void connect() {
//	sort(e + 1, e + m + 1, cmp);
//
//	for (int i = 1; i <= m; ) {
//		int j = i + 1;
//		while (j <= m && e[j].u == e[i].u)
//			++j;
//
//		for (int k = j - 1; k >= i; --k) {
//			int u = e[k].u;
//			int v = e[k].v;
//			out[u]++;
//			in[v]++;
//			add(u, v);
//		}
//
//		i = j;
//	}
//
//	for (int i = 1; i <= n; ++i)
//		cur[i] = head[i];
//}
//
//int directStart() {
//
//	int st = -1, ed = -1;
//
//	for (int i = 1; i <= n; ++i) {
//		int w = out[i] - in[i];
//
//		if (w < -1 || w > 1)
//			return -1;
//
//		if ((w == 1 && st != -1) || (w == -1 && ed != -1))
//			return -1;
//
//		if (w == 1)
//			st = i;
//		if (w == -1)
//			ed = i;
//	}
//
//	if ((st == -1) ^ (ed == -1))
//		return -1;
//
//	// 欧拉路径
//	if (st != -1)
//		return st;
//
//	// 欧拉回路，随便找有出边的点
//	for (int j = 1; j <= n; ++j)
//		if (out[j] > 0)
//			return j;
//
//	return -1;
//}
//
//void euler(int u) {
//	for (int i = cur[u]; i; i = cur[u]) {
//		cur[u] = nxt[i];
//		euler(to[i]);
//	}
//	path[++cntp] = u;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m;
//
//	for (int i = 1; i <= m; ++i)
//		cin >> e[i].u >> e[i].v;
//
//	connect();
//
//	int start = directStart();
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
//				cout << path[i] << " ";
//			cout << "\n";
//		}
//	}
//	return 0;
//}
