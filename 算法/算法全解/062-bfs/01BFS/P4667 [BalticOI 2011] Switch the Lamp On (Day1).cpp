//#include <iostream>
//#include <vector>
//#include <deque>
//#include <climits>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m;
//    cin >> n >> m;
//
//    vector<string> grid(n);
//    for (int i = 0; i < n; i++)
//        cin >> grid[i];
//
//    vector<vector<int>> dist(n + 1, vector<int>(m + 1, INT_MAX));
//    deque<pair<int, int>> dq;
//    dq.push_back({ 0,0 });
//    dist[0][0] = 0;
//
//    while (!dq.empty()) {
//        auto it = dq.front();
//        dq.pop_front();
//        int x = it.first;
//        int y = it.second;
//        int cur = dist[x][y];
//
//        // 左上
//        if (x > 0 && y > 0) {
//            int cost = (grid[x - 1][y - 1] == '\\') ? 0 : 1;
//            if (cur + cost < dist[x - 1][y - 1]) {
//                dist[x - 1][y - 1] = cur + cost;
//                if (cost == 0)
//                    dq.push_front({ x - 1,y - 1 });
//                else
//                    dq.push_back({ x - 1,y - 1 });
//            }
//        }
//
//        // 右上
//        if (x > 0 && y < m) {
//            int cost = (grid[x - 1][y] == '/') ? 0 : 1;
//            if (cur + cost < dist[x - 1][y + 1]) {
//                dist[x - 1][y + 1] = cur + cost;
//                if (cost == 0)
//                    dq.push_front({ x - 1,y + 1 });
//                else
//                    dq.push_back({ x - 1,y + 1 });
//            }
//        }
//
//        // 左下
//        if (x < n && y>0) {
//            int cost = (grid[x][y - 1] == '/') ? 0 : 1;
//            if (cur + cost < dist[x + 1][y - 1]) {
//                dist[x + 1][y - 1] = cur + cost;
//                if (cost == 0)
//                    dq.push_front({ x + 1,y - 1 });
//                else
//                    dq.push_back({ x + 1,y - 1 });
//            }
//        }
//
//        // 右下
//        if (x < n && y < m) {
//            int cost = (grid[x][y] == '\\') ? 0 : 1;
//            if (cur + cost < dist[x + 1][y + 1]) {
//                dist[x + 1][y + 1] = cur + cost;
//                if (cost == 0)
//                    dq.push_front({ x + 1,y + 1 });
//                else
//                    dq.push_back({ x + 1,y + 1 });
//            }
//        }
//    }
//
//    if (dist[n][m] == INT_MAX)
//        cout << "NO SOLUTION\n";
//    else
//        cout << dist[n][m] << "\n";
//
//    return 0;
//}