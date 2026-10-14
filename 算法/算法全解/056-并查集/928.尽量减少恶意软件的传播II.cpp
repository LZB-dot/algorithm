//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//private:
//    vector<int>father;
//    vector<int>size;
//    vector<bool>isVirus;//是否被感染
//    vector<int>infect;//感染源头,-1为被感染，-2被多个感染
//    vector<int>cnts;//初始节点感染的节点数
//
//    void build(int n) {
//        father.resize(n);
//        size.resize(n, 1);
//        isVirus.resize(n, false);
//        infect.resize(n, -1);
//        cnts.resize(n, 0);
//        for (int i = 0; i < n; ++i) {
//            father[i] = i;
//        }
//    }
//
//    int find(int x) {
//        if (x != father[x]) {
//            father[x] = find(father[x]);
//        }
//        return father[x];
//    }
//
//    void unionSets(int x, int y) {
//        int fx = find(x);
//        int fy = find(y);
//
//        if (fx != fy) {
//            father[fx] = fy;
//            size[fy] += size[fx];
//        }
//    }
//
//public:
//    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
//        int n = graph.size();
//        build(n);
//
//        for (int i : initial) {
//            isVirus[i] = true;
//        }
//
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < i; ++j) {
//                if (graph[i][j] == 1 && !isVirus[i] && !isVirus[j]) {
//                    unionSets(i, j);
//                }
//            }
//        }
//
//        for (int i : initial) {
//            for (int j = 0; j < n; ++j) {
//                if (graph[i][j] == 1 && i != j && !isVirus[j]) {
//                    int root = find(j);
//                    if (infect[root] == -1) {
//                        infect[root] = i;
//                    }
//                    else if (infect[root] != -2 && infect[root] != i) {
//                        infect[root] = -2;
//                    }
//                }
//            }
//        }
//
//        for (int i = 0; i < n; ++i) {
//            //是连通块的根且被单个初始节点感染
//            if (i == find(i) && infect[i] >=0) {
//                cnts[infect[i]] += size[i];
//            }
//        }
//
//        sort(initial.begin(), initial.end());
//        int ans = initial[0];
//        int mx = cnts[ans];
//        for (int i : initial) {
//            if (cnts[i] > mx) {
//                mx = cnts[i];
//                ans = i;
//            }
//        }
//        return ans;
//    }
//};