////未加入生成树的边在堆中只有一个条目
//
//#include<iostream>
//#include<cstring>
//#include<string>
//using namespace std;
//
//const int MAXN = 10005;
//const int MAXM = 200005;//无向边存两次
//
//int head[MAXN];//节点u的第一条边的索引
//int next_[MAXM];//边e的下一条边的索引
//int to[MAXM];//边e的目标节点
//int weight[MAXM];//边e的权值
//int cnt;//边的索引
//
////heap[i][0]节点，heap[i][1]该节点到生成树的最小权值
//int heap[MAXM][2];
//int heapSize;//堆的大小
//
////-1未入堆，-2已加入最小生成树，>=0在堆中的位置索引
//int where[MAXN];
//
//int nodeCnt;//已加入的节点数量
//int n, m;//总节点数，总边数
//
//
//void build() {
//	cnt = 1;
//	heapSize = 0;
//	nodeCnt = 0;
//	memset(head, 0, sizeof(head));
//	memset(where, -1, sizeof(where));
//}
//
////向图中添加无向边
//void addEdge(int u, int v, int w) {
//	//添加u->v的边
//	next_[cnt] = head[u];//新边的next指向原来u的第一条边
//	to[cnt] = v;//边的目标节点是v
//	weight[cnt] = w;//边的权值是w
//	head[u] = cnt++;//u的第一条边更新为当前边
//
//	//添加v->u的边
//	next_[cnt] = head[v];
//	to[cnt] = u;
//	weight[cnt] = w;
//	head[v] = cnt++;
//}
//
//
//void swapHeap(int i, int j) {
//	swap(heap[i][0], heap[j][0]);
//	swap(heap[i][1], heap[j][1]);
//
//
//	where[heap[i][0]] = i;
//	where[heap[j][0]] = j;
//}
//
////堆的向上调整
//void heapInsert(int i) {
//	while (heap[i][1] < heap[(i - 1) / 2][1]) {
//		swapHeap(i, (i - 1) / 2);
//		i = (i - 1) / 2;
//	}
//}
//
////堆的向下调整
//void heapify(int i) {
//	int l = 2 * i + 1;//左孩子
//	while (l < heapSize) {
//		//找到左右孩子中权值较小的那个
//		int best = (l + 1 < heapSize && heap[l + 1][1] < heap[l][1]) ? l + 1 : l;
//		//比较当前节点与最优孩子，取权值更小的索引
//		best = (heap[best][1] < heap[i][1]) ? best : i;
//		if (best == i)
//			break;
//
//		swapHeap(best, i);
//		i = best;
//		l = 2 * i + 1;
//	}
//}
//
//void pop() {
//	int u = heap[0][0];
//	//交换堆顶与最后一个元素
//	swapHeap(0, --heapSize);
//	heapify(0);
//
//	where[u] = -2;
//	nodeCnt++;
//}
//
//void addOrUpdateOrIgnore(int e) {
//	int v = to[e];
//	int w = weight[e];
//	// 情况1：v未入堆 → 加入堆并调整
//	if (where[v] == -1) {
//		heap[heapSize][0] = v;
//		heap[heapSize][1] = w;
//		where[v] = heapSize++;
//		heapInsert(where[v]);
//	}
//	// 情况2：v已在堆中 → 若当前权值更小则更新并调整
//	else if (where[v] >= 0) {
//		if (w < heap[where[v]][1]) {
//			heap[where[v]][1] = w;
//			heapInsert(where[v]);
//		}
//	}
//}
//
//// Prim算法：从节点1出发求最小生成树，返回总权值
//int prim() {
//	nodeCnt = 1;               // 初始：节点1已加入生成树
//	where[1] = -2;             // 标记节点1的状态为“已加入”
//	int ans = 0;               // 存储最小生成树的总权值
//
//	// 第一步：将节点1的所有邻边加入堆（初始化候选边）
//	for (int ei = head[1]; ei != 0; ei = next_[ei]) {
//		addOrUpdateOrIgnore(ei);
//	}
//
//	// 循环：每次从堆中选最小权值边，扩展生成树
//	while (heapSize > 0) {
//		// 弹出堆顶（权值最小的边），累加权值
//		int prevW = heap[0][1];  // 堆顶边的权值
//		pop();                   // 将堆顶节点加入生成树
//		ans += prevW;            // 累加到总权值
//
//		// 处理新加入节点的所有邻边，更新堆中候选节点的权值
//		int u = heap[0][0];  // 注意：pop后堆顶已更新，这里需重新获取当前堆顶的前一个节点
//
//		// 遍历新加入节点的所有边（正确逻辑应遍历刚弹出的节点）
//		for (int ei = head[heap[0][0]]; ei != 0; ei = next_[ei]) {
//			addOrUpdateOrIgnore(ei);
//		}
//	}
//
//	return ans;  // 返回总权值（若不连通，nodeCnt会小于n）
//}
//
//
//int main() {
//	ios::sync_with_stdio(false);  // 关闭输入输出同步，加速cin/cout
//	cin.tie(nullptr);             // 解除cin与cout的绑定，进一步加速
//
//	while (cin >> n >> m) {  // 处理多组测试用例
//		build();  // 初始化所有数据结构
//
//		// 读入m条无向边
//		for (int i = 0; i < m; ++i) {
//			int u, v, w;
//			cin >> u >> v >> w;
//			addEdge(u, v, w);  // 添加边到邻接表
//		}
//
//		int ans = prim();  // 计算最小生成树总权值
//
//		// 判断是否所有节点都加入生成树（图是否连通）
//		// 若连通输出总权值，否则输出"orz"
//		cout << (nodeCnt == n ? to_string(ans) : "orz") << endl;
//	}
//
//	return 0;
//}
