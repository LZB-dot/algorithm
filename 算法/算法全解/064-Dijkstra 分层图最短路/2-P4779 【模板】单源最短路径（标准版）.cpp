////https://www.luogu.com.cn/problem/P4779
//
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//const int MAXN = 100010; 
//const int MAXM = 200010; 
//const int INF = 1e9;  
//
//int head[MAXN];       
//int nxt[MAXM];     
//int to[MAXM];        
//int weight[MAXM];  
//int cnt;         
//
////堆优化相关
//int heap[MAXN];         //小根堆（存储节点编号）
//int where[MAXN];        //反向索引：-1=未入堆，-2=已弹出，>=0=在堆中的位置
//int heapSize;           //堆当前大小
//int dis[MAXN];          //源点到各节点的最短距离
//
//
//void init(int n) {
//    cnt = 1;                
//    heapSize = 0;            
//    memset(head, 0, sizeof(int) * (n + 1)); 
//    memset(where, -1, sizeof(int) * (n + 1));
//    fill(dis, dis + n + 1, INF);  
//}
//
//inline void add(int u, int v, int w) {
//    nxt[cnt] = head[u];
//    to[cnt] = v;
//    weight[cnt] = w;
//    head[u] = cnt++;
//}
//
////交换堆中两个位置的节点，并更新反向索引
//void swap(int i, int j) {
//    int tmp = heap[i];
//    heap[i] = heap[j];
//    heap[j] = tmp;
//
//    //更新节点在堆中的位置
//    where[heap[i]] = i;  
//    where[heap[j]] = j;
//}
//
////堆的上浮操作
//void heapInsert(int i) {
//    // 父节点位置为 (i-1)/2，若当前节点距离更小则上浮
//    while (dis[heap[i]] < dis[heap[(i - 1) / 2]]) {
//        swap(i, (i - 1) / 2);  //与父节点交换
//        i = (i - 1) / 2;       //更新当前位置为父节点位置
//    }
//}
//
////处理节点v的距离更新（入堆/更新堆/忽略）
//void addOrUpdateOrIgnore(int v, int w) {
//    if (where[v] == -1) {  //节点v未入堆：加入堆并更新距离
//        heap[heapSize] = v;
//        where[v] = heapSize++;  //记录位置，堆大小+1
//        dis[v] = w;
//        heapInsert(where[v]);   //上浮到正确位置
//    }
//    else if (where[v] >= 0) {  //节点v在堆中：若新距离更短则更新
//        if (w < dis[v]) {
//            dis[v] = w;
//            heapInsert(where[v]);  //上浮维持堆结构
//        }
//    }
//    // 若where[v] == -2（已弹出），无需处理（最短距离已确定）
//}
//
////判断堆是否为空
//bool isEmpty() {
//    return heapSize == 0;
//}
//
////堆的下沉操作
//void heapify(int i) {
//    int l = i * 2 + 1;  // 左子节点位置
//    while (l < heapSize) {  // 子节点存在时继续
//        // 找到左右子节点中距离较小的那个
//        int best = (l + 1 < heapSize && dis[heap[l + 1]] < dis[heap[l]]) ? l + 1 : l;
//        // 比较当前节点与子节点，取距离最小的位置
//        best = (dis[heap[best]] < dis[heap[i]]) ? best : i;
//
//        if (best == i) 
//            break; 
//
//        swap(best, i);         //交换位置
//        i = best;              //更新当前位置
//        l = i * 2 + 1;         //更新左子节点位置
//    }
//}
//
//// 弹出堆顶元素（当前距离最小的节点）
//int pop() {
//    int ans = heap[0];       // 堆顶为距离最小的节点
//    swap(0, --heapSize);     // 交换堆顶与最后一个元素，堆大小-1
//    heapify(0);              // 下沉新堆顶以维持堆结构
//    where[ans] = -2;         // 标记为已弹出（最短距离已确定）
//    return ans;
//}
//
//int compute(int n, int s, int m) {
//
//    // 源点自身距离为0，加入堆
//    addOrUpdateOrIgnore(s, 0);
//
//    // 处理堆中节点，直到堆为空
//    while (!isEmpty()) {
//        int u = pop();  //弹出当前距离最小的节点u
//
//
//        for (int e = head[u]; e != 0; e = nxt[e]) {
//            int v = to[e];   
//            int w = weight[e];
//
//            int newd = dis[u] + w; 
//            addOrUpdateOrIgnore(v, newd);  
//        }
//    }
//
//}
//
//int main() {
//    int n, m, s; 
//    cin >> n >> m >> s;
//    
//    for (int i = 0; i < m; ++i) {
//        int u, v, w;
//        cin >> u >> v >> w;
//
//        add(u, v, w);
//    }
//
//    init(n);
//
//    compute(n, s, m);  
//
//    for (int i = 1; i <= n; ++i) {
//        if (dis[i] == INF) 
//            cout << "INF ";
//        else 
//            cout << dis[i] << " ";
//    }
//    return 0;
//}