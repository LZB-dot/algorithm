//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//
//class Solution {
//private:
//    vector<int>father;
//    vector<int>mx;//最大值出现次数
//
//    void build(int n) {
//        father.resize(n);
//        mx.resize(n);
//        for (int i = 0; i < n; ++i) {
//            father[i] = i;
//            mx[i] = 1;
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
//    int unionSet(int x, int y, const vector<int>& vals) {
//        int fx = find(x);
//        int fy = find(y);
//        int path = 0;
//        //约束根节点即最大值
//        if (vals[fx] > vals[fy]) {
//            father[fy] = fx;
//        }
//        else if (vals[fx] < vals[fy]) {
//            father[fx] = fy;
//        }
//        else {
//            path = mx[fx] * mx[fy];
//            father[fx] = fy;
//            mx[fy] += mx[fx];
//        }
//        return path;
//    }
//
//public:
//    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
//        int n = vals.size();
//        build(n);
//        int ans = n;
//        //从小到大
//        sort(edges.begin(), edges.end(),
//            [&](const vector<int>& e1, const vector<int>& e2) {
//                int m1 = max(vals[e1[0]], vals[e1[1]]);
//                int m2 = max(vals[e2[0]], vals[e2[1]]);
//                return m1 < m2;
//            });
//        for (auto& edge : edges) {
//            ans += unionSet(edge[0], edge[1], vals);
//        }
//
//        return ans;
//    }
//};