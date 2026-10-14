//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
//        int res = 0;
//        vector<vector<int> >graph(n);
//        vector<int>indegree(n, 0);
//        vector<int>maxtime(n, 0);
//
//        for (auto edges : relations) {
//            int u = edges[0] - 1;
//            int v = edges[1] - 1;
//            graph[u].push_back(v);
//            indegree[v]++;
//        }
//
//        queue<int>q;
//        for (int i = 0; i < n; ++i) {
//            if (indegree[i] == 0){
//                q.push(i);
//                maxtime[i] = time[i];
//            }
//        }
//
//        while (!q.empty()) {
//            int u = q.front();
//            q.pop();
//
//            for (int v : graph[u]) {
//                maxtime[v] = max(maxtime[v], maxtime[u] + time[v]);
//                indegree[v]--;
//
//                if (indegree[v] == 0)
//                    q.push(v);
//            }
//        }
//
//        for (int t : maxtime)
//            res = max(res, t);
//
//        return res;
//    }
//};