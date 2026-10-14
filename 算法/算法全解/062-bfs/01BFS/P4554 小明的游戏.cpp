//#include<iostream>
//#include<vector>
//#include<queue>
//#include<climits>
//using namespace std;
//
//int d[] = { -1,0,1,0,-1 };
//
//int main() {
//	ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//	while (1) {
//		int n, m;
//		cin >> n >> m;
//		if (n == 0 && m == 0)
//			break;
//
//		vector<vector<char>>grid(n, vector<char>(m));
//		vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
//
//		for (int i = 0; i < n; ++i)
//			for (int j = 0; j < m; ++j)
//				cin >> grid[i][j];
//
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//
//		deque<pair<int, int>>dq;
//		dq.push_front({ x1,y1 });
//		dist[x1][y1] = 0;
//
//		while (!dq.empty()) {
//			auto it = dq.front();
//			int x = it.first;
//			int y = it.second;
//			dq.pop_front();
//
//			for (int i = 0; i < 4; ++i) {
//				int dx = d[i] + x;
//				int dy = d[i + 1] + y;
//				if (dx < 0 || dy < 0 || dx >= n || dy >= m)
//					continue;
//
//				int cost = (grid[dx][dy] == grid[x][y]) ? 0 : 1;
//				if (dist[dx][dy] > dist[x][y] + cost) {
//					dist[dx][dy] = dist[x][y] + cost;
//					if (cost == 0)
//						dq.push_front({ dx, dy });  
//					else
//						dq.push_back({ dx, dy }); 
//				}
//				
//			}
//		}
//		cout << dist[x2][y2] << "\n";
//	}
//	
//	return 0;
//}