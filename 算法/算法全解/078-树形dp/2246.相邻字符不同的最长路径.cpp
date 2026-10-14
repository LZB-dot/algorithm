//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//struct Info {
//    int maxSingle; // 以当前节点为起点，向任意一个子树延伸的最长路径长度
//    int maxPath;   // 在当前节点为根的子树中，存在的最长路径长度
//
//    Info(int s, int p) : maxSingle(s), maxPath(p) {}
//};
//
//class Solution {
//private:
//    vector<vector<int>> graph;
//
//    Info dfs(int u, int p, const string& s) {
//        //一个节点本身
//        int maxSingle = 1;
//        int maxPath = 1;
//
//        int max1 = 0; 
//        int max2 = 0;
//
//        for (int v : graph[u]) {
//            // 避免回退到父节点
//            if (v == p) 
//                continue;
//
//            Info childInfo = dfs(v, u, s);
//
//            //更新整个子树的最长路径
//            maxPath = max(maxPath, childInfo.maxPath);
//
//            if (s[v] != s[u]) {
//                //更新当前节点的 maxSingle
//                maxSingle = max(maxSingle, childInfo.maxSingle + 1);
//
//                //更新 max1 和 max2
//                if (childInfo.maxSingle > max1) {
//                    max2 = max1;
//                    max1 = childInfo.maxSingle;
//                }
//                else if (childInfo.maxSingle > max2) {
//                    max2 = childInfo.maxSingle;
//                }
//            }
//        }
//
//        // 以当前节点为最高点，连接两个子节点的路径
//        maxPath = max(maxPath, max1 + max2 + 1);
//
//        return Info(maxSingle, maxPath);
//    }
//
//public:
//    int longestPath(vector<int>& parent, string s) {
//        int n = parent.size();
//        graph.resize(n);
//
//        for (int i = 1; i < n; ++i) { 
//            int p = parent[i];
//            graph[p].push_back(i);
//            graph[i].push_back(p);
//        }
//
//        return dfs(0, -1, s).maxPath;
//    }
//};
