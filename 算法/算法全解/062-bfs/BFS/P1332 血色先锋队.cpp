//#include<iostream>
//#include<vector>
//#include<queue>
//#include<climits>
//using namespace std;
//
//#define ll long long
//
//vector<vector<int>> grid;
//vector<vector<bool>> vis;
//int n, m, a, b;
//
//int d[] = { -1, 0, 1, 0, -1 }; 
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> m >> a >> b;
//    grid.resize(n + 1, vector<int>(m + 1, INT_MAX));
//    vis.resize(n + 1, vector<bool>(m + 1, false));
//
//    vector<pair<int, int>> target;
//    queue<pair<int, int>> q;
//
//    int x, y;
//    for (int i = 0; i < a; ++i) {
//        cin >> x >> y;
//        grid[x][y] = 0; 
//        q.push({ x, y });
//        vis[x][y] = true;
//    }
//
//    for (int i = 0; i < b; ++i) {
//        cin >> x >> y;
//        target.push_back({ x, y });
//    }
//
//    while (!q.empty()) {
//        auto it = q.front();
//        q.pop();
//
//        for (int i = 0; i < 4; ++i) {
//            int dx = it.first + d[i];
//            int dy = it.second + d[i + 1];
//
//            if (dx < 1 || dy < 1 || dx > n || dy > m || vis[dx][dy]) 
//                continue;
//
//            grid[dx][dy] = grid[it.first][it.second] + 1;
//            vis[dx][dy] = true; 
//            q.push({ dx, dy });
//        }
//    }
//
//    for (auto& it : target) {
//        cout << grid[it.first][it.second] << "\n";
//    }
//
//    return 0;
//}