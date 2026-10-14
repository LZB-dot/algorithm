//
//
////https://www.luogu.com.cn/problem/P5960
//
//// 判断无限增长的环
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
//bool enter[MAXN];
//
//int n, m;
//
//void prepare() {
//    cnt = 1;
//    for (int i = 0; i <= n; ++i) {
//        head[i] = 0;
//        dist[i] = -INF;
//        update[i] = 0;
//        enter[i] = false;
//    }
//}
//
//void add(int u, int v, int w) {
//    to[cnt] = v;
//    nxt[cnt] = head[u];
//    weight[cnt] = w;
//    head[u] = cnt++;
//}
//
//bool spfa(int s) {
//    queue<int> q;
//    dist[s] = 0;
//    update[s] = 1;
//
//    q.push(s);
//    enter[s] = true;
//
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//
//        enter[u] = false;
//
//        for (int ei = head[u]; ei > 0; ei = nxt[ei]) {
//            int v = to[ei];
//            int w = weight[ei];
//
//            if (dist[v] < dist[u] + w) {
//                dist[v] = dist[u] + w;
//                if (!enter[v]) {
//
//                    if (++update[v] > n)
//                        return true;
//
//                    q.push(v);
//                    enter[v] = true;
//                }
//            }
//        }
//    }
//    return false;
//}
//
//void solve() {
//    cin >> n >> m;
//
//    prepare();
//
//    for (int i = 1; i <= n; i++)
//        add(0, i, 0);
//
//
//    for (int i = 1; i <= m; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//
//        add(u, v, -w);
//    }
//
//    if (spfa(0)) {
//        cout << "NO\n";
//    }
//    else {
//        for (int i = 1; i <= n; i++)
//            cout << dist[i] << " ";
//
//        cout << "\n";
//    }
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