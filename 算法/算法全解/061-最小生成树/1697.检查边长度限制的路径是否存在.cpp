//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//class Solution {
//private:
//    vector<int>father;
//    vector<int>rank;
//
//    void build(int n) {
//        father.resize(n);
//        rank.resize(n);
//        for (int i = 0; i < n; ++i) {
//            father[i] = i;
//            rank[i] = 1;
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
//    void unite(int x, int y) {
//        int fx = find(x);
//        int fy = find(y);
//        if (fx == fy) {
//            return;
//        }
//
//        if (rank[fx] < rank[fy]) {
//            father[fx] = fy;
//        }
//        else {
//            father[fy] = fx;
//            if (rank[fx] == rank[fy]) {
//                rank[fx]++;
//            }
//        }
//    }
//
//    bool isConnect(int x, int y) {
//        return find(x) == find(y);
//    }
//
//public:
//    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
//
//        int m = edgeList.size();
//        int k = queries.size();
//
//        vector<vector<int>>ques(k, vector<int>(4));
//        for (int i = 0; i < k; ++i) {
//            ques[i][0] = queries[i][0];
//            ques[i][1] = queries[i][1];
//            ques[i][2] = queries[i][2];
//            ques[i][3] = i;
//        }
//
//        sort(edgeList.begin(), edgeList.end(),
//            [&](const vector<int>& a, const vector<int>& b) {
//                return a[2] < b[2];
//            });
//
//        sort(ques.begin(), ques.end(),
//            [&](const vector<int>& a, const vector<int>& b) {
//                return a[2] < b[2];
//            });
//
//        build(n);
//        vector<bool>ans(k, 0);
//        int j = 0;
//        for (int i = 0; i < k; ++i) {
//            int limit = ques[i][2];
//            while (j < m && edgeList[j][2] < limit) {
//                unite(edgeList[j][0], edgeList[j][1]);
//                ++j;
//            }
//            ans[ques[i][3]] = isConnect(ques[i][0], ques[i][1]);
//        }
//        return ans;
//    }
//};