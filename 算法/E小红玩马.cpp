//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//struct Node {
//    int x, y;
//    int step;
//    int prex, prey;
//};
//
//int main() {
//    int dir[][2] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2} };
//    int n, m, k;
//    int sx, sy, ex, ey;
//    vector<pair<int, int>> path;
//
//    cin >> n >> m >> k;
//    cin >> sx >> sy >> ex >> ey;
//
//    int s = (sx + sy) % 2;
//    int e = (ex + ey) % 2;
//    if ((s + k) % 2 != e) {
//        cout << "NO" << endl;
//        return 0;
//    }
//
//    queue<Node> q;
//    vector<vector<Node>> vis(n + 1, vector<Node>(m + 1, { -1, -1, -1, -1, -1 }));
//    q.push({ sx, sy, 0, -1, -1 });
//    vis[sx][sy] = { sx, sy, 0, -1, -1 };
//
//    int min_step = -1;
//    while (!q.empty()) {
//        Node cur = q.front();
//        q.pop();
//
//        if (cur.x == ex && cur.y == ey) {
//            min_step = cur.step;
//            break;
//        }
//
//        if (cur.step >= k) {
//            continue;
//        }
//
//        for (int i = 0; i < 8; ++i) {
//            int dx = cur.x + dir[i][0];
//            int dy = cur.y + dir[i][1];
//            if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && vis[dx][dy].step == -1) {
//                vis[dx][dy] = { dx, dy, cur.step + 1, cur.x, cur.y };
//                q.push(vis[dx][dy]);
//            }
//        }
//    }
//
//    if (min_step == -1 || min_step > k || (k - min_step) % 2 != 0) {
//        cout << "NO" << endl;
//    }
//    else {
//        int x = ex, y = ey;
//        while (x != -1 && y != -1) {
//            path.emplace_back(x, y);
//            Node tmp = vis[x][y];
//            x = tmp.prex;
//            y = tmp.prey;
//        }
//        reverse(path.begin(), path.end());
//
//        int extra = k - min_step;
//        if (extra > 0) {
//            int px = path[path.size() - 2].first;
//            int py = path[path.size() - 2].second;
//            int cx = ex; 
//            int cy = ey;
//
//            for (int i = 0; i < extra; ++i) {
//                if (i % 2 == 0) {
//                    path.emplace_back(px, py);
//                }
//                else {
//                    path.emplace_back(cx, cy);
//                }
//            }
//        }
//
//        cout << "YES" << endl;
//        for (auto i = 1; i < path.size(); ++i) {
//            cout << path[i].first << " " << path[i].second << endl;
//        }
//    }
//
//    return 0;
//}