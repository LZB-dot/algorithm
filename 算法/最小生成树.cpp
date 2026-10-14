////Prim算法
//
//#include<stdio.h>
//#include<limits.h>
//
//#define V 5
//
//int minKey(int key[], int mstSet[])
//{
//    int min = INT_MAX, min_index;
//    for (int v = 0; v < V; v++)
//    {
//        if (mstSet[v] == 0 && key[v] < min)
//        {
//            min = key[v];
//            min_index = v;
//        }
//    }
//    return min_index;
//}
//
//void printMST(int parent[], int graph[V][V])
//{
//    // 打印边及其权值
//    printf("Edge \tWeight\n");
//    for (int i = 1; i < V; i++)
//    {
//        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
//    }
//}
//
//void primMST(int graph[V][V])
//{
//    int parent[V];//存储最小生成树的父节点
//    int key[V];//存储顶点到最小生成树的最小权值
//    int mstSet[V];//标记顶点是否已加入最小生成树
//    for (int i = 0; i < V; i++)
//    {
//        key[i] = INT_MAX;
//        mstSet[i] = 0;
//    }
//    key[0] = 0;
//    parent[0] = -1;
//    for (int count = 0; count < V - 1; count++)
//    {
//        int u = minKey(key, mstSet);
//        mstSet[u] = 1;
//        for (int v = 0; v < V; v++)
//        {
//            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
//            {
//                parent[v] = u;
//                key[v] = graph[u][v];
//            }
//        }
//    }
//    printMST(parent, graph);
//}
//
//int main()
//{
//    int graph[V][V] = { {0, 2, 0, 6, 0},
//                       {2, 0, 3, 8, 5},
//                       {0, 3, 0, 0, 7},
//                       {6, 8, 0, 0, 9},
//                       {0, 5, 7, 9, 0} };
//    primMST(graph);
//    return 0;
//}

//Kruskal算法

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//    int src, dest, weight; // 边的起点，终点和权值
//} Edge;
//
//typedef struct {
//    int V, E; // 顶点数和边数
//    Edge* edges; // 存储边的数组
//} Graph;
//
//// 创建图
//Graph* createGraph(int V, int E) {
//    // 分配图的内存
//    Graph* graph = (Graph*)malloc(sizeof(Graph));
//    graph->V = V;
//    graph->E = E;
//    // 分配边数组的内存
//    graph->edges = (Edge*)malloc(E * sizeof(Edge));
//    return graph;
//}
//
//// 比较函数，用于 qsort
//int compare(const void* a, const void* b) {
//    Edge* edge1 = (Edge*)a;
//    Edge* edge2 = (Edge*)b;
//    // 按权值从小到大排序
//    return edge1->weight - edge2->weight;
//}
//
//int find(int parent[], int i) {
//    // 如果 i 的父节点是自己，说明 i 是根节点
//    if (parent[i] == i)
//        return i;
//    return find(parent, parent[i]);
//}
//
//void unionSets(int parent[], int x, int y) {
//    // 查找 x 和 y 的根节点
//    int xroot = find(parent, x);
//    int yroot = find(parent, y);
//    // 将 x 的根节点的父节点设为 y 的根节点
//    parent[xroot] = yroot;
//}
//
//void kruskalMST(Graph* graph) {
//    int V = graph->V;
//    // 存储最小生成树的边，边数为 V - 1
//    Edge* result = (Edge*)malloc((V - 1) * sizeof(Edge));
//    int e = 0; // 结果数组的索引
//    int i = 0; // 排序后的边数组索引
//    qsort(graph->edges, graph->E, sizeof(Edge), compare);
//    int* parent = (int*)malloc(V * sizeof(int));
//    for (int v = 0; v < V; v++)
//        parent[v] = v;
//
//    while (e < V - 1 && i < graph->E) {
//        Edge next_edge = graph->edges[i++];
//        // 查找边的起点和终点的根节点
//        int x = find(parent, next_edge.src);
//        int y = find(parent, next_edge.dest);
//        if (x != y) {
//            result[e++] = next_edge;
//            unionSets(parent, x, y);
//        }
//    }
//
//    // 打印最小生成树
//    printf("Edge \tWeight\n");
//    for (i = 0; i < e; i++) {
//        // 打印边及其权值
//        printf("%d - %d \t%d \n", result[i].src, result[i].dest, result[i].weight);
//    }
//
//    // 释放父节点数组和结果数组的内存
//    free(parent);
//    free(result);
//}
//
//int main() {
//    int V = 4;  // 顶点数
//    int E = 5;  // 边数
//    // 创建图
//    Graph* graph = createGraph(V, E);
//
//    // 添加边
//    graph->edges[0].src = 0;
//    graph->edges[0].dest = 1;
//    graph->edges[0].weight = 10;
//
//    graph->edges[1].src = 0;
//    graph->edges[1].dest = 2;
//    graph->edges[1].weight = 6;
//
//    graph->edges[2].src = 0;
//    graph->edges[2].dest = 3;
//    graph->edges[2].weight = 5;
//
//    graph->edges[3].src = 1;
//    graph->edges[3].dest = 3;
//    graph->edges[3].weight = 15;
//
//    graph->edges[4].src = 2;
//    graph->edges[4].dest = 3;
//    graph->edges[4].weight = 4;
//
//    // 调用 Kruskal 算法
//    kruskalMST(graph);
//
//    // 释放边数组和图的内存
//    free(graph->edges);
//    free(graph);
//
//    return 0;
//}