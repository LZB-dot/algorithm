//#include<iostream>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
// 
//
//
//
//
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        while (root != nullptr) {
//            if (root->val == p->val || root->val == q->val) {
//                return root;
//            }
//            if (min(p->val, q->val) < root->val && root->val < max(p->val, q->val)) {
//                return root;
//            }
//            else if (root->val < min(p->val, q->val)) {
//                root = root->right;
//            }
//            else {
//                root = root->left;
//            }
//        }
//        return nullptr;
//    }
//};