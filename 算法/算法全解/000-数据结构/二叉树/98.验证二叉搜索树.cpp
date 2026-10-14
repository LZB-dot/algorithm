//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//private:
//    long long mi, mx; 
//public:
//    bool isValidBST(TreeNode* root) {
//        if (root == nullptr) {
//            mi = LLONG_MAX;
//            mx = LLONG_MIN;
//            return true;
//        }
//
//        // 先验证左子树
//        bool leftValid = isValidBST(root->left);
//        long long leftMi = mi;  //保存左子树的最小值
//        long long leftMx = mx;  //保存左子树的最大值
//
//        // 如果左子树无效，直接返回
//        if (!leftValid) {
//            return false;
//        }
//
//        // 左子树的最大值必须小于当前节点值
//        if (leftMx >= root->val) {
//            return false;
//        }
//
//        bool rightValid = isValidBST(root->right);
//        long long rightMi = mi;  //保存右子树的最小值
//        long long rightMx = mx;  //保存右子树的最大值
//
//        // 如果右子树无效，直接返回
//        if (!rightValid) {
//            return false;
//        }
//
//        // 右子树的最小值必须大于当前节点值
//        if (rightMi <= root->val) {
//            return false;
//        }
//
//        // 更新当前子树的最小值和最大值
//        mi = min((long long)root->val, leftMi);  // 当前子树最小值
//        mx = max((long long)root->val, rightMx); // 当前子树最大值
//
//        return true;
//    }
//};
