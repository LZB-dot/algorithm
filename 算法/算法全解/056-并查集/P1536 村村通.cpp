//#include<iostream>
//#include<vector>
//using namespace std;
//
//int cnt;
//vector<int> father, size_;
//
//void init(int n) {
//    father.resize(n + 1);
//    size_.resize(n + 1, 1);
//    for (int i = 1; i <= n; ++i) {
//        father[i] = i;
//    }
//    cnt = n;
//}
//
//int find(int x) {
//    int fx = x;
//    while (father[fx] != fx) {
//        fx = father[fx];
//    }
//    while (father[x] != fx) {
//        int nxt = father[x];
//        father[x] = fx;
//        x = nxt;
//    }
//    return fx;
//}
//
//void unite(int x, int y) {
//    int fx = find(x);
//    int fy = find(y);
//    if (fx == fy) 
//        return;
//    
//    cnt--;
//    if (size_[fx] < size_[fy]) {
//        size_[fy] += size_[fx];
//        father[fx] = fy;
//    }
//    else {
//        size_[fx] += size_[fy];
//        father[fy] = fx;
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m;
//    while (cin >> n && n != 0) {
//        cin >> m;
//        init(n);
//        for (int i = 0; i < m; ++i) {
//            int x, y;
//            cin >> x >> y;
//            unite(x, y);
//        }
//        cout << cnt - 1 << "\n";
//    }
//
//    return 0;
//}