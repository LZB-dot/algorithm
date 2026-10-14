//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//class UnionFind {
//private:
//    vector<int>father;
//    int sets;
//public:
//    UnionFind(int n) {
//        father.resize(n);
//        sets = n;
//        for (int i = 0; i < n; ++i) {
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
//private:
//    bool isSimilar(const string& s1, const string& s2) {
//        int diff = 0;
//        int n = s1.size();
//        for (int i = 0; i < n && diff < 3; ++i) {
//            if (s1[i] != s2[i]) {
//                diff++;
//            }
//        }
//        return diff == 0 || diff == 2;
//    }
//public:
//    int numSimilarGroups(vector<string>& strs) {
//        int n = strs.size();
//        UnionFind uf(n);
//        for (int i = 0; i < n; ++i) {
//            for (int j = i + 1; j < n; ++j) {
//                if (isSimilar(strs[i], strs[j])) {
//                    uf.unionSet(i, j);
//                }
//            }
//        }
//
//        return uf.getSets();
//    }
//};