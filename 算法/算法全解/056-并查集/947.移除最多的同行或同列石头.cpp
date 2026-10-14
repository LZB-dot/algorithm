//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//class UnionFind {
//private:
//    int sets;
//    vector<int>father;
//public:
//    UnionFind(int n) {
//        father.resize(n);
//        for (int i = 0; i < n; ++i) {
//            father[i] = i;
//        }
//        sets = n;
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
//class Solution {
//public:
//    int removeStones(vector<vector<int>>& stones) {
//        int n = stones.size();
//        UnionFind uf(n);
//        unordered_map<int, int>cols;
//        unordered_map<int, int>rows;
//
//        for (int i = 0; i < n; ++i) {
//            int row = stones[i][0];
//            int col = stones[i][1];
//            if (rows.count(row)) {
//                uf.unionSet(i, rows[row]);
//            }
//            else {
//                rows[row] = i;
//            }
//
//            if (cols.count(col)) {
//                uf.unionSet(i, cols[col]);
//            }
//            else {
//                cols[col] = i;
//            }
//        }
//        return n - uf.getSets();
//    }
//};