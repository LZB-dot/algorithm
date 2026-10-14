//#include<iostream>
//#include<vector>
//#include<queue>
//#include<climits>
//using namespace std;
//
//struct Node{
//	int x, y;
//	int keys;
//};
//
//int d[] = { -1,0,1,0,-1 };
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, m, p;
//	cin >> n >> m >> p;
//
//	int k;
//	cin >> k;
//	
//	//上 右 下 左
//	//-1可通行，0墙，>0钥匙
//	//记录当前位置各个方向的物
//	vector<vector<vector<int>>>grid(n + 1, vector<vector<int>>(m + 1, vector<int>(4, -1)));
//
//	int x1, y1, x2, y2, g;
//	for (int i = 0; i < k; ++i) {
//		cin >> x1 >> y1 >> x2 >> y2 >> g;
//		if (x1 == x2) {
//			if (y1 > y2) {
//				grid[x1][y1][3] = g;
//				grid[x2][y2][1] = g;
//			}
//			else {
//				grid[x1][y1][1] = g;
//				grid[x2][y2][3] = g;
//			}
//		}
//		else if (y1 == y2) {
//			if (x1 > x2) {
//				grid[x1][y1][0] = g;
//				grid[x2][y2][2] = g;
//			}
//			else {
//				grid[x1][y1][2] = g;
//				grid[x2][y2][0] = g;
//			}
//		}
//	}
//
//	//记录当前位置钥匙的状态
//	vector<vector<int>>key(n + 1, vector<int>(m + 1));
//	int s;
//	cin >> s;
//	for (int i = 0; i < s; ++i) {
//		cin >> x1 >> y1 >> g;
//		key[x1][y1] |= (1 << (g - 1));
//	}
//
//	queue<Node>q;
//	//记录到达当前点的距离
//	vector<vector<vector<int>>>dist(n + 1, vector<vector<int>>(m + 1, vector<int>(1 << 14, INT_MAX)));
//	q.push({ 1,1,0 });
//	dist[1][1][0] = 0;
//
//	while (!q.empty()) {
//		auto it = q.front();
//		q.pop();
//
//		int x = it.x;
//		int y = it.y;
//		int cur = it.keys;
//
//		for (int i = 0; i < 4; ++i) {
//			int dx = x + d[i];
//			int dy = y + d[i + 1];
//
//			if (dx<1 || dy<1 || dx>n || dy>m)
//				continue;
//
//			//当前位置要走的方向是否有墙
//			int wall = grid[x][y][i];
//			if (wall == 0)
//				continue;
//
//			if (wall > 0 && !(cur & (1 << (wall - 1))))
//				continue;
//
//			int nw = cur | key[dx][dy];
//			if (dist[dx][dy][nw] == INT_MAX) {
//				dist[dx][dy][nw] = dist[x][y][cur] + 1;
//				q.push({ dx,dy,nw });
//			}
//		}
//	}
//
//	int ans = INT_MAX;
//	for (int t = 0; t < (1 << p); ++t) {
//		ans = min(ans, dist[n][m][t]);
//	}
//
//	if (ans == INT_MAX)
//		cout << "-1\n";
//	else
//		cout << ans << "\n";
//	return 0;
//}
//
//
//
//
//
//
//
//
