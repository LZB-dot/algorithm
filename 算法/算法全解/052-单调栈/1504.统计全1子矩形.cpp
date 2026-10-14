//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//class Solution {
//public:
//    int numSubmat(vector<vector<int>>& mat) {
//        int n = mat.size(), m = mat[0].size();
//        vector<int>h(m, 0);
//        int ans = 0;
//        auto work = [&]() {
//            int res = 0;
//            vector<int>stk;
//            //小压大
//            for (int i = 0; i < m; ++i) {
//                while (!stk.empty() && h[stk.back()] >= h[i]) {
//                    int cur = stk.back();
//                    stk.pop_back();
//                    if (h[cur] > h[i]) {
//                        int l = stk.empty() ? -1 : stk.back();
//                        int len = i - l - 1;
//                        int high = max(l == -1 ? 0 : h[l], h[i]);
//                        //len * (len + 1) / 2计算底部长度的可能数
//                        res += (h[cur] - high) * len * (len + 1) / 2;
//                    }
//                }
//                stk.push_back(i);
//            }
//            while (!stk.empty()) {
//                int cur = stk.back();
//                stk.pop_back();
//                int l = stk.empty() ? -1 : stk.back();
//                int len = m - l - 1;
//                int high = l == -1 ? 0 : h[l];
//                res += (h[cur] - high) * len * (len + 1) / 2;
//            }
//
//            return res;
//            };
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                h[j] = mat[i][j] == 0 ? 0 : h[j] + 1;
//            }
//            ans += work();
//        }
//        return ans;
//    }
//};