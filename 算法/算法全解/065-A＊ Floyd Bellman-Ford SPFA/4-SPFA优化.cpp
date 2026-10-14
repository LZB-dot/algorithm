//
////Bellman-Ford+SPFA优化：
////每一轮考察所有的边看看是否可以做松弛操作是不必要的
////只有在上一次松弛过的边的节点，才有可能引起下一次的松弛
//
////1.适用于小图
////2.解决有负边（没有负环）的图的单源最短路径
////3.判断从某个点出发是否可以遇上负环。判断整张图有没有负环，可以设置虚拟源点
////4.并行运算有很大优势
//
////https://www.luogu.com.cn/problem/P3385
// 
//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//using namespace std;
//
//const int MAXN = 2001;
//const int MAXM = 6001;  
//const int INF = 1e9;
//int head[MAXN], to[MAXM], nxt[MAXM], weight[MAXM];
//int cnt;
//
//int dis[MAXN];
//int update[MAXN];
//bool inQueue[MAXN];
//bool reach[MAXN]; 
//
//void init(int n) {
//    memset(head, 0, sizeof(head));
//    memset(reach, 0, sizeof(reach));
//
//    for (int i = 1; i <= n; ++i) {
//        dis[i] = INF;
//        update[i] = 0;
//        inQueue[i] = false;
//    }
//
//    cnt = 1;
//}
//
//void add(int u, int v, int w) {
//    nxt[cnt] = head[u];
//    to[cnt] = v;
//    weight[cnt] = w;
//    head[u] = cnt++;
//}
//
//void bfsReach(int n) {
//    queue<int> q;
//    q.push(1);
//    reach[1] = true;
//   
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//
//        for (int i = head[u]; i; i = nxt[i]) {
//            int v = to[i];
//            if (!reach[v]) {
//                reach[v] = true;
//                q.push(v);
//            }
//        }
//    }
//}
//
//bool SPFA(int n) {
//    queue<int> q;
//    dis[1] = 0;
//    q.push(1);
//    inQueue[1] = true;
//    update[1]++;
//
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        inQueue[u] = false;
//
//        for (int i = head[u]; i; i = nxt[i]) {
//            int v = to[i];
//            int w = weight[i];
//
//            if (!reach[v]) 
//                continue;
//
//            if (dis[u] != INF && dis[v] > dis[u] + w) {
//                dis[v] = dis[u] + w;
//
//                if (!inQueue[v]) {
//                    q.push(v);
//                    inQueue[v] = true;
//                    update[v]++;
//
//                    if (update[v] >= n) 
//                        return true;
//                    
//                }
//            }
//        }
//    }
//    return false;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
//    int cases;
//    cin >> cases;
//    while (cases--) {
//        int n, m;
//        cin >> n >> m;
//        init(n);
//
//        for (int i = 0; i < m; ++i) {
//            int u, v, w;
//            cin >> u >> v >> w;
//            add(u, v, w);
//            if (w >= 0) 
//                add(v, u, w);
//            
//        }
//
//        bfsReach(n);
//        bool ans = SPFA(n);
//        cout << (ans ? "YES" : "NO") << '\n';
//    }
//    return 0;
//}