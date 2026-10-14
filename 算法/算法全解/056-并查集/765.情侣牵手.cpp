//#include<iostream>
//#include<vector>
//using namespace std;
//
//class UnionFind {
//private:
//    int sets;
//    vector<int>father;
//public:
//    UnionFind(int m) {
//        father.resize(m);
//        sets = m;
//        for (int i = 0; i < m; ++i) {
//            father[i] = i;
//        }
//    }
//
//    int find(int i) {
//        if (i != father[i]) {
//            father[i] = find(father[i]);
//        }
//        return father[i];
//    }
//
//    void unionSet(int x, int y) {
//        int fx = find(x);
//        int fy = find(y);
//        if (fx != fy) {
//            father[fx] = fy;
//            sets--;
//        }
//    }
//
//    int getSets() {
//        return sets;
//    }
//};
//
//class Solution {
//public:
//    int minSwapsCouples(vector<int>& row) {
//        int n = row.size() / 2;
//        UnionFind uf(n);
//
//        for (int i = 0; i < row.size(); i += 2) {
//            int x = row[i] >> 1;
//            int y = row[i + 1] >> 1;
//            uf.unionSet(x, y);
//        }
//
//        return n - uf.getSets();
//    }
//};