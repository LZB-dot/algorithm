//#include<iostream>
//#include<vector>
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
//class Solution {
//private:
//    bool flag;
//
//    int height(TreeNode* root) {
//        if (!flag || root == nullptr) {
//            return 0;
//        }
//        int leftH = height(root->left);
//        int rightH = height(root->right);
//        if (fabs(leftH - rightH) > 1) {
//            flag = false;
//        }
//        return max(leftH, rightH) + 1;
//    }
//public:
//    bool isBalanced(TreeNode* root) {
//        flag = true;
//        height(root);
//        return flag;
//    }
//};