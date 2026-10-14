//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//const int N = 2e5 + 10;
//
//struct Edge {
//    int to;      // 终点
//    int next;    // 下一条边的索引
//} edges[N];     // 存储所有边，索引为total
//
//int head[N];    //节点u的第一条边的索引
//int indegree[N];//入度
//int total;      //边的计数器
//
//// 初始化图
//void Init(int n) {
//    total = 0;
//    for (int i = 1; i <= n; ++i) {
//        head[i] = -1;  // -1表示无第一条边
//        indegree[i] = 0;
//    }
//}
//
//// 头插法添加边 u -> v
//void Add(int u, int v) {
//    edges[total].to = v;       // 用边计数器作为索引
//    edges[total].next = head[u];// 新边指向u当前的第一条边
//    head[u] = total++;         // u的第一条边更新为当前边
//}
//
//int main() {
//    ios::sync_with_stdio(false);  // 修正：添加false参数
//    cin.tie(nullptr);
//
//    int n, m;
//    cin >> n >> m;
//
//    Init(n);
//
//    // 读入边并构建图
//    for (int i = 0; i < m; ++i) {
//        int u, v;
//        cin >> u >> v;
//        indegree[v]++;  // v的入度+1
//        Add(u, v);      // 添加边u->v
//    }
//
//    // 小根堆：保证每次选择编号最小的入度为0的节点
//    priority_queue<int, vector<int>, greater<int>> pq;
//    for (int i = 1; i <= n; ++i) {
//        if (indegree[i] == 0) {
//            pq.push(i);
//        }
//    }
//
//    vector<int> res;
//    while (!pq.empty()) {
//        int u = pq.top();
//        pq.pop();
//        res.push_back(u);
//
//        // 遍历u的所有出边（链式前向星遍历）
//        for (int i = head[u]; i != -1; i = edges[i].next) {
//            int v = edges[i].to;  // 边的终点
//            indegree[v]--;
//            if (indegree[v] == 0) {
//                pq.push(v);
//            }
//        }
//    }
//
//    // 输出结果
//    if (res.size() == n) {
//        for (int i = 0; i < n; ++i) {
//            if (i > 0) cout << " ";
//            cout << res[i];
//        }
//        cout << endl;
//    }
//    else
//        cout << -1 << endl;
//
//    return 0;
//}
