//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//class Solution {
//public:
//    int maximumInvitations(vector<int>& favorite) {
//        int n = favorite.size();
//        vector<int>indegree(n, 0);
//
//        for (int i = 0; i < n; ++i) {
//            indegree[favorite[i]]++;
//        }
//
//        queue<int>q;
//        for (int i = 0; i < n; ++i) {
//            if (indegree[i] == 0)
//                q.push(i);
//        }
//           
//        vector<int>deep(n, 0);
//        while (!q.empty()) {
//            int x = q.front();
//            q.pop();
//            int y = favorite[x];
//            indegree[y]--;
//            deep[y] = max(deep[y], deep[x] + 1);
//            if (indegree[y] == 0)
//                q.push(y);
//        }
//
//        int twoRing = 0, bigRing = 0;
//        vector < bool>vis(n, false);
//        for (int i = 0; i < n; ++i) {
//            if (indegree[i] > 0 && !vis[i]) {
//                int s = 0;
//                int cur = i;
//                while (!vis[cur]) {
//                    vis[cur] = true;
//                    cur = favorite[cur];
//                    s++;
//                }
//
//                if (s == 2)
//                    twoRing += 2 + deep[i] + deep[favorite[i]];
//                else
//                    bigRing = max(bigRing, s);
//            }
//        }
//        return max(twoRing, bigRing);
//    }
//};