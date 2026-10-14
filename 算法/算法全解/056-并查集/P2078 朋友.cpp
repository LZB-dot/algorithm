//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<int> father; 
//vector<int> size_;   
//
//
//void init(int total) {
//    father.resize(total);  
//    size_.resize(total, 1); 
//    for (int i = 1; i < total; ++i) {
//        father[i] = i;
//    }
//}
//
//
//int find(int x) {
//    if (father[x] != x) {
//        father[x] = find(father[x]);
//    }
//    return father[x];
//}
//
//void unite(int x, int y) {
//    int fx = find(x);
//    int fy = find(y);
//
//    if (fx == fy) 
//        return; 
//
//
//    if (size_[fx] < size_[fy]) {
//        father[fx] = fy;
//        size_[fy] += size_[fx];
//    }
//    else {
//        father[fy] = fx;
//        size_[fx] += size_[fy];
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n, m, p, q;
//    cin >> n >> m >> p >> q;
//
//    int total = n + m + 1;
//    init(total);
//
//
//    for (int i = 0; i < p; ++i) {
//        int x, y;
//        cin >> x >> y;
//        unite(x, y);
//    }
//
//    for (int i = 0; i < q; ++i) {
//        int x, y;
//        cin >> x >> y;
//        unite(n - x, n - y);
//    }
//
//    int boy = find(1);
//    int s1 = size_[boy];
//
//    int girl = find(n + 1);
//    int s2 = size_[girl];
//
//    cout << min(s1, s2) << endl;
//
//    return 0;
//}