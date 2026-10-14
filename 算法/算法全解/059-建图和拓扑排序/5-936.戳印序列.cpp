//
//
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> movesToStamp(string stamp, string target) {
//        int m = stamp.size();
//        int n = target.size();
//
//        vector<int>ans;
//
//        int N = n - m + 1;
//        vector<int>indegree(N, 0);//需要修改的字符个数
//        vector<vector<int> >graph(n);//存储依赖i这个位置的j
//        for (int i = 0; i < N; ++i) {
//            for (int j = 0; j < m; ++j) {
//                if (target[i + j] != stamp[j]) {
//                    indegree[i]++;
//                    graph[i + j].push_back(i);
//                }
//            }
//        }
//
//        queue<int>q;
//        for (int i = 0; i < N; ++i) {
//            if (indegree[i] == 0)
//                q.push(i);
//        }
//
//        vector<bool>vis(N, 0);
//        vector<bool>cover(n, false);//字符i是否被置为？
//        int total = 0;
//        while (!q.empty()) {
//            int u = q.front();
//            q.pop();
//
//            if (vis[u])
//                continue;
//
//            vis[u] = 1;
//            ans.push_back(u);
//
//            for (int p = 0; p < m; ++p) {
//                int j = p + u;
//
//                if (cover[j])
//                    continue;
//
//                cover[j] = 1;
//                ++total;
//
//                for (int i : graph[j]) {
//                    if (--indegree[i] == 0)
//                        q.push(i);
//                }
//            }
//
//
//        }
//        reverse(ans.begin(), ans.end());
//
//        if (total != n) // 不能全部擦成问号，无解
//            return {};
//
//
//        return ans;
//    }
//};