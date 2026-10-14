//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//struct TreeNode {
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
//    int yes, no;
//
//    void dfs(TreeNode* root) {
//        if (root == nullptr) {
//            yes = no = 0;
//            return;
//        }
//        int y = root->val;
//        int n = 0;
//        dfs(root->left);
//        y += no;
//        n += max(yes, no);
//        dfs(root->right);
//        y += no;
//        n += max(yes, no);
//        yes = y;
//        no = n;
//    }
//public:
//    int rob(TreeNode* root) {
//        dfs(root);
//        return max(yes, no);
//    }
//};