//
////https://www.luogu.com.cn/problem/P4568
//
//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//#include<climits>
//using namespace std;
//
//const int MAXN = 2e4 + 10;
//const int MAXM = 1e5 + 10;
//const int MAXK = 11; 
//const int INF = 1e9;
//
//int head[MAXN], to[MAXM], nxt[MAXM], weight[MAXM];
//int cnt = 1;
//
//inline void add(int u, int v, int w) {
//    to[cnt] = v;
//    nxt[cnt] = head[u];
//    weight[cnt] = w;
//    head[u] = cnt++;
//}
//
//
//int n, m, k;
//int s, t;
//int dis[MAXN][MAXK];
//
//int solve() {
//    for (int i = 0; i < MAXN; i++) 
//        for (int j = 0; j < MAXK; j++) 
//            dis[i][j] = INF;
//
//
//    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
//    vector<vector<bool>>vis(n + 1, vector<bool>(k + 1, false));
//
//    pq.push({ 0,s,0 });
//    dis[s][0] = 0;
//  
//    while (!pq.empty()) {
//        auto it = pq.top();
//        pq.pop();
//
//        int c = it[0];
//        int u = it[1];
//        int used = it[2];
//
//        if (u == t)
//            return c;
//
//        if (vis[u][used])
//            continue;
//
//        vis[u][used] = true;
//
//        for (int i = head[u]; i; i = nxt[i]) {
//            int v = to[i];
//            int w = weight[i];
//
//            if (used < k && c < dis[v][used + 1]) {
//                dis[v][used + 1] = c;
//                pq.push({ c,v,used + 1 });
//            }
//
//            if (w + c < dis[v][used]) {
//                dis[v][used] = w + c;
//                pq.push({ w + c, v, used });
//            }
//        }
//    }
//
//    return -1;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
//    cin >> n >> m >> k;
//    cin >> s >> t;
//
//    for (int i = 1; i <= m; ++i) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        add(u, v, w);
//        add(v, u, w);
//    }
//
//    cout << solve() << "\n";
//
//    return 0;
//}
