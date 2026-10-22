//
//
////https://www.luogu.com.cn/problem/P4926
//
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring> 
//#include<queue>
//#include<unordered_map>
//#include<climits>
//
//using namespace std;
//
//const int MAXN = 1010;
//const int MAXM = 1e6 + 10;
//const double INF = 1e10;
//const double eps = 1e-6;
//
//int head[MAXN], to[MAXM], nxt[MAXM];
//double weight[MAXM];
//int cnt = 1;
//
//int sco[MAXN][2];
//int type[MAXN][4];
//
//double dist[MAXN];
//int update[MAXN];
//bool enter[MAXN];
//
//int n, s, t;
//
//void init() {
//	cnt = 1;
//
//	memset(head, 0, sizeof(head));
//	memset(update, 0, sizeof(update));
//	memset(enter, 0, sizeof(enter));
//
//	fill(dist, dist + n + 2, INF);
//}
//
//
//inline void add(int u, int v, double w) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//
//
//bool SPFA(int s) {
//	queue<int>q;
//	q.push(s);
//
//	dist[s] = 0;
//	update[s] = 1;
//	enter[s] = true;
//
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//
//		enter[u] = false;
//
//		for (int i = head[u]; i; i = nxt[i]) {
//			int v = to[i];
//			double w = weight[i];
//
//			//浮点数计算有精度误差
//			//加上eps 只有明显大于 才松弛
//			if (dist[v] > dist[u] + w + eps) {
//				dist[v] = dist[u] + w;
//
//				if (!enter[v]) {
//					if (++update[v] > n + 1)
//						return 1;
//
//					enter[v] = 1;
//					q.push(v);
//				}
//			}
//		}
//
//	}
//
//	return false;
//}
//
//
//void solve() {
//	cin >> n >> s >> t;
//
//	for (int i = 1; i <= s; ++i)
//		for (int j = 0; j < 4; ++j)
//			cin >> type[i][j];
//
//	for (int i = 1; i <= t; ++i)
//		cin >> sco[i][0] >> sco[i][1];
//
//	double ans = 0;
//	double l = 0, r = INF;
//
//	auto check = [&](double mid)->bool {
//
//		init();
//
//		for (int i = 1; i <= n; ++i)
//			add(0, i, 0);
//
//		for (int i = 1; i <= s; ++i) {
//			int op = type[i][0];
//			int u = type[i][1];
//			int v = type[i][2];
//
//			if (op == 1) {
//				double nw = type[i][3] - mid;
//				add(u, v, -log(nw));
//			}
//			else {
//				//减一点点eps，等价把<松弛成<=
//				double nw = type[i][3] + mid - eps;
//				add(u, v, log(nw));
//			}
//		}
//
//		for (int i = 1; i <= t; ++i) {
//			int u = sco[i][0];
//			double w = sco[i][1];
//
//			add(n + 1, u, log(w));
//			add(u, n + 1, -log(w));
//		}
//
//		return SPFA(0);
//	};
//
//	while (r - l >= eps) {
//		double mid = (l + r) / 2;
//
//		if (check(mid)) {
//			ans = mid;
//			l = mid + eps;
//		}
//		else
//			r = mid - eps;
//	}
//	
//	if (ans < eps) 
//		printf("-1\n");
//	else 
//		printf("%.4f\n", ans);
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