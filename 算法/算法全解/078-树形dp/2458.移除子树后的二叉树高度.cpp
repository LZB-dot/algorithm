//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//const int MAXN = 100010;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//
//class Solution {
//private:
//
//    int dfn[MAXN];//该节点的DFS序
//    int deep[MAXN];//对应节点的深度
//    int size_[MAXN];//对应节点为根的子树大小
//    int maxl[MAXN];//前i个DFS序节点的最大深度
//    int maxr[MAXN];//从第i个到最后一个DFS序节点的最大深度
//    int dfnCnt = 0;
//
//    void dfs(TreeNode* u, int depth) {
//        //用一个局部变量x保存当前节点的DFS序
//        int x = ++dfnCnt;
//
//        dfn[u->val] = x;
//        deep[x] = depth;
//        size_[x] = 1;
//
//        if (u->left) {
//            dfs(u->left, depth + 1);
//            size_[x] += size_[dfn[u->left->val]];
//        }
//        if (u->right) {
//            dfs(u->right, depth + 1);
//            size_[x] += size_[dfn[u->right->val]];
//        }
//    }
//
//public:
//    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
//        dfnCnt = 0;
//        dfs(root, 0);
//
//        //前i个DFS序的最大深度
//        maxl[0] = 0;
//        for (int i = 1; i <= dfnCnt; ++i) {
//            maxl[i] = max(maxl[i - 1], deep[i]);
//        }
//
//        //从i到末尾DFS序的最大深度
//        maxr[dfnCnt + 1] = 0;
//        for (int i = dfnCnt; i >= 1; --i) {
//            maxr[i] = max(maxr[i + 1], deep[i]);
//        }
//
//        vector<int> ans;
//        for (int u : queries) {
//            // 根据节点值找到其DFS序
//            int ind = dfn[u];
//            int left = ind - 1;
//            int right = ind + size_[ind];
//
//            // 剩余树的高度是两部分中的最大深度
//            ans.push_back(max(maxl[left], maxr[right]));
//        }
//        return ans;
//    }
//};