//#include<iostream>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//const int N = 5e5 + 10;
//const int mod = 80112002;
//
//int indegree[N];
//int outdegree[N];
//int head[N];
//int total = 0;
//int dp[N];
//
//struct edge {
//    int to;
//    int next;
//}Edges[N];
//
//void Add(int u, int v) {
//    Edges[total].to = v;
//    Edges[total].next = head[u];
//    head[u] = total++;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m;
//    cin >> n >> m;
//
//    for (int i = 1; i <= n; ++i) {
//        head[i] = -1;
//    }
//
//    for (int i = 0; i < m; ++i) {
//        int a, b;
//        cin >> a >> b;
//        indegree[b]++;
//        outdegree[a]++;
//        Add(a, b);
//    }
//
//    queue<int>q;
//    for (int i = 1; i <= n; ++i) {
//        if (indegree[i] == 0) {
//            q.push(i);
//            dp[i] = 1;
//        }
//    }
//
//    while (!q.empty()) {
//        int cur = q.front();
//        q.pop();
//
//        for (int i = head[cur]; i != -1; i = Edges[i].next) {
//            int v = Edges[i].to;
//            dp[v] = (dp[v] + dp[cur]) % mod;
//            indegree[v]--;
//            if (indegree[v] == 0) {
//                q.push(v);
//            }
//        }
//    }
//
//    int ans = 0;
//    for (int i = 1; i <= n; ++i)
//        if (outdegree[i] == 0)
//            ans = (ans + dp[i]) % mod;
//
//    cout << ans << endl;
//
//    return 0;
//}