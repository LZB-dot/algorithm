//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//typedef long long ll;
//const int MAXN = 100005;
//
//int n;
//int cow[MAXN];
//int cowSum;
//
//int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], weight[MAXN << 1];
//int cnt;
//
//int best, center;
//int sz[MAXN];
//int path[MAXN];
//
//void build() {
//    cnt = 1;
//    memset(head, 0, sizeof(head));
//    cowSum = 0;
//    best = 1e9;
//}
//
//void add(int u, int v, int w) {
//    nxt[cnt] = head[u];
//    to[cnt] = v;
//    weight[cnt] = w;
//    head[u] = cnt++;
//}
//
//void find(int u, int f) {
//    sz[u] = cow[u];
//    int maxsub = 0;
//
//    for (int i = head[u]; i; i = nxt[i]) {
//        int v = to[i];
//        if (v != f) {
//            find(v, u);
//            sz[u] += sz[v];
//            maxsub = max(maxsub, sz[v]);
//        }
//    }
//
//    maxsub = max(maxsub, cowSum - sz[u]);
//
//    if (maxsub < best) {
//        best = maxsub;
//        center = u;
//    }
//}
//
//void setPath(int u, int f) {
//    for (int i = head[u]; i; i = nxt[i]) {
//        int v = to[i];
//        if (v != f) {
//            path[v] = path[u] + weight[i];
//            setPath(v, u);
//        }
//    }
//}
//
//ll compute() {
//    for (int i = 1; i <= n; ++i) {
//        cowSum += cow[i];
//    }
//
//    find(1, 0);
//    path[center] = 0;
//    setPath(center, 0);
//
//    ll ans = 0;
//    for (int i = 1; i <= n; ++i)
//        ans += (ll)cow[i] * path[i];
//
//    return ans;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
//    cin >> n;
//    build();
//
//    for (int i = 1; i <= n; ++i)
//        cin >> cow[i];
//
//
//    for (int i = 1; i < n; ++i) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        add(u, v, w);
//        add(v, u, w);
//    }
//
//    cout << compute() << endl;
//    return 0;
//}