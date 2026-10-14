//
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//
//class Solution {
//private:
//    int cnt;
//    vector<int>head, to_, next_;
//    vector<int>indegree;
//
//    void Init(int n, int m) {
//        head.resize(n, 0);
//        to_.resize(m + 1, -1);
//        next_.resize(m + 1, -1);
//        indegree.resize(n, 0);
//        cnt = 0;
//    }
//
//    void Add(int u, int v) {
//        cnt++;
//        to_[cnt] = v;
//        next_[cnt] = head[u];
//        head[u] = cnt;
//    }
//
//    bool tuopu(int n) {
//        queue<int>q;
//        for (int i = 0; i < n; ++i) {
//            if (indegree[i] == 0)
//                q.push(i);
//        }
//
//        int ans = 0;
//        while (!q.empty()) {
//            int tmp = q.front();
//            q.pop();
//            ans++;
//
//            for (int u = head[tmp]; u != 0; u = next_[u]) {
//                int v = to_[u];
//                indegree[v]--;
//                if (indegree[v] == 0) {
//                    q.push(v);
//                }
//            }
//        }
//
//        return ans == n;
//    }
//
//public:
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//        int m = prerequisites.size();
//        Init(numCourses, m);
//        for (auto& edge : prerequisites) {
//            Add(edge[1], edge[0]);
//            indegree[edge[0]]++;
//        }
//        return tuopu(numCourses);
//    }
//};