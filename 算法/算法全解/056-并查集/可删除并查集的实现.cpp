//#include<iostream>
//using namespace std;
//
//const int MAXN = 1e6 + 10;
//int father[MAXN];
//int size_[MAXN];
//int stack_[MAXN]; 
//int mapping[MAXN]; // 逻辑节点 → 物理节点（核心）
//int nodeCount;     // 物理节点总数
//int n, m;
//
//void build() {
//    for (int i = 1; i <= n; ++i) { 
//        father[i] = i;
//        size_[i] = 1;
//        mapping[i] = i;
//    }
//    nodeCount = n; // 初始物理节点 = n
//}
//
//int find(int i) {
//    int sz = 0;
//    while (i != father[i]) {
//        stack_[sz++] = i;
//        i = father[i];
//    }
//    while (sz) {
//        father[stack_[--sz]] = i;
//    }
//    return i;
//}
//
//bool isSameSet(int x, int y) {
//    return find(mapping[x]) == find(mapping[y]);
//}
//
//void unionSet(int x, int y) {
//    int fx = find(mapping[x]);
//    int fy = find(mapping[y]);
//    if (fx != fy) {
//        if (size_[fx] >= size_[fy]) {
//            size_[fx] += size_[fy];
//            father[fy] = fx;
//        }
//        else {
//            size_[fy] += size_[fx];
//            father[fx] = fy;
//        }
//    }
//}
//
//void remove(int x) {
//    mapping[x] = ++nodeCount;       // 分配新物理节点
//    father[mapping[x]] = mapping[x];// 自己指向自己
//    size_[mapping[x]] = 1;          // 大小=1
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
//    cin >> n >> m;
//    build();
//    while (m--) {
//        int op, x, y;
//        cin >> op >> x >> y;
//
//        if (op == 3) 
//            remove(x);
//        else if (op == 2) 
//            cout << (isSameSet(x, y) ? "Y" : "N") << '\n';
//        else if (op == 1)
//            unionSet(x, y);
//    }
//    return 0;
//}