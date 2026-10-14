//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//
//struct TreeNode {
//    
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//
//
//class Solution {
//private:
//    int ans = 0;
//    unordered_map<long long, int>pre;
//
//    void dfs(TreeNode* x, int target, long long sum) {
//        if (x == nullptr) {
//            return;
//        }
//
//        sum += x->val;
//        if (pre.count(sum - target)) {
//            ans += pre[sum - target];
//        }
//
//        pre[sum]++;
//
//        dfs(x->left, target, sum);
//        dfs(x->right, target, sum);
//
//        //当前子树计算完，要移除当前子树的前缀和
//        pre[sum]--;
//    }
//public:
//    int pathSum(TreeNode* root, int targetSum) {
//        pre[0] = 1;
//        dfs(root, targetSum, 0);
//        return ans;
//    }
//};