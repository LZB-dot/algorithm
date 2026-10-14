//#include<iostream>
//#include<vector>
//using namespace std;
//
//struct Edge {
//	int to;//目标节点
//	int w;//权重
//	int next;//下一条边索引
//};
//
//class Graph {
//private:
//	vector<Edge>edges;// 存储所有边，索引从0开始
//	vector<int>head;//记录i顶点第一条边在edges的索引
//	int node_count;
//	int edge_count;
//
//public:
//	Graph(int n) :node_count(n),edge_count(0){
//		head.resize(n + 1, -1);
//		edges.reserve(2e5);
//	}
//
//	//头插法
//	void addEdge(int start, int to, int w) {
//		Edge e;
//		e.to = to; e.w = w;
//		//新边指向起点当前的第一条边
//		e.next = head[start];
//		//让起点的第一条边改为新边
//		head[start] = edge_count;
//		//将新边存入
//		edges.push_back(e);
//		//边数加一，即下一条边的索引
//		edge_count++;
//	}
//
//	//无向边处理
//	void addUnEdge(int u, int v, int w) {
//		addEdge(u, v, w);
//		addEdge(v, u, w);
//	}
//
//	void printGraph() {
//		for (int i = 1; i <= node_count; ++i) {
//			cout << "节点 " << i << " 的边: ";
//			int index = head[i];
//			while (index != -1) {
//				Edge e = edges[index];
//				cout << "(" << i << " -> " << e.to << ", 权重: " << e.w << ") ";
//				index = e.next; 
//			}
//			cout << endl;
//		}
//	}
//
//};
