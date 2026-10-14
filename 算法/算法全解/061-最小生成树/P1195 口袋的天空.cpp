//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//#define ll long long
//
//const int MAXN = 1005;
//
//int father[MAXN];
//int size_[MAXN];
//
//void init(int n) {
//    for (int i = 1; i <= n; ++i) {
//        father[i] = i;
//        size_[i] = 1; 
//    }
//}
//
//int find(int x) {
//    if (x != father[x])
//        father[x] = find(father[x]); 
//    return father[x];
//}
//
//bool unite(int x, int y) {
//    int fx = find(x);
//    int fy = find(y);
//
//    if (fx == fy)
//        return false;
//
//    if (size_[fx] > size_[fy]) {
//        size_[fx] += size_[fy];
//        father[fy] = fx;
//    }
//    else {
//        size_[fy] += size_[fx];
//        father[fx] = fy;
//    }
//
//    return true;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m, k;
//    cin >> n >> m >> k;
//
//    vector<vector<int>> edges(m);
//
//    for (int i = 0; i < m; ++i) {
//        int x, y, w;
//        cin >> x >> y >> w;
//        edges[i] = { w, x, y };
//    }
//
//
//    sort(edges.begin(), edges.end());
//
//    ll sum = 0;
//    int cnt = n;
//
//    init(n);
//    if (n == k) {
//        cout << sum << "\n";
//        return 0;
//    }
//
//    if (n < k) {
//        cout << "No Answer\n";
//        return 0;
//    }
//    for (int i = 0; i < m; ++i) {
//        int u = edges[i][1];
//        int v = edges[i][2];
//        int w = edges[i][0];
//
//        if (unite(u, v)) {
//            cnt--;
//            sum += w; 
//
//            if (cnt == k) {
//                cout << sum << "\n";
//                return 0;
//            }
//        }
//    }
//
//    cout << "No Answer\n";
//
//    return 0;
//}