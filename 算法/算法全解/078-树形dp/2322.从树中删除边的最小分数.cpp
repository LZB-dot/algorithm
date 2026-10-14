//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int MAXN = 1001;
//
//class Solution {
//private:
//    int dfn[MAXN];
//    int size_[MAXN];
//    int xor_[MAXN];
//    int cnt;
//    vector<vector<int>>graph;
//    void dfs(int u, int p, const vector<int>& nums) {
//        int tmp = ++cnt;
//        dfn[u] = tmp;
//        size_[tmp] = 1;
//        xor_[tmp] = nums[u];
//
//        for (int v : graph[u]) {
//            if (v != p) {
//                dfs(v, u, nums);
//                size_[tmp] += size_[dfn[v]];
//                xor_[tmp] ^= xor_[dfn[v]];
//            }
//        }
//    }
//    
//public:
//    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
//        int n = nums.size();
//        graph.resize(n);
//        for (auto& edge : edges) {
//            int u = edge[0], v = edge[1];
//            graph[u].push_back(v);
//            graph[v].push_back(u);
//        }
//
//        cnt = 0;
//        dfs(0, -1, nums);
//
//        int m = edges.size();
//        int ans = INT_MAX;
//
//        for (int i = 0; i < m; ++i) {
//            int a = max(dfn[edges[i][0]], dfn[edges[i][1]]);
//            for (int j = i + 1; j < m; ++j) {
//                int b = max(dfn[edges[j][0]], dfn[edges[j][1]]);
//
//                int pre, pos;
//                if (a < b) {
//                    pre = a;
//                    pos = b;
//                }
//                else {
//                    pre = b;
//                    pos = a;
//                }
//
//                int sum1, sum2, sum3;
//                sum1 = xor_[pos];//最下的组件
//                if (pos < pre + size_[pre]) {
//                    sum2 = xor_[pre] ^ xor_[pos];
//                    sum3 = xor_[1] ^ xor_[pre];
//                }
//                else {
//                    sum2 = xor_[pre];
//                    sum3 = xor_[1] ^ xor_[pre] ^ xor_[pos];
//                }
//
//                int maxXor = max({ sum1,sum2,sum3 });
//                int minXor = min({ sum1,sum2,sum3 });
//                ans = min(ans, maxXor - minXor);
//            }
//        }
//        return ans;
//    }
//};