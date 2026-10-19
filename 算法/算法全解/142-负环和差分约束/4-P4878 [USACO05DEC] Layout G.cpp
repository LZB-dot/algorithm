//
//
////https://www.luogu.com.cn/problem/P4878
//
//
//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//#define pii pair<int,int>
//
//const int MAXN = 1010;
//const int MAXM = 4e4 + 10;
//const int INF = 1e9;
//
//int head[MAXN], to[MAXM], nxt[MAXM], weight[MAXM];
//int cnt;
//
//int n, m1, m2;
//
//int dist[MAXN];
//bool in[MAXN];
//int update[MAXN];
//
//void init() {
//	cnt = 1;
//	for (int i = 0; i <= n; ++i) 
//		head[i] = 0;
//	
//}
//
//void reset(int n) {
//	for (int i = 0; i <= n; i++) {
//		dist[i] = INF;
//		in[i] = false;
//		update[i] = 0;
//	}
//}
//
//inline void add(int u, int v, int w) {
//	to[cnt] = v;
//	nxt[cnt] = head[u];
//	weight[cnt] = w;
//	head[u] = cnt++;
//}
//
//int SPFA(int s, int n) {
//	reset(n);
//
//	queue<int>q;
//	q.push(s);
//
//	dist[s] = 0;
//	in[s] = 1;
//	update[s] = 1;
//
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//
//		in[u] = false;
//
//		for (int i = head[u]; i; i = nxt[i]) {
//			int v = to[i];
//			int vw = weight[i];
//
//			if (dist[v] > dist[u] + vw) {
//
//				dist[v] = dist[u] + vw;
//
//				if (!in[v]) {
//
//					if (++update[v] > n)
//						return -1;
//
//					in[v] = 1;
//					q.push(v);
//				}
//			}
//		}
//	}
//
//	if (dist[n] == INF)
//		return -2;
//
//	return dist[n];
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m1 >> m2;
//
//	init();
//
//	for (int i = 1; i <= n; ++i)
//		add(0, i, 0);
//
//	for (int i = 1; i <= m1; ++i) {
//		int a, b, d;
//		cin >> a >> b >> d;
//		add(a, b, d);
//	}
//
//	for (int i = 1; i <= m2; ++i) {
//		int a, b, d;
//		cin >> a >> b >> d;
//		add(b, a, -d);
//	}
//
//	for (int i = 1; i < n; i++) 
//		add(i + 1, i, 0);
//	
//
//	int ans = SPFA(0, n);
//
//	if (ans == -1)
//		cout << ans << "\n";
//	else {
//		ans = SPFA(1, n);
//		cout << ans << "\n";
//	}
//
//	return 0;
//}
