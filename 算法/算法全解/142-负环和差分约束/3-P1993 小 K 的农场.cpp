//
//
////https://www.luogu.com.cn/problem/P1993
//
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//const int MAXN = 5005;
//const int MAXM = 20005;
//const int INF = 1e9;
//
//int head[MAXN], to[MAXM], nxt[MAXM], weight[MAXM];
//int cnt;
//
//int dist[MAXN];
//int update[MAXN];
//bool inq[MAXN];
//
//int n, m;
//
//void add(int u, int v, int w) {
//    to[cnt] = v;
//    nxt[cnt] = head[u];
//    weight[cnt] = w;
//    head[u] = cnt++;
//}
//
//void init(int n) {
//    cnt = 1;
//
//    for (int i = 1; i <= n; ++i) {
//        head[i] = 0;
//        update[i] = 0;
//        dist[i] = INF;
//    }
//
//}
//
//
//bool spfa(int s) {
//    queue<int>q;
//    q.push(s);
//
//    dist[s] = 0;
//    inq[s] = 1;
//    update[s] = 1;
//
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//
//        inq[u] = false;
//
//        for (int i = head[u]; i; i = nxt[i]) {
//            int v = to[i];
//            int w = weight[i];
//
//            if (dist[v] > dist[u] + w) {
//                dist[v] = dist[u] + w;
//                if (!inq[v]) {
//                    if (++update[v] > n)
//                        return true;
//                
//                    q.push(v);
//                    inq[v] = 1;
//                }
//            }
//        }
//    }
//
//    return false;
//}
//
//
//void solve() {
//    cin >> n >> m;
//
//    init(n);
//
//    for (int i = 1; i <= n; ++i)
//        add(0, i, 0);
//
//    for (int i = 1; i <= m; ++i) {
//        int type;
//        cin >> type;
//
//        int u, v, w;
//        cin >> u >> v;
//
//        if (type == 1) {
//           cin >> w;
//           add(u, v, -w);
//        }
//        else if (type == 2) {
//            cin >> w;
//            add(v, u, w);
//        }
//        else {
//            add(u, v, 0);
//            add(v, u, 0);
//        }
//    }
//
//    if (spfa(0))
//        cout << "No\n";
//    else
//        cout << "Yes\n";
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    solve();
//
//    return 0;
//}