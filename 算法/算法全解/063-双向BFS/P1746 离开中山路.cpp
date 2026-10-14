//#include <iostream>
//#include <vector>
//#include <queue>
//#include <map>
//using namespace std;
//
//int d[] = { -1,0,1,0,-1 };
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//    vector<vector<int>> grid(n + 1, vector<int>(n + 1));
//    for (int i = 1; i <= n; ++i) {
//        string s;
//        cin >> s;
//        for (int j = 1; j <= n; ++j)
//            grid[i][j] = s[j - 1] - '0';
//    }
//
//    int x1, y1, x2, y2;
//    cin >> x1 >> y1 >> x2 >> y2;
//
//    queue<pair<int, int>> q1, q2;
//    map<pair<int, int>, int> d1, d2;
//
//    q1.push({ x1,y1 });
//    q2.push({ x2,y2 });
//    d1[{x1, y1}] = 0;
//    d2[{x2, y2}] = 0;
//
//    while (!q1.empty() && !q2.empty()) {
//        if (q1.size() > q2.size()) {
//            swap(q1, q2);
//            swap(d1, d2);
//        }
//
//        int s = q1.size();
//        for (int i = 0; i < s; ++i) {
//            auto it = q1.front(); q1.pop();
//            int x = it.first, y = it.second;
//
//            for (int j = 0; j < 4; ++j) {  
//                int dx = x + d[j];
//                int dy = y + d[j + 1];
//                pair<int, int> tmp = { dx,dy };
//
//                if (dx<1 || dy<1 || dx>n || dy>n || grid[dx][dy] == 1)
//                    continue;
//
//                if (d1.count(tmp))
//                    continue;
//
//                if (d2.count(tmp)) {
//                    cout << d1[it] + 1 + d2[tmp] << "\n";
//                    return 0;
//                }
//
//                d1[tmp] = d1[it] + 1;
//                q1.push(tmp);
//            }
//        }
//    }
//
//    cout << "-1\n";
//    return 0;
//}