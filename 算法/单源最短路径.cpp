//#include<stdio.h>
//#include<limits.h>
//
//#define V 9
//
//int minDistance(int dist[], int sptSet[])
//{
//    int min = INT_MAX;
//    int min_index;
//    for (int v = 0; v < V; v++)
//    {
//        if (sptSet[v] == 0 && dist[v] <= min)
//        {
//            min = dist[v];
//            min_index = v;
//        }
//    }
//    return min_index;
//}
//
//void printSolution(int dist[])
//{
//    printf("顶点\t距离源点的最短距离\n");
//    for (int i = 0; i < V; i++)
//    {
//        printf("%d\t %d\n", i, dist[i]);
//    }
//}
//
//void Dijkstra(int graph[V][V], int src)
//{
//    int dist[V];     // 存储从源点到各个顶点的最短距离
//    int sptSet[V];   // 标记顶点是否已经确定最短路径
//    //初始化距离数组和标记数组
//    for (int i = 0; i < V; i++)
//    {
//        dist[i] = INT_MAX;
//        sptSet[i] = 0;
//    }
//    //源点到自身距离为0
//    dist[src] = 0;
//    for (int count = 0; count < V - 1; count++)
//    {
//        //找到距离源点最近且未被处理的顶点
//        int u = minDistance(dist, sptSet);
//        //标记该顶点已被处理
//        sptSet[u] = 1;
//        //更新与该顶点相邻的顶点的最短距离
//        for (int v = 0; v < V; v++)
//        {
//            // 如果顶点 v 未被处理（!sptSet[v]）
//           // 并且顶点 u 和顶点 v 之间有边相连（graph[u][v]）
//           // 并且顶点 u 到源点的距离不是无穷大（dist[u] != INT_MAX）
//           // 并且通过顶点 u 到达顶点 v 的距离比当前记录的顶点 v 到源点的距离小
//            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
//                && dist[u] + graph[u][v] < dist[v])
//            {
//                dist[v] = dist[u] + graph[u][v];
//            }
//        }
//    }
//    printSolution(dist);
//}
//
//int main() 
//{
//    // 用邻接矩阵表示图
//    int graph[V][V] = { {0, 4, 0, 0, 0, 0, 0, 8, 0},
//                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
//                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
//                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
//                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
//                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
//                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
//                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
//                       {0, 0, 2, 0, 0, 0, 6, 7, 0} };
//
//    // 源点为 0
//    Dijkstra(graph, 0);
//    return 0;
//}