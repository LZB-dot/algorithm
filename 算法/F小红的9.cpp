//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//struct Node {
//    int cur;     
//    int father;  
//    int dis;    
//    Node(int c, int f, int d) : cur(c), father(f), dis(d) {}
//};
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
//    int n;
//    cin >> n;
//    vector<vector<int>> adj(n + 1);  
//
//    for (int i = 0; i < n - 1; ++i) {
//        int u, v;
//        cin >> u >> v;
//        adj[u].push_back(v);
//        adj[v].push_back(u);
//    }
//
//    for (int u = 1; u <= n; ++u) {
//        int count = 0;
//        queue<Node> q;
//        q.push(Node(u, -1, 0));  
//
//        while (!q.empty()) {
//            Node node = q.front();
//            q.pop();
//
//            int cur = node.cur;
//            int father = node.father;
//            int dis = node.dis;
//
//            if (dis == 9) {
//                count++;
//                continue;  
//            }
//
//            if (dis > 9) {
//                continue;
//            }
//
//            for (int next : adj[cur]) {
//                if (next != father) {  
//                    q.push(Node(next, cur, dis + 1));
//                }
//            }
//        }
//
//        cout << count << " ";
//    }
//
//    return 0;
//}