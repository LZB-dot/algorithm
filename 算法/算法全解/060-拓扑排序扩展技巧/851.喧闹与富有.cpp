//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
//        int n = quiet.size();
//        vector<vector<int>>graph(n);
//        vector<int>indegree(n, 0);
//        vector<int>res(n);
//
//        for (int i = 0; i < n; ++i)
//            res[i] = i;
//
//        for (auto& edge : richer) {
//            int u = edge[0];
//            int v = edge[1];
//            graph[u].push_back(v);
//            indegree[v]++;
//        }
//
//        queue<int>q;
//        for (int i = 0; i < n; ++i) {
//            if (indegree[i] == 0)
//                q.push(i);
//        }
//
//        while (!q.empty()) {
//            int u = q.front();
//            q.pop();
//
//            for (int v : graph[u]) {
//                if (quiet[res[u]] < quiet[res[v]])
//                    res[v] = res[u];
//
//                indegree[v]--;
//                if (indegree[v] == 0)
//                    q.push(v);
//            }
//        }
//        return res;
//    }
//};