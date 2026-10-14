//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//using namespace std;
//
//#define ll long long
//
//const ll INF = 1e18;
//const int MAXN = 105;
//const int MAXM = 10005;
//
//int head[MAXN], to[MAXM], nxt[MAXM], weight[MAXM];
//int cnt;
//
//void init() {
//    cnt = 1;
//    memset(head, 0, sizeof(head));
//}
//
//void add(int u, int v, int w) {
//    weight[cnt] = w;
//    to[cnt] = v;
//    nxt[cnt] = head[u];
//    head[u] = cnt++;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//
//    init();
//
//    int w;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            cin >> w;
//            if (i != j) 
//                add(i, j, w);
//        }
//    }
//
//    vector<ll> dis(n + 1, INF);
//    vector<bool> vis(n + 1, false);
//
//    dis[1] = 0;
//    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> min_heap;
//    min_heap.push({ 0, 1 });
//
//    ll sum = 0;
//    int count = 0;
//
//    while (!min_heap.empty() && count < n) {
//        auto x = min_heap.top();
//        ll d = x.first;
//        int u = x.second;
//        min_heap.pop();
//
//        if (vis[u]) continue;
//
//        vis[u] = true;
//        sum += d;
//        count++;
//
//        for (int i = head[u]; i != 0; i = nxt[i]) {
//            int v = to[i];
//            int w = weight[i];
//
//            if (!vis[v] && w < dis[v]) {
//                dis[v] = w;
//                min_heap.push({ dis[v], v });
//            }
//        }
//    }
//
//    cout << sum << "\n";
//    return 0;
//}