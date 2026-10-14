//
////Prim算法
////选取一个点作为起始集合，选取最近的点加入该集合，重新查找最近点
//
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//using Edge = pair<int, int>;//目标节点，权值
//
//// 自定义比较器：按权值（second）升序排序（小根堆）
//struct EdgeCompare {
//	bool operator()(const Edge& a, const Edge& b) {
//		// 堆的比较器与sort相反：返回true时，a会被放到b的下方（即b优先级更高）
//		return a.second > b.second; // 权值小的优先弹出
//	}
//};
//
//
//int main() {
//	int n, m;
//	while (cin >> n >> m) {
//		vector<vector<Edge>>graph(n + 1);
//		for (int i = 0; i < m; ++i) {
//			int u, v, w;
//			cin >> u >> v >> w;
//			graph[u].emplace_back(v, w);
//			graph[v].emplace_back(u, w);
//		}
//
//		//小根堆
//		priority_queue<Edge, vector<Edge>, EdgeCompare>heap;
//		vector<bool>vis(n + 1, false);
//		int cnt = 0, ans = 0;
//
//		vis[1] = true;
//		++cnt;
//		for (const Edge& e : graph[1]) {
//			heap.push(e);
//		}
//
//		while (!heap.empty()) {
//			Edge tmp = heap.top();
//			heap.pop();
//			int v = tmp.first;
//			int w = tmp.second;
//
//			if(!vis[v]){
//				vis[v] = true;
//				++cnt;
//				ans += w;
//				for (const Edge& e : graph[v]) {
//					if (!vis[e.first])
//						heap.push(e);
//				}
//			}
//
//			if (cnt == n) {
//				break;
//			}
//
//		}
//		if (cnt == n) {
//			cout << ans << endl;
//		}
//		else {
//			cout << "orz" << endl;
//		}
//	}
//	return 0;
//}