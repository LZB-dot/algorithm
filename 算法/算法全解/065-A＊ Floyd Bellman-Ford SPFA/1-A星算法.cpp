//
////A*算法：单源最短路径（Duhjstra）的优化
////增加了从当前点到目标点的预估函数
////根据从源点出发到当前点的距离+当前点到终点的预估距离排序
//
////预估函数要求：当前点到终点预估距离 <= 当前点到终点的真实最短距离
//
//
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
////曼哈顿距离--四方向移动
//int f(int x, int y, int tx, int ty) {
//	return abs(tx - x) + abs(ty - y);
//}
//
////对角线距离--八方向移动
//int f2(int x, int y, int tx, int ty) {
//	int dx = abs(tx - x);
//	int dy = abs(ty - y);
//	return max(dx, dy);
//}
//
////欧氏距离--任意方向
//// 欧式距离
//double f3(int x, int y, int targetX, int targetY) {
//	int dx = targetX - x;
//	int dy = targetY - y;
//	return sqrt(dx * dx + dy * dy);
//}
//
//
////grid-网格（1可走，0障碍）
//int aStar(vector<vector<int>>& grid,
//	int sx, int sy, int tx, int ty) {
//	int n = grid.size();         
//	int m = grid[0].size();    
//
//	vector<vector<int>>dis(n, vector<int>(m, INT_MAX));
//	vector<vector<bool>>vis(n, vector<bool>(m, false));
//
//	dis[sx][sy] = 1;
//
//	//f = g（实际距离） + h（启发函数）
//	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>heap;
//	heap.push({ 1 + f(sx,sy,tx,ty),sx,sy });
//
//	int move[] = { -1,0,1,0,-1 };
//
//	while (!heap.empty()) {
//		auto tmp = heap.top();  
//		heap.pop();        
//
//		int fVal = tmp[0];    
//		int x = tmp[1];     
//		int y = tmp[2];    
//
//		if (vis[x][y]) 
//			continue;
//		
//		vis[x][y] = true;
//
//		if (x == tx && y == ty) 
//			return dis[x][y];
//		
//
//		for (int i = 0; i < 4; ++i) {
//			int dx = x + move[i];   
//			int dy = y + move[i + 1];
//
//			// 检查新节点是否合法：
//			// 1. 边界内（dx在[0,n)，dy在[0,m)）
//			// 2. 可通行（grid[dx][dy] == 1）
//			// 3. 未处理过（!vis[dx][dy]）
//			// 4. 从当前节点到达新节点的距离更短（dis[x][y]+1 < dis[dx][dy]）
//			if (dx >= 0 && dy >= 0 && dx < n && dy < m
//				&& grid[dx][dy] == 1 && !vis[dx][dy]
//				&& dis[x][y] + 1 < dis[dx][dy]) {
//
//				dis[dx][dy] = dis[x][y] + 1;
//				int df = f(dx, dy, tx, ty) + dis[dx][dy];
//				heap.push({ df,dx,dy });
//			}
//		}
//	}
//
//	return -1;
//}
