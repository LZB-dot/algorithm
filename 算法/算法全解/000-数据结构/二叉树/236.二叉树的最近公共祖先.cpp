//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        //如果该节点空，或者等于其中一个数
//        if (!root || root == p || root == q)
//            return root;
//        TreeNode* left = lowestCommonAncestor(root->left, p, q);
//        TreeNode* right = lowestCommonAncestor(root->right, p, q);
//        if (!left)//左子树找不到，声明两个在右子树
//            return right;
//        if (!right)
//            return left;
//        return root;//左右子树都有，则当前节点为最近公共祖先
//    }
//};