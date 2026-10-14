//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring> 
//using namespace std;
//
//#define ll long long
//
//const int MAXN = 1e4 + 5;
//const int MAXM = 1e5 + 5;
//const ll INF = 0x3f3f3f3f3f3f3f3f;  
//
//int cnt;
//int head[MAXN], nxt[MAXM];
//int to[MAXM];
//ll weight[MAXM]; 
//
//void init() {
//    cnt = 1;
//    memset(head, 0, sizeof(head));
//}
//
//void add(int u, int v, ll w) {  
//    nxt[cnt] = head[u];
//    to[cnt] = v;
//    weight[cnt] = w;
//    head[u] = cnt++;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m, k;
//    cin >> n >> m >> k;
//    init();
//    for (int i = 0; i < m; ++i) {
//        int u, v;
//        ll w;  
//        cin >> u >> v >> w;
//        add(u, v, w);
//        add(v, u, w);
//    }
//
//    auto dijkstra = [&]() { 
//        vector<vector<ll>> dis(n + 1, vector<ll>(k + 1, INF));
//
//        priority_queue<pair<ll, pair<int, int>>,
//            vector<pair<ll, pair<int, int>>>,
//            greater<pair<ll, pair<int, int>>>> min_heap;
//
//        min_heap.push({ 0, {1, 0} });
//        dis[1][0] = 0;
//
//        while (!min_heap.empty()) {
//            auto it = min_heap.top();
//            min_heap.pop();
//            ll d = it.first;
//            int u = it.second.first;
//            int c = it.second.second;
//
//            if (d > dis[u][c])
//                continue;
//
//            for (int i = head[u]; i != 0; i = nxt[i]) {
//                int v = to[i];
//                ll w = weight[i];
//
//                if (dis[v][c] > dis[u][c] + w) { 
//                    dis[v][c] = dis[u][c] + w;
//                    min_heap.push({ dis[v][c], {v, c} });
//                }
//
//                if (c + 1 <= k && dis[v][c + 1] > d) {  
//                    dis[v][c + 1] = d;
//                    min_heap.push({ dis[v][c + 1], {v, c + 1} });
//                }
//            }
//        }
//
//        return dis;
//        };
//
//    auto dist = dijkstra();
//    ll ans = INF;
//    for (int i = 0; i <= k; ++i)
//        ans = min(ans, dist[n][i]);
//
//    cout << ans << endl;
//
//    return 0;
//}