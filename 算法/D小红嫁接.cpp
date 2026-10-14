//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//    if (n <= 2) { 
//        cout << 0 << endl;
//        return 0;
//    }
//
//    vector<int> degree(n + 1, 0);
//    for (int i = 0; i < n - 1; ++i) {
//        int u, v;
//        cin >> u >> v;
//        degree[u]++;
//        degree[v]++;
//    }
//
//    int res = 0;
//    for (int i = 1; i <= n; ++i) {
//        if (degree[i] > 2) {
//            res += (degree[i] - 2); 
//        }
//    }
//
//    cout << res << endl;
//    return 0;
//}